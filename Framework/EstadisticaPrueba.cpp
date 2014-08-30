#include "EstadisticaPrueba.h"

EstadisticaPrueba::EstadisticaPrueba()
{
	ResetearResultados();
}

nat EstadisticaPrueba::GetCantidadCorrectas() const
{
	return cantCorrectas;
}

nat EstadisticaPrueba::GetCantidadIncorrectas() const
{
	return cantIncorrectas;
}

nat EstadisticaPrueba::GetCantidadNoImplementadas() const
{
	return cantNoImplementadas;
}

void EstadisticaPrueba::ResetearResultados()
{
	cantCorrectas = cantIncorrectas = cantNoImplementadas = 0;
}

void EstadisticaPrueba::ActualizarEstadisticas(TipoRetorno nroRetorno, TipoRetorno nroRetornoEsperado)
{
	if (nroRetorno == nroRetornoEsperado)
		cantCorrectas++;
	else if (nroRetorno == NO_IMPLEMENTADA)
		cantNoImplementadas++;
	else
		cantIncorrectas++;
}
