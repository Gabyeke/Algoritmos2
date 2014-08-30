#ifndef CONCATITERACION_CPP
#define CONCATITERACION_CPP

#include "ConcatIteracion.h"

template <class T>
ConcatIteracion<T>::ConcatIteracion(Puntero<Iteracion<T>> parte1, Puntero<Iteracion<T>> parte2)
{
	m_Parte1 = parte1;
	m_Parte2 = parte2;
}

template <class T>
void ConcatIteracion<T>::Reiniciar()
{
	m_Parte1.Reiniciar();
	m_Parte2.Reiniciar();
	m_PrimeraParte = m_Parte1.HayElemento();
}

template <class T>
bool ConcatIteracion<T>::HayElemento() const
{
	return (m_PrimeraParte ? m_Parte1 : m_Parte2).HayElemento();
}

template <class T>
const T& ConcatIteracion<T>::ElementoActual() const
{
	return (m_PrimeraParte ? m_Parte1 : m_Parte2).ElementoActual();
}

template <class T>
void ConcatIteracion<T>::Avanzar()
{
	if (m_PrimeraParte)
	{
		m_Parte1++;
		m_PrimeraParte = m_Parte1.HayElemento();
	}
	else
		m_Parte2++;
}

#endif