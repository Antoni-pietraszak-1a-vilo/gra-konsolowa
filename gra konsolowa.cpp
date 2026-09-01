#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

const int W=50, H=20;
int x, y, dx, dy, p1, p2, s1, s2;

void reset(){
    x=W/2; y=H/2;
    dx=rand()%2?1:-1; dy=rand()%2?1:-1;
}

void info(){
    system("cls");
    cout<<"===== INFORMACJE O AUTORZE =====\n\n";
    cout<<"Antoni Pietraszak\nKlasa: 2a\nUcze sie programowac.\n\n";
    cout<<"Nacisnij klawisz...";
    _getch();
}

void instrukcja(){
    system("cls");
    cout<<"===== JAK GRAC? =====\n\n";
    cout<<"Gracz 1: W / S\n";
    cout<<"Gracz 2: strzalki gora / dol\n";
    cout<<"Zdobadz 5 punktow, aby wygrac!\n\n";
    cout<<"Nacisnij klawisz...";
    _getch();
}

void rysuj(){
    system("cls");
    cout<<"----- PONG -----\n";
    for(int j=0; j<H; j++){
        cout<<"|";
        for(int i=0; i<W; i++){
            if(i==2 && j>=p1 && j<p1+4) cout<<"#";
            else if(i==W-3 && j>=p2 && j<p2+4) cout<<"#";
            else if(i==x && j==y) cout<<"O";
            else cout<<" ";
        }
        cout<<"|\n";
    }
    cout<<"--------------------\n";
    cout<<"Gracz 1: "<<s1<<"   Gracz 2: "<<s2<<"\n";
}


