#ifndef CONDUCTOR_PRUEBA_OBL3_H
#define CONDUCTOR_PRUEBA_OBL3_H

#include "ConductorPrueba.h"
#include "PruebaExpresiones.h"
#include "PruebaPlanilla.h"
#include "PruebasPropias.h"
#include "pruebacorreccionplanilla.h"
#include "PruebacorreccionExpresiones.h"

#include <iostream>
using namespace std;

class ConductorPruebaObl3 : public ConductorPrueba 
{
public:
	ConductorPruebaObl3();
	virtual ~ConductorPruebaObl3();

protected:
	virtual void correrPruebaConcreta();
	virtual char* getNombre()const;

private:
	// Empezar aqui a agregar los archivos de prueba
	Prueba* pruebaExpresiones;
	Prueba* pruebaPlanilla;

	Prueba* pruebaCorreccionExpresiones;
	Prueba* pruebaCorreccionPlanilla;

	Prueba* pruebasPropias;

	/* Ej:
	
	Prueba* miPrueba;

	*/

	// Terminar aqui
};

#endif