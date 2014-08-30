#include "ConductorPrueba.h"

#include <iostream>
using namespace std;

ConductorPrueba::ConductorPrueba()
{
}

ConductorPrueba::~ConductorPrueba()
{
}

void ConductorPrueba::correrPrueba()
{
	getManejadorSalida().crearDirectorio(getNombre());

	correrPruebaConcreta();
	
	getManejadorSalida().setSalidaArchivo("Resultados Totales.txt");
	getManejadorImpresion().imprimirTotalResultados(getEstadisticaGlobal());
	getManejadorSalida().setSalidaPantalla();
}

void ConductorPrueba::ver(TipoRet retorno, TipoRet retornoEsperado, char* comentario)
{
	getManejadorImpresion().imprimirResultado(retorno,retornoEsperado,comentario);

	getEstadisticaGlobal().actualizarEstadisticas(retorno,retornoEsperado);
}

EstadisticaPrueba& ConductorPrueba::getEstadisticaGlobal()
{
	return estadisticaGlobal;
}

ManejadorImpresionPrueba& ConductorPrueba::getManejadorImpresion()
{
	return *ManejadorImpresionPrueba::getInstancia();
}

ManejadorSalidaPrueba& ConductorPrueba::getManejadorSalida()
{
	return *ManejadorSalidaPrueba::getInstancia();
}