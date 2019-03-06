// Alejandro Ruiz Valero
// E53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector<int> const& v, int tam) {

	int MaxAct = 0, sumaTotal = 0, MaxRep = 1;

	for (int i = 0; i < tam; ++i) {

		if (v[i] == MaxAct)
			MaxRep++;

		if (v[i] > MaxAct) {
			MaxAct = v[i];
			MaxRep = 1;
		}

		sumaTotal += v[i];
		sumaTotal = sumaTotal - (MaxAct * MaxRep);
	}

	return sumaTotal;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

	int tam;
	std::cin >> tam;

	std::vector<int>v(tam);
	for (int i = 0; i < tam; ++i)
		std::cin >> v[i];

	int sol = resolver(v, tam);
	std::cout << sol << std::endl;
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