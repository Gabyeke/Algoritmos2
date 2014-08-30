#pragma once

#include "ManejadorImpresion.h"

class ManejadorImpresionTxt : public ManejadorImpresion
{
public:
	ManejadorImpresionTxt();

	void ImprimirResultado(TipoRetorno retorno, TipoRetorno retornoEsperado, Cadena comentario) const;
	void ImprimirTotalResultados(const Puntero<EstadisticaPrueba>& estadistica) const;
	void IniciarSeccion(Cadena nombreSeccion, TipoRetorno tipoPrueba) const;

protected:
	void IniciarPrueba() const;
	void CerrarPrueba() const;
	Cadena ObtenerExtension() const;

private:
	mutable bool seccionAbierta;

	void ImprimirComentario(Cadena comentario) const;
	void ImprimirRetorno(TipoRetorno retorno, TipoRetorno retornoEsperado) const;
};
