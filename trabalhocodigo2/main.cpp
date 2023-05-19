#include <iostream>
#include <windows.h>
#include <conio.h>
#include "rotinas.h"
using namespace std;

int main()
{
    int m[10][10];
    int x,y;
    bool jogando=false;
Basico fazer;
Jogo jogar;
 system("cls");
   fazer.mostrarCursor(FALSE);
    jogar.menu(m, x, y, jogando);

    return 0;

}
