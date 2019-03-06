//E53
// Alejandro Ruiz Valero

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "miLista4.h"

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	int num;

	miLista4<int> col;
	miLista4<int> subcola;

	while (num != 0) {
		std::cin >> num;
		col.push(num);
	}

	while (num != 0) {
		std::cin >> num;
		subcola.push(num);
	}

	col.mezclar(subcola);
	col.mostrar();

   return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     //auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
   //  std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif

    return 0;
}






