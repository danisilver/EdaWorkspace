// Alejandro Ruiz Valero
// E53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector<int> const& v, int vagAsaltados, int & posVagAsaltado) {

	int botin = 0, botinaux, posOk = 0;

	for (int i = 0; i < vagAsaltados; ++i)
		botin += v[i];

	botinaux = botin;
	posVagAsaltado++;

	while (posVagAsaltado + vagAsaltados - 1 < v.size()) {

		botinaux = botinaux - v[posVagAsaltado - 1] + v[posVagAsaltado + vagAsaltados - 1];

		if (botin <= botinaux) {
			botin = botinaux;
			posOk = posVagAsaltado;
			posVagAsaltado++;
		}

		else posVagAsaltado++;
	}

	posVagAsaltado = posOk;
	return botin;
}


void resuelveCaso() {

	int numVagones, vagAsaltados, posVagAsaltado = 0;
	std::cin >> numVagones;
	std::cin >> vagAsaltados;
	std::vector<int> v(numVagones);

	for (int i = 0; i < numVagones; ++i)
		std::cin >> v[i];

	int botin = resolver(v, vagAsaltados, posVagAsaltado);
	std::cout << posVagAsaltado << " " << botin << std::endl;
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