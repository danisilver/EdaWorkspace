// Gallardo Cruzado Mario D
// A21

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "stack_eda.h"

bool resolver(int num, std::vector<int> const& altura) {

	int grande = -1;
	int mediano = -1;
	int ind = num - 1;
	stack<int> pila;

	pila.push(altura[ind]);
	ind--;

	while (ind >= 0) {
		if (pila.empty())
			pila.push(grande);

		if (!pila.empty() && altura[ind] < pila.top()) {
			if (altura[ind] < mediano)
				return true;
			pila.push(altura[ind]);
			ind--;
		} else {
			grande = altura[ind];
			if (!pila.empty() && pila.top() < grande)
				mediano = pila.top(); pila.pop();
			else
				ind--;
		}
	}

	return false;
}

bool resuelveCaso() {
	// leer los datos de la entrada
	int num;
	std::cin >> num;
	if (!std::cin)
		return false;
	std::vector<int> altura(num);

	for (int i = 0; i < num; ++i)
		std::cin >> altura[i];

	if (resolver(num, altura))
		std::cout << "ELEGIR OTRA" << std::endl;
	else
		std::cout << "SIEMPRE PREMIO" << std::endl;

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

