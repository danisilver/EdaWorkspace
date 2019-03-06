/*
5
1 3 4 5 2
5
2 5 4 3 1
5
1 3 2 4 5
5
1 3 2 4 5
*/
#include <iostream>
#include <fstream>
#include "stack_eda.h"

bool resuelveCaso() {

	int numSobrinos;
	stack<int> pila;

	std::cin >> numSobrinos;

	if (!std::cin)  // fin de la entrada
			return false;

	int i=0;
	while(i < numSobrinos){
		int altura;
		std::cin >> altura;
		pila.push(altura);
		i++;
	}

	bool sigue = true;
	stack<int> bam;
	while(bam.size() < 3 && sigue){

		int m = pila.top(); pila.pop();
		int a = pila.top(); pila.pop();
		int b = pila.top(); pila.pop();

		if(b < m && m < a) break;



	}

	/*int bajo;
	int mediano;
	int alto;
	bool sigueBuscando = true;
	while(pila.size() >= 3 && sigueBuscando){
		mediano = pila.top(); pila.pop();
		alto = pila.top(); pila.pop();
		bajo = pila.top(); pila.pop();
		if(bajo < mediano && mediano < alto) sigueBuscando = false;
		else if(alto < mediano){
			pila.push(bajo);
			pila.push(alto);
		}
	}*/

	//std::cout << ((sigueBuscando) ? "SIEMPRE PREMIO" : "ELEGIR OTRA") << std::endl;


/*
	pila.push(0);
	pila.pop();
*/

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso())
		;

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
