#include "ConductorPrueba.h"
#include "Prueba.h"
#include "ManejadorImpresionTxt.h"
#include "ManejadorImpresionXml.h"

ConductorPrueba::ConductorPrueba(FormatoSalida fs)
{
	if (fs == TXT)
		manejadorImpresion = new ManejadorImpresionTxt();
	else
		manejadorImpresion = new ManejadorImpresionXml();
	estadisticaGlobal = new EstadisticaPrueba();
}

ConductorPrueba::~ConductorPrueba()
{
	manejadorImpresion->FinalizarManejador();
}

void ConductorPrueba::CorrerPruebas(Iterador<Puntero<Prueba>> pruebas)
{
	estadisticaGlobal->ResetearResultados();
	manejadorImpresion->CrearDirectorio("Pruebas");

	for (pruebas.Reiniciar(); pruebas.HayElemento(); pruebas++)
	{
		Puntero<Prueba> prueba = *pruebas;
		prueba->CorrerPrueba(this);
	}

	manejadorImpresion->IniciarArchivo("Resultados Totales");
	manejadorImpresion->ImprimirTotalResultados(estadisticaGlobal);
}

void ConductorPrueba::Verificar(TipoRetorno retorno, TipoRetorno retornoEsperado, Cadena comentario)
{
	manejadorImpresion->ImprimirResultado(retorno, retornoEsperado, comentario);
	estadisticaGlobal->ActualizarEstadisticas(retorno, retornoEsperado);
}

Puntero<ManejadorImpresion> ConductorPrueba::GetManejadorImpresion() const
{
	return manejadorImpresion;
}

void ConductorPrueba::IniciarSeccion(Cadena nombreSeccion, TipoRetorno tipoPrueba)
{
	assert(tipoPrueba != NO_IMPLEMENTADA);
	manejadorImpresion->IniciarSeccion(nombreSeccion, tipoPrueba);
}

void ConductorPrueba::CerrarSeccion()
{
	manejadorImpresion->CerrarSeccion();
}