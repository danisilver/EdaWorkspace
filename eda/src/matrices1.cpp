// Alejandro Ruiz Valero
// E53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tDatos {
	int PGn = 0;		// Partidos Máximos Ganados
	int Vrep = 0;		// Victorias Repetidas de los part.máximos
	int PRest = 0;		// Partidos restantes despues de la última máxima racha.
};

// función que resuelve el problema
int resolver(std::vector<std::vector<int>> m, int f, int c) {

	int sol = 0, x = 0, y = 0;

	while (x < f) {

		if (m[x][y] == x)
			sol++;

		++y;

		if (y == c) {
			y = 0;
			++x;
		}
	}

	return sol;
}


bool resuelveCaso() {

	int filas, columnas;
	std::cin >> filas;

	if (!std::cin)
		return false;

	std::cin >> columnas;

	std::vector< std::vector<int>> m(filas, std::vector<int>(columnas));

	for (int i = 0; i < filas; ++i) {
		for (int j = 0; j < columnas; ++j)
			std::cin >> m[i][j];
	}

	int sol = resolver(m, filas, columnas);
	std::cout << sol << std::endl;

	return true;
}


int main() {
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