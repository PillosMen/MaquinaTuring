#include <iostream>
#include<cstdlib>

using namespace std;

const int ERR= -1;
string pal, cinta;
int idx;
const int matran [6][3] = {
           //#  |  0  |  X
    /*q0*/ {ERR,   1, ERR},
    /*q1*/ { 5,    2,  1 },
    /*q2*/ {ERR,   3,  2 },
    /*q3*/ {ERR,   2,  3 },
    /*q4*/ { 1,    4, ERR},
    /*q5*/ {ERR,  ERR, ERR}
};

    int colCar(char c){
    if(c == '#') return 0;
    if(c == '0') return 1;
    if(c == 'x') return 2;
        cout << "Simbolo no valido" << c << endl;
            return ERR;
    }

    void mover (char m) {
        if( m == 'D' ) idx++;
        if( m == 'I' ) idx--;
    }

    int main(){
    cout << "Palabra [.]= salir: ";
    cin >> pal;
    while (pal != "."){
        cinta = "#" + pal + "#";
        int estado = 0;
        idx = 1;
        cout << cinta << endl;
        while (estado != 6 and estado != ERR){
            int col = colCar(cinta[idx]);
            cout << "col= " << col << endl;
            cout << "estado= " << estado << "idx= " << idx << endl;

            if(col >=0){

            switch(estado){

            case 0:
                if( col == 0) cinta[idx] = 'x';
                if( col == 0) mover('D');
                    break;
            case 1:
                if( col == 2) cinta[idx]= 'x';
                if( col == 1 and col == 2) mover('D');
                    break;
            case 2:
                if (col == 1) mover('D');
                else if (col == 2 ) mover ('D');

            case 3:
                if (col == 2) mover('D');
                if (col == 1) mover('D');
                    break;
            case 4:
                if (col == 0) mover ('I');
                if (col == 1) mover ('I');
                    break;
            case 5:
                if (col == 0) mover ('D');
                if (col == 2) mover ('D');
                if (col == 0) mover ('D');
                    break;
                default: break;
                }
                estado = matran[estado][col];

            }else estado = ERR;


        }

        cout << estado << endl;
        if( estado == 6)
        cout << pal << " pertenece al Lenguaje" << endl;
        else
        cout << pal << " NO ESTA en el Lenguaje" << endl;
        cout << "Palabra [.]=salir: ";
        cin >> pal;

    }

    }

return EXIT_SUCCESS;
