/*Nombre: Jesica Valdez
TP N°:
Ejercicio N°:
Comentarios:
*/

#include <iostream>
using namespace std;

int main ()
{
    //Primer lote
    int const CODIGO=3;
    int codHamburguesaEstructura1, stock;
    float precio;
    int vStock[CODIGO] = {};
    float vPrecio[CODIGO] = {};


    //Segundo Lote
    int codHambEstructura2, dia, cantidad;
    char tipoAcompaniamiento;



    //PUNTO A
    int vCantVentas[CODIGO]={};

    //PUNTO B
    int vHamburguesa[CODIGO]={};
    int mayorVenta;
    int posiMasVendida;

    //PUNTO C
    int const DIAS = 7;
    int const TIPO = 2;
    int mDias[DIAS][TIPO]={};

    //PUNTO D - REUTILIZAMOS VECTOR PUNTO A

    //PUNTO E
    int const TIPO_E = 4;
    string sDias[DIAS] = {"LUNES", "MARTES", "MIERCOLES","JUEVES", "VIERNES", "SABADO", "DOMINGO"};
    string sTipoAcomp[TIPO_E]= {"Batatas", "Papas", "Aros de cebolla", "sin acompañamiento"};
    int mDiasPuntoE[DIAS][TIPO_E]={};


    //LOTE 1
    for(int i=0; i<CODIGO; i++){

        cout << "Código de hamburguesa: ";
        cin >> codHamburguesaEstructura1;
        cout << "Precio: $";
        cin >> precio;
        cout << "Stock al comienzo de la semana: ";
        cin >> stock;
        cout << endl;

        vStock[i]=stock;
        vPrecio[i]=precio;
    }
    system("cls");


    //LOTE 2

    cout << "Ingrese Codigo de Hamburguesa: "<< endl;
    cin >> codHambEstructura2;


    while(codHambEstructura2!=0){

        cout << "Ingrese dia: ";
        cin >> dia;
        cout << "Ingrese Cantidad vendida: ";
        cin >> cantidad;
        cout << "Ingrese tipo de acompañamiento: ('B' – con batatas / 'P' – con papas / 'C' – Aros de cebolla / 'X' – sin acompañamiento)";
        cin >> tipoAcompaniamiento;
        cout << endl;

        //PUNTO A
        vCantVentas[codHambEstructura2-1]+=cantidad;

        //PUNTO B
        if(dia==5){
            vHamburguesa[codHambEstructura2-1]+=cantidad;
        }

        //PUNTO C
        if (tipoAcompaniamiento == 'B'){
            mDias[dia-1][0]++;
        }
        else if(tipoAcompaniamiento=='C'){
            mDias[dia-1][1]++;
        }

        //PUNTO D
        if (tipoAcompaniamiento == 'B'){
            mDiasPuntoE[dia-1][0]+=cantidad;
        }
        else if(tipoAcompaniamiento=='P'){
            mDiasPuntoE[dia-1][1]+=cantidad;
        }
        else if (tipoAcompaniamiento=='C'){
            mDiasPuntoE[dia-1][2]+=cantidad;
        }
        else{
            mDiasPuntoE[dia-1][3]+=cantidad;
        }




        cout << "Ingrese Codigo de Hamburguesa: "<< endl;
        cin >> codHambEstructura2;

    }

    system("cls");


    cout << "---Punto A---" << endl;
    for (int i=0; i<CODIGO; i++)
    {
        if(vCantVentas[i]>0){
            cout << "Unidades Vendidas #" << i+1 << " : " << vCantVentas[i] << endl;
            cout << "Total recaudado: $" << vCantVentas[i]*vPrecio[i] << endl;
        }
        else{
            cout << "El dia #"<< i+1 <<" No se registraron ventas" << endl;
        }
    }


    cout << endl << endl;
    cout << "---Punto B---" << endl;
    mayorVenta=vHamburguesa[0];
    posiMasVendida=0;
    for (int i=1; i<CODIGO; i++)
    {
        if(vHamburguesa[i]>mayorVenta){
            mayorVenta= vHamburguesa[i];
            posiMasVendida=i;
        }

    }

    if(posiMasVendida>0){
    cout << "Hamburguesa mas vendida el viernes: " << posiMasVendida+1;
    }else{
    cout<<"no se vendio hamburguesas el viernes"<<endl;
    }

    cout << endl << endl;
    cout << "---Punto C---" << endl;
    for (int i=0; i<DIAS; i++)
    {
        if(mDias[i][0]>0 && mDias[i][1]==0){
            cout << "Se vendieron hamburguesas con batatas pero no con aros de cebolla el dia: " << i+1 << endl;
        }
    }


    cout << endl << endl;
    cout << "---Punto D---" << endl;
    for (int i=0; i<CODIGO; i++)
    {
        if(vCantVentas[i]-vStock[i]==0){
            cout << "El codigo de Hamburguesa #:"<< i+1 << " Logro un sold out." << endl;
        }

    }

    cout << endl << endl;
    cout << "---Punto E---" << endl;
    for (int d=0; d<DIAS; d++){
            cout << "Dia: " << sDias[d] << endl;
            for(int a=0; a<TIPO_E; a++){
                cout <<"\t " <<sTipoAcomp[a] << " acumulo: " << mDiasPuntoE[d][a]<< endl;
            }
        cout << endl;
    }



return 0;

}

