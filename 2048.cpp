#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Celda{ //Clase celda que representará a cada casilla del juego

  private:

    int valor;
    int i;
    int j;

  public:

    Celda(){

        valor = 0;
        i = 0;
        j = 0;

    }

    void SetValor(int val){

      valor = val;

    }

    void SetI(int posi){

      i = posi;

    }

    void SetJ(int posj){

      j = posj;

    }

    int GetValor(){

      return valor;

    }

    int GetI(){

      return i;

    }

    int GetJ(){

      return j;

    }

};

class Tablero{

  private:

    Celda Tab[4][4];

  public:

    Tablero(){


    }

    bool Aniadir(int num){ //Método para añadir un número 2 aleatoriamente en una de las casillas exteriores, numeradas del 1 al 12. Devuelve si se ha podido añadir una cifra o no.

      bool resultado = false;
      int contador = 0;
      int cifra = 2;

      if(num == 1 && Tab[0][0].GetValor() == 0){

        Tab[0][0].SetValor(cifra);
        resultado = true;

      }else if(num == 2 && Tab[0][1].GetValor() == 0){

        Tab[0][1].SetValor(cifra);
        resultado = true;

      }else if(num == 3 && Tab[0][2].GetValor() == 0){

        Tab[0][2].SetValor(cifra);
        resultado = true;

      }else if(num == 4 && Tab[0][3].GetValor() == 0){

        Tab[0][3].SetValor(cifra);
        resultado = true;

      }else if(num == 5 && Tab[1][0].GetValor() == 0){

        Tab[1][0].SetValor(cifra);
        resultado = true;

      }else if(num == 6 && Tab[1][3].GetValor() == 0){

        Tab[1][3].SetValor(cifra);
        resultado = true;

      }else if(num == 7 && Tab[2][0].GetValor() == 0){

        Tab[2][0].SetValor(cifra);
        resultado = true;

      }else if(num == 8 && Tab[2][3].GetValor() == 0){

        Tab[2][3].SetValor(cifra);
        resultado = true;

      }else if(num == 9 && Tab[3][0].GetValor() == 0){

        Tab[3][0].SetValor(cifra);
        resultado = true;

      }else if(num == 10 && Tab[3][1].GetValor() == 0){

        Tab[3][1].SetValor(cifra);
        resultado = true;

      }else if(num == 11 && Tab[3][2].GetValor() == 0){

        Tab[3][2].SetValor(cifra);
        resultado = true;

      }else if(num == 12 && Tab[3][3].GetValor() == 0){

        Tab[3][3].SetValor(cifra);
        resultado = true;

      }

      for(int i = 0; i < 4; i++){

        for(int j = 0; j < 4; j++){

          if(Tab[i][j].GetValor() != 0){

            contador ++;

          }

        }

      }

      if(contador == 16){

        resultado = true;

      }

      return resultado;

    }

    bool Movimiento(char letra){ //Método para mover las casillas del juego.

      int contador = 0;
      int x = 1;
      bool moverse = false;

      if(letra == 'D' || letra == 'd'){

        for(int i = 0; i < 4; i++){

          for(int j = 3; j >= 0; j--){

            if(Tab[i][j].GetValor() != 0){

              while(Tab[i][j + x].GetValor() == 0 && j + x < 4){

                contador ++;
                x++;

              }

              if(contador != 0){

                Tab[i][j + contador].SetValor(Tab[i][j].GetValor());
                Tab[i][j].SetValor(0);
                moverse = true;

              }

              if(Tab[i][j + contador].GetValor() == Tab[i][j + contador + 1].GetValor() && j + contador < 3){

                Tab[i][j + contador + 1].SetValor(2 * Tab[i][j + contador + 1].GetValor());
                Tab[i][j + contador].SetValor(0);
                moverse = true;

              }

              contador = 0;
              x = 1;

            }

          }

        }

      }else if(letra == 'A' || letra == 'a'){

        for(int i = 0; i < 4; i++){

          for(int j = 0; j < 4; j++){

            if(Tab[i][j].GetValor() != 0){

              while(Tab[i][j - x].GetValor() == 0 && j - x >= 0){

                contador ++;
                x++;

              }

              if(contador != 0){

                Tab[i][j - contador].SetValor(Tab[i][j].GetValor());
                Tab[i][j].SetValor(0);
                moverse = true;

              }

              if(Tab[i][j - contador].GetValor() == Tab[i][j - contador - 1].GetValor() && j - contador > 0){

                Tab[i][j - contador - 1].SetValor(2 * Tab[i][j - contador - 1].GetValor());
                Tab[i][j - contador].SetValor(0);
                moverse = true;

              }

              contador = 0;
              x = 1;

            }

          }

        }


      }else if(letra == 'S' || letra == 's'){

        for(int i = 3; i >= 0; i--){

          for(int j = 0; j < 4; j++){

            if(Tab[i][j].GetValor() != 0){

              while(Tab[i + x][j].GetValor() == 0 && i + x < 4){

                contador ++;
                x++;

              }

              if(contador != 0){

                Tab[i + contador][j].SetValor(Tab[i][j].GetValor());
                Tab[i][j].SetValor(0);
                moverse = true;

              }

              if(Tab[i + contador][j].GetValor() == Tab[i + contador + 1][j].GetValor() && i + contador < 3){

                Tab[i + contador + 1][j].SetValor(2 * Tab[i + contador + 1][j].GetValor());
                Tab[i + contador][j].SetValor(0);
                moverse = true;

              }

              contador = 0;
              x = 1;

            }

          }

        }

      }else{

        for(int i = 0; i < 4; i++){

          for(int j = 0; j < 4; j++){

            if(Tab[i][j].GetValor() != 0){

              while(Tab[i - x][j].GetValor() == 0 && i - x >= 0){

                contador ++;
                x++;

              }

              if(contador != 0){

                Tab[i - contador][j].SetValor(Tab[i][j].GetValor());
                Tab[i][j].SetValor(0);
                moverse = true;

              }

              if(Tab[i - contador][j].GetValor() == Tab[i - contador - 1][j].GetValor() && i - contador > 0){

                Tab[i - contador - 1][j].SetValor(2 * Tab[i - contador - 1][j].GetValor());
                Tab[i - contador][j].SetValor(0);
                moverse = true;

              }

              contador = 0;
              x = 1;

            }

          }

        }

      }

      return moverse;

    }

