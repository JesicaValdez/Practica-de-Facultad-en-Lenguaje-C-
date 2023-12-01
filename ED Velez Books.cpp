/*Nombre: Jesica Valdez

Ejercicio:
Enunciado:

*/

#include <iostream>
#include <locale>
using namespace std;


//Definicion de funciones
void Punto2 (int mPunto2[][7]);
void Punto3(int vPunto3[7]);

int main ()
{
    setlocale(LC_ALL, "");

//variables
    int pedidoID, tortaID, dias, clienteID, medioContacto;
    float peso;

//Constantes
    int const  TORTA = 7;
    int const CLIENTE = 600;
    int const CONTACTO =4;

//P1
    int vClientes[CLIENTE]= {};

//P2
    int mPunto2[CLIENTE][TORTA] = {};

//P3
    int vPunto3[TORTA] = {};

//P4
    bool vPunto4P[CLIENTE] = {};
    bool vPunto4W[CLIENTE] = {};


    cout << "Ingrese ID de Pedido: ";
    cin >> pedidoID;

    while(pedidoID>0)
    {

        cout << "ID de Torta (entero entre 1 y 7): ";
        cin >> tortaID;
        cout << "Peso: ";
        cin >> peso;
        cout << "Días de anticipación del pedido: ";
        cin >> dias;
        cout << "ID de Cliente: ";
        cin >> clienteID;
        cout << "ID de Medio de Contacto: ";
        cin >> medioContacto;
        cout << endl;

        //P1
        if(dias>90)
        {
            vClientes[clienteID-800]++;
        }

        //P2
        mPunto2[clienteID-800][tortaID-1]++;

        //P3
        if(peso > vPunto3[tortaID-1])
        {
            vPunto3[tortaID-1]=peso;
        }

        //P4
        if(medioContacto == 1000)
        {
            vPunto4P[clienteID-800]=true;
        }
        else if(medioContacto == 3000)
        {
            vPunto4P[clienteID-800]=true;
        }


        cout << "Ingrese ID de Pedido: ";
        cin >> pedidoID;
    }
    cout << endl;

//recorro
    cout << "---Punto 1---" << endl;
    int cont=0;
    for (int i=0; i<CLIENTE; i++)
    {

        if(vClientes[i]>0)
        {
            cont++;
        }
    }
    cout <<"Cantidad de clientes: " << cont << endl;

    cout << "---Punto 2---" << endl;
    Punto2(mPunto2);

    cout << "---Punto 3---" << endl;
    Punto3(vPunto3);

    cout << "---Punto 4---" << endl;
    for (int i=0; i<CLIENTE; i++)
    {
        if(vPunto4P[i]==0 && vPunto4W[i]==0)
        {
            cout << "ID Cliente: " << i+800 << endl;
        }
    }

    return 0;
}


///Declaracion Funciones
void Punto2 (int mPunto2[][7])
{

    for (int f=0; f<600; f++)
    {
        for (int c=0; c<7; c++)
        {
            if(mPunto2[f][c]>1)
            {
                cout << "Id Cliente: " << f+800 << endl;
            }
        }
    }
}

void Punto3(int vPunto3[7])
{
    string nombre[7]= {"Rogel", "Selva negra", "Cheesecake", "Chocotorta", "Lemon pie", "Balcarce", "Chajá"};

    for (int i=0; i<7; i++)
    {
        cout << nombre[i] << " el peso registrado fue: " << vPunto3[i] << endl;
    }
}

