#include <iostream>
//INTEGRANTES DEL GRUPO:
//Joaquín Muñoz Rodríguez
//Marcia Montenegro Cavagnaro
//Gabriel Rodríguez

using namespace std;

char espacios[10] = {'o','1','2','3','4','5','6','7','8','9'};

//verificamos las jugadas posibles para ganar
int verificaganador(){
if (espacios[1] == espacios[2] && espacios[2] == espacios[3])

        return 1;
    else if (espacios[4] == espacios[5] && espacios[5] == espacios[6])

        return 1;
    else if (espacios[7] == espacios[8] && espacios[8] == espacios[9])

        return 1;
    else if (espacios[1] == espacios[4] && espacios[4] == espacios[7])

        return 1;
    else if (espacios[2] == espacios[5] && espacios[5] == espacios[8])

        return 1;
    else if (espacios[3] == espacios[6] && espacios[6] == espacios[9])

        return 1;
    else if (espacios[1] == espacios[5] && espacios[5] == espacios[9])

        return 1;
    else if (espacios[3] == espacios[5] && espacios[5] == espacios[7])

        return 1;
    else if (espacios[1] != '1' && espacios[2] != '2' && espacios[3] != '3'
                    && espacios[4] != '4' && espacios[5] != '5' && espacios[6] != '6'
                  && espacios[7] != '7' && espacios[8] != '8' && espacios[9] != '9')

        return 0;
    else
        return -1;


}


//DIBUJO DEL TABLERO
// CLS para borrar lo que ya se puso

void tablero()
{

    cout << "\n\n TRES EN RAYA \n\n";

    cout << "Jugador 1 (X)  -  Jugador 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << espacios[1] << "  |  " << espacios[2] << "  |  " << espacios[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << espacios[4] << "  |  " << espacios[5] << "  |  " << espacios[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << espacios[7] << "  |  " << espacios[8] << "  |  " << espacios[9] << endl;

    cout << "     |     |     " << endl << endl;
}


int main()
{

  //int modo_juego;
  //cout<<"¿Qué modo de juego eliges? presiona 1, para jugador vs jugador y para jugador vs PC presiona 2 ";
  //cin>>modo_juego;

	int jugador = 1,i,elige;

    char simbolo;
    do
    {
        tablero();
        jugador=(jugador%2)?1:2; //identificar a que jugador le corresponde jugar

        cout << "Jugador " << jugador << ", ingresa un número:  ";
        cin >> elige;

        simbolo=(jugador == 1) ? 'X' : 'O'; //verifica que jugador esta jugando para asignarle el simbolo correspondiente
        //todos estas comprobaciones simplemente son para poder verificar que el sitio que elige el jugador este libre de cualquier simbolo
        if (elige == 1 && espacios[1] == '1')

            espacios[1] = simbolo;
        else if (elige == 2 && espacios[2] == '2')

            espacios[2] = simbolo;
        else if (elige == 3 && espacios[3] == '3')

            espacios[3] = simbolo;
        else if (elige == 4 && espacios[4] == '4')

            espacios[4] = simbolo;
        else if (elige == 5 && espacios[5] == '5')

            espacios[5] = simbolo;
        else if (elige == 6 && espacios[6] == '6')

            espacios[6] = simbolo;
        else if (elige == 7 && espacios[7] == '7')

            espacios[7] = simbolo;
        else if (elige == 8 && espacios[8] == '8')

            espacios[8] = simbolo;
        else if (elige == 9 && espacios[9] == '9')

            espacios[9] = simbolo;
        else //si el espacio ya esta ocupado imprime el mensaje
        {
            cout<<"espacio no encontrado ";

            jugador--;
            cin.ignore();
            cin.get();
        }
        i=verificaganador();//comprueba todo el rato si el juego ya tuvo un ganador

        jugador++;
    }while(i==-1); //mientras i sea -1 el codigo se ejecuta con normalidad
    tablero(); //dibuja el tablero, al estar en un while lo actualiza constantemente
    if(i==1)

        cout<<"==>\aJugador "<<--jugador<<" Ganador ";
    else
        cout<<"==>\aJuego empatado";

    cin.ignore(); //Esencialmente, para las sentencias std::cin que usa ignorar antes
    // de hacer una llamada getline, porque cuando un usuario ingresa algo con
    //std::cin, pulsa enter y un '\n' char entra en el cin buffer.
    //Luego, si usa getline, obtiene el carácter de nueva línea en lugar de la cadena que desea.
    //Entonces haces un std::cin.ignore(1000,'\n') y eso debería borrar el búfer hasta la cadena que deseas.
     //(El 1000 se coloca allí para omitir una cantidad específica de caracteres antes del punto de interrupción
       // especificado, en este caso, el carácter de nueva línea\n).

    cin.get(); //cin.get() es una función que lee un carácter que se introduce desde
    //el teclado, el cual podemos almacenar en una variable.
    return 0;

}
    //1 el juego termino con un ganador
    //-1 el juego sigue ejecutandose
    //O empate
