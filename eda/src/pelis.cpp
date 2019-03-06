// Alejandro Ruiz Valero
// E53

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

#include "horas.h"
#include "peliculas.h"

bool resuelveCaso() {
	int num_peliculas;
	cin >> num_peliculas;
	if (num_peliculas == 0)
		return false;

	vector<peliculas> pelis(num_peliculas);
	for (peliculas & p : pelis) {
		cin >> p;
	}

	sort(pelis.begin(), pelis.end());

	for (int i = 0; i < num_peliculas; ++i) {
		cout << pelis[i];
	}
	cout << "---\n";
	return true;
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	//auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	// std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
