/*Nombre: Jesica Valdez

Ejercicio: Secretaria de Medio Ambiente

*/

#include <iostream>
#include <locale>
using namespace std;


//Definicion de funciones
bool EsToxico(int arboles);
void Punto4(int vZona4[21]);

int main ()
{
    setlocale(LC_ALL, "");

//variables
    int arbol, tipo, numZona, estado;
    float altura;

//Constantes
    int const TIPO_ARBOL = 10;
    int const ZONA = 21;
    int const ESTADO = 5;

//P1
    int vEstadoO[ZONA] = {};
    int vEstadoP[ZONA] = {};

//P2
    int vZona[ZONA] = {};

//P3
    bool mPunto3[TIPO_ARBOL][ZONA] = {};
    string nombreA[10]=
    {
        "Arce de Azúcar",
        "Pino",
        "Roble",
        "Abedul",
        "Almendro",
        "Nogal",
        "Cerezo",
        "Manzano",
        "Eucalipto",
        "Árbol del Caqui"
    };

//P4
    int vZona4[ZONA] = {};



    cout << "Ingrese ARBOL : ";
    cin >> arbol;

    while(arbol!=0)
    {

        cout << "altura: ";
        cin >> altura;
        cout << "tipo arbol: ";
        cin >> tipo;
        cout << "Num zona: ";
        cin >> numZona;
        cout << "Estado Arbol: ";
        cin >> estado;
        cout << endl;

        //P1
        if(numZona == 1)
        {
            vEstadoP[numZona-100]++;
        }
        else if (numZona == 5)
        {
            vEstadoO[numZona-100]++;
        }

        //P2
        if(altura > 2.5 && EsToxico(arbol))
        {
            vZona[numZona-100]++;
        }

        //P3
        mPunto3[tipo-11][numZona-100]=true;

        //P4
        if(!EsToxico(arbol))
        {
            vZona4[numZona-5]++;
        }


        cout << "Ingrese ARBOL : ";
        cin >> arbol;

//recorro
        cout << "------1-------" << endl;
        for (int i=0; i<ZONA; i++)
        {
            if(vEstadoO[i]>vEstadoP[i])
            {
                cout << i+100 << endl;
            }
        }

        cout << "------2-------" << endl;
        for (int i=0; i<ZONA; i++)
        {
            cout << "Zona: " << i+100 << "Cantidad: " << vZona[i] << endl;
        }

        cout << "------3-------" << endl;
        for (int f=0; f<TIPO_ARBOL; f++)
        {
            cout << "Tipo: " << nombreA[f] << endl;
            for (int c=0; c<ZONA; c++)
            {
                if(mPunto3[f][c]==true)
                {
                    cout << "Zona: " << c+100 << endl;
                }
            }
        }

        cout << "------4-------" << endl;
        Punto4(vZona4);


        return 0;
    }


///Declaracion Funciones
    bool EsToxico(int arboles)
    {
        if(arboles == 12 || arboles == 15 || arboles == 17 || arboles == 18 || arboles == 19)
        {
            return 1;
        }
        else
        {
            return 0;
        }

    }

    void Punto4(int vZona4[21])
    {
        int cont = 0;

        for (int i=0; i<21; i++)
        {
            if(vZona4[i]>0)
            {
                cont ++;
            }
        }
        cout << "Cantidad de zonas: " << cont << endl;
    }
