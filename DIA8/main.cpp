
#include"Arbol.h"
#include <bits/stdc++.h>
using namespace std;
#include<iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include<chrono>

int main() {
    auto start = chrono::high_resolution_clock::now();//Medir el tiempo de ejecucion

    //Abrir el fichero input.txt para los datos del AoC
    ifstream archivo("input.txt");
    if (!archivo.is_open()) { //Compruebo si el archivo esta abierto correctamente
        cout << "No se pudo abrir el archivo.\n";
        return 1;
    }

    int x, y, z; //Coordenadas
    char coma; //',' separa las coordenadas x,y,z 
    Arbol nuevo_arbol; //Creo el arbol
    while (archivo >> x >> coma >> y >> coma >> z) {
        // x, y, z ya son enteros del fichero "input.txt"
        //cout << x << " " << y << " " << z << "\n";
        nuevo_arbol.Insertar_nodo(x,y,z);
    }
    archivo.close(); //Cierro archivo 

    //Vector de nodos
    vector<Nodo*> nodos;
    nuevo_arbol.Obtener_Nodos(nodos); /*Ejemplo:       2
                                                    1     3            
                                           nodos=[1, 2 , 3] */
    int n=nodos.size(); //Obtengo el tamanyo del vector de Nodos
    double distancia;
    vector<vector<double>> aristas; //(distancia, nodo i, nodo j)
    
    for(int i = 0; i < nodos.size(); i++){
        for(int j = i+1; j < nodos.size(); j++){
            distancia = nuevo_arbol.Calculo_distancia(nodos[i], nodos[j]); // Llamamos desde el objeto
            aristas.push_back({distancia,(double) i,(double) j});
        } //segundo For
    }//primer For
    //Ordenar vector de Aristas por distancias
    sort(aristas.begin(), aristas.end());

    nuevo_arbol.Union(n);

    int limite = min(1000, (int)aristas.size());

    // Conectamos los nodos usando Union
    for(int i = 0; i < limite; i++){
       int a = (int)aristas[i][1]; // nodo origen
        int b = (int)aristas[i][2]; // nodo destino
        nuevo_arbol.Union(a, b);
    }

    vector<int>tam=nuevo_arbol.Tamanyo();
    //ordenamos de mayor a menor
    sort(tam.rbegin(), tam.rend());

    int sol=1;
    for(int i=0; i<min(3,(int)tam.size()); i++){
        sol=sol*tam[i];
    }
    
    auto end = chrono::high_resolution_clock::now();
    
    chrono::duration<double> duracion = end - start;

    cout<<"SOL AoC:"<<sol<<"\n";
    cout << "Tiempo de ejecucion: " << duracion.count() << " segundos\n";


    return 0;
}