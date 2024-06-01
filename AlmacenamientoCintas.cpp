#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura para representar un fichero
struct Fichero {
    int longitud;
};

// Función para ordenar ficheros por longitud
bool compararPorLongitud(const Fichero& a, const Fichero& b) {
    return a.longitud < b.longitud;
}

// Función para encontrar el orden óptimo de almacenamiento y calcular el TMR
double almacenamientoOptimoEnCintas(std::vector<Fichero>& ficheros) {
    // Ordenar los ficheros por longitud en orden ascendente
    sort(ficheros.begin(), ficheros.end(), compararPorLongitud);

    // Calcular el Tiempo Medio de Recuperación (TMR)
    double TMR = 0;
    int n = ficheros.size();
    for (int i = 0; i < n; ++i) {
        int suma = 0;
        for (int j = 0; j <= i; ++j) {
            suma += ficheros[j].longitud;
        }
        TMR += suma;
    }
    TMR /= n;

    return TMR;
}

int main() {
    // Ejemplo de conjunto de ficheros
    vector<Fichero> ficheros = {
        {5}, {10}, {3}
    };

    // Calcular el TMR para el orden óptimo de almacenamiento
    double TMR = almacenamientoOptimoEnCintas(ficheros);

    // Imprimir el orden óptimo de almacenamiento y el TMR
    cout << "Orden óptimo de almacenamiento:\n";
    for (const auto& fichero : ficheros) {
        cout << "Longitud: " << fichero.longitud << "\n";
    }
    cout << "Tiempo Medio de Recuperación (TMR): " << TMR << "\n";

    return 0;
}