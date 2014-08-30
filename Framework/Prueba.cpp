#include "Prueba.h"

#include "Cadena.h"
#include "ConductorPrueba.h"
#include "EstadisticaPrueba.h"


Prueba::Prueba()
{
	m_Conductor = NULL;
	m_EstadisticaPrueba = new EstadisticaPrueba();
}

Prueba::~Prueba()
{
}

void Prueba::Verificar(TipoRetorno retorno, TipoRetorno retornoEsperado, Cadena comentario)
{
	m_EstadisticaPrueba->ActualizarEstadisticas(retorno,retornoEsperado);
	m_Conductor->Verificar(retorno,retornoEsperado,comentario);
}

void Prueba::CorrerPrueba(Puntero<ConductorPrueba> conductor)
{
	m_Conductor = conductor;
	{
		// Las llaves son necesarias para que se llame al destructor de Cadena antes de correr PruebaMemoria por segunda vez
		Cadena nombrePrueba = GetNombre();
		m_Conductor->GetManejadorImpresion()->CrearDirectorio(nombrePrueba);
		m_Conductor->GetManejadorImpresion()->IniciarArchivo(nombrePrueba);
	}
	CorrerPruebaConcreta();
	m_Conductor->GetManejadorImpresion()->ImprimirTotalResultados(m_EstadisticaPrueba);
	m_Conductor->GetManejadorImpresion()->CambiarDirectorio("..");
	m_Conductor = NULL;
}

void Prueba::IniciarSeccion(Cadena nombreSeccion, TipoRetorno tipoPrueba)
{
	assert(tipoPrueba != NO_IMPLEMENTADA);
	m_Conductor->IniciarSeccion(nombreSeccion, tipoPrueba);
}

void Prueba::CerrarSeccion()
{
	m_Conductor->CerrarSeccion();
}