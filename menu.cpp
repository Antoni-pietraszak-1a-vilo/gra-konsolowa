#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

using namespace std;

void clearScreen() {
	system("cls");
}

void waitForKey() {
	cout << "\nNacisnij dowolny klawisz, aby wrocic do menu...";
	_getch();
}

void startGame() {
	clearScreen();
	cout << "Rozpoczynam gre PONG...\n";
	cout << "(Tutaj mozesz dodac implementacje gry)\n";
	waitForKey();
}

void howToPlay() {
	clearScreen();
	cout << "Jak grac?\n\n";
	cout << "- Sterowanie dla lewego gracza: W (gora), S (dol)\n";
	cout << "- Sterowanie dla prawego gracza: Strzalka gora, Strzalka dol\n";
	cout << "- Celem jest odbic pilke tak, aby przeciwnik jej nie zlapal.\n";
	cout << "- Gra toczy sie do ustalonej liczby punktow.\n";
	waitForKey();
}

void about() {
	clearScreen();
	cout << "Informacje o autorze:\n\n";
	cout << "Antoni Pietraszak\n";
	cout << "Klasa: 1a\n";
	cout << "Ucze sie programowac.\n";
	waitForKey();
}

int main() {
	char choice;
	do {
		clearScreen();
		cout << "------ PONG - MENU ------\n";
		cout << "1. Zacznij grę\n";
		cout << "2. Jak grać?\n";
		cout << "3. Informacje o autorze\n";
		cout << "4. Wyjdź z gry\n\n";
		cout << "Wybierz opcje (1-4): ";

		choice = _getch();
		cout << choice << "\n";

		switch (choice) {
			case '1': startGame(); break;
			case '2': howToPlay(); break;
			case '3': about(); break;
			case '4': clearScreen(); cout << "Do widzenia!\n"; Sleep(700); break;
			default:
				cout << "Nieprawidlowy wybor. Sprobuj ponownie...\n";
				Sleep(700);
		}
	} while (choice != '4');

	return 0;
}




