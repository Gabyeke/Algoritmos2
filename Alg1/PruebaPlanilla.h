#ifndef PRUEBAPLANILLA_H
#define PRUEBAPLANILLA_H

#include "Prueba.h"
#include "ConductorPrueba.h"
#include "InterfazDelSistemaImp.h"
#include "ExpresionImp.h"

#include <iostream>
using namespace std;

class PruebaPlanilla : public Prueba  
{

public:
	PruebaPlanilla(ConductorPrueba* conductor);
	virtual ~PruebaPlanilla();
	virtual void correrPruebaConcreta();

protected:
	virtual char* getNombre()const;

private:
	InterfazDelSistema* interfaz;

	void PruebaCreacionHojas();	
	void PruebaRenombrarHojas();
	void PruebaEliminarHojas();
	void PruebaDeshacerUltimaOperacion();

	void PruebaExpresiones1();
	void PruebaExpresiones2();
	void PruebaExpresiones3();
	void PruebaExpresiones4();
	void PruebaEvaluarReferencia();
	void PruebaError();
	void InsertarHojas(); //Crea nuevamente la interfaz y crea las Hojas
	void RenombrarHojas();
	void EliminarHojas();
	void CrearHojas(); //Crea nuevamente la interfaz y Hojas necesarias para la prueba
};

#endif