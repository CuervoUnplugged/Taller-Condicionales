#include <iostream>
using namespace std;

int main() {
    double montoTotal;
    int numPersonas;
    int cantidadProductos;
    double precioUnitario;
    char operacion;

    cout << "Ingrese el monto total a cobrar: ";
    cin >> montoTotal;
    while (montoTotal < 0) {
        cout << "Monto inválido. Ingrese un monto positivo: ";
        cin >> montoTotal;
    }

    cout << "Ingrese el número de personas para dividir el monto: ";
    cin >> numPersonas;
    while (numPersonas <= 0) {
        cout << "Número inválido. Debe ser mayor que cero: ";
        cin >> numPersonas;
    }

    double costoPorPersona = montoTotal / numPersonas;
    cout << "Costo por persona: $" << costoPorPersona << endl;

    cout << "Ingrese la cantidad de productos: ";
    cin >> cantidadProductos;
    while (cantidadProductos <= 0) {
        cout << "Cantidad inválida. Debe ser mayor que cero: ";
        cin >> cantidadProductos;
    }

    cout << "Ingrese el precio unitario de cada producto: ";
    cin >> precioUnitario;
    while (precioUnitario < 0) {
        cout << "Precio inválido. Debe ser positivo: ";
        cin >> precioUnitario;
    }

    double costoTotalProductos = cantidadProductos * precioUnitario;
    cout << "Costo total de los productos: $" << costoTotalProductos << endl;

    cout << "Ingrese la operación a realizar (+, -, *, /): ";
    cin >> operacion;
    while (operacion != '+' && operacion != '-' && operacion != '*' && operacion != '/') {
        cout << "Operación inválida. Ingrese uno de los símbolos (+, -, *, /): ";
        cin >> operacion;
    }

    double resultado;
    if (operacion == '+') {
        resultado = montoTotal + costoTotalProductos;
        cout << "Resultado de la suma: $" << resultado << endl;
    } else if (operacion == '-') {
        resultado = montoTotal - costoTotalProductos;
        cout << "Resultado de la resta: $" << resultado << endl;
    } else if (operacion == '*') {
        resultado = montoTotal * costoTotalProductos;
        cout << "Resultado de la multiplicación: $" << resultado << endl;
    } else { // división
        if (costoTotalProductos == 0) {
            cout << "Error: División por cero no permitida." << endl;
        } else {
            resultado = montoTotal / costoTotalProductos;
            cout << "Resultado de la división: $" << resultado << endl;
        }
    }

    return 0;
}
