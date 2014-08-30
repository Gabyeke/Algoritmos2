#ifndef PRUEBA_H
#define PRUEBA_H


#include "TipoRetorno.h"
#include "ConductorPrueba.h"
#include "ManejadorImpresionPrueba.h"
#include "ManejadorSalidaPrueba.h"

#include <iostream>
using namespace std;
#include <string.h>

class ConductorPrueba;

class Prueba  
{
public:
	Prueba(ConductorPrueba* conductor);
	virtual ~Prueba();

	virtual void correrPrueba();
protected:
	virtual void correrPruebaConcreta()=0;
	virtual char* getNombre()const=0;
	ManejadorImpresionPrueba&	getManejadorImpresion();
	ManejadorSalidaPrueba&		getManejadorSalida();

	void ver(TipoRet retorno, TipoRet retornoEsperado, char* comentario = "");

	EstadisticaPrueba& getEstadisticaPrueba();
private:
	EstadisticaPrueba estadisticaPrueba;
	ConductorPrueba* conductorPrueba;
};

#endif