//E53
// Alejandro Ruiz Valero

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "miLista.h"

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	int num;
	std::cin >> num;
	if (!std::cin)  // fin de la entrada
      return false;

	miLista<int> col;

	while (num != 0) {
		col.push(num);
		std::cin >> num;
	}

	col.duplicar();
	std::cout << col.size() << std::endl;
	col.mostrar();

	int num2;
	std::cin >> num2;
	while (num2 != 0) {
		col.push(num2);
		std::cin >> num2;
	}

	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
		col.pop();
	std::cout << col.size() << std::endl;
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

