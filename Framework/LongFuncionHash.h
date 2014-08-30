#pragma once

#include "FuncionHash.h"

class LongFuncionHash : public FuncionHash<long>
{
public:
	nat CodigoDeHash(const long& l) const { return l < 0 ? -l : l; }
};
