//Librerías para trabajar en el proyecto
#include <iostream>
#include <string>
//Definir tipo de espacio a utilizar (ya no es necesario utilizar std::)
using namespace std;
/*
Declaración de clases
*/
//Clase Cuentahabiente
class Cuentahabiente {
public:
    string nombreCompleto;
    int edad;
    int anosCuentahabiente;
    // Constructor para inicializar los datos del Cuentahabiente
    Cuentahabiente() {
        cout << "*** DATOS DEL CUENTAHABIENTE ***" << endl;
        cout << "Ingresa tu nombre: ";
        getline(cin, nombreCompleto);
        cout << "Ingresa tu edad: ";
        cin >> edad;
        cout << "Ingresa tus años en el banco: ";
        cin >> anosCuentahabiente;
    }
};

// Definición de la clase Cuenta
class Cuenta {
public:
    long numeroCuenta;
    long cantidadTotalEfectivo;
    bool estadoCuenta;

    // Constructor para inicializar los datos de la Cuenta
    Cuenta() {
        cout << "*** DATOS DE LA CUENTA ***" << endl;
        cout << "Ingresa el número de cuenta: ";
        cin >> numeroCuenta;
        cout << "Ingresa la cantidad total de efectivo: ";
        cin >> cantidadTotalEfectivo;
        estadoCuenta = (cantidadTotalEfectivo >= 3000); // Calcula el estado de la cuenta

        // Verifica el estado de la cuenta
        if (estadoCuenta) {
            cout << "*** Su cuenta está activa ***" << endl;
        } else {
            cout << "*** Su cuenta no posee el capital mínimo para registro ***" << endl;
            exit(0); // Termina la ejecución del programa
        }
    }
};

// Definición de la clase Transaccion
class Transaccion {
public:
    long numeroTransaccion;
    char tipoTransaccion;
    string operacionTransaccion;
    int cantidadTransaccion;

    // Constructor para inicializar los datos de la Transacción
    Transaccion(long numero) {
      cout << "*** DATOS DE LA CUENTA ***" << endl;
        cout << "Ingresa el número de transacción: ";
        cin >> numeroTransaccion;
        cout << "Ingresa el tipo de transacción (R para retiro, D para depósito): ";
        cin >> tipoTransaccion;
        cout << "Ingresa el concepto de la transacción: ";
        getline(cin, operacionTransaccion);
        cout << "Ingresa la cantidad de la transacción: ";
        cin >> cantidadTransaccion;
    }
};

int main() {
    char repetir;
    do {
        //Creación de objetos
        Cuentahabiente cuentahabiente;
        Cuenta cuenta;
        Transaccion transaccion1(1);
        Transaccion transaccion2(2);
        Transaccion transaccion3(3);

        // Realizar las operaciones de depósito o retiro según el tipo de transacción
        cuenta.cantidadTotalEfectivo += (transaccion1.tipoTransaccion == 'D') ? transaccion1.cantidadTransaccion : -transaccion1.cantidadTransaccion;
        cuenta.cantidadTotalEfectivo += (transaccion2.tipoTransaccion == 'D') ? transaccion2.cantidadTransaccion : -transaccion2.cantidadTransaccion;
        cuenta.cantidadTotalEfectivo += (transaccion3.tipoTransaccion == 'D') ? transaccion3.cantidadTransaccion : -transaccion3.cantidadTransaccion;

        // Mostrar el balance de la cuenta
        cout << "*** EL BALANCE DE SU CUENTA ES EL SIGUIENTE ***" << endl;
        cout << "Cuenta: " << cuenta.numeroCuenta << endl;
        cout << "Saldo anterior: " << cuenta.cantidadTotalEfectivo + (transaccion1.tipoTransaccion == 'D' ? -transaccion1.cantidadTransaccion : transaccion1.cantidadTransaccion) + (transaccion2.tipoTransaccion == 'D' ? -transaccion2.cantidadTransaccion : transaccion2.cantidadTransaccion) + (transaccion3.tipoTransaccion == 'D' ? -transaccion3.cantidadTransaccion : transaccion3.cantidadTransaccion) << endl;
        cout << "Saldo actual: " << cuenta.cantidadTotalEfectivo << endl;

        // Preguntar al usuario si desea repetir el proceso
        cout << "¿Desea repetir el proceso? (S para sí, cualquier otra tecla para salir): ";
        cin >> repetir;

    } while (repetir == 'S' || repetir == 's');

    return 0;
}
