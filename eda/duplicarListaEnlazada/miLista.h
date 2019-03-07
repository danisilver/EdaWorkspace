// A21
// Gallardo Cruzado Mario D

/*
5 3 1 8 0
0
7 7 0
*/


#include <iostream>
#include <fstream>
#include "queue_eda.h"

template <typename T>
class miLista:public queue<T> {

	using Nodo = typename queue<T>::Nodo;
public:


	void duplicar() {
		Nodo * act = this->prim;
		while (act != nullptr) {
			Nodo * nuevo = new Nodo(act->elem, act->sig);
			this->ult = nuevo;
			act->sig = nuevo;
			act = nuevo->sig;
			this->nelems++;
		}
	}

	void mostrar() {

		Nodo * act = this->prim;
		while (act != nullptr) {
			std::cout<< act->elem << " ";
			act = act->sig;
		}
		std::cout << std::endl;

	}

};
