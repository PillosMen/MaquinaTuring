#include <iostream>
#include <cstdlib>
using namespace std;
const int ERR= -1;
string pal, cinta;
int idx;

const int matran[6][3] = {
/*q0*/{ERR, ERR,1},
/*q1*/{5,   1,  2 },
/*q2*/{4,   2,  3},
/*q3*/{ERR, 3,  2},
/*q4*/{1,   4,  4},
/*q5*/{ERR,  ERR,ERR}

};


int colCar(char c) {
if(c == '#') return 0;
if(c == 'x') return 1;
if(c == '0') return 2;

cout << "Simbolo NO valido!!" << c << endl;
return ERR;
}
void mover(char m) {
if( m == 'D' ) idx++;
if( m == 'I' ) idx--;
}


int main() {
cout << "Palabra [.]=salir: ";
cin >> pal;
while(pal != ".") {
cinta = "#" + pal + "#";
int estado = 0;
idx = 1;
cout << cinta << endl;
while (estado != 5 and estado != ERR) {


int col = colCar(cinta[idx]);
cout << "col= " << col << endl;
//cout << "estado= " << estado << " idx= " << idx << endl;
if( col >=0 ) {


switch(estado) {
case 0: if( col == 2) cinta[idx] = 'x';
mover('D');
break;
case 1:
    if( col == 2) cinta[idx]= 'x';
    if( col==0 ) mover('I');
    else if( col>0 ) mover('D');
    break;
case 2:
    if (col == 0) mover('I');
    else if(col >0)mover('D');
    break;
case 3:
    if (col == 2) cinta[idx]= 'x';
    if(col >0) mover('D');
    break;

case 4:
    if (col == 0) mover('D');
    else if (col > 0) mover('I');
    break;
    default: break;
}
estado = matran[estado][col];
} else estado = ERR;

}
cout << estado << endl;
if( estado == 5)
cout << pal << " pertenece al Lenguaje" << endl;
else
cout << pal << " NO ESTA en el Lenguaje" << endl;
cout << "Palabra [.]=salir: ";
cin >> pal;
}
return EXIT_SUCCESS;
}


