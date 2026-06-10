#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

using namespace std;

void clearScreen() {
	system("cls");
}

void waitForKey() {
	cout << "\nNaciœnij dowolny klawisz, aby wróciæ do menu...";
	_getch();
}

void startGame() {
	clearScreen();
	cout << "Rozpoczynam grê PONG...\n";
	cout << "(Tutaj mo¿esz dodaæ implementacjê gry)\n";
	waitForKey();
}

void howToPlay() {
	clearScreen();
	cout << "Jak graæ?\n\n";
	cout << "- Sterowanie dla lewego gracza: W (góra), S (dó³)\n";
	cout << "- Sterowanie dla prawego gracza: Strza³ka góra, Strza³ka dó³\n";
	cout << "- Celem jest odbiæ pi³kê tak, aby przeciwnik jej nie z³apa³.\n";
	cout << "- Gra toczy siê do ustalonej liczby punktów.\n";
	waitForKey();
}

void about() {
	clearScreen();
	cout << "Informacje o autorze:\n\n";
	cout << "Antoni Pietraszak\n";
	cout << "Klasa: 1a\n";
	cout << "Uczê siê programowaæ.\n";
	waitForKey();
}

int main() {
	char choice;
	do {
		clearScreen();
		cout << "------ PONG - MENU ------\n";
		cout << "1. Zacznij grê\n";
		cout << "2. Jak graæ?\n";
		cout << "3. Informacje o autorze\n";
		cout << "4. WyjdŸ z gry\n\n";
		cout << "Wybierz opcjê (1-4): ";

		choice = _getch();
		cout << choice << "\n";

		switch (choice) {
			case '1': startGame(); break;
			case '2': howToPlay(); break;
			case '3': about(); break;
			case '4': clearScreen(); cout << "Do widzenia!\n"; Sleep(700); break;
			default:
				cout << "Nieprawid³owy wybór. Spróbuj ponownie...\n";
				Sleep(700);
		}
	} while (choice != '4');

	return 0;
}




