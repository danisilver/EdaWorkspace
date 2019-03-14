//Mario D Gallardo Cruzado
//A21

/* casos.txt
5 0 1 4 -6 2 -1 2 6 3 -4 4 6 1 -5 5 0 0
5
3 -1 9 -2 3
-6 4 3 1 -3 1 0 0
5
3 9 3 -3 -3
-2 0 2 1 -3 5 3 2 -5 5 -5 1 -6 2 -2 3 1 1 -6 2 0 0
5
3 0 -4 3 -3
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "polinomio.h"
#include "monomio.h"

bool resuelveCaso() {

	polinomio p;
	int nTimes;
	int x;
	std::cin >> p;
	//std::cout << p << std::endl;
	std::cin >> nTimes;
	if (!std::cin)
		return false;
	for (int i = 0; i < nTimes-1; i++) {
		std::cin >> x;
		int resultado = p.resolver(x);
		std::cout << resultado << " ";
	}
	std::cin >> x;
	int resultado = p.resolver(x);
	std::cout << resultado << std::endl;

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
