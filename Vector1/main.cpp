#include <iostream>
#include "Vector.h"

using namespace std;

// Calcula la suma total de todas las ventas del mes.
double calcularTotal(Vector<double>& ventas) {

    double total = 0;

    for (int i = 0; i < ventas.getSize(); i++) {
        total += ventas[i];
    }

    return total;
}

// Busca el día que tuvo la menor cantidad de ventas.
int buscarDiaMenorVenta(Vector<double>& ventas) {

    int posicionMenor = 0;

    for (int i = 1; i < ventas.getSize(); i++) {

        if (ventas[i] < ventas[posicionMenor]) {
            posicionMenor = i;
        }
    }

    return posicionMenor;
}

// Busca el producto con mayor cantidad de ventas.
int buscarProductoMasVendido(Vector<int>& ventasProductos) {

    int posicionMayor = 0;

    for (int i = 1; i < ventasProductos.getSize(); i++) {

        if (ventasProductos[i] > ventasProductos[posicionMayor]) {
            posicionMayor = i;
        }
    }

    return posicionMayor;
}

int main() {

    // Vector que almacena las ventas de cada uno de los 30 días.
    Vector<double> ventasDiarias(30);

    ventasDiarias[0] = 250;
    ventasDiarias[1] = 180;
    ventasDiarias[2] = 320;
    ventasDiarias[3] = 150;
    ventasDiarias[4] = 400;
    ventasDiarias[5] = 275;
    ventasDiarias[6] = 210;
    ventasDiarias[7] = 350;
    ventasDiarias[8] = 290;
    ventasDiarias[9] = 175;
    ventasDiarias[10] = 420;
    ventasDiarias[11] = 310;
    ventasDiarias[12] = 260;
    ventasDiarias[13] = 195;
    ventasDiarias[14] = 380;
    ventasDiarias[15] = 450;
    ventasDiarias[16] = 230;
    ventasDiarias[17] = 315;
    ventasDiarias[18] = 280;
    ventasDiarias[19] = 165;
    ventasDiarias[20] = 390;
    ventasDiarias[21] = 340;
    ventasDiarias[22] = 225;
    ventasDiarias[23] = 300;
    ventasDiarias[24] = 410;
    ventasDiarias[25] = 270;
    ventasDiarias[26] = 185;
    ventasDiarias[27] = 360;
    ventasDiarias[28] = 295;
    ventasDiarias[29] = 430;

    // Vector que almacena las ventas acumuladas de cada producto.
    Vector<int> ventasProductos(5);

    ventasProductos[0] = 120;
    ventasProductos[1] = 250;
    ventasProductos[2] = 180;
    ventasProductos[3] = 310;
    ventasProductos[4] = 200;

    // Calculamos las ventas totales del mes.
    double total = calcularTotal(ventasDiarias);

    // Buscamos el día con menor cantidad de ventas.
    int diaMenor = buscarDiaMenorVenta(ventasDiarias);

    // Buscamos el producto más vendido.
    int productoMayor = buscarProductoMasVendido(ventasProductos);

    cout << "===== ANALISIS DE VENTAS =====" << endl;

    cout << "Ventas totales del mes: "
         << total << " euros" << endl;

    cout << "Dia con menor cantidad de ventas: "
         << diaMenor + 1 << endl;

    cout << "Producto mas vendido: Producto "
         << productoMayor + 1 << endl;

    return 0;
}