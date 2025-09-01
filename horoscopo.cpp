#include <iostream>
using namespace std;

bool fechaValida(int dia, int mes) {
    if (mes < 1 || mes > 12) return false;
    int diasMes[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (dia < 1 || dia > diasMes[mes - 1]) return false;
    return true;
}

string signoZodiacal(int dia, int mes) {
    if ((mes == 12 && dia >= 22) || (mes == 1 && dia <= 19)) return "Capricornio";
    else if ((mes == 1 && dia >= 20) || (mes == 2 && dia <= 18)) return "Acuario";
    else if ((mes == 2 && dia >= 19) || (mes == 3 && dia <= 20)) return "Piscis";
    else if ((mes == 3 && dia >= 21) || (mes == 4 && dia <= 19)) return "Aries";
    else if ((mes == 4 && dia >= 20) || (mes == 5 && dia <= 20)) return "Tauro";
    else if ((mes == 5 && dia >= 21) || (mes == 6 && dia <= 20)) return "Géminis";
    else if ((mes == 6 && dia >= 21) || (mes == 7 && dia <= 22)) return "Cáncer";
    else if ((mes == 7 && dia >= 23) || (mes == 8 && dia <= 22)) return "Leo";
    else if ((mes == 8 && dia >= 23) || (mes == 9 && dia <= 22)) return "Virgo";
    else if ((mes == 9 && dia >= 23) || (mes == 10 && dia <= 22)) return "Libra";
    else if ((mes == 10 && dia >= 23) || (mes == 11 && dia <= 21)) return "Escorpio";
    else if ((mes == 11 && dia >= 22) || (mes == 12 && dia <= 21)) return "Sagitario";
    return "Fecha inválida";
}

int main() {
    int dia, mes;
    cout << "Ingrese día de nacimiento: ";
    cin >> dia;
    cout << "Ingrese mes de nacimiento: ";
    cin >> mes;

    if (!fechaValida(dia, mes)) {
        cout << "Fecha inválida." << endl;
        return 1;
    }

    cout << "Su signo zodiacal es: " << signoZodiacal(dia, mes) << endl;
    return 0;
}