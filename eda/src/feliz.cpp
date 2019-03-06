/*
 * feliz.cpp
 *
 *  Created on: 30 ene. 2019
 *      Author: daniel
 */
#include "conjunto.h"
#include <iostream>

using namespace std;

int siguiente(int n){
	int suma = 0;
	while(n > 0){
		int digito = n % 10;
		suma = digito * digito;
		n /= 10;
	}
	return suma;
}

bool happy(int n){
	set<int> cjto;
	while(n!=1 && !cjto.contains(n)){
		cjto.insert(n);
		n = siguiente(n);
	}
	return n==1;
}

int main(){
	set<int> cjto;
	try{
		cjto.erase(0);
	} catch(exception& e){
		cout << "exception" << endl;
	}
	return 0;
}

