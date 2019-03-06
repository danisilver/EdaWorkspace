//A21
// Gallardo Cruzado Mario D
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "miLista3.h"

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	int n, num, m, p;
	std::cin >> n;
	if (!std::cin)  // fin de la entrada
      return false;

	miLista3<int> col;
	miLista3<int> subcola;

	for (int i = 0; i < n; ++i) {
		std::cin >> num;
		col.push(num);
	}

	std:: cin >> m >> p;

	for (int i = 0; i < m; ++i) {
		std::cin >> num;
		subcola.push(num);
	}

	col.anadir(subcola, p);
	col.mostrar();

   return true;
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   //auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

   while (resuelveCaso());

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   //std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}



