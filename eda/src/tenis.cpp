// Alejandro Ruiz Valero
// E53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

struct datos {
	bool jugador;
	int numeroJuegos;
};

datos resolver(std::vector<std::string> const& partidos, int ini, int fin, int rondaFinal, int & rondaActual) {

	if (fin - ini == 1) {
		rondaActual = 1;

		if ((partidos[ini] != "NP") && (partidos[fin] != "NP"))
			return { true, 1 };
		else if ((partidos[ini] != "NP") || (partidos[fin] != "NP"))
			return { true, 0 };
		else return { false, 0 };
	}

	else {
		int m = (ini + fin) / 2;

		datos Izq = resolver(partidos, ini, m, rondaFinal, rondaActual);
		datos Der = resolver(partidos, m + 1, fin, rondaFinal, rondaActual);

		if ((rondaFinal > rondaActual) && Izq.jugador && Der.jugador) {
			++rondaActual;
			return { true, (Izq.numeroJuegos + Der.numeroJuegos + 1) };
		}

		else if (Izq.jugador || Der.jugador) {
			++rondaActual;
			return { true, (Izq.numeroJuegos + Der.numeroJuegos) };
		}

		else {
			++rondaActual;
			return { false, (Izq.numeroJuegos + Der.numeroJuegos) };
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int tam;
	std::cin >> tam;
	if (!std::cin) return false;

	int rondaFinal;
	std::cin >> rondaFinal;

	std::vector<std::string> partidos(tam);

	for (std::string & jugador : partidos)
		std::cin >> jugador;

	int rondaActual;
	datos sol = resolver(partidos, 0, tam - 1, rondaFinal, rondaActual);
	std::cout << sol.numeroJuegos << std::endl;
	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	//save old buf and redirect std::cin to datos.txt
	//auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	//std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
