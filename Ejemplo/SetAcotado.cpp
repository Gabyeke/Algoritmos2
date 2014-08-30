#ifndef SETACOTADO_CPP
#define SETACOTADO_CPP

#include "SetAcotado.h"
#include "ArrayIteracion.h"

template <class T>
SetAcotado<T>::SetAcotado(nat tamanio)
{
	pos = 0;
	set = Array<T>(tamanio);
}

template <class T>
void SetAcotado<T>::Insertar(const T &x)
{
	if (!EsLleno() && !Pertenece(x))
	{
		set[pos] = x;
		pos++;
	}
}

template <class T>
bool SetAcotado<T>::EsVacio() const
{
	return pos == 0;
}

template <class T>
bool SetAcotado<T>::EsLleno() const
{
	return pos == set.Largo;
}

template <class T>
nat SetAcotado<T>::Tamanio() const
{
	return pos;
}

template <class T>
bool SetAcotado<T>::Pertenece(const T &x) const
{
	for (Iterador<T> it = ObtenerIterador(); it.HayElemento(); it++)
	{
		if (x == *it)
			return true;
	}
	return false;
}

template <class T>
Puntero<Set<T>> SetAcotado<T>::Union(Puntero<Set<T>> A) const
{
	Puntero<Set<T>> res = new SetAcotado<T>(Tamanio() + A->Tamanio());
	for (Iterador<T> it = ObtenerIterador(); it.HayElemento(); it++)
		res->Insertar(*it);
	for (Iterador<T> it = A->ObtenerIterador(); it.HayElemento(); it++)
		res->Insertar(*it);
	return res;
}
	
template <class T>
Puntero<Set<T>> SetAcotado<T>::Interseccion(Puntero<Set<T>> A) const
{
	Puntero<Set<T>> res = new SetAcotado<T>(Tamanio() + A->Tamanio());
	for (Iterador<T> it = ObtenerIterador(); it.HayElemento(); it++)
	{
		if (A->Pertenece(*it))
			res->Insertar(*it);
	}
	return res;
}

template <class T>
Puntero<Set<T>> SetAcotado<T>::Diferencia(Puntero<Set<T>> A) const
{
	Puntero<Set<T>> res = new SetAcotado<T>(Tamanio() + A->Tamanio());
	for (Iterador<T> it = ObtenerIterador(); it.HayElemento(); it++)
	{
		if (!A->Pertenece(*it))
			res->Insertar(*it);
	}
	return res;
}

template <class T>
Iterador<T> SetAcotado<T>::ObtenerIterador() const
{
	return new ArrayIteracion<T>(set, pos);
}

#endif