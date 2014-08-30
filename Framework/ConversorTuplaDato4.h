#pragma once

#include "Conversor.h"
#include "Tupla.h"

template <class T1, class T2, class T3, class T4>
class ConversorTuplaDato4 : public Conversor<Tupla<T1,T2,T3,T4>, T4>
{
public:
	virtual ~ConversorTuplaDato4(){}
protected:
	T4 Convertir(const Tupla<T1,T2,T3,T4>& t) const { return t.Dato4; }
};