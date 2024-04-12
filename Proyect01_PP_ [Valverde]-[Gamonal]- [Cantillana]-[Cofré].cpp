/*
Nombre de la asignatura: Paradigmas de programacion
NRC: 8150 / Seccion: 558

Leve descripcion: miau

Nombres autores:  Maximiliano Cantillana 21.141.918-0
                  Catalina Gamonal [AGREGAR RUT]
                  Valeria apellidoxd [AGREGAR RUT]
                  Liliana Valverde 21.438.525.2
*/

#include <iostream>
#include <fstream>
using namespace std;

const string CONTRASENA_OPERADOR = "operador123", CONTRASENA_DIRECTIVO = "directivo456";

class Datos {
public:
    float MONTO[12][15]; // Matriz de números reales
    int M; // Número de meses
    int N; // Número de sucursales
    Datos() {
        M = 0;
        N = 0;
        for (int i = 0; i < 12; i++) { // Inicialización de la matriz
            for (int j = 0; j < 15; j++) {
                MONTO[i][j] = 0.0;
            }
        }
    }

    // Método para ingresar las ventas de cada sucursal en cada mes
    void ingresarVentas() {
        do {
            cout << "\nIngrese el numero de sucursales (maximo 15): ";
            cin >> N;
            if (N < 1 || N > 15) {
                cout << "El numero de sucursales debe estar entre 1 y 15!!!" << endl;
            }
        } while (N < 1 || N > 15);

        do {
            cout << "\nIngrese el numero de meses (maximo 12): ";
            cin >> M;
            if (M < 1 || M > 12) {
                cout << "El numero de meses debe estar entre 1 y 12!!!" << endl;
            }
        } while (M < 1 || M > 12);

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << "\nIngrese ventas de la sucursal " << j + 1 << " en el mes " << i + 1 << ": ";
                cin >> MONTO[i][j];
            }
        }
    }

    // Método para mostrar las ventas de cada sucursal en cada mes
    void mostrarVentas() {
        cout << "\nGanancias de " << N << " sucursales en " << M << " meses\n";
        cout << "\t\t";
        for (int i = 0; i < M; i++) { // Mostrar encabezados de meses
            cout << "mes " << i + 1 << "\t";
        }
        cout << endl;

        for (int i = 0; i < N; i++) { // Recorrido por columnas (sucursales)
            cout << "sucursal " << i + 1 << "\t";
            for (int j = 0; j < M; j++) { // Recorrido por filas (meses)
                cout << MONTO[j][i] << "\t";
            }
            cout << endl;
        }
    }
    void gestionVentas() {

        float mayor = 0;
        int posicion;

        cout <<"\nCosmeticos Gatito: Sistema de gestion de ventas\n";
        cout <<"\nMontos de ventas de " << N << " sucursales en " << M << " meses\n";
        cout <<"\t\t";
        for (int i = 0; i < M; i++) { // Mostrar encabezados de meses
            cout << "Mes " << i + 1 << "\t";
        }
        cout << endl;
        for (int i = 0; i < N; i++) { // Recorrido por columnas (sucursales)
            cout << "Sucursal " << i + 1 << "\t";
            for (int j = 0; j < M; j++) { // Recorrido por filas (meses)
                cout << MONTO[j][i] << "\t";
            }
            cout << endl;
        }
        cout << endl;
        cout <<"Monto de ventas por sucursales:\n";
        for (int j = 0; j < N; j++) {
            int suma = 0; // Inicializa la suma para cada fila

            // Itera sobre cada elemento de la fila actual
            for (int i = 0; i < M; i++) {
                suma += MONTO[i][j]; // Suma el elemento actual al total de la fila
            }

            // Imprime la suma de la fila actual
            cout << "Monto de ventas de la Sucursal " << j+1 << " : " << suma << endl;
        }
        cout << endl;
        cout << "Promedio de ventas por cada mes:\n";

        float promedio, promedios[M];

        for (int i = 0; i < M; i++) {
            int suma = 0; // Inicializa la suma para cada fila

            // Itera sobre cada elemento de la fila actual
            for (int j = 0; j < N; j++) {
                suma += MONTO[i][j]; // Suma el elemento actual al total de la fila
            }

            promedio = (suma/N);
            promedios[i] = promedio;

            // Imprime la suma de la fila actual
            cout << "Promedio de ventas del mes " << i+1 << " : " << promedio << endl;
            suma = 0;
        }
        for (int i = 0; i < M; i++){

            if (promedios[i] > mayor){
                mayor = promedios[i];
                posicion = i;
            }
        }
        cout <<"Mes con mayor promedio: el Numero " << posicion + 1 << " con un promedio de: " << mayor << endl;
    }
};
class Archivo {
private:
    fstream archivo; // Archivo para el respaldo de datos
public:
    void respaldar(int M, int N, float MONTO[12][15]) {
        char respuesta;
        cout << "¿Desea respaldar los datos en un archivo? (s/n): ";
        cin >> respuesta;

        if (respuesta == 's' || respuesta == 'S') {
            archivo.open("archivo_respaldo.txt",ios::out);
            archivo.close();
            archivo.open("archivo_respaldo.txt",ios::app);
            archivo << M << '\n';
            archivo << N << '\n';
            for(int i=0; i<M; i++){ // Recorrido por filas
                for(int j=0; j<N; j++){
                    archivo << MONTO[i][j] << '\n';
                }
            }
            archivo.close();
            cout << "Los datos han sido exitosamente guardados..." << endl;
        } else {
            cout << "Los datos no se han guardado." << endl;
        }
        cin.ignore();
        cin.get();
    }

    void LeerDatos(int& M, int& N, float MONTO[12][15]){

            archivo.open("archivo_respaldo.txt" ,ios::in);
            if (!archivo)
                cout << "El archivo no existe" << '\n';
            else {
                archivo >> N;
                archivo >> M;
                for(int j=0;j<N;j++){ // Recorrido por filas
                    for(int i=0;i<M;i++){
                        archivo >> MONTO[i][j];
                    }
                }
                archivo.close();
                cout << "\nDatos recuperados desde respaldo..." << '\n';
            }
            cin.get();
        }
};

int main() {
    int opcion;
    Datos om; // Objeto matriz
    Archivo oa; // Objeto archivo

    cout << "Cosmeticos Gatito: Sistema de gestion de ventas." << endl;

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
                om.ingresarVentas();
                om.mostrarVentas();
                oa.respaldar(om.M,om.N,om.MONTO);
            }
            else {
                cout << "\nINCORRECTO, ACCESO DENEGADO." << endl;
            }
        }
        else if (opcion == 2) { // Opción para directivo
            string contrasena;
            cout << "\nIngrese la clave de directivo: ";
            cin >> contrasena;

            if (contrasena == CONTRASENA_DIRECTIVO) { // Verificación de la contraseña del directivo
                oa.LeerDatos(om.M, om.N, om.MONTO);
                om.gestionVentas();
            }
            else {
                cout << "\nINCORRECTO, ACCESO DENEGADO." << endl;
            }
        }
        else if (opcion != 3) { // Opción para salir del programa
            cout << "\nOpcion invalida. Por favor, seleccione una opcion valida." << endl;
        }
    } while (opcion != 3); // El bucle continúa hasta que se selecciona la opción de salir del programa

    return 0;
}
