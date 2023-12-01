/*Nombre: Jesica Valdez

Ejercicio: Infracciones de Transito

*/

#include <iostream>
#include <locale>
using namespace std;


//Definicion de funciones
void ObtenerTipoHorario(int horario);
void PUNTO2(int vAgente[300]);

int main ()
{
    setlocale(LC_ALL, "");

//variables
    int numInfraccion, codAgente, dia, mes, hora, tipoInf, distrito;
    float importe;

//Constantes
    int const COD_AG = 300;
    int const TIPO_INF = 10;
    int const DISTRITO = 111;
    int const MES = 12;
    string nombresInf[TIPO_INF] =
    {
        "Exceso de velocidad",
        "Conducir bajo la influencia de alcohol o drogas",
        "Conducir mientras programa en C++",
        "Hablar o enviar mensajes de texto mientras se conduce",
        "no usar el cinturón de seguridad",
        "No respetar los semáforos",
        "Conducir sin licencia";
        "Estacionarse en lugares prohibidos"
        ,
        "Conducir conectado a Zoom",
        "Conducir sin luces encendidas"
    };

//P1
    int vTipoD[TIPO_INF] = {};
    int vTipoN[TIPO_INF] = {};

//P2
    int vAgente[COD_AG] = {};

//P3
    int vDistrito[DISTRITO] = {};

//P4
    int mPunto4[MES][TIPO_INF] = {};



    cout << "Ingrese Número de infracción: ";
    cin >> numInfraccion;

    while(numInfraccion!=0)
    {

        cout << " Código de Agente : ";
        cin >> codAgente;
        cout << "dia: ";
        cin >> dia;
        cout << "mes";
        cin >> mes;
        cout << "hora: ";
        cin >> hora;
        cout << "tipo inf: ";
        cin >> tipoInf;
        cout << "distrito: ";
        cout << distrito;
        cout << "Importe: ";
        cin >> importe;
        cout << endl;

        //P1
        if(ObtenerTipoHorario(hora))
        {
            vTipoD[tipoInf-10]++;
        }
        else
        {
            vTipoN[tipoInf-10]++;
        }

        //P2
        vAgente[codAgente-1]++;

        //P3
        if(mes >=1 && mes <=3)
        {
            vDistrito[distrito-500]+=importe;
        }

        //P4
        mPunto4[mes-1][tipoInf-10]++;

        cout << "Ingrese Número de infracción: ";
        cin >> numInfraccion;
    }

//recorro
    cout << "----1-----" << endl;
    for (int i=0; i<TIPO_INF; i++)
    {
        if(vTipoN[i]>vTipoD[i])
        {
            cout << "Tipo Infraccion: " << nombresInf[i] << endl;
        }
    }

    cout << "----2-----" << endl;
    PUNTO2(vAgente);

    cout << "----3-----" << endl;
    cout << "Distrito: "
         for (int i=0; i<DISTRITO; i++)
    {
        if(vDistrito[i] < 1000000)
        {
            cout << i+500 << endl;
        }
    }

    cout << "----4-----" << endl;
    for (int f=0; f<MES; f++)
    {
        cout << "Mes #" << f+1 << endl;
        for (int c=0; c<TIPO_INF; c++)
        {
            if(mPunto4[f][c]>0)
            {
                cout << nombresInf[c] << "Cantidad: " << mPunto4[f][c] << endl;
            }
        }
    }


    return 0;
}


///Declaracion Funciones
void ObtenerTipoHorario(int horario)
{
    if(horario >=6 && horario <=18)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

void PUNTO2(int vAgente[300])
{
    for (int i=0; i<300; i++)
    {
        if(vAgente[i]>0)
        {
            cout << "Cod: " << i+1 << endl;
        }
    }

}
