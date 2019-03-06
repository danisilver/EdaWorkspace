// Alejandro Ruiz Valero
// E53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdlib.h>

bool resolver(int & peso) {

	int pI, dI, pD, dD;
	bool okIzq = true, okDer = true;
	std::cin >> pI >> dI >> pD >> dD;

	if (pI == 0) okIzq = resolver(pI);

	if (pD == 0) okDer = resolver(pD);

	if (okIzq && okDer && ((pI * dI) == (pD * dD))) {
		peso = pD + pI;
		return true;
	}

	else return false;
}


void resuelveCaso() {
	// leer los datos de la entrada
	int peso;

	// escribir sol
	if (resolver(peso)) std::cout << "SI" << "\n";
	else std::cout << "NO" << "\n";
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	//save old buf and redirect std::cin to datos.txt
	//auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	//std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}