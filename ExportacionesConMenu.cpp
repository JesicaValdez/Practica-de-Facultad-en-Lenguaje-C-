/*Nombre: Jesica Valdez

Ejercicio: Exportaciones con Menu
*/

#include <iostream>
#include <locale>
using namespace std;


//Definicion de funciones
void registrar(int vAnio[5], int vPais[10], int vProducto[8]);
void ReporteA(int vAnio[5]);
void ReporteB(int vPais[10]);
void ReporteC(int vProducto[8]);
void Creditos();

int main ()
{
 setlocale(LC_ALL, "");

 //constantes
 int const ANIO = 5;
 int const PAIS = 10;
 int const PRODUCTO = 8;

 int vAnio[ANIO] = {};
 int vPais[PAIS] = {};
 int vProducto[PRODUCTO] = {};

 int op;
    do{
        cout << endl << endl;
        cout << "----Menu Principal----" << endl;
        cout << "----------------------" << endl;
        cout << endl;
        cout << "1) Registrar Informacion " << endl;
        cout << "2) Reporte A " << endl;
        cout << "3) Reporte B " << endl;
        cout << "4) Reporte C " << endl;
        cout << "5) Creditos " << endl;
        cout << "--------------------------" << endl;
        cout << "0) SALIR" << endl;
        cin >> op;
        system("cls");


        switch(op){
            case 1: registrar(vAnio, vPais, vProducto);
            break;
            case 2: ReporteA(vAnio);
            break;
            case 3: ReporteB(vPais);
            break;
            case 4: ReporteC(vProducto);
            break;
            case 5: Creditos();
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
void registrar(int vAnio[5], int vPais[10], int vProducto[8]){

    int anio, pais, producto, toneladas;
    float importe;


    cout << "Ingrese año: ";
    cin >> anio;

 while(anio!=0){

    cout << "pais: ";
    cin >> pais;
    cout << "producto: ";
    cin >> producto;
    cout << "toneladas: ";
    cin >> toneladas;
    cout << "importe en millones: ";
    cin >> importe;
    cout << endl;

    //Reporte A
    vAnio[anio-2016]++;

    //Reporte B
    vPais[pais-101]+=toneladas;

    //Reporte C
    vProducto[producto-1]+=importe;

    //P5



    cout << "Ingrese año: ";
    cin >> anio;
 }
    system("cls");



}

void ReporteA(int vAnio[5]){
    cout << "Exportaciones realizadas: " << endl;
for (int i=0; i<5; i++){
    cout << "Año: " << i+2016 << " Exportaciones: " << vAnio[i] << endl;
}

}

void ReporteB(int vPais[10]){
    int mayor = 0;
    int pos;
    for (int i=0; i<10; i++){
        if(vPais[i]>mayor){
            mayor = vPais[i];
            pos = i;
        }
    }
    cout << "B) Cod Pais con mas importacion: " << pos+101 << endl;
}

void ReporteC(int vProducto[8]){

    string nombre[8]={
    "Soja",
    "Trigo",
    "Maiz",
    "Limon",
    "Naranja",
    "Manzana",
    "Carne Vacuna",
    "Mariscos"
    };

    for (int i=0; i<8; i++){
        cout << nombre[i] << " total exportado: " << vProducto[i] << endl;
    }

}

void Creditos(){

    cout << "---Equipo Resilente---" << endl;
    cout << "Yamil Diaz" << endl;
    cout << "Jesica Valdez" << endl;
}
