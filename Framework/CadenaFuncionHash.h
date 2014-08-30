#pragma once

#include "Cadena.h"
#include "FuncionHash.h"

class CadenaFuncionHash : public FuncionHash<Cadena>
{
public:
	nat CodigoDeHash(const Cadena& c) const;
};
