// Alejandro Ruiz Valero
// E53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector<int> const& v, int ini, int fin, int cont) {

	if (fin - ini == 1 || v[ini] == v[fin - 1]) return cont;

	else {

		int m = (ini + fin - 1) / 2;

		if (ini == m) {
			if (v[ini] != v[fin - 1]) ++cont;
			else return cont;
		}

		else {

			if (v[ini] == v[m]) return resolver(v, m, fin, cont);
			else {
				cont = resolver(v, ini, m + 1, cont);
				if (v[m] == v[fin - 1]) return cont;
				else return resolver(v, m, fin, cont);
			}
		}
	}

	return cont;
}

bool resuelveCaso() {
	// leer los datos de la entrada

	int tam;
	std::cin >> tam;
	if (tam > 0) {
		std::vector<int> v(tam);

		for (int i = 0; i < tam; ++i) {
			std::cin >> v[i];
		}

		if (!std::cin)
			return false;

		int cont = 1;

		int sol = resolver(v, 0, tam, cont);
		std::cout << sol << std::endl;
		// escribir sol
		return true;
	}

	else return false;
}

int mainMethod() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	//auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	//std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
