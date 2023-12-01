/*Nombre: Jesica Valdez

Ejercicio: Biblioteca con menu
Enunciado:

*/

#include <iostream>
#include <locale>
using namespace std;


//Definicion de funciones
void cargar(int mPuntoA[][5000], int vSocios[501], int mPuntoC[][2], bool vSociosD[501]);
void PuntoA(int mPuntoA[][5000]);
void PuntoB(int vSocios[501]);
void PuntoC(int mPuntoC[][2]);
void PuntoD(bool vSociosD[501]);

int main (){
 setlocale(LC_ALL, "");

 //Constantes
 int const LIBRO = 5000 ;
 int const DIA = 30;
 int const CATEGORIA = 11;
 int const SOCIO = 501;

int mPuntoA[DIA][LIBRO] = {};
int vSocios[SOCIO] = {};
int mPuntoC[CATEGORIA][2] = {};
bool vSociosD[SOCIO] = {};

    int op;
    do{
        cout << endl << endl;
        cout << "----Menu Principal----" << endl;
        cout << "----------------------" << endl;
        cout << endl;
        cout << "1) CARGAR INFORMACION " << endl;
        cout << "2) Punto A " << endl;
        cout << "3) Punto B " << endl;
        cout << "4) Punto C " << endl;
        cout << "5) Punto D " << endl;
        cout << "--------------------------" << endl;
        cout << "0) SALIR" << endl;
        cin >> op;
        system("cls");


        switch(op){
            case 1: cargar(mPuntoA, vSocios, mPuntoC, vSociosD);
            break;
            case 2: PuntoA(mPuntoA);
            break;
            case 3: PuntoB(vSocios);
            break;
            case 4: PuntoC(mPuntoC);
            break;
            case 5: PuntoD(vSociosD);
            break;
            case 0:
            break;

        }


    }
        while (op!=0);


 //recorro



return 0;
}


///Declaracion Funciones
void cargar(int mPuntoA[][5000], int vSocios[501], int mPuntoC[][2], bool vSociosD[501]){

 //variables
 int libro, dia, cat, socio, duracionPrestamo;

 cout << "Ingrese LIBRO: ";
 cin >> libro;

 while(libro!=0){

    cout << "dia: ";
    cin >> dia;
    cout << "categoria: ";
    cin >> cat;
    cout << "num socio: ";
    cin >> socio;
    cout << "duracion: ";
    cin >> duracionPrestamo;
    cout << endl;

    //P2
    mPuntoA[dia-1][libro-1]++;

    //P3
    if(duracionPrestamo>7){
        vSocios[socio-1000]++;
    }
    //P4
    mPuntoC[cat-1000][0]+=duracionPrestamo;
    mPuntoC[cat-1000][1]++;

    //P5
    vSociosD[socio-1000]=true;


    cout << "Ingrese LIBRO: ";
    cin >> libro;
 }
    system("cls");


}



void PuntoA(int mPuntoA[][5000]){
//recorro matriz
    int cont=0;
    for (int f=0; f<30; f++){

        for (int c=0; c<5000; c++){
            if(mPuntoA[f][c]>0){
                cont++;
            }
        }
    }
    cout << "Cantidad Prestamos realizados :" << cont << endl << endl;

}

void PuntoB(int vSocios[501]){
//recorro vector
    for (int i=0; i<501; i++){
            if(vSocios[i]>0){
            cout << "Socio: " << i+1000 << endl;
            }
    }

}

void PuntoC(int mPuntoC[11][2]){
    float promedio;
    for (int i=0; i<11; i++){
        if(mPuntoC[i][1]>0){
            promedio =  (float)mPuntoC[i][0] / mPuntoC[i][1];
            cout << "Categoria: " << i+1000 << " duracion promedio: " << promedio << endl;
        }
    }
}

void PuntoD(bool vSociosD[501]){
    int cont=0;
    for (int i=0; i<501; i++){
        if(!vSociosD[i]){
            cont++;
        }
    }
    cout << "D) Cantidad Socios:" << cont << endl;

}
