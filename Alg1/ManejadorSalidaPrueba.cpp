#ifndef MANEJADOR_SALIDA_PRUEBA_CPP
#define MANEJADOR_SALIDA_PRUEBA_CPP

#include "ManejadorSalidaPrueba.h"

#include <iostream>
using namespace std;


ManejadorSalidaPrueba* ManejadorSalidaPrueba::instanciaManejador = NULL;

ManejadorSalidaPrueba::ManejadorSalidaPrueba()
{
	pantalla = cout.rdbuf();
}

ManejadorSalidaPrueba::~ManejadorSalidaPrueba()
{
	if ( archivoActual.is_open() )
		archivoActual.close();
}

ManejadorSalidaPrueba* ManejadorSalidaPrueba::getInstancia()
{
	if ( instanciaManejador == NULL )
		instanciaManejador = new ManejadorSalidaPrueba();

	return instanciaManejador;
}

void ManejadorSalidaPrueba::setSalidaArchivo(char* nombreArchivo)
{
	if ( archivoActual.is_open() )
	{
		archivoActual.close();
	}

	archivoActual.open(nombreArchivo,ios::out);

	printf("Se creo el archivo: %s\n", nombreArchivo);

	cout.rdbuf(archivoActual.rdbuf());
}

void ManejadorSalidaPrueba::setSalidaPantalla()
{
	if ( archivoActual.is_open() )
		archivoActual.close();

	cout.rdbuf(pantalla);
}

void ManejadorSalidaPrueba::crearDirectorio(char* nombreDirectorio)
{
	_mkdir(nombreDirectorio);
	cambiarDirectorio(nombreDirectorio);
	printf("Se creo el directorio: %s\n", nombreDirectorio);
}

void ManejadorSalidaPrueba::cambiarDirectorio(char* nombreDirectorio)
{
	_chdir(nombreDirectorio);
}

#endif
