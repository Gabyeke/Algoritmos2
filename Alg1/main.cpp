#include "ConductorPruebaObl3.h"
#include "InterfazDelSistema.h"
#include "interfazdelsistemaimp.h"
#include "Expresion.h"
#include "ExpresionImp.h"
#include "ExpresionCte.h"
#include "ListaImp.h"

#include <iostream>
using namespace std;

void main()
{
	ConductorPrueba* prueba = new ConductorPruebaObl3();
	prueba->correrPrueba();
	delete prueba;
	system("pause");
}

