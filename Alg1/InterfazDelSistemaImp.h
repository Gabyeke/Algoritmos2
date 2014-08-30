#ifndef INTERFAZ_DEL_SISTEMA_IMP_H
#define INTERFAZ_DEL_SISTEMA_IMP_H

class Planilla;
#include "Planilla.h"
#include "Constantes.h"
#include "InterfazDelSistema.h"
#include "PilaImp.h"


#include <iostream>
using namespace std;


class InterfazDelSistemaImp  : public InterfazDelSistema
{
public:
	
	InterfazDelSistemaImp();
	~InterfazDelSistemaImp();
			
	TipoRet InsertarHoja(char *nombreHoja);
	TipoRet EliminarHoja(char *nombreHoja);
	TipoRet RenombrarHoja(char *nombreActual, char *nombreNuevo);
	TipoRet ListarHojas(OrdenListado orden);
	TipoRet DeshacerUltimaOperacion();

	TipoRet AsignarExpresionACelda(char *nombreHoja, int columna, int fila,  const Expresion &exp);
	TipoRet EliminarCelda(char *nombreHoja, int columna, int fila);	
	TipoRet ListarCeldasEvaluadas(char *nombreHoja, int columnaDesde, int filaDesde, int columnaHasta, int filaHasta);
	TipoRet ListarCeldaSinEvaluar(char *nombreHoja, int columna, int fila);	
	
	int EvaluarReferencia(char *referencia, bool &error);
	void SetPlanilla(const Planilla &p);
	Planilla& GetPlanilla() const;
	

private:

	// Atributos
	Planilla *planilla;
	Pila<Planilla> *pila;
};

#endif
