#ifndef MATRIZITERACION_CPP
#define MATRIZITERACION_CPP

#include "MatrizIteracion.h"
#include "Matriz.h"

template <class T>
MatrizIteracion<T>::MatrizIteracion(const Matriz<T>& iterable)
: m_Iterable(iterable)
{
}

template <class T>
void MatrizIteracion<T>::Reiniciar()
{
	m_Posicion = 0;
}

template <class T>
bool MatrizIteracion<T>::HayElemento() const
{
	return m_Posicion < m_Iterable.Largo;
}

template <class T>
const Array<T>& MatrizIteracion<T>::ElementoActual() const
{
	return m_Iterable[m_Posicion];
}

template <class T>
void MatrizIteracion<T>::Avanzar()
{
	m_Posicion++;
}

#endif