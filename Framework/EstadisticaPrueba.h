#pragma once

#include "TipoRetorno.h"

typedef unsigned int nat;

class EstadisticaPrueba  
{
public:
	EstadisticaPrueba();

	nat GetCantidadCorrectas()const;
	nat GetCantidadIncorrectas()const;
	nat GetCantidadNoImplementadas()const;

	void ResetearResultados();

	void ActualizarEstadisticas(TipoRetorno nroRetorno, TipoRetorno nroRetornoEsperado);
private:
	nat cantCorrectas, cantIncorrectas, cantNoImplementadas;
};
