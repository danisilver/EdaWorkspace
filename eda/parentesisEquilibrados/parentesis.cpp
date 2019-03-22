// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "stack_eda.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string cadena;
    
    getline(std::cin, cadena);
    if (! std::cin)
        return false;
    
    
    stack<char> pila;

    bool notBalanced = false;

    for (char& c: cadena) {
    	if(!pila.empty() && c == pila.top()) {
    		pila.pop();
    	} else {
    		switch (c) {
    		case '[': pila.push(']'); break;
    		case '(': pila.push(')'); break;
    		case '{': pila.push('}'); break;
    		case ']':
    		case ')':
    		case '}':
    			notBalanced = true;
    			break;
    		default:
    			break;
    		}
    	}
     }

    if (notBalanced || !pila.empty())
    	std::cout << "NO"<< std::endl;
    else
    	std::cout << "SI"<< std::endl;


    return true;
}



int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     //auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     //std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}
