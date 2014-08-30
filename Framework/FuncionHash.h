#pragma once

typedef unsigned int nat;

#include "Funcion.h"

template <class T>
class FuncionHash abstract : public Funcion1<T,nat>
{
public:
	virtual nat CodigoDeHash(const T& dato) const abstract;
protected:
	nat Evaluar(const T& t) const { return CodigoDeHash(t); }
};
