//A21
// Gallardo Cruzado Mario D


#include <iostream>
#include <fstream>
#include "queue_eda.h"

template <typename T>
class miLista3:public queue<T> {

	using Nodo = typename queue<T>::Nodo;
public:


	void anadir(miLista3<T> &subcola,const int &p) {
		if (p == 0) {
			subcola.ult->sig = this->prim;
			this->prim = subcola.prim;
		} else {

			Nodo * act = this->prim;

			for (int i = 1; i < p; ++i) {
				act = act->sig;
			}
			subcola.ult->sig = act->sig;
			act->sig = subcola.prim;
		}
		this->nelems += subcola.nelems;
		subcola.prim = nullptr;
		subcola.ult = nullptr;
		subcola.nelems = 0;
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