    bool Fin(){ //Método para saber cuando el juego termina.

      int contador = 0;
      bool resultado = false;

      for(int i = 0; i < 4; i++){

        for(int j = 0; j < 3; j++){

          if(Tab[i][j].GetValor() != Tab[i][j + 1].GetValor() && Tab[i][j].GetValor() != 0 && Tab[i][j + 1].GetValor() != 0){

            contador ++;

          }

        }

      }

      for(int j = 0; j < 4; j++){

        for(int i = 0; i < 3; i++){

          if(Tab[i][j].GetValor() != Tab[i + 1][j].GetValor() && Tab[i][j].GetValor() != 0 && Tab[i + 1][j].GetValor() != 0){

            contador ++;

          }

        }

      }

      if(contador == 24){

        resultado = true;

      }

      contador = 0;

      return resultado;

    }

    void Mostrar(){ //Método para mostrar en la terminal el juego, con sus distintos colores respectivamente.

      cout << endl;

      for(int i = 0; i < 4; i++){

        for(int j = 0; j < 4; j++){

          if(Tab[i][j].GetValor() == 0){

            cout << Tab[i][j].GetValor() << "   ";

          }else if(Tab[i][j].GetValor() == 2){

            cout << "\033[1;2;33m2\033[0m"<< "   ";

          }else if(Tab[i][j].GetValor() == 4){

            cout << "\033[1;33m4\033[0m"<< "   ";

          }else if(Tab[i][j].GetValor() == 8){

            cout << "\033[1;2;32m8\033[0m"<< "   ";

          }else if(Tab[i][j].GetValor() == 16){

            cout << "\033[1;32m16\033[0m"<< "   ";

          }else if(Tab[i][j].GetValor() == 32){

            cout << "\033[1;2;36m32\033[0m"<< "   ";

          }else if(Tab[i][j].GetValor() == 64){

            cout << "\033[1;36m64\033[0m"<< "   ";

          }else if(Tab[i][j].GetValor() == 128){

            cout << "\033[1;2;34m128\033[0m"<< "   ";

          }else if(Tab[i][j].GetValor() == 256){

            cout << "\033[1;34m256\033[0m"<< "   ";

          }else if(Tab[i][j].GetValor() == 512){

            cout << "\033[1;2;35m512\033[0m"<< "   ";

          }else if(Tab[i][j].GetValor() == 1024){

            cout << "\033[1;35m1024\033[0m"<< "   ";

          }else if(Tab[i][j].GetValor() == 2048){

            cout << "\033[1;2;31m1024\033[0m"<< "   ";

          }else if(Tab[i][j].GetValor() == 4096){

            cout << "\033[1;31m1024\033[0m"<< "   ";

          }else{

            cout << Tab[i][j].GetValor() << "   ";

          }


        }

        cout << endl << endl;

      }

    }

};

