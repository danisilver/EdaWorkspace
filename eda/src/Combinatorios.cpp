// AlejandroRuiz Valero
// E53

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tMatriz = std::vector <std::vector <int >>;

// función que resuelve el problema

int resolver(int a, int b, tMatriz & matr) {

	if (b == 0 || b == a) return matr[a][b] = 1;

	else if (b == 1 || b == a - 1) return matr[a][b] = a;

	else {

		if (matr[a - 1][b - 1] == -1) matr[a - 1][b - 1] = resolver(a - 1, b - 1, matr);
		if (matr[a - 1][b] == -1) matr[a - 1][b] = resolver(a - 1, b, matr);
		return matr[a][b] = matr[a - 1][b - 1] + matr[a - 1][b];
	}
}

	// Resuelve un caso de prueba, leyendo de la entrada la
	// configuración, y escribiendo la respuesta
bool resuelveCaso() {

		int a, b;
		std::cin >> a >> b;

		if (!std::cin)
			return false;

		tMatriz matriz(a + 1, std::vector <int >(b + 1, -1));
		std::cout << resolver(a, b, matriz) << std::endl;

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
