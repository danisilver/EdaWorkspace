//E53
// Alejandro Ruiz Valero


#include <iostream>
#include <fstream>
#include "queue_eda.h"

template <typename T>
class miLista2:public queue<T> {

	using Nodo = typename queue<T>::Nodo;
public:


	void invertir(Nodo *n) {
		if(!(n->sig == this->ult))
			invertir(n->sig);
		n->sig->sig = n;
	}
	void invertir() {
		if(this->ult == nullptr) return;
		Nodo * temp = this->prim;
		Nodo * act = this->prim;
		if(this->prim == this->ult) return;
		this->prim=this->ult;
		invertir(act);
		this->ult = temp;
		this->ult->sig = nullptr;
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
