//A21
//Gallardo Cruzado Mario D

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "set.h"



bool resuelveCaso() {

	char caracter;
	int kElementos;
	std::cin >> caracter;
	std::cin >> kElementos;
	if (! std::cin)
	        return false;
	if(caracter == 'P') {
		std::string palabra("");
		set<std::string> conjunto;

		while(palabra.compare("FIN") != 0){
			std::cin >> palabra;
			if(palabra.compare("FIN") != 0) conjunto.insert(palabra);
		}
		while(conjunto.size() > 3) conjunto.eliminaMenor();
		conjunto.mostrar();
	} else if(caracter == 'N') {
		int num = 0;
		set<int> conjunto;
		while(num != -1){
			std::cin >> num;
			if(num != -1) conjunto.insert(num);
		}
		while(conjunto.size() > 3) conjunto.eliminaMenor();
		conjunto.mostrar();
	} else {return false;}

    if (! std::cin)
        return false;

    return true;
}



int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("casos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif


    while (resuelveCaso())
    	;


     //Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif

    return 0;
}
