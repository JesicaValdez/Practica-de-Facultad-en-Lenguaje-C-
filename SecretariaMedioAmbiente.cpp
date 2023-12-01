/*Nombre: Jesica Valdez

Ejercicio:

*/

#include <iostream>
#include <locale>
using namespace std;


//Definicion de funciones
bool EsToxico(int arbol);
void Punto4(vZonaP4[21]);

int main ()
{
 setlocale(LC_ALL, "");

 //variables
 int arbol, tipoArbol, zona, estado;
 float altura;

 //Constantes
 int const TIPO = 10;
 int const ZONA = 21;
 int const ESTADO = 5 ;

 //P1
 int vOptimo[ZONA] = {};
 int vPeligroso[ZONA] = {};

 //P2
 int vZONA[ZONA]={};

 //P3
bool mPunto3[TIPO][ZONA] = {};
string nombreA [10] = {"Arce de Azúcar ", "Pino", "Roble", "Abedul", "Almendro", "Nogal", "Cerezo", "Manzano", "Eucalipto", " Arbol del Caqui" };

//P4
int vZonaP4[ZONA] = {};


 cout << "Ingrese #Arbol: ";
 cin >> arbol;

 while(arbol!=0){

    cout << "Altura: ";
    cin >> altura;
    cout << "tipo arbol: ";
    cin >> tipoArbol;
    cout << "Numero de Zona";
    cin >> zona;
    cout << "estado del arbol : ";
    cin >> estado;
    cout << endl;

    //P1
    if(estado==5){
        vOptimo[zona-100]++;
    }else if(estado==1){
        vPeligroso[zona-100]++;
    }

    //P2
    if(altura>2.5 && EsToxico(tipoArbol)){
        vZONA[zona-100]++;
    }
    //P3
    mPunto3[tipoArbol-11][zona-100]=true;

    //P4
    if(!EsToxico(tipoArbol)){
        vZonaP4[zona-100]++;
    }

    cout << "Ingrese #Arbol: ";
    cin >> arbol;

 }

 //recorro
 cout << "---Punto 1---" << endl;
 for (int i=0; i<ZONA; i++){
    if(vOptimo[i]>vPeligroso[i]){
        cout << "Zona: " << i+100 << endl;
    }
 }

 cout << "---Punto 2---" << endl;
for (int i=0;i<ZONA; i++){
    if(vZONA[i]>0){
        cout << "Zona con Arboles altos y toxicos: " << i+100 << endl;
    }
}

cout << "---Punto 3---" << endl;
for (int f=0; f<TIPO; f++){
      cout << nombreA[f] << endl;
    for (int c=0; c<ZONA; c++){
          cout << "ZONA: " << c+100 << endl;
    }
}

cout << "---Punto 4---" << endl;
Punto4(vZonaP4);

return 0;
}


///Declaracion Funciones
bool EsToxico(int arbol){
    if(arbol==12 || arbol==15 || arbol==17 || arbol ==18 || arbol==19 ){
        return 1;
    }
    else {
        return 0;
    }

}

void Punto4(vZonaP4[21]){
    int cont = 0;

    for (int i=0; i<ZONA; i++){
        if(vZonaP4[i]>0){
            cont++;
        }
    }
    cout << "Cantidad de Zonas: " << cont << endl;
}

