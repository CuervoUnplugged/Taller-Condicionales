#include <iostream>
#include <string>
using namespace std;

bool validarPIN(const string& pin) {
    if (pin.length() != 4) return false;
    for (char c : pin)
        if (c < '0' || c > '9') return false;
    return true;
}

int main() {
    const string PIN_CORRECTO = "1234";
    double saldo = 1000.0;
    string pin;
    int intentos = 0;

    while (intentos < 3) {
        cout << "Ingrese su PIN de 4 dígitos: ";
        cin >> pin;
        if (validarPIN(pin) && pin == PIN_CORRECTO) {
            cout << "PIN correcto. Acceso concedido.\n";
            break;
        }
        cout << "PIN inválido o incorrecto.\n";
        intentos++;
    }

    if (intentos == 3) {
        cout << "Cuenta bloqueada por demasiados intentos.\n";
        return 1;
    }

    int opcion = 0;
    while (opcion != 3) {
        cout << "\n1. Consultar saldo\n2. Retirar dinero\n3. Salir\nSeleccione opción: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "Saldo: $" << saldo << "\n";
        } else if (opcion == 2) {
            double monto;
            cout << "Monto a retirar: $";
            cin >> monto;
            if (monto > 0 && monto <= saldo) {
                saldo -= monto;
                cout << "Retiro exitoso. Nuevo saldo: $" << saldo << "\n";
            } else {
                cout << "Monto inválido o saldo insuficiente.\n";
            }
        } else if (opcion != 3) {
            cout << "Opción inválida.\n";
        }
    }

    cout << "Gracias por usar el cajero.\n";
    return 0;
}
