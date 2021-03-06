﻿// AlejandroRuiz Valero
// E53

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector<int> const & a, std::vector<int> const & b, int pos, int const tam) {

	if (pos < tam - 1 && a[pos] == b[pos])
		//CHANGED no habia return
		return resolver(a, b, pos + 1, tam);

	else return a[pos];
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int tam;
	std::cin >> tam;

	std::vector<int> a(tam);
	std::vector<int> b(tam - 1);

	for (int i = 0; i < tam; ++i)
		std::cin >> a[i];

	for (int j = 0; j < tam - 1; ++j)
		std::cin >> b[j];

	int sol = resolver(a, b, 0, tam);

	std::cout << sol << std::endl;

}

int mainMethod() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
