/* datos.txt
9
1
3
3
1 2 2
5
1 1 2 9 9
5
1 2 2 9 9
5
1 1 2 2 9
7
3 5 5 9 9 11 11
7
3 3 5 9 9 11 11
7
3 3 5 5 9 11 11
7
3 3 5 5 9 9 11
 */
#include <malloc.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
void printVect(vector<int> vect){
	for(int i=0; i < vect.size(); i++)
		cout << vect[i] <<" ";
	cout << endl;
}
int resolver(vector<int> vect, int n){
	int pos = 0;
	int x = 1;
	while(x+1<n){
		if(vect[x]==vect[pos]){
			pos = x + 1;
			x = x + 2;
			//printVect(vect);
			//cout << "pos:" << pos << endl;
			//cout << "x:" << x << endl;
		}
		else x = x + 1;
		//cout << "x:" << x << endl;
	}
	return pos;
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
