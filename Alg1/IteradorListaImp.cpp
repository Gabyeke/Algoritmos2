#ifndef ITERADORLISTAIMP_CPP
#define ITERADORLISTAIMP_CPP

#include "IteradorListaImp.h"

#include <iostream>
using namespace std;

template <class T>
IteradorListaImp<T>::IteradorListaImp() {
	actual = ppio = NULL;
}

template <class T>
IteradorListaImp<T>::IteradorListaImp(const ListaImp<T> &l) {
	ppio = actual = l.ppio;
}

template <class T>
IteradorListaImp<T>::IteradorListaImp(const IteradorListaImp<T> &it) {
	ppio = it.ppio;
	actual = it.actual;
}
	
template <class T>
Iterador<T> &IteradorListaImp<T>::operator=(const IteradorListaImp<T> &it) {
	if (this != &it) {
		ppio = it.ppio;
		actual = it.actual;
	}
	return *this;
}

template <class T>
Iterador<T> *IteradorListaImp<T>::Clon() const {
	IteradorListaImp<T> *it = new IteradorListaImp<T>(*this);
	return it;
}

template <class T>
IteradorListaImp<T>::~IteradorListaImp() {
}

template <class T>
const T &IteradorListaImp<T>::Elemento() const {
	return actual->dato;
}

template <class T>
T &IteradorListaImp<T>::ElementoInseguro() const {
	return actual->dato;
}

template <class T>
void IteradorListaImp<T>::Resto() {
	actual = actual->sig;
}

template <class T>
bool IteradorListaImp<T>::EsFin() const {
	return actual == NULL;
}

template <class T>
void IteradorListaImp<T>::Principio() {
	actual = ppio;
}


#endif