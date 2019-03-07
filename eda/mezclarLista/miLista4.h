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

		act = cmp(this->ult, subcola.ult);
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
	/*
			if(!this->empty()) {
				cmp(act, subact);
			} else {
				this->prim = subcola.prim;
				this->ult = subcola.ult;
			}

			if(subcola.prim->elem < this->prim->elem)//Segfault
				this->prim = subcola.prim;
			if (subcola.ult->elem > this->ult->elem)
				this->ult = subcola.ult;

	*/
	/*
		Nodo * act = this->prim;


		while(subcola.prim != nullptr){
			Nodo *actprim = subcola.prim;
			Nodo *antprim = actprim;
			while(subcola.prim != nullptr && act->elem > subcola.front()){
				antprim = actprim;
				actprim = actprim->sig;
			}
			if(antprim != subcola.prim){
				antprim->sig = this->prim;
				this->prim = subcola.prim;
				subcola.prim = actprim;
			}

			Nodo *anterior = act;
			while(subcola.prim != nullptr && act->elem < subcola.front()){
				anterior = act;
				act = act->sig;
			}
			if(anterior != act){
				Nodo *next = subcola.prim;
				subcola.prim = subcola.prim->sig;
				next->sig = act;
				anterior->sig = next;
			}
		}*/

	void mostrar() {

		Nodo * act = this->prim;
		while (act != nullptr) {
			std::cout<< act->elem << " ";
			act = act->sig;
		}
		std::cout << std::endl;

	}

/*	void cmp(Nodo *izq, Nodo *der){
		if (izq == nullptr || der == nullptr)  return;

		if(izq->elem <= der->elem) {
			cmp(izq->sig, der);
			izq->sig = der;
		} else {
			cmp(izq, der->sig);
			der->sig = izq;
		}
	}*/

};
