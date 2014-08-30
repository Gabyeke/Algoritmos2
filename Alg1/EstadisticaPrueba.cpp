#include "EstadisticaPrueba.h"

#include <iostream>
using namespace std;

EstadisticaPrueba::EstadisticaPrueba()
{
	cantCorrectas = cantIncorrectas = cantNoImplementadas = 0;
}

EstadisticaPrueba::~EstadisticaPrueba()
{
}

int EstadisticaPrueba::getCantidadCorrectas()const
{
	return cantCorrectas;
}

int EstadisticaPrueba::getCantidadIncorrectas()const
{
	return cantIncorrectas;
}

int EstadisticaPrueba::getCantidadNoImplementadas()const
{
	return cantNoImplementadas;
}

void EstadisticaPrueba::resetearResultados()
{
	cantCorrectas = cantIncorrectas = cantNoImplementadas = 0;
}

void EstadisticaPrueba::actualizarEstadisticas(TipoRet nroRetorno, TipoRet nroRetornoEsperado)
{
	if ( nroRetorno == nroRetornoEsperado )
	{
		cantCorrectas++;
	} else {
		if ( nroRetorno == NO_IMPLEMENTADA )
		{
			cantNoImplementadas++;
		} else {
			cantIncorrectas++;
		}
	}
}
