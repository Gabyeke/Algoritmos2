#ifndef PRUEBACORRECCIONPLANILLA_H
#define PRUEBACORRECCIONPLANILLA_H

#include "Prueba.h"
#include "ConductorPrueba.h"
#include "InterfazDelSistemaImp.h"
#include "ExpresionImp.h"

#include <iostream>
using namespace std;

class PruebaCorreccionPlanilla : public Prueba  
{

public:
	PruebaCorreccionPlanilla(ConductorPrueba* conductor);
	virtual ~PruebaCorreccionPlanilla();
	virtual void correrPruebaConcreta();

protected:
	virtual char* getNombre()const;

private:
	InterfazDelSistema* interfaz;
};

#endif