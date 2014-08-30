#pragma once

template <class T>
class Matriz;

#include "Array.h"
#include "Iteracion.h"

template <class T>
class MatrizIteracion : public Iteracion<const Array<T>>
{
public:
	MatrizIteracion(const Matriz<T>& iterable);

	void Reiniciar();
	bool HayElemento() const;
	const Array<T>& ElementoActual() const;
	void Avanzar();

private:
	Matriz<T> m_Iterable;
	nat m_Posicion;
};

#include "MatrizIteracion.cpp"