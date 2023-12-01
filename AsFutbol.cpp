#include <iostream>
#include <clocale>

using namespace std;

/*
La Asociaci�n de F�tbol de General Pacheco dispone de la informaci�n de los equipos que
participaron en los �ltimos 5 torneos realizados. Por cada equipo se registr�:
- N�mero de torneo (N�mero entero)
- N�mero de equipo (N�mero entero)
- Partidos ganados (N�mero entero)
- Partidos empatados (N�mero entero)
- Partidos perdidos (N�mero entero)
- Goles a favor (N�mero entero)
- Goles en contra (N�mero entero)
- Puntos descontados por sanciones (N�mero entero)
La informaci�n se encuentra agrupada por n�mero de torneo. Para indicar la finalizaci�n de
carga de datos de un torneo se ingresa un n�mero de equipo igual a cero.
Se pide calcular e informar:
A) Por cada torneo, el equipo campe�n del certamen. Indicando el n�mero de equipo y
los puntos obtenidos. (30 puntos)
B) La cantidad de torneos que no hayan tenido equipos a los que se les descont�
puntos por sanciones. (30 puntos)
C) La diferencia de goles del equipo nro 15. (20 puntos)
D) El equipo que menos partidos haya empatado en un torneo pero que al menos haya
empatado alguno. Indicar el n�mero de equipo, la cantidad de partidos empatados y
el n�mero de torneo. (20 puntos)
Aclaraciones:
- S�lo habr� un equipo con la mayor cantidad de puntos en cada torneo. Se otorgan 3
puntos por partido ganado y 1 punto por partido empatado. Se deben descontar los
puntos debido a sanciones.
- Habr� s�lo un equipo con la menor cantidad de empates en un torneo.
*/

int main (){

    setlocale (LC_ALL,"Spanish");

    int num_torneo, num_equipo, ganados, empatados, perdidos, goles_favor, goles_contra, punt_descontados, x ;

    //Punto A
    int puntos , max_puntos, max_equipo;
    bool band_puntos = 0;

    //Punto B
    int acu_puntos_descontados, torn_sin_desc = 0;

    //Punto C
    float dif_goles;

    //Punto D
    int menos_empatado, equipo_menos_emp, cant_emp;
    bool prim_men_emp = 0;
    for ( x = 0; x < 5; x++){

        cout << "Numero de torneo: ";
        cin >> num_torneo;
        cout << "Numero de equipo: ";
        cin >> num_equipo;

        //Punto A
        puntos = 0;
        band_puntos = 0;
        //Punto B
        acu_puntos_descontados = 0;

        //Punto D
        menos_empatado = 0;
        equipo_menos_emp = 0;
        cant_emp = 0;
        prim_men_emp = 0;

        while (num_equipo != 0){

            cout << "Partidos ganados: " ;
            cin >> ganados;
            cout << "Partidos empatados: " ;
            cin >> empatados;
            cout << "Partidos Perdidos: " ;
            cin >> perdidos;
            cout << "Goles a favor: " ;
            cin >> goles_favor;
            cout << "Goles en contra: " ;
            cin >> goles_contra;
            cout << "Puntos descontados: " ;
            cin >> punt_descontados;
            cout << endl;


            //Punto A
            puntos = ganados * 3 + empatados * 1 - punt_descontados;

            if (band_puntos == 0){
                max_puntos = puntos;
                max_equipo = num_equipo;
                band_puntos = 1;
            }
            else {
                if (puntos > max_puntos){
                    max_puntos = puntos;
                    max_equipo = num_equipo;
                }
            }

            //Punto B
            acu_puntos_descontados += punt_descontados;

            //Punto C
            if (num_equipo == 15){
                dif_goles = goles_favor - goles_contra;
            }

            //Punto D

            if (empatados > 0 ){
                if (prim_men_emp == 0){
                    menos_empatado = empatados;
                    equipo_menos_emp = num_equipo;
                    cant_emp = empatados;
                    prim_men_emp = 1;
                }
                else {
                    if (empatados < menos_empatado){
                        menos_empatado = empatados;
                        equipo_menos_emp = num_equipo;
                        cant_emp = empatados;
                    }
                }
            }

            cout << "Numero de equipo: ";
            cin >> num_equipo;


        }

        //Punto A
        cout << "Campeon del torneo: " << num_torneo << " Equipo n�: " << max_equipo << " Puntos: " << max_puntos << endl;

        //Punto B
        if (acu_puntos_descontados == 0){
            torn_sin_desc++;
        }

        //Punto D
        cout << "Torneo: " << num_torneo << " equipo con menos empates mayores a cero: " << equipo_menos_emp << " cantidad de empates: " << cant_emp << endl;


    }

        //Punto B
        cout << "Total de torneos sin puntos descontados: " << torn_sin_desc << endl;

        //Punto C
        cout << "La diferencia de goles del equipo 15 es: " << dif_goles << endl;




    return 0;

}
