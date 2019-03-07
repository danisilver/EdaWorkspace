// A21
// Gallardo Cruzado Mario D


#include <iostream>
#include <fstream>
#include "queue_eda.h"

template <typename T>
class miLista : public queue<T> {

	using Nodo = typename queue<T>::Nodo;
public:

	Nodo *intercambiar(Nodo *izq, Nodo *der){
		if(izq != nullptr) this->ult = izq;
		if(der == nullptr) return izq;
		if(izq == nullptr) return nullptr;

		izq->sig = intercambiar(der->sig, (der->sig ? der->sig->sig:nullptr));
		der->sig = izq;
		return der;
	}

	void invertirDosAdos() {
		if(this->size() < 2) return;

		this->prim = intercambiar(this->prim, this->prim->sig);
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
