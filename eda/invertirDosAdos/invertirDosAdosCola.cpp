// A21
// Gallardo Cruzado Mario D

#include <iostream>
#include <fstream>

#include "miLista.h"

bool resuelveCaso() {

	int numElementos;

	miLista<int> col;

	std::cin >> numElementos;

	if(numElementos == 0) return false;

	for (int i = 0; i < numElementos; ++i) {
		int elemento;
		std::cin >> elemento;
		col.push(elemento);
	}

	if (!std::cin)  // fin de la entrada
		return false;

	col.invertirDosAdos();
	col.mostrar();

   return true;
}

int main() {
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("casos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif


     while(resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif

    return 0;
}
