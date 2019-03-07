// A21
// Gallardo Cruzado Mario D


#include <iostream>
#include <fstream>
#include "queue_eda.h"

template <typename T>
class miLista4:public queue<T> {

	using Nodo = typename queue<T>::Nodo;
public:

	Nodo *cmp(Nodo *izq, Nodo *der){
		if (izq == nullptr && der == nullptr)  return nullptr;
		if(izq == nullptr) return der;
		if(der == nullptr) return izq;

		if(izq->elem <= der->elem) {
			Nodo *sig = cmp(izq->sig, der);
			izq->sig = sig;
			return izq;
		} else {
			Nodo *sig = cmp(der->sig, izq);
			der->sig = sig;
			return der;
		}
	}

	void mezclar(miLista4<T> &subcola) {
		Nodo *act = this->prim;
		Nodo *subact = subcola.prim;

		Nodo *prim = cmp(act, subact);
		this->prim = prim;

		//act = cmp(this->ult, subcola.ult);
		Nodo *ult = act;
		while(act != nullptr){
			act = act->sig;
			ult = act;
		}
		this->ult = ult;


		this->nelems += subcola.nelems;
		subcola.prim = subcola.ult = nullptr;
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
