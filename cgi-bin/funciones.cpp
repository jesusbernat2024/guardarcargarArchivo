#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;


int main() {

    // Obtener el método de la solicitud (GET o POST)
    const char* request_method = getenv("REQUEST_METHOD");
    char* query_string = nullptr;

    if (request_method != nullptr && strcmp(request_method, "GET") == 0) {
        // Si el método es GET, leer la cadena de consulta de la URL
        query_string = getenv("QUERY_STRING");
    } 
    else if (request_method != nullptr && strcmp(request_method, "POST") == 0) {
        // Si el método es POST, leer el contenido de la entrada estándar (stdin)
        const char* content_length_str = getenv("CONTENT_LENGTH");
        int content_length = 0;
        if (content_length_str != nullptr) {
            content_length = atoi(content_length_str); // Convertir a entero
        }
        query_string = new char[content_length + 1];  // Reservar espacio para el contenido POST
        cin.read(query_string, content_length);       // Leer desde stdin
        query_string[content_length] = '\0';          // Asegurarse de que sea una cadena terminada
    }


    // Inicializar variables
    int numero = 0;
    char orden[50] = "";

    if (query_string != nullptr) {
        // Parsear los parámetros
        char* param = strdup(query_string);  // Hacer una copia de la cadena de consulta
        char* token = strtok(param, "&");    // Separar los parámetros
        while (token != nullptr) {
            if (sscanf(token, "numero=%d", &numero) == 1) {  }
            if (sscanf(token, "orden=%49s", orden) == 1) {  }
            token = strtok(nullptr, "&");    // Continuar con el siguiente parámetro
        }
        free(param);  // Liberar la memoria
    }


    if( string(orden) == "anadir"){
        string linea = "";
        ifstream archivo("registro.txt");
        getline(archivo, linea);
        archivo.close();

        if(linea != "") linea += ", " + to_string(numero);
        else linea = to_string(numero);

        ofstream archivo0("registro.txt"); // Crear aquí
        archivo0 << linea << "\n"; // Escribir contenido
        archivo0.close(); // Cerrar archivo

        cout << "Content-Type: text/plain\n\n";
        cout << linea;
    }
    
    if( string(orden) == "resetear"){
        string linea = "...";

        ofstream archivo0("registro.txt"); // Crear aquí
        archivo0 << linea << "\n"; // Escribir contenido
        archivo0.close(); // Cerrar archivo

        cout << "Content-Type: text/plain\n\n";
        cout << linea;

    }

    if( string(orden) == "cargar"){

        // Abrir fichero
        ifstream archivo("registro.txt");
        
        // capturar contenido
        string linea = "...";
        getline(archivo,linea);
        // cerrar fichero
        archivo.close();

        cout << "Content-Type: text/plain\n\n";
        cout << linea;
    }


    return 0;
}