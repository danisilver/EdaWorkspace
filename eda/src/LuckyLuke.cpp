// Alejandro Ruiz Valero
// E53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
template <class T> int binarioIzq(std::vector <T> const& v, T elem , int ini, int fin) {

	if (ini >= fin) return ini;
	else if (ini+1 == fin) return ini; 

	else { 
		int m = (ini + fin -1) / 2;

		if (v[m] < elem) return binarioIzq(v,elem ,m+1,fin);
		else return binarioIzq(v,elem ,ini,m+1);
	} 
}

template <class T> int binarioDr(std::vector <T> const& v, T elem , int ini, int fin) {

	if (ini >= fin) return ini; 
	else if (ini + 1 == fin) return ini;

	else {
		int m = (ini + fin) / 2;

		if (elem < v[m]) return binarioDr(v,elem ,ini,m);
		else return binarioDr(v,elem ,m ,fin);
	}
}

bool resuelveCaso() { 
	int tam , elem; 
	std::cin >> tam; 

	if (!std::cin)
		return false; 

	std::cin >> elem;
	std::vector <int> v(tam);

	for (int& n : v) std::cin >> n; 

	int posIzq = binarioIzq(v,elem ,0, tam);
	if (posIzq == tam || v[posIzq] != elem) std::cout << "NO EXISTE" << '\n';

	else { 

		int posDr = binarioDr(v,elem ,0, tam);
		if (posIzq == posDr) std::cout << posIzq << '\n';
		else std::cout << posIzq << ' ' << posDr << '\n';
	}

	return true; 
}


int mainMethod() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
