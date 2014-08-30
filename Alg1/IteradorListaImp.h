#ifndef ITERADORLISTAIMP_H
#define ITERADORLISTAIMP_H

#include "Iterador.h"
#include "ListaImp.h"

#include <iostream>
using namespace std;

template <class T>
class ListaImp;

template <class T>
class NodoLista;

template <class T>
class IteradorListaImp : public Iterador<T> {
private:
	NodoLista<T> *actual;
	NodoLista<T> *ppio;

public:
	IteradorListaImp();
	IteradorListaImp(const ListaImp<T> &l);
	IteradorListaImp(const IteradorListaImp<T> &it);
		
	Iterador<T> &operator=(const IteradorListaImp<T> &it);
	Iterador<T> *Clon() const;

	virtual ~IteradorListaImp();

	const T &Elemento() const;
	T &ElementoInseguro() const;
	void Resto();
	bool EsFin() const;
	void Principio();
};

#include "IteradorListaImp.cpp"

#endif