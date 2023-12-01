#include <iostream>
#include <clocale>

using namespace std;

/*

*/


int main(){
    setlocale(LC_ALL, "Spanish");

    int cod_proy, cod_prov, dia;
    char tipo;
    float importe;

    //PUNTO A
    bool vec_PA[10] = {};

    //PUNTO B
    float vec_PB[31] = {};
    float maximo_dia;
    int max_pos;

    //PUNTO C
    int vec_PC_cod_proy[100] = {};
    int vec_pintura [100] = {};
    int vec_material[100] = {};
    int vec_cont[100] = {};


    cout << "Codigo de proyecto: ";
    cin >> cod_proy;

    while (cod_proy != 0){
        cout << "Codigo de proveedor: ";
        cin >> cod_prov;
        cout << "Codigo de dia: ";
        cin >> dia;
        cout << "Tipo: ";
        cin >> tipo;
        cout << "Importe: ";
        cin >> importe;
        cout << endl ;


        //PUNTO A
        if (tipo == 'P'){
            vec_PA[cod_prov-1] = true;
        }

        //PUNTO B
        vec_PB[dia-1] += importe;

        //PUNTO C
        vec_PC_cod_proy[cod_proy-100] ++;

        if (tipo == 'M'){
            vec_material[cod_proy-100]++;
        }
        if (tipo == 'P'){
            vec_pintura[cod_proy-100]++;
        }


        cout << "Codigo de proyecto: ";
        cin >> cod_proy;

    }

    cout << "PUNTO A : "<< endl;
    cout << "Proveedores a los que nunca compraron pintura: " << endl;
    for (int x = 0; x < 10; x++){
        if (!vec_PA[x]){
            cout << x+1 << " ";
        }
    }

    cout << "PUNTO B :" << endl;

    maximo_dia = vec_PB[0];
    max_pos = 0;

    for (int x = 1; x < 31; x++){
        if (vec_PB[x] > maximo_dia){
            maximo_dia = vec_PB[x];
            max_pos = x;
        }
    }

    cout << "El dia que mas se gasto fue: " << max_pos+1 <<  endl;


    //PUNTO C
    int total_comp;
    int tot_pint;
    int tot_mat;

    for (int x = 0; x < 100; x++){
        if (vec_PC_cod_proy[x] > 0){
            total_comp = vec_PC_cod_proy[x];
            tot_pint = vec_pintura[x];
            tot_mat = vec_material[x];

            cout << "Proyecto: " << x+100 << endl;
            cout << "De construccion:  " << (float) tot_mat*100/total_comp << " %" << endl;
            cout << "Pintura: " << (float) tot_pint*100/total_comp << " %" << endl;
            cout << endl;
        }
    }




    return 0;
}
