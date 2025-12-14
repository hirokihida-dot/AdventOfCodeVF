#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool esLineaVacia(const string& s) {
    for (char c : s) {
        if (c != ' ' && c != '\r' && c != '\n' && c != '\t')
            return false;
    }
    return true;
}

int main() {

  // -------- ABRIR ARCHIVO--------
    ifstream file("puzzle.txt");
    if (!file.is_open()) {
        cerr << "No se pudo abrir puzzle.txt\n"; //MENSAJE ERROR SI NO ENCUENTRA EL INPUT
        return 1; 
    }

    vector<pair<long long, long long>> rangos;
    string line;

    // -------- LEER RANGOS --------
    while (getline(file, line)) {
        if (esLineaVacia(line)) break; // PUNTO DE RUPTURA EN LA LECTURA DE RANGOS

        long long a, b;
        if (sscanf(line.c_str(), "%lld-%lld", &a, &b) == 2) { 
            rangos.push_back({a, b});  // RANGO INFERIOR Y SUPERIOR
        }
    }

    // -------- LEER IDS --------
    long long id;
    long long total = 0;

    while (file >> id) { 
        for (auto& r : rangos) { //CHECK DE LOS ID CON LOS RANGOS
            if (id >= r.first && id <= r.second) {
                total++; //CONTADOR DE LOS ID'S VALIDOS
                break;
            }
        }
    }

    cout << "IDs frescos: " << total << endl;

    return 0;
}
