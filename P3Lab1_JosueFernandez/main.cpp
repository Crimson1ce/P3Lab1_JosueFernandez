#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/*
 * Laboratorio 1, Programación 3
 * 
 * Josué Fernández, 12011228
 */

int menu(); //Muestra menu
double pi(int); //Devuelve valor de pi
double sigmoide(int); //Calcula funcion Sigmoide
double potencia(double, int); //Calcula una potencia

int main(int argc, char** argv) {

    int opcion = 0;
    int valorX = 0, limite = 0;

    while (opcion != 3) {
        switch (opcion = menu()) {
            case 1://Sigmoide
            {
                cout << "Ejercicio 1: Función Sigmoide" << endl << endl
                        << "Ingrese el valor entero de x: ";
                cin >> valorX;
                cout << endl << endl //Llamamos la funcion sigmoide()
                        << "El valor de la funcion sigmoide  es " << endl
                        << "f(" << valorX << ") = " << sigmoide(valorX) << endl;
                break;
            }
            case 2://Pi
            {
                cout << "Ejercicio 2: Aproximacion de PI" << endl << endl
                        << "Ingrese el valor limite para el calculo: ";
                cin >> limite;
                cout << endl;

                while (limite < 0) {
                    cout << "    El limite para el calculo no puede ser menor a 0. Ingrese de nuevo: ";
                    cin >> limite;
                }

                cout << endl //Llamamos la funcion pi()
                        << "El valor de la aproximacion de pi cuando el limite es "
                        << limite << " es " << pi(limite) << endl;
                break;
            }
            case 3:
            {
                cout << endl << "    Nos vemos!!" << endl;
                break;
            }
        } //Fin de switch
    } //Fin de while
    return 0;
}

/* 
 * Muestra el menú con las opciones a elegir.
 */
int menu() {
    int opcion = 0;

    do {
        cout << endl << "-----MENU-----" << endl
                << "1. Funcion Sigmoide" << endl
                << "2. Aproximacion de Pi" << endl
                << "3. Salir" << endl
                << "Ingrese la opcion que desee: ";
        cin >> opcion;
        if (opcion < 1 || opcion > 3) {
            cout << endl << "    Ha ingresado una opcion invalida. Ingrese de nuevo." << endl;
        }
    } while (opcion < 1 || opcion > 3);

    cout << endl;

    return opcion;
}

/*
 * Calcula el valor de la Función Sigmoide con el valor
 * provisto.
 */
double sigmoide(int valorX) {
    double e = 2.718281828;
    return ( 1 / (1 + potencia(e, -valorX)));
}

/*
 * Calcula el primer número a la potencia del segundo número.
 */
double potencia(double numero, int exponente) {
    if (exponente == 0)
        return 1.0;
    else if (exponente > 0)
        return numero * potencia(numero, exponente - 1);
    else
        return (1.0 / numero) * potencia(numero, exponente + 1);
}

/*
 * Calcula, utilizando el valor tope provisto, una serie 
 * que converge en el valor aproximado de PI y lo retorna.
 */
double pi(int limite) {
    double resultado = 0.0;
    for (int n = 0; n <= limite; n++) {
        int numerador = 0;
        if (n % 2 == 0)
            numerador = 1;
        else
            numerador = -1;
        int denominador = 2 * n + 1;
        resultado += (double) numerador / (double) denominador;
    }
    return 4.0 * resultado;
}