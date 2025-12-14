#include"Nodo.h"

#include <bits/stdc++.h>
using namespace std;
#include<iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include<chrono>

class Arbol{
    private:
        Nodo *raiz; //Raíz del arbol
        vector<int> padre; //Vector guardara id padres
        vector<int> tamanyo; //indicar tamaño de las raizes
    //Metodo de ordenamiento del arbol, Var x
        Nodo* Insertar(Nodo* nodo, int x, int y, int z){
            if(nodo==nullptr){
                return new Nodo(x,y,z); // SI NO LO HAY LO CREO
            }
        //Si la x es menor lo pondremos en la izquierda
            if(x < nodo->x){
                nodo->izquierdo=Insertar(nodo->izquierdo,x,y,z);
            }
        //Si la x es mayor insertamos en la derecha
            else{
                nodo->derecho=Insertar(nodo->derecho,x,y,z);
            }
            return(nodo);
    }

    Nodo* Imprimir(Nodo*nodo){
        if(nodo==nullptr){
            return 0;
        }
        Imprimir(nodo->izquierdo);
        cout<<"Nodo:" << nodo->x << ","<< nodo->y << "," << nodo->z <<"\n";
        Imprimir(nodo->derecho);
    }

    //Metodo para recorrer de forma ordenada el arbol
    void inorderRec(Nodo* nodo, vector<Nodo*>& nodos) {
        //Caso base
        if (!nodo){
            return;}
        //Recorro la subparte izquierda
        inorderRec(nodo->izquierdo, nodos);
        //Guardo el nodo actual en el vector de nodos
        nodos.push_back(nodo);
        //Recorro la subparte derecha
        inorderRec(nodo->derecho, nodos);
    }


    public:
    //INICIALIZO EL ARBOL: METODO CONSTRUCTOR
        Arbol(){
            raiz=nullptr;
        }
        //Insertar un nuevo nodo al arbol
        void Insertar_nodo(int x, int y, int z){
            raiz=Insertar(raiz,x,y,z);

        }
        //Metodo para imprimir cada Nodo
        void Imprimir_nodo(){
            Imprimir(raiz);
        }
        
        void Obtener_Nodos(vector<Nodo*>& nodos) { 
            inorderRec(raiz, nodos);
        }
        //Metodo para calcular la distancia 
        double Calculo_distancia(Nodo*a,Nodo*b){
            return(sqrt(pow(a->x - b->x, 2)+ pow(a->y - b->y , 2) + pow(a->z - b->z, 2)));
        }

        void Union(int n){
            //IDENTIFICO LOS NODOS PADRES
            padre.resize(n);
            tamanyo.resize(n,1);
            for(int i=0; i<n; i++){
                padre[i]=i;
            }
        }
        int Encontrar(int a){
            //Metodo para localizar un padre
            //Caso Base:
            if(padre[a]==a){
                return a;
            }
            //Recursivo: //Sigue buscando por padres.
            return(padre[a] =Encontrar(padre[a]));
        }

        void Union(int a, int b){
            int ra=Encontrar(a); //raiz "nodo A"
            int rb=Encontrar(b); //Raíz "nodo B"
            //Compruebo si ambos tiene la misma raiz
            if(ra==rb){
                return; //No hay que unir nada
            }
            //En el caso de que el conjunto sea menor, lo uno al conjunto más grande
            if(tamanyo[ra] < tamanyo[rb]){ 
                swap(ra,rb);
            }
            //Raiz rb dependerá también de ra
            padre[rb]=ra;
            //actualizamos el tamanyo
            tamanyo[ra]=tamanyo[ra]+tamanyo[rb];
        }

        vector<int>Tamanyo(){
            //Hago una copia del 'padre'
            vector<int> res(padre.size(),0);
            //Recorro todos los elementos del padre
            for(int i=0; i<padre.size();i++){
                //Encouentro la raiz principal
                res[Encontrar(i)]++;
                //+1 al conjunto al que pertenece

            }
            return res;
        }
};
