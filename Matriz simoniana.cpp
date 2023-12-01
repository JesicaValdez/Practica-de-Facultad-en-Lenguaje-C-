#include <iostream>
#include <clocale>
using namespace std;

///DECLARACION DE FUNCION

bool EsMatrizSimoniana(int mat[5][5]);


int main (){
    setlocale (LC_ALL,"Spanish");

    int matriz[5][5] = {6,2,3,4,7,5,4,1,10,11,1,1,1,1,1,9,8,4,2,-5,10,10,10,10,10};

    cout << EsMatrizSimoniana(matriz);


    return 0;
}



///DEFINICION DE LA FUNCION
bool EsMatrizSimoniana(int mat[5][5]){
    int vec_suma[5] = {}, acu;
    bool band_simon = 0;

    for (int x = 0; x < 5; x++){
        acu = 0;
        for (int j = 0; j < 5; j++){
            acu += mat[x][j];
        }
        vec_suma[x] = acu;
    }

    for (int m = 0; m < 5; m++){
        for (int x = 0; x < 5; x++){
            for (int j = 0; j < 5; j++){
                if (vec_suma[m] == mat[x][j]){
                    band_simon = 1;
                }
            }
        }
    }

    return band_simon;
}
