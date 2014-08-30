#include "CadenaFuncionHash.h"

nat CadenaFuncionHash::CodigoDeHash(const Cadena& c) const
{
	nat hashCode = 0;
	for (nat i = 0; i < c.Largo; i++)
		hashCode += c[i];
	return hashCode;
}
