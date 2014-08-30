#include "ConductorPruebaObl3.h"

#include <iostream>
using namespace std;

ConductorPruebaObl3::ConductorPruebaObl3()
{
	//Empezar aqui a instanciar los archivos de prueba
	
	pruebaExpresiones = new PruebaExpresiones(this);

	pruebaPlanilla = new PruebaPlanilla(this);

	pruebaCorreccionPlanilla = new PruebaCorreccionPlanilla(this);

	pruebaCorreccionExpresiones = new PruebaCorreccionExpresiones(this);

	pruebasPropias = new PruebasPropias(this);


	/* Ej:
	
	miPrueba = new MiPrueba(this);

	Recordar que el constructor de la prueba recibe el Conductor

	*/

	// Terminar aqui
}

ConductorPruebaObl3::~ConductorPruebaObl3()
{
	// Empezar aqui a borrar los archivos de prueba
	delete pruebaExpresiones;

	delete pruebaPlanilla;

	delete pruebaCorreccionPlanilla;

	delete pruebaCorreccionExpresiones;

	delete pruebasPropias;

	/* Ej:
	
	delete miPrueba;

	*/

	// Terminar aqui
}

void ConductorPruebaObl3::correrPruebaConcreta()
{
	// Empezar aqui a llamar los metodos de prueba
	pruebaExpresiones->correrPrueba();

	pruebaPlanilla->correrPrueba();

	pruebaCorreccionExpresiones->correrPrueba();

	pruebaCorreccionPlanilla->correrPrueba();

	pruebasPropias->correrPrueba();

	/* Ej:
	
	miPrueba->correrPrueba();

	*/

	// Terminar aqui
}

char* ConductorPruebaObl3::getNombre()const
{
	return "PruebaPlanillaDeCalculo";
}
