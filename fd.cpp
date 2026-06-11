#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
using namespace std;
const int W=40,H=20,P=6,M=3;
void cls(){system("cls");}
void waitKey(){cout<<"\nNacisnij klawisz...";_getch();}
void draw(int bx,int by,int px,int s,int l){
 cls(); cout<<"Zlap kulke! Punkty:"<<s<<" Zycia:"<<l<<"\n";
 for(int y=0;y<=H;y++){for(int x=0;x<=W;x++){
 if(y==0||y==H||x==0||x==W) cout<<"#";
 else if(y==H-1 && x>=px && x<px+P) cout<<"=";
 else if(x==bx && y==by) cout<<"O";
 else cout<<" ";}
 cout<<"\n";}
 cout<<"A/D lub <- ->, ESC wyjscie\n";}
void playGame(){
 srand((unsigned)time(NULL));
 int px=W/2-P/2,bx=1+rand()%(W-2),by=1,s=0,l=M,k;
 while(l>0){
 draw(bx,by,px,s,l);
 if(_kbhit()){k=_getch(); if(k==0||k==224) k=_getch();
 if((k=='a'||k=='A'||k==75||k==37)&&px>1) px--;
 if((k=='d'||k=='D'||k==77||k==39)&&px+P<W) px++;
 if(k==27) break;}
 by++;
 if(by>=H-1){ if(bx>=px && bx<px+P) s++; else l--;
 bx=1+rand()%(W-2); by=1; }
 Sleep(120); }
 draw(bx,by,px,s,l); cout<<"Koniec gry! Punkty:"<<s<<"\n"; waitKey();}
void show(const char* lines[]) {
    cls();
    for (int i = 0; lines[i]; i++) {
        cout << lines[i] << "\n";
    }
    waitKey();
}

int main() {
    char c;
    const char* menu[] = {
        "--- MENU ---",
        "1. Gra",
        "2. Jak grac",
        "3. O autorze",
        "4. Wyjscie",
        "Wybierz: ",
        NULL
    };
    const char* how[] = {
        "Jak grac?",
        "",
        "Graj: A/D lub lewo/prawo.",
        "Zlap spadajaca kulke.",
        NULL
    };
    const char* about[] = {
        "Autor: Antoni Pietraszak",
        "Klasa: 1a",
        NULL
    };

    do {
        cls();
        for (int i = 0; menu[i]; i++) {
            cout << menu[i] << "\n";
        }
        c = _getch();
        cout << c << "\n";

        if (c == '1') playGame();
        else if (c == '2') show(how);
        else if (c == '3') show(about);
        else if (c == '4') {
            cls();
            cout << "Do widzenia!\n";
            Sleep(700);
        } else {
            cout << "Nieprawidlowy wybor\n";
            Sleep(700);
        }
    } while (c != '4');

    return 0;
}




