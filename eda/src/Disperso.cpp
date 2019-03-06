// Alejandro Ruiz Valero
// E53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool resolver(std::vector <int> const& v, int ini, int fin, int k) {

	if (ini + 1 == fin) return true;
	else if (ini+2 == fin) return k <= std::abs(v[ini+1] - v[ini]); 
	else { 

		int m = (ini + fin) / 2;
		bool sIz = resolver(v, ini, m, k);
		bool sDr = resolver(v, m, fin, k);
		return sIz && sDr && k <= std::abs(v[ini] - v[fin - 1]);
	}
}


bool resuelveCaso() {

	int tam;
	std::cin >> tam;

	if (!std::cin)
		return false;

	int k;
	std::cin >> k;
	std::vector <int> v(tam);

	for (int& n : v) std::cin >> n;

	if (resolver(v, 0, tam, k)) std::cout << "SI" << std::endl;
	else std::cout << "NO " << std::endl;

	return true;
}


int mainMethod() {
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
