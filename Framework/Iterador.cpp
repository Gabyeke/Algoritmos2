#ifndef ITERADOR_CPP
#define ITERADOR_CPP

#include "Iterador.h"
#include "ConversorCast.h"
#include "ConvertIteracion.h"

template <class T>
Iterador<T>::Iterador(Iteracion<T>* iteracion)
: m_Iteracion(iteracion)
{
	Reiniciar();
}

template <class T>
Iterador<T>::Iterador(const Puntero<Iteracion<T>>& iteracion)
: m_Iteracion(iteracion)
{
	Reiniciar();
}

template <class T>
Iterador<T>::Iterador(const Iterador<T>& iterador)
: 	m_Iteracion(iterador.m_Iteracion)
{
}

template <class T>
const Iterador<T>& Iterador<T>::operator=(Iteracion<T>* iteracion)
{
	m_Iteracion = iteracion;
	Reiniciar();
	return *this;
}

template <class T>
const Iterador<T>& Iterador<T>::operator=(const Puntero<Iteracion<T>>& iteracion)
{
	m_Iteracion = iteracion;
	Reiniciar();
	return *this;
}

template <class T>
const Iterador<T>& Iterador<T>::operator=(const Iterador<T>& iterador)
{
	m_Iteracion = iterador.m_Iteracion;
	return *this;
}

template <class T>
void Iterador<T>::Reiniciar()
{
	if (m_Iteracion)
		m_Iteracion->Reiniciar();
}

template <class T>
bool Iterador<T>::HayElemento() const
{
	return m_Iteracion && m_Iteracion->HayElemento();
}

template <class T>
const T& Iterador<T>::ElementoActual() const
{
	assert(HayElemento());
	return m_Iteracion->ElementoActual();
}

template <class T>
void Iterador<T>::Avanzar()
{
	assert(HayElemento());
	m_Iteracion->Avanzar();
}

template <class T>
Iterador<T>& Iterador<T>::operator++()
{
	Avanzar();
	return *this;
}

template <class T>
Iterador<T>& Iterador<T>::operator++(int)
{
	Avanzar();
	return *this;
}

template <class T>
const T& Iterador<T>::operator*() const
{
	return ElementoActual();
}

template <class T>
template <class U> Iterador<T>::operator Iterador<U>() const
{
	return Convert<U, ConversorCast<T,U>>();
}

template <class T>
template <class U, typename Conv>
Iterador<U> Iterador<T>::Convert() const
{
	return Iterador<U>(m_Iteracion ? new ConvertIteracion<T,U,Conv>(m_Iteracion) : NULL);
}

#endif