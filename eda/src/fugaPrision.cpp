/*
12
a e
a b c e
c h
d e f g h
c h
c e f g h
c h
c d f g h
c h
c d e g h
c h
c d e f h
c h
c d e f g
d h
e f g h
d h
d f g h
d h
d e g h
d h
d e f h
d h
d e f g
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int c = 0;
char resolver(char vector[], int a, int b, char s){
	if(a==b+1) {
		return s;
	} else {
		int m = (a+b)/2;
		if(vector[m]>s)
			return resolver(vector, a, m-1, s);
		else
			return resolver(vector, m+1, a, s);
	}
}

void resuelveCaso() {

	char first, last;
	cin >> first;
	cin >> last;

	int tam = last - first;

	char *vector = (char *) malloc(sizeof(char) * tam);

	for (int i = 0; i < tam; i++)
		cin >> vector[i];

	char sol = resolver(vector, 0, tam-1, (last+first)/2);

	cout << sol << endl;
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