/*
Problema 1- Nivel: 🙂
Cargar las notas del primer parcial de los 78 estudiantes de un curso. Luego de cargar todas las notas:
- Pedir un número y mostrar por pantalla la nota registrada. Por ejemplo, se ingresa 10 para mostrar el décimo examen.
- Listar cuántos estudiantes obtuvieron una nota mayor al promedio.

int main ()
{
    //variables
    int nota, numero;

    //constantes
    int const CANTIDAD_ESTUDIANTES = 5;
    //inicializamos el vector
    int vNotas[CANTIDAD_ESTUDIANTES] = {};

    //PUNTO A
    int acuNotas;
    //PUNTO B
    int cant;
    float promedio;



    //cargamos el vector
    for(int i=0; i<CANTIDAD_ESTUDIANTES; i++){
        cout << "Ingrese nota: ";
        cin >> nota;
        vNotas[i] = nota;
        acuNotas += nota;
    }

    //mostramos vector
    for (int i=0; i<CANTIDAD_ESTUDIANTES; i++){
        cout << "mostramos numero: " << vNotas[i] << endl;
    }
    cout << endl;

    //asociamos el numero que ingresa el usuario con la posicion del vector
    cout << "Ingrese el numero de la nota que deseas ver: ";
    cin >> numero;
    cout << vNotas[numero-1];
    cout << endl;

    //Punto B
    promedio = (float) acuNotas/CANTIDAD_ESTUDIANTES;
    cout << "El promedio de notas es: " << promedio << endl;

    for (int i=0; i>CANTIDAD_ESTUDIANTES; i++){
        if(vNotas[i]>promedio){
            cant++;
        }
    }
    cout << endl;
    cout << "Cantidad de notas mayor al promedio = " << cant << endl;








return 0;



Problema 2 - Nivel: 😅
Una persona desea registrar los gastos realizados durante un mes. Ha definido que los gastos se pueden categorizar en:

ID de Categoría
Nombre de categoría
1
Servicios
2
Alimentación
3
Limpieza
4
Transporte
5
Educación
6
Salud
7
Ocio
8
Impuestos
9
Vestimenta
10
Inversiones


Por cada gasto registrado se ingresa el siguiente registro:
- Día (número entero)
- ID de Categoría de gasto (número entero entre 1 y 10)
- Importe del gasto (número real)

La información no se encuentra agrupada ni ordenada. No se sabe de antemano cuántos registros de gastos habrá. El fin de la carga de información se indica con un día igual a cero.

Calcular e informar:
A) La categoría de gasto que mayor dinero se haya destinado y cuál es dicha categoría.
B) Por cada categoría de gasto, el nombre de la categoría y el total acumulado en concepto de gastos del mes.
C) La cantidad de categorías de gasto que no hayan registrado movimientos.
D) Por cada día, la cantidad de gastos que se hayan registrado. Sólo mostrar aquellos registros de días que hayan registrado gastos.

int main ()
{
    int dia, idCategoria;
    float importe;

    //constantes
    int const ID_CATEGORIA = 10;
    int const DIAS = 31;
    string nombreCat[ID_CATEGORIA] = {"1-Servicios", "2-Alimentacion", "3-Limpieza", "4-Transporte", "5-Educacion", "6-Salud", "7-Ocio", "8- Impuestos", "9-Vestimenta", "10-Inveriones"};


    //PUNTO A
    float acuGastos[ID_CATEGORIA] = {};
    float mayorGasto;
    int posicionMayorCategoria;

    //PUNTO C
    int contPuntoC =0;

    //PUNTO D
    int vDias[31] = {};

    cout << "Ingrese el dia: "<< endl;
    cin >> dia;


    while(dia!=0){

        cout << "Ingrese ID de Categoría de gasto: " << endl;
        cin >> idCategoria;
        cout << "Ingrese Importe del gasto: "<< endl;
        cin >> importe;
        cout << endl;

        //PUNTO A
        acuGastos[idCategoria-1]+=importe;

        //PUNTO D
        vDias[dia-1]++;




        cout << "Ingrese el dia: "<< endl;
        cin >> dia;

    }

    system("cls");


    cout << "---Punto A---" << endl;
    mayorGasto=acuGastos[0];
    //sacamos la posicion de la categoria mayor
    posicionMayorCategoria=0;
    for (int i=1; i<ID_CATEGORIA; i++)
    {
        if(acuGastos[i]>mayorGasto){
            mayorGasto = acuGastos[i];
            posicionMayorCategoria=i;
        }
    }
    cout <<"La categoria que mayor gasto realizo fue: " << nombreCat[posicionMayorCategoria] <<" Con un importe de: " << mayorGasto << endl;


    cout << endl << endl;
    cout << "---Punto B---" << endl;
    for(int i=0; i<ID_CATEGORIA; i++){
        cout << nombreCat[i] << " : " << acuGastos[i] << endl;
    }

    cout << endl << endl;
    cout << "---Punto C---" << endl;
    for(int i=0; i<ID_CATEGORIA; i++){
        if(acuGastos[i]==0){
            contPuntoC++;
        }
    }
    cout << "La cantidad de categorias que no efectuaron gastos: " << contPuntoC << endl;

    cout << endl << endl;
    cout << "---Punto D---" << endl;
    for(int i=0; i<DIAS; i++){
        if(vDias[i]>0){
            cout << "La cantidad de gastos del dia: " << i+1 << " es de: " << vDias[i] << endl;
        }
    }

return 0;

Problema 3 - Nivel: 😓
Una fundación que se dedica a fomentar la adopción de mascotas dispone de los registros de adopciones del año 2023. Por cada adopción que se haya efectuado se registró:
Mes de la adopción (entero entre 1 y 12)
Tipo de animal adoptado (entero entre 10 y 15)
Edad del adoptante responsable
Tipo de vivienda del adoptante responsable (entero entre 1 y 5)

La información no se encuentra agrupada ni ordenada bajo ningún criterio. Para indicar el fin de la carga de datos se ingresa un mes de adopción igual a cero.

Se pide calcular e informar
El tipo de animal más adoptado en general.
El promedio de edad de los adoptantes de cada tipo de animal.
Por cada tipo de animal y tipo de vivienda la cantidad total de adopciones registradas.

Aclaración:
Los tipos de animales son:
10 - Perro, 11 - Gato, 12 - Conejo, 13 - Hurón, 14 - Caballo, 15 - Oveja

Los tipos de vivienda son:
1 - Casa, 2 - Departamento, 3 - Casa Quinta, 4 - Finca, 5 - Duplex


int main ()
{
    int mesAdopcion, tipoAnimal, edadAdoptante, tipoVivienda;


    //constantes
    int const TIPO_ANIMAL = 6;
    int const TIPO_VIVIENDA = 5;
    string sTipoAnimal[TIPO_ANIMAL] = {"10 - Perro", "11 - Gato", "12 - Conejo", "13 - Hurón", "14 - Caballo", "15 - Oveja"};
    string sTipoVivienda[TIPO_VIVIENDA] = {"1 - Casa", "2 - Departamento", "3 - Casa Quinta", "4 - Finca", "5 - Duplex"};

    //PUNTO A
    int vPuntoA[TIPO_ANIMAL]={};
    int mayorPuntoA, posicionPuntoA;

    //PUNTO B
    int acuEdad[TIPO_ANIMAL]={};
    float promedio;

    //PUNTO C
    int mCantidad[TIPO_ANIMAL][TIPO_VIVIENDA]= {};


    cout << "Ingrese el mes de Adopcion: "<< endl;
    cin >> mesAdopcion;


    while(mesAdopcion!=0){

        cout << "Ingrese Tipo de animal adoptado: " << endl;
        cin >> tipoAnimal;
        cout << "Ingrese Edad del adoptante responsable: "<< endl;
        cin >> edadAdoptante;
        cout << "Ingrese Tipo de vivienda del adoptante responsable: " << endl;
        cin >> tipoVivienda;
        cout << endl;

        //PUNTO A
        vPuntoA[tipoAnimal-10]++;

        //PUNTO B
        acuEdad[tipoAnimal-10]+=edadAdoptante;

        //PUNTO C
        mCantidad[tipoAnimal-10][tipoVivienda-1]++;



        cout << "Ingrese el mes de Adopcion: "<< endl;
        cin >> mesAdopcion;

    }

    system("cls");


    cout << "---Punto A---" << endl;
    mayorPuntoA=vPuntoA[0];
    posicionPuntoA=0;
    //sacamos la posicion del mas adoptado
    for (int i=1; i<TIPO_ANIMAL; i++)
    {
        if(vPuntoA[i]>mayorPuntoA){
            mayorPuntoA = vPuntoA[i];
            posicionPuntoA=i;
        }
    }
    cout <<"El animal mas adoptado fue: " << sTipoAnimal[posicionPuntoA] << endl;


    cout << endl << endl;
    cout << "---Punto B---" << endl;
    for(int i=0; i<TIPO_ANIMAL; i++){
        if(vPuntoA[i]>0){
            promedio = (float)acuEdad[i]/vPuntoA[i];
            cout << "El promedio de adoptantes del Tipo: " << sTipoAnimal[i] << " es: " << promedio << endl;
        }
    }

    cout << endl << endl;
    cout << "---Punto C---" << endl;
    for(int animalFila=0; animalFila<TIPO_ANIMAL; animalFila++){
            cout << "Cantidad de adopciones de: " << sTipoAnimal[animalFila] << endl;
        for(int viviendaColumna=0; viviendaColumna<TIPO_VIVIENDA; viviendaColumna++){
            cout << "\t en vivienda " << sTipoVivienda[viviendaColumna]<< " es: " << mCantidad[animalFila][viviendaColumna] << endl;
        }
        cout << endl;
    }



return 0;

Problema 4 - Nivel: 😓
La mundialmente conocida hamburguesería Coco’s Burger desea registrar la información de las ventas de la primera semana de Agosto 2023 de su local ubicado en Canelones, Uruguay.

Por cada venta se registra:
•    Código de hamburguesa (entero de 1 a 5)
•    Día (entero de 1 - Lunes a 7 - Domingo)
•    Cantidad vendida (entero)
•  Tipo de Acompañamiento ('B' – con batatas / 'P' – con papas / 'C' – Aros de cebolla / 'X' – sin acompañamiento)

Pueden existir varios registros de ventas para la misma hamburguesa. El fin de la carga de datos se indica con un código de hamburguesa igual a 0.

A este lote se le precede otro ordenado por número de hamburguesa con la siguiente información:
•    Código de hamburguesa (1 a 5)
•    Precio (float)
•    Stock al comienzo de la semana (entero)

Se pide determinar e informar:
Por cada hamburguesa, la cantidad de unidades vendidas y el total recaudado.
La hamburguesa más vendida el viernes.
Los días que se vendieron hamburguesas acompañadas de Batatas pero no se vendieron hamburguesas acompañadas de Aros de Cebolla.
Las hamburguesas que lograron un sold out (vendieron todo)
Por cada día y acompañamiento, la cantidad de hamburguesas vendidas.



#include <iostream>
using namespace std;

int main ()
{
    //Primer lote
    int const CODIGO=3;
    int codHamburguesaEstructura1, stock;
    float precio;
    int vStock[CODIGO] = {};
    float vPrecio[CODIGO] = {};


    //Segundo Lote
    int codHambEstructura2, dia, cantidad;
    char tipoAcompaniamiento;



    //PUNTO A
    int vCantVentas[CODIGO]={};

    //PUNTO B
    int vHamburguesa[CODIGO]={};
    int mayorVenta;
    int posiMasVendida;

    //PUNTO C
    int const DIAS = 7;
    int const TIPO = 2;
    int mDias[DIAS][TIPO]={};



    //LOTE 1
    for(int i=0; i<CODIGO; i++){

        cout << "Código de hamburguesa: ";
        cin >> codHamburguesaEstructura1;
        cout << "Precio: $";
        cin >> precio;
        cout << "Stock al comienzo de la semana: ";
        cin >> stock;
        cout << endl;

        vStock[i]=stock;
        vPrecio[i]=precio;
    }
    system("cls");


    //LOTE 2

    cout << "Ingrese Codigo de Hamburguesa: "<< endl;
    cin >> codHambEstructura2;


    while(codHambEstructura2!=0){

        cout << "Ingrese dia: ";
        cin >> dia;
        cout << "Ingrese Cantidad vendida: ";
        cin >> cantidad;
        cout << "Ingrese tipo de acompañamiento: ('B' – con batatas / 'P' – con papas / 'C' – Aros de cebolla / 'X' – sin acompañamiento)";
        cin >> tipoAcompaniamiento;
        cout << endl;

        //PUNTO A
        vCantVentas[codHambEstructura2-1]+=cantidad;

        //PUNTO B
        if(dia==5){
            vHamburguesa[codHambEstructura2-1]+=cantidad;
        }

        //PUNTO C
        if (tipoAcompaniamiento == 'B'){
            mDias[dia-1][0]++;
        }
        else if(tipoAcompaniamiento=='C'){
            mDias[dia-1][1]++;
        }


        cout << "Ingrese Codigo de Hamburguesa: "<< endl;
        cin >> codHambEstructura2;

    }

    system("cls");


    cout << "---Punto A---" << endl;
    for (int i=0; i<CODIGO; i++)
    {
        if(vCantVentas[i]>0){
            cout << "Unidades Vendidas #" << i+1 << " : " << vCantVentas[i] << endl;
            cout << "Total recaudado: $" << vCantVentas[i]*vPrecio[i] << endl;
        }
        else{
            cout << "El dia #"<< i+1 <<" No se registraron ventas" << endl;
        }
    }


    cout << endl << endl;
    cout << "---Punto B---" << endl;
    mayorVenta=vHamburguesa[0];
    posiMasVendida=0;
    for (int i=1; i<CODIGO; i++)
    {
        if(vHamburguesa[i]>mayorVenta){
            mayorVenta= vHamburguesa[i];
            posiMasVendida=i;
        }

    }

    if(posiMasVendida>0){
    cout << "Hamburguesa mas vendida el viernes: " << posiMasVendida+1;
    }else{
    cout<<"no se vendio hamburguesas el viernes"<<endl;
    }

    cout << endl << endl;
    cout << "---Punto C---" << endl;
    for (int i=0; i<DIAS; i++)
    {
        if(mDias[i][0]>0 && mDias[i][1]==0){
            cout << "Se vendieron hamburguesas con batatas pero no con aros de cebolla el dia: " << i+1 << endl;
        }
    }


return 0;

Problema 5 - Nivel: ☠️
Un individuo acaba de obtener su álbum de figuritas de DragonCube. Se trata de un libro cuyas páginas cuentan con espacios en blanco designados para pegar 50 figuritas.

Estos espacios en blanco están numerados y cada uno de ellos está reservado para una figurita en particular, identificada con el mismo número. Luego de obtener el álbum, el coleccionista comienza a comprar paquetes de figuritas que contienen, cada uno, 5 unidades. Los paquetes vienen identificados con un número natural como código.



Las figuritas, además de estar numeradas, se clasifican por:

Tipo de figurita:
- Común (C)
- Holograma (H)

Se pide realizar un programa que permita registrar, por cada paquete, la información de las
5 figuritas. Los registros tienen la siguiente estructura:
Número de paquete (entero)
Número de figurita (1 a 50)
Tipo de figurita (C o H)
¿Pegar en el álbum? (S/N)

No hay límites en la cantidad de paquetes que el coleccionista pueda comprar. La carga de datos finaliza con un número de paquete igual a 0. Calcular e informar:
La cantidad de figuritas comunes repetidas.
La cantidad de figuritas faltantes del álbum.
La cantidad de hologramas entre las figuritas compradas (sin contar las repetidas).
El estado del álbum pudiendo ser uno de los siguientes casos:
"Incompleto" si no se llegaron a pegar las 50 figuritas.
"Completo" si se llegaron a pegar las 50 figuritas entre comunes y hologramas.
"Completo común" si está completo pero además tiene las 50 figuritas comunes pegadas.
"Completo holográfico" si está completo pero además tiene las 50 figuritas hologramas pegadas.
Teniendo en cuenta que cada paquete cuesta $500 y que cada figurita común se puede vender a $20 y cada holograma a $50. Calcular el costo total de la colección y el costo total de una potencial venta de figuritas no pegadas de la colección.

Aclaraciones:
Cuando se carga los datos de un paquete se debe solicitar la información de las cinco figuritas que incluye el paquete.
El álbum tiene 50 figuritas en total pero los paquetes pueden traer de cada una la variante común y holograma. En total son 100 figuritas distintas.
El coleccionista puede decidir si pega en el álbum figuritas comunes y hologramas, sólo comunes o sólo hologramas. Cada espacio del álbum sin figuritas es una figurita faltante.
Las figuritas que el coleccionista no pega en el álbum son parte de su colección en una pila aparte. Si el coleccionista tiene la figurita #1 varias veces pero nunca la pegó en el álbum entonces el álbum no puede considerarse completo.
Se considera una figurita repetida si tiene la misma figurita del mismo tipo más de una vez. Por ejemplo, si tengo la figurita #1 común y #1 holograma en mi colección, no la tengo repetida. Sin embargo, si tres veces tengo la figura #1 holograma en mi colección entonces la tengo repetida DOS veces.




*/
