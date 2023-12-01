/*Nombre: Jesica Valdez

Ejercicio: Juego Erwin

*/

#include <iostream>
#include <locale>
using namespace std;

//Definicion de funciones:
void punto1(int vSO[6]);
void punto3(int mDatos[][2]);

int main ()
{
    setlocale(LC_ALL, "spanish");

    int numEncuesta, edad, pais, gradoSatisfaccion, idSO, tiempo;

    int const SO=6;
    int const PAIS=66;
    int const GENERACION=4;


//P1.
    int vSO[SO]= {};

//P2.
    int cantEncuestados=0;

//P3.
    int mDatos[PAIS][2]= {};

//P4.
    bool mDatos4[GENERACION][SO]= {};
    string generacionesS[GENERACION] = {"PIXEL", "CONTROL", "AVENTURA", "MAESTRIA"};

    cout <<"ingresa un número de encuesta: ";
    cin >> numEncuesta;

    while(numEncuesta!=0)
    {
        cout << "Edad: ";
        cin >> edad;
        cout << "Pais: ";
        cin >> pais;
        cout << "Grado satisfaccion: ";
        cin >> gradoSatisfaccion;
        cout << "Sistema Operativo: ";
        cin >> idSO;
        cout << "Tiempo de juego total: ";
        cin >> tiempo;
        cout << endl;

        //P1
        if(edad>60)
        {
            vSO[idSO/100-1]++;
        }

        //P2.
        if(tiempo>=60 && tiempo<=180)
        {
            cantEncuestados++;
        }

        //P3.
        mDatos[pais-50][0]+=gradoSatisfaccion;
        mDatos[pais-50][1]++;

        //P4 indentamos el rango de edad en la matriz validando previamente
        if(edad<=5 && edad<=15)
        {
            mDatos4[0][idSO/100-1]=true;
        }
        else if(edad<=16 && edad<=30)
        {
            mDatos4[1][idSO/100-1]=true;
        }
        else if(edad<=31 && edad<=50)
        {
            mDatos4[2][idSO/100-1]=true;
        }
        else
        {
            mDatos4[3][idSO/100-1]=true;
        }


        cout <<"ingresa un número de encuesta: ";
        cin >> numEncuesta;

    }


//P1
    cout << "---PUNTO 1---" <<endl;
    punto1(vSO);

//P2.
    cout << "---PUNTO 2---" <<endl;
    cout << "Cant encuestados: " << cantEncuestados << endl;

//P3.
    cout << "---PUNTO 3---" <<endl;
    punto3(mDatos);

//P4.
    for (int f=0; f<GENERACION; f++)
    {
        if(mDatos4[f][0] && !mDatos4[f][4])
        {
            cout << generacionesS[f] << endl;
        }

    }




    return 0;
}

//Declaracion de funcion
void punto1(int vSO[6])
{

    string nombres[6] = {"DOS", "WINDOWS", "LINUX", "MacOS", "ANDROID", "iOS"};

    for (int i=0; i<6; i++)
    {
        if(vSO[i]>0)
        {
            cout << "el sistema: " << nombres[i] << "no registro jugador mayor de 60años" << endl;
        }
    }


}

//P3.
void punto3(int mDatos[][2])
{
    int contador=0;
    float promedio;

    for (int i=0; i<66; i++)
    {
        if(mDatos[i][1]>0)
        {
            promedio = float mDatos[i][0]/mDatos[i][1];
            if(promedio>3)
            {
                contador++;
            }
        }

    }
    cout << "cantidad de paises con grado de satisfacción promedio sea mayor a 3: " << contador << endl;

}
