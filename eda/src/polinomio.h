//Mario D Gallardo Cruzado
//A21
#ifndef POLINOMIO_H_
#define POLINOMIO_H_

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "monomio.h"

class polinomio {
private:
	std::vector<monomio> arrPolinomio;
public:
	void add(monomio m) {
		if(m.a==0 && m.exp==0) return;
		if(arrPolinomio.empty()) {
			arrPolinomio.push_back(m);
		} else  {
			auto pos = std::lower_bound(arrPolinomio.begin(), arrPolinomio.end(), m);
			if((*pos).exp == m.exp){
				(*pos).a += m.a;
			} else {
				arrPolinomio.push_back(m);
			}
			sort(arrPolinomio.begin(), arrPolinomio.end());
		}
	}
	int resolver(int x) {
		int resultado = 0;
		for (monomio &m : arrPolinomio) {
			resultado += m.a * pow(x, m.exp);
		}
		return resultado;
	}
	void read(std::istream &entrada) {
		monomio m;
		entrada >> m;
		if (!entrada)
			return;
		while (!(m.a==0 && m.exp==0)) {
			add(m);
			entrada >> m;
		}
	}
	void print(std::ostream &salida) const{
		for (monomio const &m : arrPolinomio)
			salida << m << ' ';
	}
};

inline std::ostream &operator<<(std::ostream &salida, polinomio const &p) {
	p.print(salida);
	return salida;
}

inline std::istream &operator>>(std::istream &entrada, polinomio &p) {
	p.read(entrada);
	return entrada;
}

#endif /* POLINOMIO_H_ */
