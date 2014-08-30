#pragma once

#include "Iteracion.h"
#include "Puntero.h"

template <class T>
class ConcatIteracion : public Iteracion<T>
{
public:
	ConcatIteracion(Puntero<Iteracion<T>> parte1, Puntero<Iteracion<T>> parte2);

	void Reiniciar();
	bool HayElemento() const;
	const T& ElementoActual() const;
	void Avanzar();

private:
	Puntero<Iteracion<T>> m_Parte1;
	Puntero<Iteracion<T>> m_Parte2;
	bool m_PrimeraParte;
	//mutable T m_Actual;
};

#include "ConcatIteracion.cpp"