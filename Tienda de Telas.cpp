/*Nombre: Jesica Valdez

Ejercicio:  Tienda de Telas

*/

#include <iostream>
#include <locale>
using namespace std;


//Definicion de funciones
void (int []);

int main ()
{
 setlocale(LC_ALL, "");

 //variables
 int suc, dia, numColor;
 float mtrsVend, imp;

 //Constantes
 int const SUC= 10;
 int const DIA= 30;
 int const N_TELA= 10;

 //P1
float vColores[N_TELA]={};
string nombres[10]={
"Celeste",
"Blanco",
"Rojo",
"Amarillo",
"Negro",
"Azul",
"Francia",
"Gris",
"Naranja",
"Rosa",
"Aguamarina"
};

 //P2
 float vSuc[SUC]={};

 //P3
bool mPunto3[SUC][N_TELA]={};


 cout << "Ingrese Sucursal: ";
 cin >> suc;

 while(suc!=0){

    cout << "Dia de la venta: ";
    cin >> dia;
    cout << "Num color de la tela: ";
    cin >> numColor;
    cout << "Metros Vendidos: ";
    cin >> mtrsVend;
    cout << "Importe: $";
    cin >> imp;
    cout << endl;

    //P1
        vColores[numColor-11]+=mtrsVend;

    //P2
    if(numColor==13){
        vSuc[suc-1]+=imp;
    }

    //P3
    mPunto3[suc-1][numColor-11]=true;


    cout << "Ingrese Sucursal: ";
    cin >> suc;
 }

 //recorro
 cout << "----Punto 1----" << endl;
 for (int i=0; i<N_TELA; i++){
    if(vColores[i]>1000){
        cout << nombres[i] << endl;
    }
 }

 cout << "----Punto 2----" << endl;
 int maxRec=0;
 int pos;
 for (int i=0; i<SUC; i++){

    if(vSuc[i]>maxRec){
        maxRec=vSuc[i];
        pos=i;
    }
 }
    cout << "Suc con mayor recaudacion: " << pos+1 endl;

cout << "----Punto 3----" << endl;
int cont=0;
for (int f=0; f<SUC; f++){

    if(mPunto3[f][0] && mPunto3[f][1] && !mPunto3[f][5]){
        cont++;
    }

}
cout << "Cant suc: " << cont << endl;


return 0;
}


///Declaracion Funciones

