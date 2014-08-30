#pragma once

#include "Iterador.h"

template <class T>
class Iterable abstract
{
public:
	virtual ~Iterable(){}

	// Retorna un nuevo iterador sobre la estructura
	// Postcondici�n: El iterador se encuentra reiniciado
	virtual Iterador<T> ObtenerIterador() const abstract;
};
