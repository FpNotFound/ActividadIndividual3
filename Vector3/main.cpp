#include <iostream>
#include <string>
#include <cmath>
#include "Vector.h"

using namespace std;

// Calcula el promedio de las calificaciones de un estudiante.
double calcularPromedioEstudiante(Vector<double>& calificaciones) {

    double suma = 0;

    for (int i = 0; i < calificaciones.getSize(); i++) {
        suma += calificaciones[i];
    }

    return suma / calificaciones.getSize();
}

// Calcula el promedio de una asignatura.
double calcularPromedioAsignatura(
    Vector<Vector<double>*>& estudiantes,
    int asignatura) {

    double suma = 0;

    for (int i = 0; i < estudiantes.getSize(); i++) {
        suma += (*estudiantes[i])[asignatura];
    }

    return suma / estudiantes.getSize();
}

// Calcula la varianza de una asignatura.
// La varianza indica cuánto se dispersan las calificaciones
// respecto al promedio.
double calcularVarianzaAsignatura(
    Vector<Vector<double>*>& estudiantes,
    int asignatura) {

    double promedio =
        calcularPromedioAsignatura(estudiantes, asignatura);

    double suma = 0;

    for (int i = 0; i < estudiantes.getSize(); i++) {

        double diferencia =
            (*estudiantes[i])[asignatura] - promedio;

        suma += diferencia * diferencia;
    }

    return suma / estudiantes.getSize();
}

// Busca al estudiante con el mejor promedio.
int buscarMejorEstudiante(
    Vector<Vector<double>*>& estudiantes) {

    int mejor = 0;

    double mejorPromedio =
        calcularPromedioEstudiante(*estudiantes[0]);

    for (int i = 1; i < estudiantes.getSize(); i++) {

        double promedio =
            calcularPromedioEstudiante(*estudiantes[i]);

        if (promedio > mejorPromedio) {
            mejorPromedio = promedio;
            mejor = i;
        }
    }

    return mejor;
}

// Busca la asignatura con mayor dispersión.
int buscarMayorDispersion(
    Vector<Vector<double>*>& estudiantes,
    int numeroAsignaturas) {

    int mayor = 0;

    double mayorVarianza =
        calcularVarianzaAsignatura(estudiantes, 0);

    for (int i = 1; i < numeroAsignaturas; i++) {

        double varianza =
            calcularVarianzaAsignatura(estudiantes, i);

        if (varianza > mayorVarianza) {
            mayorVarianza = varianza;
            mayor = i;
        }
    }

    return mayor;
}

int main() {

    const int NUM_ESTUDIANTES = 5;
    const int NUM_ASIGNATURAS = 3;

    // Nombres de los estudiantes.
    Vector<string> nombres(NUM_ESTUDIANTES);

    nombres[0] = "James";
    nombres[1] = "Saida";
    nombres[2] = "Juan";
    nombres[3] = "Esteban";
    nombres[4] = "Mora";

    // Nombres de las asignaturas.
    Vector<string> asignaturas(NUM_ASIGNATURAS);

    asignaturas[0] = "Programacion";
    asignaturas[1] = "Matematicas";
    asignaturas[2] = "Bases de Datos";

    // Creamos un Vector para las calificaciones de cada estudiante.
    Vector<Vector<double>*> estudiantes(NUM_ESTUDIANTES);

    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        estudiantes[i] = new Vector<double>(NUM_ASIGNATURAS);
    }

    // Calificaciones de Ana.
    (*estudiantes[0])[0] = 9.0;
    (*estudiantes[0])[1] = 8.5;
    (*estudiantes[0])[2] = 9.5;

    // Calificaciones de Carlos.
    (*estudiantes[1])[0] = 7.0;
    (*estudiantes[1])[1] = 8.0;
    (*estudiantes[1])[2] = 7.5;

    // Calificaciones de Maria.
    (*estudiantes[2])[0] = 9.5;
    (*estudiantes[2])[1] = 9.0;
    (*estudiantes[2])[2] = 9.0;

    // Calificaciones de Pedro.
    (*estudiantes[3])[0] = 6.5;
    (*estudiantes[3])[1] = 7.0;
    (*estudiantes[3])[2] = 6.0;

    // Calificaciones de Laura.
    (*estudiantes[4])[0] = 8.0;
    (*estudiantes[4])[1] = 9.5;
    (*estudiantes[4])[2] = 8.5;

    // Buscamos el estudiante con mejor desempeño.
    int mejorEstudiante =
        buscarMejorEstudiante(estudiantes);

    // Mostramos el promedio de cada asignatura.
    cout << "===== RENDIMIENTO DE ESTUDIANTES =====" << endl;

    cout << "\nPromedio por asignatura:" << endl;

    for (int i = 0; i < NUM_ASIGNATURAS; i++) {

        double promedio =
            calcularPromedioAsignatura(estudiantes, i);

        cout << asignaturas[i] << ": "
             << promedio << endl;
    }

    // Buscamos la asignatura con mayor dispersión.
    int asignaturaMayorDispersion =
        buscarMayorDispersion(
            estudiantes,
            NUM_ASIGNATURAS);

    cout << "\nEstudiante con mejor desempeno: "
         << nombres[mejorEstudiante] << endl;

    cout << "Asignatura con mayor dispersion: "
         << asignaturas[asignaturaMayorDispersion] << endl;

    cout << "Varianza: "
         << calcularVarianzaAsignatura(
                estudiantes,
                asignaturaMayorDispersion)
         << endl;

    // Liberamos la memoria utilizada.
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        delete estudiantes[i];
    }

    return 0;
}