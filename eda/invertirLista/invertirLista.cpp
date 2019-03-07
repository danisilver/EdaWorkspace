// A21
// Gallardo Cruzado Mario D

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

/*
1 2 3 4 0
0
8 7 6 0
3 0
*/


#include <iostream>
#include <fstream>
#include "miLista2.h"

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	int num;
	std::cin >> num;
	if (!std::cin)  // fin de la entrada
      return false;

	miLista2<int> col;

	while (num != 0) {
		col.push(num);
		std::cin >> num;
	}

	col.invertir();
	col.mostrar();

   return true;
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

   while (resuelveCaso());

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}




