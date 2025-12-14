#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
#include<iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include<chrono>
class Nodo{
    public:
        int x,y,z; //Coordenadas
        Nodo * izquierdo; //Nodo izquierdo del arbol
        Nodo * derecho; //Nodo derecho del arbol

        //Método constructor:
        Nodo(int x,int y, int z){
            this->x=x;
            this->y=y;
            this->z=z;
            izquierdo=nullptr;
            derecho=nullptr;
        }
};