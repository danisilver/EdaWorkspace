// Alejandro Ruiz Valero
// E53

#ifndef _PELICULAS
#define _PELICULAS

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include "horas.h"

class peliculas {
private:
	horas hora_final;
	std::string nombre;

public:
	peliculas(horas hora_in = horas(), horas hora_dur = horas(), std::string n = "") {
		nombre = n;
		hora_final = hora_in + hora_dur;
	}

	bool operator<(peliculas const& p) const {
			if (hora_final == p.hora_final)
				return nombre < p.nombre;
			else return hora_final < p.hora_final;
		}

	void read(std::istream & i = std::cin) {
		horas h_in, h_dur;
		std::string nom;
		i >> h_in >> h_dur;
		getline(std::cin, nom);
		
		*this = peliculas(h_in, h_dur, nom);
	}
	void print(std::ostream& o = std::cout) const& {
		o << std::setfill('0') << std::setw(2) << hora_final << ' ' << nombre << std::endl;
	}
};


inline std::ostream & operator<<(std::ostream & salida, peliculas const& h) {
	h.print(salida);
	return salida;
}

inline std::istream & operator>>(std::istream & entrada, peliculas & h) {
	h.read(entrada);
	return entrada;
}

#endif
