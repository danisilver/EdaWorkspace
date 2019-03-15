// Alejandro Ruiz Valero
// E53


#include <iostream>
#include <iomanip>
#include <fstream>

#include "gtree.h"


template <typename T>
int altura(gtree<T> const & t) {

	if (t.empty()) return 1;

	else {
		int m = 1;
		std::vector<gtree<T>> v = t.subtrees();
		for (unsigned int i = 0; i < v.size(); ++i)
			m = std::max(m, 1 + altura(v[i]));
		return m;
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

	gtree<int> t = leerArbol(0);

	std::cout <<altura(t) << std::endl;

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
	//std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
