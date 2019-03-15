// Alejandro Ruiz Valero
// E53


#include <iostream>
#include <iomanip>
#include <fstream>

#include "../fronteraArbolBinario/bintree_eda.h"

template <typename T>
int frontera(bintree<T> const & t, std::vector <int> & v) {

	if (t.empty()) return 0;

	if (frontera(t.left(), v) + frontera(t.right(), v) == 0) {
		v.push_back(t.root());
		return 1;
	}
	else return 1;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada

	bintree<int> t = leerArbol(-1);
	std::vector <int> w;

	int n = frontera(t, w);
	for (int i = 0; i < w.size(); ++i)
		std::cout << w[i] << " ";

	std::cout << std::endl;
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