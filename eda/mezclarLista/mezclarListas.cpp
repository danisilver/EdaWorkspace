

/* casos.txt
*/

#include <iostream>
#include <fstream>
#include "miLista4.h"

bool resuelveCaso() {

	int num = 1;

	miLista4<int> col;
	miLista4<int> subcola;

	while (num != 0) {
		std::cin >> num;
		if(num!=0)col.push(num);
	}

	num = 1;

	while (num != 0) {
		std::cin >> num;
		if(num!=0) subcola.push(num);
	}

	col.mezclar(subcola);
	col.mostrar();

   return true;
}

int main() {
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("casos.txt");
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






