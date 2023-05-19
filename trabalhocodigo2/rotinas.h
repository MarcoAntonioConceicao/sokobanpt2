#ifndef ROTINAS_H_INCLUDED
#define ROTINAS_H_INCLUDED

#include <iostream>
#include <windows.h> //cursor
#include <conio.h> //getch
#include <fstream> //arquivo
#include <stdlib.h> //random


/*
0   BLACK
1   BLUE
2   GREEN
3   CYAN
4   RED
5   MAGENTA
6   BROWN
7   LIGHTGRAY
8   DARKGRAY
9   LIGHTBLUE
10  LIGHTGREEN
11  LIGHTCYAN
12  LIGHTRED
13  LIGHTMAGENTA
14  YELLOW
15  WHITE

*/


using namespace std;
string palavra;

struct Basico  {
bool fazer;
void posicaoxy( int column, int line )
{
        COORD coord;
        coord.X = column;
        coord.Y = line;
        SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
    }
void mostrarCursor(bool showFlag)
{
        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

        CONSOLE_CURSOR_INFO     cursorInfo;

        GetConsoleCursorInfo(out, &cursorInfo);
        cursorInfo.bVisible = showFlag; // set the cursor visibility
        SetConsoleCursorInfo(out, &cursorInfo);
    }
void colorir (int cor){

        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(out, cor);
    }
};

struct mapas {
bool maps;

 void imprimir(int m[10][10], int x, int y){
         Basico fazer;
        for (int i=0;i<10;i++){
            for (int j=0;j<10;j++){
                if(i==x and j==y){
                    fazer.colorir(10); ///colorir faz com que a escrita a seguir seja com a cor número 10
                    cout<<char(2); ///impressão do personagem.
                    fazer.colorir(7); ///retorna a cor original após o fim da escrita
                } else {
                    switch(m[i][j]){
                        case 0:
                            cout<<" "; ///impressão do espaço vazio
                            break;

                        case 1:
                            fazer.colorir(14);
                            //cout<<char(178); ///impressão da parede
                            cout<<char(219); ///impressão da parede
                            fazer.colorir(7);
                            break;

                        case 2:
                            fazer.colorir(12);
                            cout<<char(219); ///impressão da caixa
                            fazer.colorir(7);
                            break;
                        case 3:
                            fazer.colorir(9);
                            cout<<char(4); ///impressão do destino da caixa
                            fazer.colorir(7);
                            break;
                        case 4:
                            fazer.colorir(11);
                            cout<<char(219); ///impressão da caixa no destino
                            fazer.colorir(7);
                            break;
                    }
                }

            }
            cout<<"\n";

        }

    } //fim imprime()

  void selecionar_mapa(int m[10][10], int &x, int &y){
        int selecionar;
        int mapa[10][10];
        int num;
       int escolha;
        cout << "Digite 1 se deseja escolher o mapa que deseja jogar: " << endl;
        cout << "Digite 2 se deseja jogar um mapa aleatorio." << endl;
        cin>>selecionar;
        if(selecionar == 1){
          cout <<  "Escolha um mapa digitando entre 1 a 4." << endl;
          cin >> escolha;
        switch(escolha) {
case 1:
palavra = "mapa1";
break;

case 2:
palavra = "mapa2";
break;

case 3:
palavra = "mapa3";

break;
case 4:
palavra = "mapa4";
break;
        }
ifstream txtfile;
 std::string palavra_chave = palavra;
    std::string linha;
    bool encontrou_palavra = false;

txtfile.open("mapas.txt");
    while (std::getline(txtfile, linha)) {
        if (linha.find(palavra_chave) != std::string::npos) {
            encontrou_palavra = true;
            break;
        }
    }
      if (encontrou_palavra) {
                txtfile >> x; txtfile >> y;
                for(int i=0; i<10; i++){
                    for(int j=0; j<10; j++){
                        txtfile >> mapa[i][j];
                    }
                }
      }



                for(int i=0; i<10; i++){
                    for(int j=0; j<10; j++){
                        m[i][j]=mapa[i][j];
                    }
                }




        } //fim switch

        system("cls");

if (selecionar == 2) {
num = rand() % 4 + 1;

if (num = 1){ palavra = "mapa1"; }
if (num = 2){ palavra = "mapa2"; }
if (num = 3){ palavra = "mapa3"; }
if (num = 4){ palavra = "mapa4"; }

ifstream txtfile;
 std::string palavra_chave = palavra;
    std::string linha;
    bool encontrou_palavra = false;

txtfile.open("mapas.txt");
    while (std::getline(txtfile, linha)) {
        if (linha.find(palavra_chave) != std::string::npos) {
            encontrou_palavra = true;
            break;
        }
    }
      if (encontrou_palavra) {
                txtfile >> x; txtfile >> y;
                for(int i=0; i<10; i++){
                    for(int j=0; j<10; j++){
                        txtfile >> mapa[i][j];
                    }
                }
      }



                for(int i=0; i<10; i++){
                    for(int j=0; j<10; j++){
                        m[i][j]=mapa[i][j];
                    }
                }




        } //fim switch



    } //fim selecionar









};

