#pragma once

#include "Set.h"
#include "Array.h"

#define MAX_LARGO 10

template <class T>
class SetAcotado : public Set<T>
{
public:
	SetAcotado(nat tamanio = MAX_LARGO);

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
	Array<T> set;
	nat pos;
};

#include "SetAcotado.cpp"
