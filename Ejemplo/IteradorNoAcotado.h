#pragma once

#include "Iteracion.h"
#include "NodoSet.h"

template <class T>
class IteradorNoAcotado : public Iteracion<T>
{
public:
	IteradorNoAcotado(Puntero<NodoSet<T>> iterable);

	void Reiniciar();
	bool HayElemento() const;
	const T& ElementoActual() const;
	void Avanzar();

private:
	Puntero<NodoSet<T>> ppio;
	Puntero<NodoSet<T>> actual;
};

#include "IteradorNoAcotado.cpp"
