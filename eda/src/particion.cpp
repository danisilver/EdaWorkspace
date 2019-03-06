// Alejandro Ruiz Valero
// E53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
bool resolver(std::vector<int> const& v, int tam, int p) {

	bool b = true;
	int maximoIzq = v[0];

	for (int i = 0; i < tam; i++) {

		if (i <= p) {
			if (v[i] > maximoIzq)
				maximoIzq = v[i];
		}

		else {

			if (maximoIzq >= v[i])
				b = false;
		}
	}

	return b;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

	int tam, p;
	std::cin >> tam;
	std::cin >> p;
	std::vector<int> v(tam);

	for (int i = 0; i < tam; i++) 
		std::cin >> v[i];

	bool b = resolver(v, tam, p);

	if (b == true)
		std::cout << "SI" << std::endl;
	else std::cout << "NO" << std::endl;
}

int main() {
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