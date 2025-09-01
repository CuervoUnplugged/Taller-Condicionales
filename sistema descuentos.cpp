#include <iostream>
#include <string>
using namespace std;

int main() {
    string tipoCliente;
    int cantidadProductos;
    double precioUnitario;

    cout << "Ingrese tipo de cliente (VIP o regular): ";
    getline(cin, tipoCliente);

    // Convertir a minúsculas para comparación simple
    for (char &c : tipoCliente) {
        c = tolower(c);
    }

    while (tipoCliente != "vip" && tipoCliente != "regular") {
        cout << "Tipo inválido. Ingrese 'VIP' o 'regular': ";
        getline(cin, tipoCliente);
        for (char &c : tipoCliente) {
            c = tolower(c);
        }
    }

    cout << "Ingrese cantidad de productos: ";
    cin >> cantidadProductos;
    while (cantidadProductos <= 0) {
        cout << "Cantidad inválida. Ingrese un número positivo: ";
        cin >> cantidadProductos;
    }

    cout << "Ingrese precio unitario: $";
    cin >> precioUnitario;
    while (precioUnitario <= 0) {
        cout << "Precio inválido. Ingrese un valor positivo: $";
        cin >> precioUnitario;
    }

    double totalSinDescuento = cantidadProductos * precioUnitario;
    double descuento = 0.0;

    if (tipoCliente == "vip") {
        descuento = 0.20; // 20%
    } else if (tipoCliente == "regular" && cantidadProductos >= 4) {
        descuento = 0.10; // 10%
    }

    double montoDescuento = totalSinDescuento * descuento;
    double totalConDescuento = totalSinDescuento - montoDescuento;

    cout.precision(2);
    cout << fixed;
    cout << "\nTotal sin descuento: $" << totalSinDescuento << endl;
    cout << "Descuento aplicado: " << (descuento * 100) << "% ($" << montoDescuento << ")" << endl;
    cout << "Total a pagar: $" << totalConDescuento << endl;

    return 0;
}
