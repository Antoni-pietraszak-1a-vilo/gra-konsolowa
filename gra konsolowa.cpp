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
    cout<<"=== INFORMACJE O AUTORZE ===\n\n";
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
void gra(){
    s1=s2=0; p1=p2=H/2-2; reset();

    while(s1<5 && s2<5){

        if(GetAsyncKeyState(VK_ESCAPE) & 0x8000) return;


        if((GetAsyncKeyState('W') & 0x8000) && p1>0) p1--;
        if((GetAsyncKeyState('S') & 0x8000) && p1<H-4) p1++;


        if((GetAsyncKeyState(VK_UP) & 0x8000) && p2>0) p2--;
        if((GetAsyncKeyState(VK_DOWN) & 0x8000) && p2<H-4) p2++;

        x+=dx; y+=dy;

        if(y<=0||y>=H-1) dy=-dy;
        if(x==3&&y>=p1&&y<p1+4) dx=1;
        if(x==W-4&&y>=p2&&y<p2+4) dx=-1;

        if(x<=0){ s2++; reset(); }
        if(x>=W-1){ s1++; reset(); }

        rysuj();
        Sleep(70);
    }

    system("cls");
    cout<<"===== KONIEC GRY =====\n\n";
    cout<<(s1>s2?"Wygral Gracz 1!":"Wygral Gracz 2!")<<"\n";
    cout<<"Wynik: "<<s1<<" : "<<s2<<"\n\n";
    cout<<"Nacisnij klawisz...";
    _getch();
}

int main(){
    srand(time(0));
    char w;

    do{
        system("cls");
        cout<<"----- PONG - MENU -----\n";
        cout<<"1. Zacznij gre\n";
        cout<<"2. Jak grac?\n";
        cout<<"3. Informacje o autorze\n";
        cout<<"4. Wyjdz z gry\n\n";
        cout<<"Wybierz opcje (1-4): ";
        w=_getch();

        switch(w){
            case '1': gra(); break;
            case '2': instrukcja(); break;
            case '3': info(); break;
        }
    } while(w!='4');

    return 0;
}

