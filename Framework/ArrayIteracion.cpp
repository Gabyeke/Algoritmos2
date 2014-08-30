#ifndef ARRAYITERACION_CPP
#define ARRAYITERACION_CPP

#include "ArrayIteracion.h"
#include "Array.h"

template <class T>
ArrayIteracion<T>::ArrayIteracion(const Array<T>& iterable)
: m_Iterable(iterable)
{
	m_Largo = iterable.Largo;
}

template <class T>
ArrayIteracion<T>::ArrayIteracion(const Array<T>& iterable, nat largo)
: m_Iterable(iterable)
{
	m_Largo = largo;
}

template <class T>
void ArrayIteracion<T>::Reiniciar()
{
	m_Posicion = 0;
}

template <class T>
bool ArrayIteracion<T>::HayElemento() const
{
	return m_Posicion < m_Largo;
}

template <class T>
const T& ArrayIteracion<T>::ElementoActual() const
{
	return m_Iterable[m_Posicion];
}

template <class T>
void ArrayIteracion<T>::Avanzar()
{
	m_Posicion++;
}

#endif