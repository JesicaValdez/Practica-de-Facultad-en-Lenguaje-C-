#include <iostream>
#include <clocale>

using namespace std;


bool EsVectorVeleziano (int vec[], int tam){
    int cont = 0, solos = 0;
    bool es_veleziano = 0;

    for (int x = 0; x < tam; x++){
        cont = 0;
        for (int i = 0; i < tam; i++){

            if (vec[x] == vec[i]){
                cont++;
            }

        }


        if (cont != 2){
           solos++;
        }
    }
        if (!solos){
            return true;
        }
        else {
            return false;
        }
}


int main(){
    setlocale(LC_ALL, "Spanish");


    int vec_num [6] = {1,2,3,4,5,5};

    cout << EsVectorVeleziano(vec_num, 6);

    return 0;
}





///FUNCION DEL PUNTO 1

