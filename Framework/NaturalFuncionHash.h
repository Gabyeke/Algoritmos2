#ifndef NATURALFUNCIONHASH_H
#define NATURALFUNCIONHASH_H

#include "FuncionHash.h"

class NaturalFuncionHash : public FuncionHash<nat>
{
public:
	nat CodigoDeHash(const nat& dato) const { return dato; }
};

#endif