#include <iostream>
#include <clocale>

using namespace std;


int main() {
    setlocale (LC_ALL, "Spanish");

    int num_dia, num_art, gen_musical, min_show, canc_tocadas;

    //PUNTO A
    int mayor_show = -1, mayor_genero;

    //PUNTO B
    int  vec_dias[31]={}, full_dias = 0;

    //PUNTO C
    int vec_cont_temas[31]= {};

    cout << "Numero de dia: ";
    cin >> num_dia;

    while (num_dia != 0){
        cout << "Numero de artista: ";
        cin>> num_art;
        cout << "Genero musical: ";
        cin >> gen_musical;
        cout << "Min show: ";
        cin >> min_show;
        cout << "Canciones tocadas: ";
        cin >> canc_tocadas;
        cout << "--------------------" << endl;


        //PUNTO A

       if (num_dia == 3){
            if (min_show > mayor_show){
                mayor_show = min_show;
                mayor_genero = gen_musical;
            }
       }

       //PUNTO B
       vec_dias[num_art-100] += num_dia;

       //PUNTO C
       vec_cont_temas[num_art-100]+=canc_tocadas;




        cout << "Numero de dia: ";
        cin >> num_dia;
    }

    //PUNTO B
    for (int x = 0; x < 31; x++){
        if (vec_dias[x] == 6){
            full_dias++;
        }
    }


    cout << "PUNTO A:  Genero musical con mas minutos de show: " << mayor_genero << endl;
    cout << "PUNTO B: Cantidad de bandas que tocaron los 3 dias: " << full_dias << endl;
    //PUNTO C
    cout << "Artistas que tocaron mas de tres temas: " << endl;
    for (int x = 0; x < 31; x++){
        if (vec_cont_temas[x] >= 5){
            cout << x+100 << endl;;
        }
    }




    return 0;
}
