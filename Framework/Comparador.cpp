#ifndef COMPARADOR_CPP
#define COMPARADOR_CPP

#include "Comparador.h"

template <class T>
Comparador<T>::~Comparador()
{
}

template <class T>
bool Comparador<T>::SonIguales(const T& t1, const T& t2) const
{
	return Comparar(t1, t2) == IGUALES;
}

template <class T>
bool Comparador<T>::SonDistintos(const T& t1, const T& t2) const
{
	// Se define que los elementos son distintos, si el
	// resultado de la comparación no da IGUALES,
	// por lo tanto SonDistintos devuelve true si el comparar
	// devuelve MENOR, MAYOR o DISTINTOS
	return Comparar(t1, t2) != IGUALES;
}

template <class T>
bool Comparador<T>::EsMenor(const T& t1, const T& t2) const
{
	return Comparar(t1, t2) == MENOR;
}

template <class T>
bool Comparador<T>::EsMayor(const T& t1, const T& t2) const
{
	return Comparar(t1, t2) == MAYOR;
}


template <class T>
CompRetorno Comparador<T>::ComparadorOperadores::Comparar(const T& t1, const T& t2) const
{
	__if_exists(T::operator==)
	{
		if (t1 == t2)
			return IGUALES;
	}
	__if_exists(T::operator<)
	{
		if (t1 < t2)
			return MENOR;
	}
	__if_exists(T::operator>)
	{
		if (t1 > t2)
			return MAYOR;
	}

	return DISTINTOS;
}


template <class T>
const Comparador<T>& Comparador<T>::Default = Comparador<T>::ComparadorOperadores();

#endif