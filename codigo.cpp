#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Estructura para almacenar información de los libros
struct Libro {
    string titulo;
    int copiasDisponibles;
};

// Función para mostrar todos los libros
void mostrarLibros(const vector<Libro>& libros) {
    cout << "Lista de libros:\n";
    for (size_t i = 0; i < libros.size(); ++i) {
        cout << i + 1 << ". " << libros[i].titulo
             << " (Copias disponibles: " << libros[i].copiasDisponibles << ")\n";
    }
}

// Función para reservar un libro
void reservarLibro(vector<Libro>& libros, int indice) {
    if (indice >= 1 && indice <= libros.size() && libros[indice - 1].copiasDisponibles > 0) {
        libros[indice - 1].copiasDisponibles--;
        cout << "El libro \"" << libros[indice - 1].titulo << "\" ha sido reservado.\n";
    } else {
        cout << "Reserva no válida. Verifica el número del libro o la disponibilidad.\n";
    }
}

// Función para verificar el inicio de sesión
bool iniciarSesion(const string& usuario, const string& contrasena) {
    const string usuarioCorrecto = "admin";
    const string contrasenaCorrecta = "1234";

    if (usuario == usuarioCorrecto && contrasena == contrasenaCorrecta) {
        return true;
    }
    return false;
}

int main() {
    // Lista de libros con sus respectivas copias disponibles
    vector<Libro> libros = {
        {"Cien años de soledad", 3},
        {"Don Quijote de la Mancha", 2},
        {"La sombra del viento", 5},
        {"El principito", 1}
    };

    string usuario, contrasena;
    int opcion, numeroLibro;

    // Solicitar inicio de sesión
    cout << "Bienvenido al Sistema de Reserva de Libros.\n";
    cout << "Por favor, inicie sesión.\n";
    cout << "Usuario: ";
    cin >> usuario;
    cout << "Contraseña: ";
    cin >> contrasena;

    if (!iniciarSesion(usuario, contrasena)) {
        cout << "Credenciales incorrectas. Acceso denegado.\n";
        return 0; // Finaliza el programa si las credenciales son incorrectas
    }

    cout << "Inicio de sesión exitoso. Accediendo al sistema...\n";

    do {
        cout << "\nSistema de Reserva de Libros\n";
        cout << "1. Mostrar libros\n";
        cout << "2. Reservar un libro\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarLibros(libros);
                break;
            case 2:
                cout << "Ingrese el número del libro que desea reservar: ";
                cin >> numeroLibro;
                reservarLibro(libros, numeroLibro);
                break;
            case 3:
                cout << "Saliendo del sistema. ¡Hasta pronto!\n";
                break;
            default:
                cout << "Opción no válida. Intente nuevamente.\n";
        }
    } while (opcion != 3);

    return 0;
}
