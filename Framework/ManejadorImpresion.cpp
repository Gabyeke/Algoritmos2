#include "ManejadorImpresion.h"
#include "EstadisticaPrueba.h"
#include "Puntero.h"
#include <iostream>
#include <direct.h>
using namespace std;

ManejadorImpresion::ManejadorImpresion()
{
	cadERROR = "ERROR";
	cadOK = "OK";
	cadNO_IMPLEMENTADA = "NO_IMPLEMENTADA";
	pantalla = cout.rdbuf();
	finalizado = false;
}

ManejadorImpresion::~ManejadorImpresion()
{
	assert(finalizado);
}

Cadena ManejadorImpresion::GetStringRetorno(TipoRetorno retorno) const
{
	switch (retorno)
	{
		case OK:
			return cadOK;
		case ERROR:
			return cadERROR;
		default:
			return cadNO_IMPLEMENTADA;
	}
}

void ManejadorImpresion::CrearDirectorio(Cadena nombreDirectorio) const
{
	assert(!finalizado);
	char* chr = new char[nombreDirectorio.Largo + 1];
	CadenaToChar(nombreDirectorio, chr);
	_mkdir(chr);
	_chdir(chr);
	printf("Se creo el directorio: %s\n", chr);
	delete[] chr;
}

void ManejadorImpresion::CambiarDirectorio(Cadena nombreDirectorio) const
{
	assert(!finalizado);
	char* chr = new char[nombreDirectorio.Largo + 1];
	CadenaToChar(nombreDirectorio, chr);
	_chdir(chr);
	delete[] chr;
}

void ManejadorImpresion::IniciarArchivo(Cadena nombreArchivo)
{
	assert(!finalizado);
	CerrarArchivo();
	Cadena ext = ObtenerExtension();
	char* chr = new char[nombreArchivo.Largo + ext.Largo + 2];
	CadenaToChar(nombreArchivo, chr);
	chr[nombreArchivo.Largo] = '.';
	CadenaToChar(ext, chr, nombreArchivo.Largo + 1);
	archivoActual.open(chr, ios::out);
	printf("Se creo el archivo: %s\n", chr);
	delete[] chr;
	IniciarPrueba();
}

void ManejadorImpresion::CerrarArchivo()
{
	assert(!finalizado);
	if (archivoActual.is_open())
	{
		CerrarPrueba();
		archivoActual.close();
		PasarSalidaPantalla();
	}
}

void ManejadorImpresion::CerrarSeccion() const
{
}


void ManejadorImpresion::CadenaToChar(const Cadena& c, char* chr, nat offset) const
{
	nat i;
	for (i = 0; i < c.Largo; i++)
		chr[i + offset] = c[i];
	chr[i + offset] = '\0';
}

void ManejadorImpresion::PasarSalidaArchivo() const
{
	assert(!finalizado);
	assert(archivoActual.is_open());
	cout.rdbuf(archivoActual.rdbuf());
}

void ManejadorImpresion::PasarSalidaPantalla() const
{
	assert(!finalizado);
	cout.rdbuf(pantalla);
}

void ManejadorImpresion::FinalizarManejador()
{
	assert(!finalizado);
	CerrarArchivo();
	finalizado = true;
}
