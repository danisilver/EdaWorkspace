// Alejandro Ruiz Valero
// E53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


struct tIntervalo {
	int ini = 0;
	int fin = -1;
};


// función que resuelve el problema
tIntervalo resolver(std::vector<int> const& v, const int altura, int fin) {

	tIntervalo interv;
	int posIni, posFin, i = 0, dist = 0;

	while (i < fin) {

		if (v[i] > altura) {

			if (dist == 0) {
				posIni = i;
				posFin = i;
			}

			else posFin = i;

			if (posFin - posIni > interv.fin - interv.ini) {
				interv.ini = posIni;
				interv.fin = posFin;
			}

			dist++;
		}

		else dist = 0;

		i++;
	}

	return interv;
}

void resuelveCaso() {

	int numEdif, altura;
	std::cin >> numEdif;
	std::cin >> altura;
	std::vector<int> v(numEdif);

	for (int i = 0; i < numEdif; ++i)
		std::cin >> v[i];

	tIntervalo sol = resolver(v, altura, numEdif);
	std::cout << sol.ini << " " << sol.fin << std::endl;
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