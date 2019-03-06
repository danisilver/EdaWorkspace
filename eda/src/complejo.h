// Alejandro Ruiz Valero
// E53

#ifndef _COMPLEJO
#define _COMPLEJO

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cmath>

template <class T>
class complejo {
private:

	T real;
	T imaginario;

public:
	complejo(T r = 0.00, T im = 0.00) {
		real = r;
		imaginario = im;
	}
	// observadoras
	T rGet() const { return real; }
	T imGet() const { return imaginario; }

	// operador de comparacion
	float modulo () {
		return sqrt(real*real + imaginario*imaginario);
	}

	complejo<T> operator+(complejo<T> const& c) const {
		return complejo(c.real + real, c.imaginario + imaginario);
	}

	complejo<T> operator*(complejo<T> const& c) const {

			return complejo(real * c.real - imaginario * c.imaginario,
					real * c.imaginario + imaginario * c.real);
		}

	complejo<T>& operator=(complejo<T> const& o){
		real = o.real;
		imaginario = o.imaginario;
		return *this;
	}

	void read(std::istream & i = std::cin) {
		T r, im;
		i >> r >> im;
		*this = complejo(r, im);
	}
};

template <class T>
std::istream & operator>>(std::istream & entrada, complejo<T> & c) {
	c.read(entrada);
	return entrada;
}

#endif


