#ifndef PILA_H
#define PILA_H

#include <iostream>
using namespace std;
#include <assert.h>

template <class T>
class Pila abstract {

public:

	virtual ~Pila() {}
	
	// Inserta un elemento en el tope
	virtual void Push(const T &e) abstract;

	// Returna el elemento del tope
	virtual const T& Top() abstract;

	// Extrae un elemento del tope y lo retorna
	virtual T Pop() abstract;

	// Vacia toda la pila
	virtual void Vaciar() abstract;

	// Retorna la cantidad de elementos de la pila
	virtual unsigned int Largo() const abstract;

	// Reorna true si la pila esta vacia
	virtual bool EsVacia() const abstract;

	virtual Pila<T> &operator=(const Pila<T> &p) abstract; 

protected:
	Pila() {}
	Pila(const Pila<T> &p) {}

};


#endif