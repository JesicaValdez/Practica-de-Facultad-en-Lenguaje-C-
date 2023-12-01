/*Nombre: Jesica Valdez

Ejercicio: Editorial Velez Book
*/

#include <iostream>
#include <locale>
#include "herader.h"
using namespace std;

///MAIN

int main()
{
    setlocale(LC_ALL, "");

    int idVenta, idAutor,  idGenero, pagsLibros, idSuc;
    float precio;

    int const AUTOR = 1000;
    int const GENERO = 7;
    int const SUCURSALES = 4;

    //Punto 1
    bool mPtoA[GENERO][SUCURSALES]= {};
    //Punto 2
    int vAutores[AUTOR]= {};
    //Punto 3
    int mPto3[GENERO][2]= {};
    //Punto 4 - se reutiliza el vector del punto 2


    cout <<"Ingresar numero de Venta: ";
    cin >> idVenta;
    while(idVenta!=0)
    {

        cout << "Ingresar autor ID:";
        cin >> idAutor;
        cout << "Ingresar Genero ID: ";
        cin >> idGenero;
        cout << "Ingresar precio $";
        cin >> precio;
        cout << "Ingresar Pagina: ";
        cin >> pagsLibros;
        cout << "Ingresar Sucursal: ";
        cin >> idSuc;
        cout << endl;

        //punto 1
        mPtoA[idGenero-1][idSuc/1000-1]=true;

        //punto 2
        if(pagsLibros>1200)
        {
            vAutores[idAutor-500]++;
        }

        //Punto 3
        mPto3[idGenero-1][0]+=precio;
        mPto3[idGenero-1][1]++;

        //Punto 4
        vAutores[idAutor-500]+=precio;



        cout <<"Ingresar numero de Venta: ";
        cin >> idVenta;

    }
    cout << endl;

    cout << "---Punto A---"<<endl;
    for (int c=0; c<SUCURSALES; c++)
    {
        if((mPtoA[0][c]==0) || (mPtoA[3][c]==0))
        {
            cout << "la sucursal #"<< (c+1)*1000<< " no vendio libros del genero Terror ni Ciencia Ficcion." << endl;
        }
    }
    cout << endl;

    cout << "---Punto 2---" << endl;
    Punto2(vAutores);

    cout << "---Punto 3---" << endl;
    Punto3(mPto3);

    cout << "---Punto 4---"<<endl;
    int mayorRec=0;
    int posMayor;

    for (int i=0; i<AUTOR; i++)
    {
        if(vAutores[i]>mayorRec)
        {
            mayorRec=vAutores[i];
            posMayor= i
        }

    }
    cout << "El autor que mas recaudo es: " << posMayor+500 << endl;



    return 0;
}

*/
///FUNCIONES
//Punto 2 declaracion de la funcion
void Punto2(int vAutores[])
{
    int contador=0;
    for (int i=0; i<1000; i++)
    {
        if(vAutores[i]>0)
        {
            contador++;
        }
    }
    cout << endl;
    cout << "Autores que vendieron al menos 1 libro con mas de 1200 paginas: " << contador << endl;

}

//Punto 3 declaracion de la funcion
void Punto3(int mPto3[][2])
{
    string sGenero[7] = {"Terror", "Biografia", "Novela", "Ciencia ficcion", "Historia", "Ciencia", "Salud"};

    float promedio;

    for(int i=0; i<7; i++)
    {
        if(mPto3[i][1]>0)
        {
            promedio = (float)mPto3[i][0] / mPto3[i][1];
            cout << "Genero: " << sGenero[i] << " Promedio de precio de venta: $" << promedio << endl;
        }
    }

}
