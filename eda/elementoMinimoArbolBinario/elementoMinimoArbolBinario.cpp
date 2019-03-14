
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <string>
#include "bintree_eda.h"


template <typename T>
T minimo(bintree<T> const &tree){
	bintree<T> left = tree.left();
	bintree<T> right = tree.right();

	if(left.empty() && right.empty()) {
		return tree.root();
	} else if(left.empty() && !right.empty()){
		T rval = right.root();
		T t = tree.root();
		return rval < t ? rval : t;
	} else  if(!left.empty() && right.empty()){
		T lval = left.root();
		T t = tree.root();
		return lval < t ? lval : t;
	} else {
		T izq = minimo(left);
		T der = minimo(right);
		return (izq < der) ? izq : der;
	}
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

   // leer los datos de la entrada
   char c;
   std::cin >> c;

   if (!std::cin)  // fin de la entrada
      return false;


   if(c=='N'){
	   int emptyElement = -1;
	   bintree<int> tree = leerArbol(emptyElement);
	   int min = minimo(tree);
	   std::cout << min << std::endl;
   } else {
	   std::string emptyElement = "#";
	   bintree<std::string> tree = leerArbol(emptyElement);
	   std::string r = minimo(tree);
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
