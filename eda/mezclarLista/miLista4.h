//E53
// Alejandro Ruiz Valero


#include <iostream>
#include <fstream>
#include "queue_eda.h"

template <typename T>
class miLista4:public queue<T> {

	using Nodo = typename queue<T>::Nodo;
public:

	void cmp(Nodo *izq, Nodo *der){
		if (izq == nullptr) {
			izq->sig = der;
			return;
		}
		if (der == nullptr) {
			der->sig = der;
			return;
		}

		if(izq->elem < der->elem) {
			cmp(izq->sig, der);
			izq->sig = der;
		} else {
			cmp(izq, der->sig);
			der->sig = izq;
		}
	}

	void mezclar(miLista4<T> &subcola) {
		Nodo * act = this->prim;
		Nodo * subact = subcola.prim;

		cmp(act, subact);
		if(subcola.prim->elem < this->prim->elem)
			this->prim = subcola.prim;
		if (subcola.ult->elem > this->ult->elem)
			this->ult = subcola.ult;


		this->nelems += subcola.nelems;
		subcola.prim = nullptr;
		subcola.ult = nullptr;
		subcola.nelems = 0;
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
