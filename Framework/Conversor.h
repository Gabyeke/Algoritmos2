#pragma once

#include "Funcion.h"

// Convierte algo de tipo T en algo de tipo U
template <class T, class U>
class Conversor abstract : public Funcion1<T,U>
{
public:
	virtual ~Conversor(){}
	U operator()(const T& t) const { return Convertir(t); }
protected:
	virtual U Convertir(const T& t) const abstract;
	U Evaluar(const T& t) const { return Convertir(t); }
};
