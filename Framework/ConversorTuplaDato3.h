#pragma once

#include "Conversor.h"
#include "Tupla.h"

template <class T1, class T2, class T3, class T4 = DatoNulo>
class ConversorTuplaDato3 : public Conversor<Tupla<T1,T2,T3,T4>, T3>
{
public:
	virtual ~ConversorTuplaDato3(){}
protected:
	T3 Convertir(const Tupla<T1,T2,T3,T4>& t) const { return t.Dato3; }
};