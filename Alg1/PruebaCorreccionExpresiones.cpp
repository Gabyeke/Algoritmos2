#include "PruebacorreccionExpresiones.h"

#include <iostream>
using namespace std;

PruebaCorreccionExpresiones::PruebaCorreccionExpresiones(ConductorPrueba* conductor)
:Prueba(conductor)
{
}

PruebaCorreccionExpresiones::~PruebaCorreccionExpresiones()
{
}

void PruebaCorreccionExpresiones::correrPruebaConcreta()
{

}

char* PruebaCorreccionExpresiones::getNombre()const
{
	return "PruebaCorreccionExpresiones";
}

