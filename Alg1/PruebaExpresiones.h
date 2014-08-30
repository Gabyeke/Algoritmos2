#ifndef PRUEBA_EXP_H
#define PRUEBA_EXP_H

#include "Prueba.h"
#include "ConductorPrueba.h"
#include "ExpresionImp.h"

#include <iostream>
using namespace std;

class PruebaExpresiones : public Prueba  
{

public:
	PruebaExpresiones(ConductorPrueba* conductor);
	virtual ~PruebaExpresiones();
	virtual void correrPruebaConcreta();

protected:
	virtual char* getNombre()const;

private:
	void pruebasEjemploOK();
	void pruebasEjemploERROR();
	
	void PruebaSimple1();	
	void PruebaSimple2();	

	void Prueba1();
	void Prueba2();
	void Prueba3();
	void PruebaERROR1();
};

#endif
