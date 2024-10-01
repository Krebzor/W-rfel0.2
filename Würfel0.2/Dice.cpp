#include <iostream>
using namespace std;

class Dice {
protected:
	int sides; // Anzahl der Seiten

public:
	// Konstruktor
	Dice(int s) : sides(s) {}

	// Funktion zum Würfeln
	virtual int roll() const {
		return (rand() % sides) + 1;
	}

	// Destruktor
	virtual ~Dice() {}
};
static void chooseDiceAndRoll() {
    int diceType;
    int numberOfRolls;
    int totalPoints = 0;

    cout << "Waehle einen Wuerfeltyp: \n";
    cout << "1. W6\n";
    cout << "2. W20\n";
    cout << "3. W100\n";
    cout << "Gib die Nummer des Wuerfels ein: ";
    cin >> diceType;

    cout << "Wie oft moechtest du den Wuerfel werfen? ";
    cin >> numberOfRolls;

    // Erstelle den entsprechenden Würfel basierend auf der Auswahl
    Dice* selectedDice = nullptr;
    switch (diceType) {
    case 1:
        selectedDice = new Dice(6);
        break;
    case 2:
        selectedDice = new Dice(20);
        break;
    case 3:
        selectedDice = new Dice(100);
        break;
    default:
        std::cout << "Ungueltige Auswahl. W6 wird als Standard verwendet.\n";
        selectedDice = new Dice(6);
    }

    // Würfel die angegebene Anzahl an Malen
    cout << "\nWuerfelergebnisse:\n";
    for (int i = 0; i < numberOfRolls; ++i) {
        int result = selectedDice->roll(); // Ergebnis jedes Wurfes
        cout << "Wurf " << (i + 1) << ": " << result << endl;
        totalPoints += result;
    }

    cout << "Gesamtsumme des Wurfes: " << totalPoints << endl;
    
    // Speicher freigeben
    delete selectedDice;
}

