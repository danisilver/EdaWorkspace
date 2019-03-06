/*
5
7 5 3 8 9
8
9 8 7 6 5 4 3 2
1
2
2
3 5
10
34 25 12 10 9 8 7 6 5 9
 */

#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


int resolver(int vect[], int a, int b){
	if(a == b) {
		return vect[a];
	} else {
		int m = (a+b)/2;
		if(vect[m]<vect[m+1])
			return resolver(vect, a, m);
		else
			return resolver(vect, m+1, b);
	}
}

bool resuelveCaso() {
    int tam;
    cin >> tam;


    int sol = 0;
    int *vect = (int *)malloc(sizeof(int) * tam);

    if(!cin)
    	return false;
    else
    	for (int i = 0 ; i < tam; ++i)
    		cin >> vect[i];

    sol = resolver(vect, 0, tam-1);

    cout << sol << endl;

    return true;
}

int main(){
	// Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while ( resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

}
