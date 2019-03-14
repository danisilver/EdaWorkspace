#ifndef GTREE_H_
#define GTREE_H_

#include <memory>   // shared_ptr, make_shared
#include <stdexcept>
#include <stack>
#include <vector>
#include <queue>
#include <iostream>

template <class T>
class gtree {
protected:
	struct TreeNode;
	using Link = std::shared_ptr<TreeNode>;
	struct TreeNode {
		TreeNode(T const &e) : elem(e) {}
		TreeNode(T const &e, std::vector<Link> st) : elem(e), st(st) {};
		T elem;
		std::vector<Link> st;
	};

	Link raiz;

	gtree(Link const &r) : raiz(r) {}
public:
	// árbol vacío
	gtree() : raiz(nullptr) {}

	// árbol hoja
	gtree(T const& e) :
		raiz(std::make_shared<TreeNode>(e, nullptr)) {}

	gtree(T const& e, std::vector<gtree<T>> const &r) :raiz(std::make_shared<TreeNode>(e)) {
		for (unsigned int i = 0; i < r.size(); ++i) {
			raiz->st.push_back(r[i].raiz);
		}
	}

	bool empty() const {
		return raiz == nullptr;
	}

	// consultar la raíz
	T const& root() const {
		if (empty()) throw std::domain_error("El arbol vacio no tiene raiz.");
		else return raiz->elem;
	}


	// consultar el hijo izquierdo
	std::vector<gtree<T>> subtrees() const {
		if (empty()) throw std::domain_error("El arbol vacio no tiene hijos");
		else {
			std::vector<gtree<T>> subt;
			for (unsigned int i = 0; i < raiz->st.size(); ++i) {
				std::vector<Link> v = raiz->st;
				subt.push_back(v[i]);
			}
			return subt;
		}
	}

};

// lee un árbol binario de la entrada estándar
gtree<int> leerArbol(int vacio) {
	int raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return { raiz, {} };
	}
	else { // leer recursivamente los hijos
		std::vector<gtree<int>> v;
		for (int i = 0; i < raiz; ++i) {
			gtree<int> subtree = leerArbol(vacio);
			v.push_back(subtree);
		}
		return { raiz, v };
	}
}

#endif /* GTREE_H_ */
