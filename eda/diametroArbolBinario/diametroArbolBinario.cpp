
#include <iostream>
#include <fstream>
#include <string>
#include "bintree_eda.h"

template <typename T>
T minimo(bintree<T> &tree, std::vector<int> vec){

}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

   // leer los datos de la entrada
   char c;
   std::cin >> c;

   if (!std::cin)  // fin de la entrada
      return false;

   std::string emptyEl = ".";
   bintree<std::string> arbol;


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
