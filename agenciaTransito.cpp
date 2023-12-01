/*Nombre: Jesica Valdez

Ejercicio:
Enunciado:

*/

#include <iostream>
#include <locale>
using namespace std;


//Definicion de funciones
bool ObtenerTipoHorario(int hora);
void Punto2(int vAgentes[300]);

int main ()
{
 setlocale(LC_ALL, "");

 //variables
 int numInfraccion, codAgente, dia, mes, hora, tipoInfraccion, distrito;
 float importe;

 //Constantes
 int const AGENTE = 300;
 int const TIPO_INFRACCION = 10;
 int const DISTRITO = 111;
 int const MES = 12;

 //P1
 int vTipoDiurno[TIPO_INFRACCION] = {};
 int vTipoNocturno[TIPO_INFRACCION] = {};
 string sNombresInfracciones [10] = {"Exceso de Velocidad", "Conducir bajo la influencia de alcohol o drogas", "Conducir mientras programa en C++", "Hablar o enviar mensajes de texto mientras se conduce",
"No usar el cinturón de seguridad", "No respetar los semáforos", "Conducir sin licencia", "Estacionarse en lugares prohibidos", "Conducir conectado a Zoom", "Conducir sin luces encendidas"};

 //P2
int vAgentes[AGENTE]={};

 //P3
int vDistrito[DISTRITO]={};

 //P4
 int mPunto4[MES][TIPO_INFRACCION] = {};



 cout << "Ingrese Número de infracción: ";
 cin >> numInfraccion;

 while(numInfraccion!=0){

    cout << "Código de Agente: ";
    cin >> codAgente;
    cout << "Día: ";
    cin >> dia;
    cout << "Mes: ";
    cin >> mes;
    cout << "Hora: ";
    cin >> hora;
    cout << "Tipo de infracción: ";
    cin >> tipoInfraccion;
    cout << "Distrito: ";
    cin >> distrito;
    cout << "Importe de la infraccion: ";
    cin >> importe;
    cout << endl;

    //P1
    if(ObtenerTipoHorario(hora)){
        vTipoDiurno[tipoInfraccion-10]++;
    }else{
        vTipoNocturno[tipoInfraccion-10]++;
    }

    //P2
    vAgentes[codAgente-1]++;

    //P3
    if(mes >=1 && mes <=3){
    vDistrito[distrito-500]+=importe;
    }

    //P4
    mPunto4[mes-1][tipoInfraccion-10]++;

    cout << "Ingrese Número de infracción: ";
    cin >> numInfraccion;
 }

 //recorro
 cout << "---PUNTO 1---"<< endl;
 for (int i=0; i<TIPO_INFRACCION; i++){
    if(vTipoNocturno[i]>vTipoDiurno[i]){
        cout << sNombresInfracciones[i] << endl;
    }
 }

cout << "---PUNTO 2---"<< endl;
Punto2(vAgentes);

cout << "---PUNTO 3---" << endl;
for (int i=0; i<DISTRITO; i++){
    if(vDistrito[i]<1000000){
        cout <<"DISTRITO: "<< i+500 <<endl;
    }
}

cout << "---PUNTO 4---" << endl;
for (int f=0; f<MES; f++){
        cout <<"MES # " <<f+1 <<":"<< endl;
    for (int c=0; c<TIPO_INFRACCION; c++){
            if(mPunto4[f][c]>0){
                cout << sNombresInfracciones[c] << endl << " cantidad: " << mPunto4[f][c] << endl;
            }

        }

    }



return 0;
}


///Declaracion Funciones
bool ObtenerTipoHorario(int hora){

    if(hora >= 06 && hora <= 18){
        return 1;
    }else{
        return 0;
    }

}

void Punto2(int vAgentes[300]){
    for (int i=0; i<300; i++){
        if(vAgentes[i]>0){
            cout << "Codigo de Agente: " << i+1<< endl;
        }
    }
}
