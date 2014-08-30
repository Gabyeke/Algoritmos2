#pragma once

#include "FuncionHash.h"

class IntFuncionHash : public FuncionHash<int>
{
public:
	nat CodigoDeHash(const int& i) const { return i < 0 ? -i : i; }
};