int main(){

  Tablero t1;
  int num = 0;
  int ronda = 1;
  char mover;
  bool GameOver = false;

  cout << endl << endl;

  cout << "\033[1;31m██████╗  ██████╗ ██╗  ██╗ █████╗     ██████╗ ██╗   ██╗    ██████╗ ███████╗██████╗ ██████╗ ██╗   ██╗ ██████╗██╗  ██╗███████╗\033[0m " << endl;
  cout << "\033[1;31m╚════██╗██╔═████╗██║  ██║██╔══██╗    ██╔══██╗╚██╗ ██╔╝    ██╔══██╗██╔════╝██╔══██╗██╔══██╗██║   ██║██╔════╝██║ ██╔╝██╔════╝\033[0m" << endl;
  cout << "\033[1;31m █████╔╝██║██╔██║███████║╚█████╔╝    ██████╔╝ ╚████╔╝     ██████╔╝█████╗  ██║  ██║██████╔╝██║   ██║██║     █████╔╝ ███████╗\033[0m" << endl;
  cout << "\033[1;31m██╔═══╝ ████╔╝██║╚════██║██╔══██╗    ██╔══██╗  ╚██╔╝      ██╔═══╝ ██╔══╝  ██║  ██║██╔══██╗██║   ██║██║     ██╔═██╗ ╚════██║\033[0m" << endl;
  cout << "\033[1;31m███████╗╚██████╔╝     ██║╚█████╔╝    ██████╔╝   ██║       ██║     ███████╗██████╔╝██║  ██║╚██████╔╝╚██████╗██║  ██╗███████║\033[0m" << endl;
  cout << "\033[1;31m╚══════╝ ╚═════╝      ╚═╝ ╚════╝     ╚═════╝    ╚═╝       ╚═╝     ╚══════╝╚═════╝ ╚═╝  ╚═╝ ╚═════╝  ╚═════╝╚═╝  ╚═╝╚══════╝\033[0m" << endl;


  cout << endl << endl << "Para mover el tablero utilice W A S D" << endl;

  srand((unsigned)time(0));

  while(GameOver == false){

    num = (rand() % 12) + 1; //Generamos el numero aleatorio entre 1 y 12 para ir añadiendo al juego.

    if(t1.Aniadir(num) == true){ //Si se ha podido añadir un 2 en cierta casilla pasamos a realizar lo siguiente.

      t1.Mostrar(); //Mostrarle el tablero al usuario
      GameOver = t1.Fin(); //Obtener el estado de la partida
      cout << endl << "RONDA: " << ronda;

      if(GameOver == false){ //Si no ha acabado la partida pasamos a lo siguiente.

        cout << endl << "Introduzca el movimiento: "; //Le pedimos un movimiento al usuario.
        cin >> mover;


        while(mover != 'W' && mover != 'A' && mover != 'S' && mover != 'D' && mover != 'w' && mover != 'a' && mover != 's' && mover != 'd'){ //Nos aseguramos de que es correcto.

          cout << endl << "Direccion mal introducida, introduzca una nueva: ";
          cin >> mover;

        }

        while(t1.Movimiento(mover) == false){ //Si no se puede mover en esa dirección se repite el proceso.

          cout << "\033[2J\033[1;1H";
          t1.Mostrar();
          cout << endl << "RONDA: " << ronda;

          cout << endl << "Introduzca el movimiento: ";
          cin >> mover;


          while(mover != 'W' && mover != 'A' && mover != 'S' && mover != 'D' && mover != 'w' && mover != 'a' && mover != 's' && mover != 'd'){

            cout << endl << "Direccion mal introducida, introduzca una nueva: ";
            cin >> mover;

          }

        }

        cout << "\033[2J\033[1;1H";

      }

      ronda ++; //Cada vez que se completa un ciclo pasamos de ronda.

    }

  }

  cout << endl << endl;

  cout << "\033[1;32m ██████╗  █████╗ ███╗   ███╗███████╗         ██████╗ ██╗   ██╗███████╗██████╗ \033[0m" << endl;
  cout << "\033[1;32m██╔════╝ ██╔══██╗████╗ ████║██╔════╝        ██╔═══██╗██║   ██║██╔════╝██╔══██╗\033[0m" << endl;
  cout << "\033[1;32m██║  ███╗███████║██╔████╔██║█████╗          ██║   ██║██║   ██║█████╗  ██████╔╝\033[0m" << endl;
  cout << "\033[1;32m██║   ██║██╔══██║██║╚██╔╝██║██╔══╝          ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗\033[0m" << endl;
  cout << "\033[1;32m╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗        ╚██████╔╝ ╚████╔╝ ███████╗██║  ██║\033[0m" << endl;
  cout << "\033[1;32m ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝         ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝\033[0m" << endl;


}
