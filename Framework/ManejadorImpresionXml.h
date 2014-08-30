#pragma once

#include "ManejadorImpresion.h"

class ManejadorImpresionXml : public ManejadorImpresion
{
public:
	ManejadorImpresionXml();

	void ImprimirResultado(TipoRetorno retorno, TipoRetorno retornoEsperado, Cadena comentario) const;
	void ImprimirTotalResultados(const Puntero<EstadisticaPrueba>& estadistica) const;
	void IniciarSeccion(Cadena nombreSeccion, TipoRetorno tipoPrueba) const;
	void CerrarSeccion() const;

protected:
	void IniciarPrueba() const;
	void CerrarPrueba() const;
	Cadena ObtenerExtension() const;

private:
	Cadena ampCod, ampDec, comCod, comDec, menCod, menDec, mayCod, mayDec;
	Cadena cadDefecto;
	mutable nat m_SeccionesAbiertas;
	mutable bool m_PruebaAbierta;

	Cadena Codificar(Cadena c) const;
};
