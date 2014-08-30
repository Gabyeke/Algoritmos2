#pragma once

#include "Cadena.h"
#include "EstadisticaPrueba.h"
#include "Iteracion.h"
#include "ManejadorImpresion.h"
#include "Puntero.h"
#include "TipoRetorno.h"

class Prueba;

enum FormatoSalida
{
	TXT,
	XML
};

class ConductorPrueba
{
	friend Prueba;
public:
	ConductorPrueba(FormatoSalida fs = TXT);
	~ConductorPrueba();

	void CorrerPruebas(Iterador<Puntero<Prueba>> pruebas);
	Puntero<ManejadorImpresion> GetManejadorImpresion() const;
	void IniciarSeccion(Cadena nombreSeccion, TipoRetorno tipoPrueba);
	void CerrarSeccion();

protected:
	void Verificar(TipoRetorno retorno, TipoRetorno retornoEsperado, Cadena comentario);

private:
	Puntero<EstadisticaPrueba> estadisticaGlobal;
	Puntero<ManejadorImpresion> manejadorImpresion;
};
