#include <iostream>
 #include <cstdlib>
 using namespace std;
 const int ERR= -1;
 string pal, cinta;
 int idx;
 const int matran[7][5] = {
 /*q0*/{ERR, 5, 1, ERR, ERR},
 /*q1*/{ERR, 1, 1, 2, ERR},
 /*q2*/{4, ERR, ERR, 2, 2 },
 /*q3*/{ERR, ERR, ERR, ERR, 4 },
 /*q4*/{0, 4, 4, 4, 4 },
 /*q5*/{6, 5, ERR, ERR, ERR},
 /*q6*/{ERR, ERR, ERR, ERR, ERR}
 };

 int colCar(char c) {
 if(c == '#') return 0;
 if(c == 'x') return 1;
 if(c == 'a') return 2;
 if(c == 'b') return 3;
 if(c == 'c') return 4;
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
 while (estado != 6 and estado != ERR) {
 int col = colCar(cinta[idx]);
 cout << "col= " << col << endl;
 cout << "estado= " << estado << " idx= " << idx << endl;
 if( col >=0 ) {
 switch(estado) {
 case 0: if( col == 2) cinta[idx] = '#';
 if( col == 0 or col == 2) mover('D');
 break;
 case 1: if( col == 3) cinta[idx]= 'x';
 if( col > 0 and col < 4) mover('D');
 break;
 case 2: if (col == 0) mover('I');
 else if (col > 2) mover('D');
 break;
 case 3: if( col == 4) {
 cinta[idx] = '#';
 mover('I');
 }
 break;
 case 4: if( col == 0 ) mover('D');
 else if( col > 0) mover('I');
 break;
 case 5: if(col == 1) cinta[idx] = '#';
 if( col == 0) mover('I');
 else if( col == 1) mover('D');
 break;
 default: break;
 }
 estado = matran[estado][col];
 } else estado = ERR;

 }
 cout << estado << endl;
 if( estado == 6)
 cout << pal << " pertenece al Lenguaje" << endl;
 else
 cout << pal << " NO ESTA en el Lenguaje" << endl;
 cout << "Palabra [.]=salir: ";
 cin >> pal;
 }
 return EXIT_SUCCESS;
 }
