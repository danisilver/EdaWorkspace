// Alejandro Ruiz Valero
// E53


#include <iostream>
#include <iomanip>
#include <fstream>
#include "complejo.h"


void resuelveCaso() {

	int iteraciones;
	complejo<float> c;
	std::cin >> c;
	std::cin >> iteraciones;

	int i = 0;

	complejo<float> nth;
	while( i < iteraciones){
		nth = nth * nth + c;
		if(nth.modulo() > 2) break;
		i++;
	}
	if (i == iteraciones)
		std::cout << "SI" << std::endl;
	else std::cout << "NO" << std::endl;
    // escribir sol

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
