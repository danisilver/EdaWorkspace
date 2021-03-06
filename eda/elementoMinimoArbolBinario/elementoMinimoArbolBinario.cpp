
// Nombre y Apellidos

// Comentario general sobre la soluci�n,
// explicando c�mo se resuelve el problema

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include "bintree_eda.h"

template<typename T>
T minimoRecursion(bintree<T> const &tree) {
	if (tree.left().empty() && tree.right().empty()) return tree.root();
	return std::min(
			tree.root(),
			std::min(
					minimoRecursion(tree.left().empty() ? ({ tree.root(); }) : tree.left()),
					minimoRecursion(tree.right().empty() ? ({ tree.root(); }) : tree.right())));
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuraci�n, y escribiendo la respuesta
bool resuelveCaso() {

   // leer los datos de la entrada
   char c;
   std::cin >> c;

   if (!std::cin)  // fin de la entrada
      return false;


   if(c=='N'){
	   int emptyElement = -1;
	   bintree<int> tree = leerArbol(emptyElement);
	   int min = minimoRecursion(tree);
	   std::cout << min << std::endl;
   } else {
	   std::string emptyElement = "#";
	   bintree<std::string> tree = leerArbol(emptyElement);
	   std::string r = minimoRecursion(tree);
	   std::cout << r << std::endl;
   }

   // escribir sol

   return true;
}



int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

   while (resuelveCaso());

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