struct Jogo  {
bool fazer;
mapas maps;

void menu(int m[10][10], int &x, int &y, bool &jogando){
        ofstream arquivomovimentos;
        int selecionar;
        system("cls");
        cout<<"\nBEM VINDO! SELECIONE: \n1 - Novo jogo...\n2 - Continuar...\n3 - Sobre.......\n4 - Sair........\n"<<endl;

        cin>>selecionar;
        switch(selecionar){
            case 1:
                jogando = true;
                if (jogando == true){
            arquivomovimentos.open("movimento.txt", ios::trunc);
        }
                system("cls");
                maps.selecionar_mapa(m, x, y);
                sokoban(m, x, y, jogando);
                break;
            case 2:
                if(jogando){
                    system("cls");
                    sokoban(m, x, y, jogando);
                } else {
                    system("cls");
                    jogando = true;
                    maps.selecionar_mapa(m, x, y);
                    sokoban(m, x, y, jogando);
                }

                break;
            case 3:
                system("cls");
                sobre(m, x, y, jogando);
                break;
            case 4:
                exit(0);
                break;
         //fim switch

}
system("cls");
    } //fim selecionar


 void sobre(int m[10][10], int &x, int &y, bool &jogando){
        cout<<"Sokoban e um jogo que voce move caixas para os pontos finais para conseguir passar de fase." << endl;
        cout<<"Codigo feito por: Marco Antonio." << endl;
        cout<<"Professor: Thiago Felski." << endl;
        cout<<"Aperte qualquer tecla para retornar ao menu.";
        char tecla=getch();
        system("cls");
        menu(m, x, y, jogando);
    }

void sokoban(int m[10][10], int &x, int &y, bool &jogando){
   Basico fazer;
   string nome;
    int movimentos = 0;
    while(!vitoria(m)){
        maps.imprimir(m, x, y);
        movimentar(m, x, y, movimentos);
       fazer.posicaoxy(0,0); ///posiciona a escrita no console no eixo x,y. A posição 0,0 é a do canto superior esquerdo.
    }

    jogando=false;
    system("cls");
    cout << "Registre seu nickname na tabela de pontuacao:" << endl;
    cin >> nome;

if(palavra == "mapa1") {
    adicionarPlacar(nome, movimentos, palavra); // Chamada da função movida para antes da limpeza da tela
}
    cout<<"\nVoce venceu!\nAperte qualquer tecla para retornar ao menu.\n";
    char tecla=getch();
    system("cls");
    menu(m, x, y, jogando);
}


void adicionarPlacar(string nome, int movimentos, string palavra) {
    // Abra o arquivo de placar em modo de escrita, com o flag ios::app
    ofstream arquivoPlacar("placar.txt", ios::app);

    // Verifique se o arquivo foi aberto corretamente
    if (arquivoPlacar.is_open()) {
        // Escreva os dados no arquivo
        arquivoPlacar << "Mapa 1 - "<< nome << " - " << movimentos << endl;

        // Feche o arquivo
        arquivoPlacar.close();
    } else {
        cout << "Erro ao abrir o arquivo de placar." << endl;
    }
}


