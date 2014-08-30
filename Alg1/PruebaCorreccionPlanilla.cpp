#include "PruebaCorreccionPlanilla.h"

#include <iostream>
using namespace std;

PruebaCorreccionPlanilla::PruebaCorreccionPlanilla(ConductorPrueba* conductor)
:Prueba(conductor)
{
	interfaz = new InterfazDelSistemaImp();
}

PruebaCorreccionPlanilla::~PruebaCorreccionPlanilla()
{
	delete interfaz;
}
char* PruebaCorreccionPlanilla::getNombre()const
{
	return "PruebaCorreccionPlanilla";
}

void PruebaCorreccionPlanilla::correrPruebaConcreta()
{
}



