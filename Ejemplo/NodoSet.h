#pragma once

#include "Puntero.h"

template <class U>
struct NodoSet
{
	U Dato;
	Puntero<NodoSet<U>> Sig;
};