    void movimentar (int m[10][10], int &x, int &y, int &movimentos) {
        char tecla;
        bool jogando = true;
        ofstream arquivomovimentos;
        if (_kbhit()){
            tecla=getch();
            switch(tecla){
                case 72:
                    ///move -> livre
                    if(m[x-1][y]==0 or m[x-1][y]==3){
                        x--;
                        movimentos ++;
                    arquivomovimentos.open("movimento.txt", ios::app);
                    arquivomovimentos << "w cima // " << endl;


                    }
                    ///caixa livre -> livre
                    else if(m[x-1][y]==2 and m[x-2][y]==0){
                        x--;
                      movimentos ++;
                    arquivomovimentos.open("movimento.txt", ios::app);
                    arquivomovimentos << "w cima // " << endl;
                        m[x][y]=0;  ///após o movimento
                        m[x-1][y]=2;  ///a frente do movimento


                    }
                    ///caixa fim -> livre
                    else if(m[x-1][y]==4 and m[x-2][y]==0){
                        x--;
                     movimentos ++;
                arquivomovimentos.open("movimento.txt", ios::app);
                arquivomovimentos << "w cima // "<< endl;

                        m[x][y]=3;  ///após o movimento
                        m[x-1][y]=2;  ///a frente do movimento

                    }
                    ///caixa livre -> fim
                    else if(m[x-1][y]==2 and m[x-2][y]==3){
                        x--;
                         movimentos ++;
                         arquivomovimentos.open("movimento.txt", ios::app);
                    arquivomovimentos << "w cima // " << endl;
                        m[x][y]=0;  ///após o movimento
                        m[x-1][y]=4;  ///a frente do movimento


                    }
                    ///caixa fim -> fim
                    else if(m[x-1][y]==4 and m[x-2][y]==3){
                        x--;
                       movimentos ++;
                        arquivomovimentos.open("movimento.txt");
                    arquivomovimentos << "w // cima " << endl;
                        m[x][y]=3;  ///após o movimento
                        m[x-1][y]=4;  ///a frente do movimento

                    }

                   arquivomovimentos.close();

               break;
                case 80: ///move -> livre
                    if(m[x+1][y]==0 or m[x+1][y]==3){
                        x++;
                      movimentos ++;
                    arquivomovimentos.open("movimento.txt", ios::app);
                    arquivomovimentos << "s baixo // " << endl;
                    }
                    ///caixa livre -> livre
                    else if(m[x+1][y]==2 and m[x+2][y]==0){
                        x++;
                       movimentos ++;
                         arquivomovimentos.open("movimento.txt", ios::app);
                    arquivomovimentos << "s baixo // " << endl;
                        m[x][y]=0;  ///após o movimento
                        m[x+1][y]=2;  ///a frente do movimento

                    }
                    ///caixa fim -> livre
                    else if(m[x+1][y]==4 and m[x+2][y]==0){
                        x++;
                        movimentos ++;
                         arquivomovimentos.open("movimento.txt", ios::app);
                    arquivomovimentos << "s baixo // " << endl;
                        m[x][y]=3;  ///após o movimento
                        m[x+1][y]=2;  ///a frente do movimento

                    }
                    ///caixa livre -> fim
                    else if(m[x+1][y]==2 and m[x+2][y]==3){
                        x++;
                        movimentos ++;
                         arquivomovimentos.open("movimento.txt", ios::app);
                    arquivomovimentos << "s baixo // " << endl;
                        m[x][y]=0;  ///após o movimento
                        m[x+1][y]=4;  ///a frente do movimento

                    }
                    ///caixa fim -> fim
                    else if(m[x+1][y]==4 and m[x+2][y]==3){
                        x++;
                          movimentos ++;
                         arquivomovimentos.open("movimento.txt", ios::app);
                    arquivomovimentos << "s baixo // " << endl;
                        m[x][y]=3;  ///após o movimento
                        m[x+1][y]=4;  ///a frente do movimento

                    }
                arquivomovimentos.close();
                break;
                case 75: ///move -> livre
                    if(m[x][y-1]==0 or m[x][y-1]==3){
                        y--;
                         movimentos ++;
                    arquivomovimentos.open("movimento.txt", ios::app);
                    arquivomovimentos << "a esquerda // " << endl;
                    }
                    ///caixa livre -> livre
                    else if(m[x][y-1]==2 and m[x][y-2]==0){
                        y--;
                        movimentos ++;
                        arquivomovimentos.open("movimento.txt", ios::app);
                    arquivomovimentos << "a esquerda // " << endl;
                        m[x][y]=0;  ///após o movimento
                        m[x][y-1]=2;  ///a frente do movimento

                    }
                    ///caixa fim -> livre
                    else if(m[x][y-1]==4 and m[x][y-2]==0){
                        y--;
                          movimentos ++;
                        arquivomovimentos.open("movimento.txt", ios::app);
                    arquivomovimentos << "a esquerda // " << endl;
                        m[x][y]=3;  ///após o movimento
                        m[x][y-1]=2;  ///a frente do movimento

                    }
                    ///caixa livre -> fim
                    else if(m[x][y-1]==2 and m[x][y-2]==3){
                        y--;
                          movimentos ++;
                        arquivomovimentos.open("movimento.txt", ios::app);
                    arquivomovimentos << "a esquerda // " << endl;
                        m[x][y]=0;  ///após o movimento
                        m[x][y-1]=4;  ///a frente do movimento

                    }
                    ///caixa fim -> fim
                    else if(m[x][y-1]==4 and m[x][y-2]==3){
                        y--;
                          movimentos ++;
                        arquivomovimentos.open("movimento.txt", ios::app);
                    arquivomovimentos << "a esquerda // " << endl;
                        m[x][y]=3;  ///após o movimento
                        m[x][y-1]=4;  ///a frente do movimento

                    }
                  arquivomovimentos.close();
                break;
                case 77: ///move -> livre
                    if(m[x][y+1]==0 or m[x][y+1]==3){
                        y++;
                       movimentos ++;
                    arquivomovimentos.open("movimento.txt", ios::app);
                    arquivomovimentos << "d direita // " << endl;
                    }
                    ///caixa livre -> livre
                    else if(m[x][y+1]==2 and m[x][y+2]==0){
                        y++;
                         movimentos ++;
                        arquivomovimentos.open("movimento.txt", ios::app);
                    arquivomovimentos << "d direita // " << endl;
                        m[x][y]=0;  ///após o movimento
                        m[x][y+1]=2;  ///a frente do movimento


}
                    ///caixa fim -> livre
                    else if(m[x][y+1]==4 and m[x][y+2]==0){
                        y++;
                        movimentos ++;
                        arquivomovimentos.open("movimento.txt", ios::app);
                    arquivomovimentos << "d direita // " << endl;
                        m[x][y]=3;  ///após o movimento
                        m[x][y+1]=2;  ///a frente do movimento

                    }
                    ///caixa livre -> fim
                    else if(m[x][y+1]==2 and m[x][y+2]==3){
                        y++;
                       movimentos ++;
                        arquivomovimentos.open("movimento.txt", ios::app);
                    arquivomovimentos << "d direita // " << endl;
                        m[x][y]=0;  ///após o movimento
                        m[x][y+1]=4;  ///a frente do movimento

                    }
                    ///caixa fim -> fim
                    else if(m[x][y+1]==4 and m[x][y+2]==3){
                        y++;
                       movimentos ++;
                        arquivomovimentos.open("movimento.txt", ios::app);
                    arquivomovimentos << "d direita // " << endl;
                        m[x][y]=3;  ///após o movimento
                        m[x][y+1]=4;  ///a frente do movimento

                    }
                   arquivomovimentos.close();
                break;
             case 'q': menu(m, x, y, jogando);

   break;



            }

        }
cout << "Movimentos: "<< movimentos;
    } //movimento

    //verifica vitória
    bool vitoria (int m[10][10]){
        for (int i=0; i<10; i++) {
            for (int j=0; j<10; j++) {
                if (m[i][j]==3){
                    return false;
                }
            }
        }
        return true;
    }




};


#endif // ROTINAS_H_INCLUDED
