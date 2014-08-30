#ifndef CONDUCTOR_PRUEBA_H
#define CONDUCTOR_PRUEBA_H

#include "EstadisticaPrueba.h"
#include "ManejadorImpresionPrueba.h"
#include "ManejadorSalidaPrueba.h"
#include "Prueba.h"

#include <iostream>
using namespace std;

class Prueba;

class ConductorPrueba
{
	friend Prueba;
public:
	ConductorPrueba();
	virtual ~ConductorPrueba();

	virtual void correrPrueba();

protected:	
	virtual void correrPruebaConcreta()=0;
	virtual char* getNombre()const=0;

	virtual void ver(TipoRet retorno, TipoRet retornoEsperado, char* comentario = "");

	EstadisticaPrueba&			getEstadisticaGlobal();
	ManejadorImpresionPrueba&	getManejadorImpresion();
	ManejadorSalidaPrueba&		getManejadorSalida();
private:
	EstadisticaPrueba estadisticaGlobal;
};

#endif
