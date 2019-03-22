
#include <iostream>
#include <fstream>
#include <string>
#include "bintree_eda.h"
#include "queue_eda.h"

template <typename T>
bintree<T> reconstruir(queue<T> &preorden, queue<T> &inorden){

	T raiz = preorden.front();

	if(inorden.size() == 1 && preorden.size() == 1)
		return {nullptr, inorden.top(), nullptr};
	else if(inorden.size() == 1 && preorden.size() > 1)
		return { reconstruir(izq), raiz, nullptr}
	else if(inorden.size() > 1 && preorden.size() == 1)
		return { nullptr, raiz, reconstruir(der)}
	else if(inorden.size() == 1 && preorden.size() > 1)
		return { reconstruir(izq) , raiz, reconstruir(der)}
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

   // leer los datos de la entrada
   char c;
   std::cin >> c;

   queue<int> inorden;
   queue<int> preorden;

   std::string line;
   std::getline(std::cin, line);
   std::stringstream ss(line);

   int num;
   while(ss >> num) {
	   preorden.push(num);
   }

   std::getline(std::cin, line);
   std::stringstream ss2(line);

   int num2;
   while(ss2 >> num2) {
	   preorden.push(num);
   }

   if (!std::cin)  // fin de la entrada
      return false;

   std::string emptyEl = ".";
   bintree<int> arbol = reconstruir(preorden, inorden);

   std::vector<int> postorden = arbol.postorder();


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
