#pragma once

#include "Conversor.h"
#include "Tupla.h"

template <class T1, class T2, class T3 = DatoNulo, class T4 = DatoNulo>
class ConversorTuplaDato1 : public Conversor<Tupla<T1,T2,T3,T4>, T1>
{
public:
	virtual ~ConversorTuplaDato1(){}
protected:
	T1 Convertir(const Tupla<T1,T2,T3,T4>& t) const { return t.Dato1; }
};