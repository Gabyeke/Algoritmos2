#include "Prueba.h"

#include <iostream>
using namespace std;

Prueba::Prueba(ConductorPrueba* conductor)
{
	conductorPrueba = conductor;
}

Prueba::~Prueba()
{
}

void Prueba::ver(TipoRet retorno, TipoRet retornoEsperado, char* comentario)
{
	getEstadisticaPrueba().actualizarEstadisticas(retorno,retornoEsperado);
	
	conductorPrueba->ver(retorno,retornoEsperado,comentario);
}

EstadisticaPrueba& Prueba::getEstadisticaPrueba()
{
	return estadisticaPrueba;
}

ManejadorImpresionPrueba& Prueba::getManejadorImpresion()
{
	return *ManejadorImpresionPrueba::getInstancia();
}

ManejadorSalidaPrueba& Prueba::getManejadorSalida()
{
	return *ManejadorSalidaPrueba::getInstancia();
}

void Prueba::correrPrueba()
{
	char* nombrePrueba = getNombre();
	char* nombreArchivo = new char[strlen(nombrePrueba) + 5];
	strcpy_s(nombreArchivo, strlen(nombrePrueba) + 5, nombrePrueba);
	strcat_s(nombreArchivo, strlen(nombreArchivo) + 5, ".txt");

	getManejadorSalida().crearDirectorio(nombrePrueba);

	getManejadorSalida().setSalidaArchivo(nombreArchivo);

	delete []nombreArchivo;

	correrPruebaConcreta();
	
	getManejadorImpresion().imprimirTotalResultados(getEstadisticaPrueba());

	getManejadorSalida().cambiarDirectorio("..");
}