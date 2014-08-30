#pragma once

template <class T>
class Puntero;

#include "Cadena.h"
#include "EstadisticaPrueba.h"

#include <iostream>
#include <fstream>
#include <streambuf>
using namespace std;

class ManejadorImpresion abstract
{
public:
	ManejadorImpresion();
	virtual ~ManejadorImpresion();

	virtual void ImprimirResultado(TipoRetorno retorno, TipoRetorno retornoEsperado, Cadena comentario) const abstract;
	virtual void ImprimirTotalResultados(const Puntero<EstadisticaPrueba>& estadistica) const abstract;
	virtual void IniciarSeccion(Cadena nombreSeccion, TipoRetorno tipoPrueba) const abstract;
	virtual void CerrarSeccion() const;

	void CrearDirectorio(Cadena nombreDirectorio) const;
	void CambiarDirectorio(Cadena nombreDirectorio) const;
	void IniciarArchivo(Cadena nombreArchivo);
	void FinalizarManejador();

protected:
	Cadena GetStringRetorno(TipoRetorno retorno) const;
	void CadenaToChar(const Cadena& c, char* chr, nat offset = 0) const;
	void PasarSalidaArchivo() const;
	void PasarSalidaPantalla() const;
	virtual void IniciarPrueba() const abstract;
	virtual void CerrarPrueba() const abstract;
	virtual Cadena ObtenerExtension() const abstract;

private:
	Cadena cadERROR;
	Cadena cadOK;
	Cadena cadNO_IMPLEMENTADA;
	bool finalizado;

	streambuf* pantalla;
	ofstream archivoActual;

	void CerrarArchivo();
};
