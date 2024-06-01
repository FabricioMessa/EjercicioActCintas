#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura para representar una actividad
struct Actividad {
    int inicio;
    int fin;
};

// Función para ordenar actividades por tiempo de finalización
bool compararPorFin(const Actividad &a, const Actividad &b) {
    return a.fin < b.fin;
}

// Función para seleccionar el máximo número de actividades que no se solapan
vector<Actividad> SelecciónActividades(vector<Actividad> &C) {
    // Ordenar las actividades por tiempo de finalización
    sort(C.begin(), C.end(), compararPorFin);

    vector<Actividad> S;
    if (C.empty()) {
        return S;
    }

    // Seleccionar la primera actividad
    S.push_back(C[0]);
    int prev = 0;

    // Iterar sobre las actividades restantes
    for (size_t i = 1; i < C.size(); ++i) {
        if (C[i].inicio >= C[prev].fin) {
            S.push_back(C[i]);
            prev = i;
        }
    }

    return S;
}

int main() {
    // Ejemplo de conjunto de actividades
    vector<Actividad> actividades = {
        {1, 3}, {2, 5}, {4, 6}, {6, 7}, {5, 8}, {8, 9}
    };

    // Obtener las actividades seleccionadas
    vector<Actividad> seleccionadas = SelecciónActividades(actividades);

    // Imprimir las actividades seleccionadas
    cout << "Actividades seleccionadas:\n";
    for (const auto &actividad : seleccionadas) {
        std::cout << "Inicio: " << actividad.inicio << ", Fin: " << actividad.fin << "\n";
    }

    return 0;
}