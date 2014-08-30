#ifndef PRUEBASPROPIAS_H
#define PRUEBASPROPIAS_H

#include "Prueba.h"
#include "ConductorPrueba.h"
#include "InterfazDelSistemaImp.h"
#include "ExpresionImp.h"

#include <iostream>
using namespace std;

class PruebasPropias : public Prueba  
{

public:
	PruebasPropias(ConductorPrueba* conductor);
	virtual ~PruebasPropias();
	virtual void correrPruebaConcreta();
	virtual void pruebasPropiasOK();
	virtual void pruebasPropiasERROR();




protected:
	virtual char* getNombre()const;

private:

	void CreacionDeHojas();

	void AsignacionDeExpresionesACeldas();

	void Prueba_OK1_EXPRESIONES();
	void Prueba_OK2_EXPRESIONES();
	void Prueba_OK3_EXPRESIONES();	
	void Prueba_OK4_EXPRESIONES();	
	void Prueba_OK5_EXPRESIONES();

	void Prueba_OK1_PLANILLA();
	void Prueba_OK2_PLANILLA();
	void Prueba_OK3_PLANILLA();	
	void Prueba_OK4_PLANILLA();	
	void Prueba_OK5_PLANILLA();	
	void Prueba_OK6_PLANILLA();
	void Prueba_OK7_PLANILLA();


	void Prueba_ERROR1_EXPRESION();
	void Prueba_ERROR1_PLANILLA();


	InterfazDelSistema* interfaz;
};

#endif