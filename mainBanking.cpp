#include <iostream>
#include <string>

using namespace std;

// Definición de la clase CuentaHabiente
class CuentaHabiente {
public:
  string nombre;
  int edad;
  int anosCuentaHabiente;

  // Método para obtener datos del cuentahabiente
  void obtenerDatos();
};

// Definición de la clase Cuenta
class Cuenta {
public:
  int numeroCuenta;
  long efectivoTotal;
  bool estadoCuenta;

  // Métodos para obtener datos, definir estado y mostrar estado de la cuenta
  void obtenerDatos();
  void definirEstado();
  void mostrarEstado();
};

// Definición de la clase Transaccion
class Transaccion {
public:
  Cuenta *balanceEfectivo; // Referencia a un objeto de la clase Cuenta, el cuál
                           // modificará el total de efectivo del usuario
  long numeroTransaccion;
  string conceptoTransaccion;
  char tipoTransaccion;
  int cantidadTransaccion;

  // Métodos para obtener datos, definir tipo de transacción y realizar
  // operación
  void obtenerDatos();
  void definirTipoTrans();
  void operar();
};

// Método de la clase Transaccion para realizar operación según el tipo
void Transaccion::operar() {
  if (tipoTransaccion == 'D') {
    balanceEfectivo->efectivoTotal += cantidadTransaccion;
  } else if (tipoTransaccion == 'R') {
    balanceEfectivo->efectivoTotal -= cantidadTransaccion;
  }
}

// Función para preguntar al usuario si desea repetir el programa
bool repetirProceso() {
  char respuesta;
  cout << "¿Desea repetir el proceso? (S para sí, N para no): ";
  cin >> respuesta;
  return (respuesta == 'S' || respuesta == 's');
}

// Método de la clase CuentaHabiente para obtener datos del cuentahabiente
void CuentaHabiente::obtenerDatos() {
  cout << "*** DATOS DEL CUENTAHABIENTE ***" << endl;
  cout << "Ingresa tu nombre: ";
  getline(cin, nombre);
  cout << "Ingresa tu edad: ";
  cin >> edad;
  cout << "Ingresa los años que llevas en la cuenta: ";
  cin >> anosCuentaHabiente;
}

// Método de la clase Cuenta para obtener datos de la cuenta
void Cuenta::obtenerDatos() {
  cout << "*** DATOS DE LA CUENTA ***" << endl;
  cout << "Ingresa tu numero de cuenta: ";
  cin >> numeroCuenta;
  cout << "Ingresa tu efectivo total: ";
  cin >> efectivoTotal;
}

// Método de la clase Cuenta para definir el estado de la cuenta
void Cuenta::definirEstado() {
  estadoCuenta = (efectivoTotal >= 3000); // Tiene que ser mayor a 3000 para que
                                          // realizar las acciones posteriores
}

// Método de la clase Cuenta para mostrar el estado de la cuenta
void Cuenta::mostrarEstado() {
  switch (estadoCuenta) {
  case true:
    cout << "*** Su cuenta está activa ***" << endl;
    break;
  case false:
    cout << "*** Su cuenta no posee el capital mínimo para registro, lo siento "
            "***"
         << endl;
    exit(0);
  }
}

// Método de la clase Transaccion para obtener datos de la transacción
void Transaccion::obtenerDatos() {
  cout << "Ingresa el número de transacción: ";
  cin >> numeroTransaccion;
  cin.ignore();
  cout << "Ingresa el concepto de la transacción: ";
  getline(cin, conceptoTransaccion);
  cout << "Ingresa la cantidad de la transacción: ";
  cin >> cantidadTransaccion;
}

// Método de la clase Transaccion para definir el tipo de transacción
void Transaccion::definirTipoTrans() {
  if (tipoTransaccion != 'D' && tipoTransaccion != 'R') {
    cout << "Tipo de transacción no válido. Terminando el programa." << endl;
    exit(1);
  }
}

// Función principal (main) del programa
int main() {
  // Bucle principal para permitir repetir el proceso
  do {
    // Crear objeto CuentaHabiente
    CuentaHabiente cuentahabiente;
    cuentahabiente.obtenerDatos();

    // Crear objeto Cuenta e invocar a todos sus métodos
    Cuenta cuenta;
    cuenta.obtenerDatos();
    cuenta.definirEstado();
    cuenta.mostrarEstado();

    // Bucle para obtener datos y realizar 3 transacciones
    for (int i = 1; i <= 3; ++i) {
      Transaccion *transaccion; // Crear objeto transaccion

      // Solicitar que se ingrese el tipo de transacción
      char tipo;
      cout << "Ingrese el tipo de transacción para la transacción " << i
           << " (D para depósito, R para retiro): ";
      cin >> tipo;

      // Crear instancia de Transaccion según si es un Depósito o Retiro
      switch (tipo) {
      case 'D':
      case 'd':
        transaccion = new Transaccion();
        transaccion->tipoTransaccion = 'D';
        break;
      case 'R':
      case 'r':
        transaccion = new Transaccion();
        transaccion->tipoTransaccion = 'R';
        break;
      default:
        cout << "Tipo de transacción no válido. Terminando el programa."
             << endl;
        return 1;
      }

      // Invocar los métodos de la clase Transaccion
      transaccion->balanceEfectivo = &cuenta;
      transaccion->obtenerDatos();
      transaccion->definirTipoTrans();
      transaccion->operar();

      delete transaccion; // Destrucción del objeto
    }

    // Mostrar información de la cuenta después de las operaciones (Depósito o
    // Retiro)
    cout << "*** INFORMACIÓN DE LA CUENTA DESPUÉS DE OPERACIONES ***" << endl;
    cout << "Número de cuenta: " << cuenta.numeroCuenta << endl;
    cout << "Efectivo total: " << cuenta.efectivoTotal << endl;

    // Invocar las funciones de la clase Cuenta
    cuenta.definirEstado();
    cuenta.mostrarEstado();
  }

  while (repetirProceso()); // Repetir el programa si el usuario lo desea

  return 0;
}
