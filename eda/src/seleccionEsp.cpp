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
void resolver(std::vector <int> const& v, tDatos & dat, int numPartidos) {

	int iAct = 0, pos = 0;

	while (pos < numPartidos) {

		if (v[pos] > 0) {
			iAct++;

			if (iAct > dat.PGn) {
				dat.PGn = iAct;
				dat.Vrep = 0;
				dat.PRest = 0;
			}

			if (iAct == dat.PGn) {
				dat.Vrep++;
				dat.PRest = 0;
			}

			if (iAct < dat.PGn)
				dat.PRest++;
		}

		else {
			iAct = 0;
			dat.PRest++;
		}

		pos++;
	}
}


bool resuelveCaso() {

	int numPartidos;
	tDatos dat;
	std::cin >> numPartidos;

	if (!std::cin)
		return false;

	std::vector <int> v(numPartidos);
	for (int& n : v) std::cin >> n;

	resolver(v, dat, numPartidos);
	std::cout << dat.PGn << " " << dat.Vrep << " " << dat.PRest << std::endl;

	return true;
}


int main() {
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