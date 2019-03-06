/*
 * Nreinas.cpp
 *
 *  Created on: 9 ene. 2019
 *      Author: daniel
 */
#include <malloc.h>
#include <iostream>

using namespace std;

bool esValida(int *, int);
void tratarSolucion(int *, int);


void nReinas(int vect[], int j, int k){
	for (int i = 0; i < k; i++) {
		vect[j] = i;
		if(esValida(vect, j)){
			if(j == k-1)
				tratarSolucion(vect, k);
			else
				nReinas(vect, j+1, k);
		}
	}
}

bool esValida(int vect[], int k){
	int i = 0;
	bool correcto = true;
	while(i < k && correcto){
		if((vect[i] == vect[k]) || abs(vect[k] - vect[i]) == k-i)
			correcto = false;
		else i++;
	}
	return correcto;
}

void tratarSolucion(int vect[], int size){
	for (int i = 0; i < size; i++) {
		cout << vect[i] << " ";
	}
	cout << endl;
}

int tam = 4;
int vect[4];

int main(){
	nReinas(vect, 0, 8);
	system("pause");
	return 0;
}
