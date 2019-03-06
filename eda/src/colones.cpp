/* datos.txt
3
5
2 3 6 9 11
9
1 6 2 9 7 4 8 10 13
0
 */
#include <malloc.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> vect,int size) {
	int n = size;
	int k = size-1;
	int m = k;
	while(k>=0){
		if(vect[k]<= vect[m]) {
			n--;
			m=k;
		}
		k = k-1;
	}
	return n;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int tam;
	cin >> tam;

	vector<int> v(tam);
	int sol;

	for (int i = 0; i < tam; ++i){
		cin >> v[i];
		//cout << v[i] << " ";

	}
	//cout << "\n";

	sol = resolver(v,tam);

	cout << sol << "\n";
}


int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	ifstream in("datos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();



	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
