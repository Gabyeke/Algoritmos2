#ifndef ITERADORNOACOTADO_CPP
#define ITERADORNOACOTADO_CPP

#include "IteradorNoAcotado.h"

template <class T>
IteradorNoAcotado<T>::IteradorNoAcotado(Puntero<NodoSet<T>> iterable)
: ppio(iterable)
{
}


template <class T>
void IteradorNoAcotado<T>::Reiniciar()
{
	actual = ppio;
}

template <class T>
bool IteradorNoAcotado<T>::HayElemento() const
{
	return actual != NULL;
}

template <class T>
const T& IteradorNoAcotado<T>::ElementoActual() const
{
	return actual->Dato;
}

template <class T>
void IteradorNoAcotado<T>::Avanzar()
{
	actual = actual->Sig;
}

#endif