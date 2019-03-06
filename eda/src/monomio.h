//Mario D Gallardo Cruzado
//A21
#ifndef MONOMIO_H_
#define MONOMIO_H_
#include <iostream>

class monomio {
public:
	int a;
	int exp;
	monomio(int a=0, int exp=0) {
		(*this).a = a;
		(*this).exp = exp;
	}

	bool operator<(monomio const &b) {
		return exp < b.exp;
	}

	void read(std::istream &cin) {
		int a, exp;
		cin >> a >> exp;
		*this = monomio(a, exp);
	}

	void print(std::ostream &cout) const {
		cout << a << ' ' << exp;
	}
};

inline std::istream &operator>>(std::istream &in, monomio &m) {
	m.read(in);
	return in;
}

inline std::ostream &operator<<(std::ostream &cout, monomio const &m) {
	m.print(cout);
	return cout;
}

#endif /* MONOMIO_H_ */
