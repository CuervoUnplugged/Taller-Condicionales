#include <iostream>
using namespace std;

bool horaValida(int h, int m) {
    return (h >= 0 && h <= 23) && (m >= 0 && m <= 59);
}

int main() {
    int hEntrada, mEntrada, hSalida, mSalida;

    cout << "Ingrese hora de entrada (0-23): ";
    cin >> hEntrada;
    cout << "Ingrese minutos de entrada (0-59): ";
    cin >> mEntrada;

    if (!horaValida(hEntrada, mEntrada)) {
        cout << "Hora de entrada inválida." << endl;
        return 1;
    }

    cout << "Ingrese hora de salida (0-23): ";
    cin >> hSalida;
    cout << "Ingrese minutos de salida (0-59): ";
    cin >> mSalida;

    if (!horaValida(hSalida, mSalida)) {
        cout << "Hora de salida inválida." << endl;
        return 1;
    }

    // Convertir todo a minutos desde medianoche
    int entradaMin = hEntrada * 60 + mEntrada;
    int salidaMin = hSalida * 60 + mSalida;

    // Si salida es menor que entrada, se asume que es al día siguiente
    if (salidaMin < entradaMin) {
        salidaMin += 24 * 60;
    }

    int duracion = salidaMin - entradaMin;
    int horasTrabajadas = duracion / 60;
    int minutosTrabajados = duracion % 60;

    cout << "Tiempo trabajado: " << horasTrabajadas << " horas y " << minutosTrabajados << " minutos." << endl;

    return 0;
}
