#pragma once

#include "Set.h"
#include "Array.h"
#include "NodoSet.h"

template <class T>
class SetNoAcotado : public Set<T>
{
public:
	SetNoAcotado();

	void Insertar(const T &x);

	bool EsVacio() const;
	bool EsLleno() const;
	nat Tamanio() const;
	bool Pertenece(const T &x) const;

	Puntero<Set<T>> Union(Puntero<Set<T>> A) const;
	Puntero<Set<T>> Interseccion(Puntero<Set<T>> A) const;
	Puntero<Set<T>> Diferencia(Puntero<Set<T>> A) const;

	Iterador<T> ObtenerIterador() const;

private:
	Puntero<NodoSet<T>> set;
	nat tamanio;
};

#include "SetNoAcotado.cpp"
