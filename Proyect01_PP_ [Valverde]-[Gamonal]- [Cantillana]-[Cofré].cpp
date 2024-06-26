/*
Nombre de la asignatura: Paradigmas de programacion
NRC: 8150 / Seccion: 558

Leve descripcion: El código es un sistema de gestión de ventas diseñado para una empresa de cosméticos. Ofrece dos opciones de usuario: Operador y Directivo. Los operadores ingresan y respaldan datos de ventas por mes y sucursal. Los directivos pueden leer estos datos respaldados y acceder a estadísticas como la suma de ventas por sucursal, los promedios de ventas mensuales y el mes con el mayor promedio de ventas.

Nombres autores:  Maximiliano Cantillana 21.141.918-0
                  Catalina Gamonal [AGREGAR RUT]
                  Valeria Cofré [AGREGAR RUT]
                  Liliana Valverde 21.438.525.2
*/

#include <iostream>
#include <fstream> //Incluye libreria que permite el manejo de archivos
using namespace std;

const string CONTRASENA_OPERADOR = "operador123", CONTRASENA_DIRECTIVO = "directivo456"; // Declaración de constantes para contraseñas de operador y directivo

class Datos {// Definición de la clase Datos
public:
    float MONTO[12][15]; // Definicion de matriz 'MONTO' en donde se almancenan los datos
    int M; // Definicion de variable 'meses' como M
    int N; // Definicion de variable 'sucursales' como N
    Datos() { // Constructor de la clase Datos
        M = 0;
        N = 0;
        for (int i = 0; i < 12; i++) { //Construccion de la matriz 'MONTO'
            for (int j = 0; j < 15; j++) {
                MONTO[i][j] = 0.0;
            }
        }
    }

    void ingresarVentas() { // Definicion método para ingresar las ventas de cada sucursal en cada mes como 'ingresarVentas'
        do { //Inicio de un bucle do-while
            cout << "\nIngrese el numero de sucursales (maximo 15): ";
            cin >> N; //Registro numero de sucursales ingresado por el operador
            if (N < 1 || N > 15) { // Comprueba si el número de meses está fuera del rango permitido
                cout << "El numero de sucursales debe estar entre 1 y 15!!!" << endl;
            }
        } while (N < 1 || N > 15); // El bucle funcionara si el número de meses esta dentro del rango permitido

        do {
            cout << "\nIngrese el numero de meses (maximo 12): ";
            cin >> M; //Registro numero de meses ingresado por el operador
            if (M < 1 || M > 12) { // Comprueba si el número de meses está fuera del rango permitido
                cout << "El numero de meses debe estar entre 1 y 12!!!" << endl;
            }
        } while (M < 1 || M > 12); // El bucle funcionara si el número de sucursales esta dentro del rango permitido

        for (int i = 0; i < M; ++i) { // Bucle para ingresar las ventas de cada sucursal en cada mes
            for (int j = 0; j < N; ++j) {
                cout << "\nIngrese ventas de la sucursal " << j + 1 << " en el mes " << i + 1 << ": ";
                cin >> MONTO[i][j]; //Se registran los datos ingresados por el operador y se almacenan en la matriz MONTO
            }
        }
    }

    void mostrarVentas() { // Definicion del metodo para mostrar las ventas de cada sucursal en cada mes como 'mostrarVentas'
        cout << "\nGanancias de " << N << " sucursales en " << M << " meses\n";
        cout << "\t\t";
        for (int i = 0; i < M; i++) { //  Recorrido por filas para mostrar encabezados de meses de manera horizontal
            cout << "mes " << i + 1 << "\t";
        }
        cout << endl;

        for (int i = 0; i < N; i++) { // Recorrido por columnas para mostrar encabezados de sucursales de manera vertical
            cout << "sucursal " << i + 1 << "\t";
            for (int j = 0; j < M; j++) { // Recorrido por la matriz 'MONTO' para mostrar las ventas de cada sucursal por mes
                cout << MONTO[j][i] << "\t";
            }
            cout << endl;
        }
    }
    void gestionVentas() {

        float mayor = 0; // Declaración de variables utilizadas para calcular el apartado de promedios
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

            for (int i = 0; i < M; i++) {
                suma += MONTO[i][j]; // Suma el elemento actual al total de la fila
            }
            cout << "Monto de ventas de la Sucursal " << j+1 << " : " << suma << endl; // Imprime la suma de la fila actual
        }
        cout << endl;
        cout << "Promedio de ventas por cada mes:\n";

        float promedio, promedios[M]; //Se define un arreglo para almacenar los promedios de cada mes y poder trabajar con ellos

        for (int i = 0; i < M; i++) {
            int suma = 0; // Inicializa la suma para cada fila

            for (int j = 0; j < N; j++) {
                suma += MONTO[i][j]; // Suma el elemento actual al total de la columna
            }

            promedio = (suma/N);    // Se divide la suma total de la fila 
            promedios[i] = promedio; // Se almacena el promedio de cadda fila en el arreglo promedios

            // Imprime el promedio de cada mes 
            cout << "Promedio de ventas del mes " << i+1 << " : " << promedio << endl;
            suma = 0;
        }
        for (int i = 0; i < M; i++){    // Ciclo que recorre el arreglo promedios para buscar el promedio mayor 

            if (promedios[i] > mayor){
                mayor = promedios[i];   // Busca el promedio mayor y guarda la posicion de este para saber cual es el mes con mayor promedio
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
    void respaldar(int M, int N, float MONTO[12][15]) {  // Funcion que permite respaldar los datos de la matriz en un archivo de texto
        char respuesta;
        cout << "¿Desea respaldar los datos en un archivo? (s/n): ";
        cin >> respuesta;

        if (respuesta == 's' || respuesta == 'S') {
            archivo.open("archivo_respaldo.txt",ios::out);
            archivo.close();
            archivo.open("archivo_respaldo.txt",ios::app);
            archivo << M << '\n';
            archivo << N << '\n';
            for(int i=0; i<M; i++){ // Recorrido por filas para almacenar los datos uno por uno en el archivo de texto
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

    void LeerDatos(int& M, int& N, float MONTO[12][15]){  // Funcion que permite leer los datos del archivo de texto de respaldo y almacenarlos en matriz MONTO

            archivo.open("archivo_respaldo.txt" ,ios::in);
            if (!archivo)
                cout << "El archivo no existe" << '\n';
            else {
                archivo >> N; // se leen los dos primeros numeros del archivo lo cual indica las dimensiones de la matriz
                archivo >> M;
                for(int j=0;j<N;j++){ // Recorrido por columnas
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
    Datos om; // Creación de objeto matriz
    Archivo oa; // Creación de objeto archivo

    cout << "Cosmeticos Gatito: Sistema de gestion de ventas." << endl;

    do {
        // Menú principal para seleccionar el tipo de usuario o salir del programa
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
                om.ingresarVentas(); // llamada del metodo para ingresar las ventas en la matriz
                om.mostrarVentas();  // llamada del metodo que muestra las ventas por pantalla
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
                oa.LeerDatos(om.M, om.N, om.MONTO);   // llamada del metodo que lee y almacena los datos del archivo de respaldo en la matriz nuevamente
                om.gestionVentas(); //llamada de la función que muestra por pantalla toda la información necesaria para el perfil de Directivo
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
