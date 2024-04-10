/*
Nombre de la asignatura: Paradigmas de programacion
NRC: 8150 / Seccion: 558

Leve descripcion: miau

Nombres autores: Maximiliano Cantillana [AGREGAR RUT]
                  Catalina Gamonal [AGREGAR RUT]
                  Valeria apellidoxd [AGREGAR RUT]
                  Liliana Valverde 21.438.525.2
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <string>
using namespace std;

// Definición de constantes para el número máximo de meses y sucursales
const int MAX_MESES = 12, MAX_SUCURSALES = 15;

// Contraseñas para operador y directivo
const string CONTRASENA_OPERADOR = "operador123", CONTRASENA_DIRECTIVO = "directivo456";


class sistema {
protected:
    float mn[12][15]; // Matriz de números reales
    int M; // Número de meses
    int N; // Número de sucursales
    fstream archivo;

public:

    // Método para ingresar las ventas de cada sucursal en cada mes
    void ingresarVentas() {
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << "Ingrese ventas de la sucursal " << j + 1 << " en el mes " << i + 1 << ": ";
                cin >> mn[i][j];
            }
        }
    }

    // Método para mostrar las ventas de cada sucursal en cada mes
    void mostrarVentas() const {
        cout << "\nMontos de venta de " << N << " Sucursales en " << M << " Meses\n";
            for(int i=0;i<N;i++){ // Recorrido por filas
                for(int j=0;j<M;j++){
                    cout << mn[i][j] << "\t";
                }
                cout << "\n";
            }
            cin.get();
    }

    // Método para respaldar los datos de ventas en un archivo
    void respaldarDatos(string nombreArchivo){
            archivo.open(nombreArchivo ,ios::out);
            archivo.close();
            // Se abre en modo de agregación para insertar datos
            archivo.open(nombreArchivo,ios::app);
            // Se guardan los datos pertinentes
            archivo << N << '\n';
            archivo << M << '\n';
            for(int i=0;i<N;i++){ // Recorrido por filas
                for(int j=0;j<M;j++){
                    archivo << mn[i][j] << '\n';
                }
            }
            cout << "Matriz respaldada en archivo..." << '\n';
            archivo.close();
            cin.get();
    }

    void cargar(string nombreArchivo){
        // Se abre el archivo en modo lectura para extraer los datos
        archivo.open(nombreArchivo ,ios::in);
        if (!archivo) // Si se produce un error, el archivo no existe
            cout << "El archivo No existe!!!" << '\n';
        else { // El archivo existe y se extraen los datos pertinentes
            archivo >> N;
            archivo >> M;
            for(int i=0;i<N;i++){ // Recorrido por filas
                for(int j=0;j<M;j++){
                    archivo >> mn[i][j];
                }
            }
            archivo.close();
            cout << "Matriz recuperada desde archivo..." << '\n';
        }
        cin.get();
    }
};



int main() {
    int M, N; // Variables para el número de meses y sucursales
    int opcion;

    cout << "Cosmeticos gatito: Sistema de gestion de ventas." << endl;
    do {
        // Menú principal para seleccionar el tipo de usuario
        cout << "\nSeleccione el tipo de usuario:" << endl;
        cout << "1. Operador" << endl;
        cout << "2. Directivo" << endl;
        cout << "3. Salir del programa" << endl;
        cin >> opcion;


        if (opcion == 1) { // Opción para operador
            string contrasena;
            cout << "\nIngrese la clave de operador: ";
            cin >> contrasena;

            if (contrasena == CONTRASENA_OPERADOR) { // Verificación de la contraseña del operador
                do {
                    cout << "\nIngrese el numero de sucursales (maximo 15): ";
                    cin >> N;
                    if (N < 1 || N > MAX_SUCURSALES) {
                        cout << "El numero de sucursales debe estar entre 1 y 15!!!" << endl;
                    }
                } while (N < 1 || N > MAX_SUCURSALES);

                do {
                    cout << "Ingrese el numero de meses (maximo 12): ";
                    cin >> M;
                    if (M < 1 || M > MAX_MESES) {
                        cout << "El numero de meses debe estar entre 1 y 12!!!" << endl;
                    }
                } while (M < 1 || M > MAX_MESES);

                sistema Sistema;
                Sistema.ingresarVentas();
                Sistema.mostrarVentas();

                string nombreArchivo;
                cout << "\nDesea respaldar los datos en un archivo? (S/N): ";
                char respuesta;
                cin >> respuesta;
                if (respuesta == 'S' || respuesta == 's') {
                    cout << "Ingrese el nombre del archivo para respaldar los datos: ";
                    cin >> nombreArchivo;
                    Sistema.respaldarDatos(nombreArchivo);
                }
            } else {
                cout << "\nINCORRECTO, ACCESO DENEGADO." << endl;
            }
        } else if (opcion == 2) { // Opción para directivo
            string contrasena;
            cout << "\nIngrese la clave de directivo: ";
            cin >> contrasena;

            if (contrasena == CONTRASENA_DIRECTIVO) { // Verificación de la contraseña del directivo
                cout << "\nFuncionalidad del Directivo aun no implementada miau :33" << endl;
            } else {
                cout << "\nINCORRECTO, ACCESO DENEGADO." << endl;
            }
        } else if (opcion != 3) { // Opción para salir del programa
            cout << "\nOpcion invalida. Por favor, seleccione una opcion valida." << endl;
        }
    } while (opcion != 3); // El bucle continúa hasta que se selecciona la opción de salir del programa

    return 0;
}
