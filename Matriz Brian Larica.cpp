#include <iostream>
#include <clocale>

using namespace std;
bool EsBrianLarica(int mat[][5]){

    int cont = 0;
    int repetidos = 0;

    for(int x = 0; x < 5; x++){
        for (int i = 0; i < 5; i++){
            cont = 0;
            for (int m = 0; m < 5; m++){
                for (int j = 0; j < 5; j++){
                    if (mat [x][i] == mat[m][j] ){
                        cont ++;
                    }
                }
            }
            if (cont > 1){
                repetidos++;
            }
        }

    }
    if (repetidos == 0){
        return true;
    }
    else{
        return false;
    }

}

int main(){
    setlocale(LC_ALL, "Spanish");

    int mat[][5] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};

    cout << EsBrianLarica(mat);



return 0;
}





