/*Nombre: Jesica Valdez

Ejercicio:
Enunciado:

*/

#include <iostream>
#include <locale>
using namespace std;



int main ()
{
 setlocale(LC_ALL, "");

    int torneo, equipo, partidosGanados, partidosEmpatados, partidosPerdidos, golesAfavor, golesEnContra, puntosDescontados;
    int const CANT_TORNEOS =5;

    //PUNTO A
    int puntos, puntosMax, equipoCampeon;
    bool band_puntos = 0;

    //PUNTO B
    bool bandPtoB=false;
    int torneosSinSanciones=0;

    //PUNTO C
    int diferenciaGoles=0;

    //PUNTO D
    bool bandPtoD = false;
    int eqMenosEmpates, cantEmpates, torneoMenosEmpates;

    for (int i=0;i<CAN_TORNEOS; i++){


        cout << "Numero de Torneo: ";
        cin >> torneo;
        cout << "Ingresar numero de Equipo: #";
        cin >> equipo;

        while(equipo!=0){

            cout << "Partidos ganados: ";
            cin >> partidosGanados;
            cout << "Partidos empatados: ";
            cin >> partidosEmpatados;
            cout << "Partidos perdidos: ";
            cin >> partidosPerdidos;
            cout << "Goles a favor: ";
            cin >> golesAfavor;
            cout << "Goles en contra: ";
            cin >> golesEnContra;
            cout << "Puntos descontados por sanciones: ";
            cin >> puntosDescontados;
            cout << "------------------------------------" <<endl;

            //PUNTO A
            puntos = (partidosGanados*3 + empatados*1) - puntosDescontados;
            if(!band_puntos){
                puntosMax = puntos;
                equipoCampeon = equipo;
                band_puntos =1;
            }
            else if (puntos > puntosMax){
                puntosMax = puntos;
                equipoCampeon = equipo;
            }

            //PUNTO B
            if(puntosDescontados!=0){
                bandPtoB = true;
            }

            //PUNTO C
            if(equipo==15){
                diferenciaGoles += golesAfavor - golesEnContra;

            }

            //PUNTO D
             if(empatados > 0){
                if(!bandPuntoD){
                    eqMenosEmpates = num_equipo;
                    cantEmpates = empatados;
                    torneoMenosEmpates = num_torn;
                    bandPuntoD = true;
                }
                else{
                    if(empatados < cantEmpates){
                        eqMenosEmpates = num_equipo;
                        cantEmpates = empatados;
                        torneoMenosEmpates = num_torn;
                    }
                }
             }


            cout << "Ingresar numero de Equipo: #";
            cin >> equipo;
        }

        cout << "---PUNTO A---" << endl;
        cout <<"Campeon del torneo " << torneo << " es el equipo " << equipoCampeon << " con " << puntosMax << " puntos" << endl;

        //PUNTO B
        if(!bandPtoB){
            torneosSinSanciones++;
        }



    }
    cout << "---PUNTO B---" << endl;
    cout << "La cantidad de torneos sin equipos sancionados es: " << torneosSinSanciones << endl;
    cout << "---PUNTO C---" << endl;
    cout << "La diferencia de goles del equipo numero 15 es: " << diferenciaDeGoles << endl;
    cout << "---PUNTO D---" << endl;
    cout << "Equipo con menos empates " << eqMenosEmpates << " con " << cantEmpates << " empates, durante el torneo " << torneoMenosEmpates << endl;





return 0;
}
