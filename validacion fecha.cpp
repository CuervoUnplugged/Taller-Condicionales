#include <iostream>
#include <ctime>
using namespace std;

bool esBisiesto(int anio) {
    return (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0));
}

int diasEnMes(int mes, int anio) {
    if (mes == 2) {
        return esBisiesto(anio) ? 29 : 28;
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return 30;
    } else if (mes >= 1 && mes <= 12) {
        return 31;
    } else {
        return 0; // mes inválido
    }
}

bool fechaValida(int dia, int mes, int anio) {
    if (anio < 1900 || mes < 1 || mes > 12) return false;
    int maxDias = diasEnMes(mes, anio);
    if (dia < 1 || dia > maxDias) return false;

    time_t t = time(nullptr);
    tm* fechaActual = localtime(&t);
    int anioActual = fechaActual->tm_year + 1900;
    int mesActual = fechaActual->tm_mon + 1;
    int diaActual = fechaActual->tm_mday;

    if (anio > anioActual) return false;
    if (anio == anioActual && mes > mesActual) return false;
    if (anio == anioActual && mes == mesActual && dia > diaActual) return false;

    return true;
}

int main() {
    int dia, mes, anio;

    cout << "Ingrese día de nacimiento: ";
    cin >> dia;
    cout << "Ingrese mes de nacimiento: ";
    cin >> mes;
    cout << "Ingrese año de nacimiento: ";
    cin >> anio;

    if (!fechaValida(dia, mes, anio)) {
        cout << "Fecha inválida. Por favor ingrese una fecha correcta." << endl;
        return 1;
    }

    time_t t = time(nullptr);
    tm* fechaActual = localtime(&t);
    int mesActual = fechaActual->tm_mon + 1;

    if (mes == mesActual) {
        cout << "¡Feliz cumpleaños! Usted es elegible para la promoción." << endl;
    } else {
        cout << "No cumple años este mes. No es elegible para la promoción." << endl;
    }

    return 0;
}
