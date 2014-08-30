#ifndef ITERABLE_H
#define ITERABLE_H

#include "Cadena.h"
#include "Iterador.h"

#include <iostream>
using namespace std;

template <class T>
class Iterable abstract
{
	friend ostream& operator<< <>(ostream& out, const Iterable<T>& iterable);
	
public:
	virtual ~Iterable(){}

	// Retorna un nuevo iterador sobre la estructura
	// Postcondición: El iterador se encuentra reiniciado

	virtual Iterador<T> GetIterador() const abstract; 
};

template <class T>
ostream& operator<< <>(ostream& out, const Iterable<T>& iterable)
{
	Cadena separador = "";
	Cadena separadorComa = ", ";
	for (Iterador<T> &it = iterable.GetIterador(); !it.EsFin(); it++)
	{
		out << separador << it->Elemento();
		separador = separadorComa;
	}
	return out;
}

#endif