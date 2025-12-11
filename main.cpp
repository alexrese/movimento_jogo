/*
  Código criado por Thiago Felski Pereira
  Adaptado Alex Luciano Roesler Rese
  Move um caractere na matriz sem testes
  Útil para implementação de jogos
  com movimentação de personagem.
  (Típicos de algoritmos)
*/
#include <iostream>
#include <termios.h>
#include <unistd.h>
using namespace std;

int getch(void) {
  int ch;
  struct termios oldt;
  struct termios newt;
  tcgetattr(STDIN_FILENO, &oldt); // guarda as configurações antigas
  newt = oldt; // copia as configurações antigas para as novas
  newt.c_lflag &= ~(ICANON | ECHO); // faz uma mudança nas novas configurações
  tcsetattr(STDIN_FILENO, TCSANOW, &newt); // aplica as novas configurações
  ch = getchar();                          // pega a tecla
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restaura as configurações antigas
  return ch;                               // retorna o caractere lido
}

void SetCursorPos(int XPos, int YPos) {
  printf("\033[%d;%dH", YPos + 1, XPos + 1);
}

int main() {
  printf("\033[?25l"); //código para o desativar o cursor no console    
    
  int px = 2, py = 2;
  int m[5][5] = {{1, 1, 1, 1, 1},
                 {1, 0, 0, 0, 1},
                 {1, 0, 2, 0, 1},
                 {1, 0, 0, 0, 1},
                 {1, 1, 1, 1, 1}};

  char x;
  while (true) {
    cout << "texto antes da matriz\n";
    // imprime matriz
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        switch (m[i][j]) {
        case 0:
          cout << " ";
          break;
        case 1:
          printf("\033[0;44m");// fundo do texto azul
          cout << " ";
          printf("\033[0m");//todo texto normal
          break;
        case 2:
          cout << "@";    
          break;
        default:
          cout << " ";
        }
      }
      cout << endl;
    }
    cout << "texto depois da matriz\n";
    // atualiza jogador
    x = getch(); // pega a tecla
    switch (x) {
    case 'w':
      // remove da posição antiga
      m[px][py] = 0;
      // adiciona na nova posição
      px = px - 1;
      m[px][py] = 2;
      break;

    case 's':
      // remove da posição antiga
      m[px][py] = 0;
      // adiciona na nova posição
      px = px + 1;
      m[px][py] = 2;
      break;

    case 'a':
      // remove da posição antiga
      m[px][py] = 0;
      // adiciona na nova posição
      py = py - 1;
      m[px][py] = 2;
      break;

    case 'd':
      // remove da posição antiga
      m[px][py] = 0;
      // adiciona na nova posição
      py = py + 1;
      m[px][py] = 2;
      break;
      // default:
    }
    // coloca o cursor na posição inicial
    SetCursorPos(0, 0);
    //(void)system("clear");
  }

  return 0;
}
