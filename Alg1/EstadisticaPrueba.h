#ifndef ESTADISTICAPRUEBA_H
#define ESTADISTICAPRUEBA_H

#include "TipoRetorno.h"

#include <iostream>
using namespace std;

class EstadisticaPrueba  
{
public:
	EstadisticaPrueba();
	virtual ~EstadisticaPrueba();

	int getCantidadCorrectas()const;
	int getCantidadIncorrectas()const;
	int getCantidadNoImplementadas()const;

	void resetearResultados();

	void actualizarEstadisticas(TipoRet nroRetorno, TipoRet nroRetornoEsperado);
private:
	int cantCorrectas, cantIncorrectas, cantNoImplementadas;

};

#endif