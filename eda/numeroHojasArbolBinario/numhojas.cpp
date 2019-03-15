// Alejandro Ruiz Valero
// E53


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"


// función que resuelve el problema
template <typename T>
int altura(bintree<T> const & t) {

	if (t.empty()) return 0;
	else return 1 + (std::max(altura(t.left()), altura(t.right())));

}

template <typename T>
int numNodos(bintree<T> const & t) {
	
	if (t.empty()) return 0;

	else return 1 + numNodos(t.left()) + numNodos(t.right());
}

template <typename T>
int numHojas(bintree<T> const & t) {

	if (t.empty()) return 0;

	else if (numHojas(t.left()) + numHojas(t.right()) == 0)
			return 1;
	else return numHojas(t.left()) + numHojas(t.right());
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada

	bintree<char> t = leerArbol('.');
	
	std::cout << numNodos(t) << " " << numHojas(t) << " " << altura(t) << std::endl;
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