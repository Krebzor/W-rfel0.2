#include <iostream>
#include "Dice.cpp"
using namespace std;

int main() {
    srand(std::time(0)); // Zufallsgenerator initialisieren

    char repeat = 'y';

    while (repeat == 'y') {
        chooseDiceAndRoll(); // Die Funktion zur Auswahl und zum W�rfeln aufrufen

        cout << "\nMoechtest du erneut wuerfeln? (y/n): ";
        cin >> repeat;
    }

    return 0;
}
