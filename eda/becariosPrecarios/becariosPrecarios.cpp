//A21 Gallardo Cruzado Mario D

#include <iostream>
#include <iomanip>
#include <fstream>

#include "gtree.h"

template <typename T>
int numBecarios(gtree<T> const & t, int k) {
	int becarios = 0;
	if(t.empty()) return 0;
	if(t.root() == 0)
		if(k<=0) return 1;
	std::vector<gtree<T>> v= t.subtrees();
	for(unsigned int i=0; i < v.size();i++){
		becarios += numBecarios(v[i], k-1);
	}
	return becarios;
}

/*template <typename T>
int numBecarios(gtree<T> const & t, int nivel, int k) {
	int becarios = 0;
	if(t.empty()) return 0;
	if(t.subtrees().empty()) { if(k<=0) return 1; }
	std::vector<gtree<T>> v= t.subtrees();
	for(unsigned int i=0; i < t.subtrees().size();i++){
		becarios += numBecarios(v[i], nivel + 1, k-1);
	}
	return becarios;
}*/


bool resuelveCaso() {

	int k;
	std::cin >> k;

	gtree<int> t = leerArbol(0);

	if(!std::cin) return false;

	std::cout << numBecarios(t, k) << std::endl;
	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


	while(resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
