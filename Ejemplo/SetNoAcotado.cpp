#ifndef SETNOACOTADO_CPP
#define SETNOACOTADO_CPP

#include "SetNoAcotado.h"
#include "IteradorNoAcotado.h"

template <class T>
SetNoAcotado<T>::SetNoAcotado()
{
	set = NULL;
	tamanio = 0;
}

template <class T>
void SetNoAcotado<T>::Insertar(const T &x)
{
	if (!EsLleno() && !Pertenece(x))
	{
		Puntero<NodoSet<T>> nuevo = new NodoSet<T>();
		nuevo->Dato = x;
		nuevo->Sig = set;
		set = nuevo;
		tamanio++;
	}
}

template <class T>
bool SetNoAcotado<T>::EsVacio() const
{
	return tamanio == 0;
}

template <class T>
bool SetNoAcotado<T>::EsLleno() const
{
	return false;//Es no Acotado
}

template <class T>
nat SetNoAcotado<T>::Tamanio() const
{
	return tamanio;	
}

template <class T>
bool SetNoAcotado<T>::Pertenece(const T &x) const
{
	for (Iterador<T> it = ObtenerIterador(); it.HayElemento(); it++)
	{
		if (x == *it)
			return true;
	}
	return false;
}

template <class T>
Puntero<Set<T>> SetNoAcotado<T>::Union(Puntero<Set<T>> A) const
{
	Puntero<Set<T>> res = new SetNoAcotado<T>();
	for (Iterador<T> it = ObtenerIterador(); it.HayElemento(); it++)
		res->Insertar(*it);
	for (Iterador<T> it = A->ObtenerIterador(); it.HayElemento(); it++)
		res->Insertar(*it);
	return res;
}
	
template <class T>
Puntero<Set<T>> SetNoAcotado<T>::Interseccion(Puntero<Set<T>> A) const
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
Puntero<Set<T>> SetNoAcotado<T>::Diferencia(Puntero<Set<T>> A) const
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
Iterador<T> SetNoAcotado<T>::ObtenerIterador() const
{
	return new IteradorNoAcotado<T>(set);	
}

#endif