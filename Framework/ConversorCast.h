#pragma once

#include "Conversor.h"

template <class T, class U>
class ConversorCast : public Conversor<T, U>
{
public:
	virtual ~ConversorCast(){}
protected:
	U Convertir(const T& t) const { return t; }
};
