#ifndef PILAIMP_H
#define PILAIMP_H

#include "Pila.h"
#include "ListaImp.h"
#include "Planilla.h"
#include "Hoja.h"
#include <iostream>
using namespace std;
#include <assert.h>

template <class T>
class PilaImp:public Pila <T>{
public:
	
	PilaImp();
	PilaImp(const Pila<T> &p);
	~PilaImp();
	
	// Inserta un elemento en el tope
	void Push(const T &e);

	// Returna el elemento del tope
	const T& Top();

	// Extrae un elemento del tope y lo retorna
	T Pop();

	// Vacia toda la pila
	void Vaciar();

	// Retorna la cantidad de elementos de la pila
	unsigned int Largo() const;

	// Reorna true si la pila esta vacia
	bool EsVacia() const;

	Pila<T> &operator=(const Pila<T> &p);



	//Atributos
private:
	ListaImp<Planilla> *listaDeOperaciones; //no sabemos que va aca pero van los datos de las operaciones realizadas
};

#include "PilaImp.cpp"

#endif