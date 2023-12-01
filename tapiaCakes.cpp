/*Nombre: Jesica Valdez

Ejercicio: Tapia Cakes

*/

#include <iostream>
#include <locale>
using namespace std;


//declaracion de la funcion:
void Puntoo2 (int mPuntoB[][7]);
void Puntoo3 (int vTorta[7]);

int main ()
{
    setlocale(LC_ALL, "spanish");

    int pedido, torta, diasAnticipados, cliente, medioContacto;
    float peso;

//constantes
    int const CLIENTE = 600;
    int const TORTA = 7;
    int const MEDIO_CONTACTO = 4;

//A.
    int contadorA;
    int vClientes[CLIENTE]= {};

//B.
    int mPuntoB[CLIENTE][TORTA]= {};

//C.
    int vTorta[7]= {};

//D.
    bool mPunto3[CLIENTE][MEDIO_CONTACTO]= {};


    cout << "Ingrese numero de pedido: ";
    cin >> pedido;

    while(pedio<=0)
    {

        cout << "Torta: ";
        cin << torta;
        cout <<"Peso: ";
        cin >> peso;
        cout << "Dias de anticipacion: ";
        cin >> diasAnticipados;
        cout << "ID cliente: ";
        cin >> cliente;
        cout << "Medio de contacto: ";
        cin >> medioContacto;
        cout << endl;

        //A.
        if(diasAnticipados>90)
        {
            vClientes[cliente-800]++;
        }

        //B.
        mPuntoB[cliente-800][torta-1]++;

        //C.
        vTorta[torta-1]+=peso;

        //D.
        mPunto3[cliente-800][medioContacto/1000-1]=true;




        cout << "Ingrese numero de pedido: ";
        cin >> pedido;

    }

//A.
    contadorA=0;
    for (int i=0; i<CLIENTE; i++)
    {

        if(vClientes[i]>0)
        {
            contadorA++;
        }
    };
    cout << "Cantidad de clientes que realizaron pedidos con mas de 90 dias: "<< contadorA << endl;

//B.
    cout << "---PUNTO 2---" << endl;
    Puntoo2(mPuntoB);

//C.
    Puntoo3(vTorta);

//D
    for(f=0; f<CLIENTE; f++)
    {
        if(!mPunto3[f][0] && !mPunto3[f][3])
        {
            cout << "El Cliente "<< f+800 <<  "no pidio tortas en persona ni por WhatsApp." << endl;
        }

    }



    return 0;
}

//PUNTO 2
void Puntoo2 (int mPuntoB[][7])
{
    for(f=0; f=CLIENTE; f++)
    {
        for(c=0; c=TORTA; C++)
        {
            if(mPuntoB[f][c]>1)
            {
                cout << "Clientes que pidieron mas de una vez la misma torta: " << 800+1 << endl;
            }
        }
    }

}


//PUNTO 3
void Puntoo3 (int vTorta[7])
{
    string nombreTorta[7]= {"Rogel", "Selva", "Selva Negra", "Cheescake", "Chocotorta", "Lemon Pie", "Balcarce", "Chaja"};
    int pesoMaximo=0;


    for(int i=0; i<TORTA; i++)
    {
        if(vTorta[i]>pesoMaximo)
        {
            pesoMaximo=vTorta[i];
        }
        cout << "Para la torta: " << nombreTorta[i] << " el peso maximo registrado fue: " << pesoMaximo << endl;
    }

}
