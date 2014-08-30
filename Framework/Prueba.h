#pragma once

class Cadena;
class ConductorPrueba;
class EstadisticaPrueba;

#include "Puntero.h"
#include "TipoRetorno.h"

class Prueba abstract
{
public:
	Prueba();
	virtual ~Prueba();

	void CorrerPrueba(Puntero<ConductorPrueba> conductor);

protected:
	virtual void CorrerPruebaConcreta() abstract;
	virtual Cadena GetNombre() const abstract;
	Puntero<EstadisticaPrueba>& GetEstadisticaPrueba();

	void Verificar(TipoRetorno retorno, TipoRetorno retornoEsperado, Cadena comentario);
	void IniciarSeccion(Cadena nombreSeccion, TipoRetorno tipoPrueba = OK);
	void CerrarSeccion();

private:
	Puntero<EstadisticaPrueba> m_EstadisticaPrueba;
	Puntero<ConductorPrueba> m_Conductor;
};
