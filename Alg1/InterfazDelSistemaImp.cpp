#ifndef INTERFAZ_DEL_SISTEMA_IMP_CPP
#define INTERFAZ_DEL_SISTEMA_IMP_CPP

#include "InterfazDelSistemaImp.h"
#include "Planilla.h"
//#include "Pila.h"
#include "PilaImp.h"

#include <iostream>
using namespace std;

//***********************************************************************
// Inicialización de los atributos
InterfazDelSistemaImp::InterfazDelSistemaImp()
{
	planilla = new Planilla();
	pila = new PilaImp<Planilla>();
}
//***********************************************************************
// DESTRUCTOR
// Eliminación de los objetos creados con "new"
InterfazDelSistemaImp::~InterfazDelSistemaImp()
{
	planilla->~Planilla();
}
//***********************************************************************
// INSERTAR HOJA
TipoRet InterfazDelSistemaImp::InsertarHoja(char *nombreHoja)
{
	TipoRet resultado = ERROR;
	resultado = planilla->InsertarHoja(nombreHoja);

	//Cargar planilla a la pila
	//Planilla* copia = planilla;
	//pila->Push(*copia);
	return resultado;	
}

//***********************************************************************
// ELIMINAR HOJA
TipoRet InterfazDelSistemaImp::EliminarHoja(char *nombreHoja)
{
	TipoRet resultado = ERROR;
	resultado = planilla->EliminarHoja(nombreHoja);

	//Cargar planilla a la pila
	//Planilla* copia = planilla;
	//pila->Push(*copia);
	return resultado;
}
//***********************************************************************
// RENOMBRAR HOJA
TipoRet InterfazDelSistemaImp::RenombrarHoja(char *nombreActual, char *nombreNuevo)
{
	TipoRet resultado = ERROR;
	resultado = planilla->RenombrarHoja(nombreActual, nombreNuevo);

	//Cargar planilla a la pila
	//Planilla* copia = planilla;
	//pila->Push(*copia);
	return resultado;
}
//***********************************************************************
// LISTAR HOJAS
TipoRet InterfazDelSistemaImp::ListarHojas(OrdenListado orden)
{
	TipoRet resultado = ERROR;
	resultado = planilla->ListarHojas(orden); 
	return resultado;
}
//***********************************************************************
// DESHACER ULTIMA OPERACION
TipoRet InterfazDelSistemaImp::DeshacerUltimaOperacion()
{
	TipoRet resultado = ERROR;
	if(pila->Largo()==0) {
		cout<<"No existen cambios para deshacer"<<endl;
	}
	else {
		delete planilla;
		planilla = &(pila->Pop());
		resultado = OK;
	}

	return resultado;
}
//***********************************************************************
// ASIGNAR EXPRESION A CELDA
TipoRet InterfazDelSistemaImp::AsignarExpresionACelda(char *nombreHoja, int columna, int fila,  const Expresion &exp)
{
	TipoRet resultado = ERROR;
	resultado = this->planilla->AsignarExpresionACelda(nombreHoja, columna, fila, exp);

	//Cargar planilla a la pila
	//Planilla* copia = planilla;
	//pila->Push(*copia);
	return resultado;
}
//***********************************************************************
// ELIMINAR CELDA
TipoRet InterfazDelSistemaImp::EliminarCelda(char *nombreHoja, int columna, int fila)
{
	TipoRet resultado = ERROR;
	resultado = this->planilla->EliminarCelda(nombreHoja, columna, fila);

	//Cargar planilla a la pila
	//Planilla* copia = planilla;
	//pila->Push(*copia);
	return resultado;
}
//***********************************************************************
// LISTAR CELDAS EVALUADAS
TipoRet InterfazDelSistemaImp::ListarCeldasEvaluadas(char *nombreHoja, int columnaDesde, int filaDesde, int columnaHasta, int filaHasta)
{
	TipoRet resultado = ERROR;
	if(this->planilla->CoordenadasValidas(filaDesde, columnaDesde) && this->planilla->CoordenadasValidas(filaHasta, columnaHasta)) {

		Hoja* encontrada = this->planilla->BuscarHoja(nombreHoja);
		if (!(encontrada->EsHojaVacia())){	
			resultado = planilla->ListarCeldasEvaluadas(nombreHoja, columnaDesde, filaDesde, columnaHasta, filaHasta, this);
		}
		else {
			cout<<"ERROR: Nombre de Hoja invalido"<<endl;
		}
	}
	else {
		cout<<"ERROR: Coordenadas invalidas"<<endl;
	}
	return resultado;
}
//***********************************************************************
// LISTAR CELDAS SIN EVALUAR
TipoRet InterfazDelSistemaImp::ListarCeldaSinEvaluar(char *nombreHoja, int columna, int fila)
{
	TipoRet resultado = ERROR;
	if(this->planilla->CoordenadasValidas(fila, columna)) {
		Hoja* encontrada = this->planilla->BuscarHoja(nombreHoja);
		if (!(encontrada->EsHojaVacia())){	
			planilla->ListarCeldaSinEvaluar(this, nombreHoja, columna, fila);
			resultado = OK;
		}
		else {
			cout<<"ERROR: Nombre de Hoja invalido"<<endl;
		}
	}
	else {
		cout<<"ERROR: Coordenadas invalidas"<<endl;
	}
	return resultado;
}	
//***********************************************************************
// EVALUAR REFERENCIA
int InterfazDelSistemaImp::EvaluarReferencia(char *referencia, bool &error)
{
	int resultado = this->planilla->EvaluarReferencia(this, referencia, error);
	if(error) {
		cout<<"ERROR: Se produjo un error en la Evaluacion"<<endl;
	}
	return resultado;
}
//***********************************************************************
// SETS Y GETS

void InterfazDelSistemaImp::SetPlanilla(const Planilla &p) {
	*this->planilla = p;
}
//------------------------------------------------------------------------

Planilla& InterfazDelSistemaImp::GetPlanilla() const {
	return *this->planilla;
}

//***********************************************************************


		
#endif