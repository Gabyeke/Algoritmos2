#pragma once

#include "Iteracion.h"
#include "Puntero.h"

template <class T, class U, typename Conv>
class ConvertIteracion : public Iteracion<U>
{
public:
	ConvertIteracion(Puntero<Iteracion<T>> toConvert);

	void Reiniciar();
	bool HayElemento() const;
	const U& ElementoActual() const;
	void Avanzar();

private:
	Puntero<Iteracion<T>> m_ToConvert;
	mutable U m_Actual;
};

#include "ConvertIteracion.cpp"
