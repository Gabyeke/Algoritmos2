/*#ifndef FILA_CPP
#define FILA_CPP

#include "Fila.h"
#include "IteradorListaImp.h"

#include <iostream>
using namespace std;


//***********************************************************************
// CONSTRUCTOR SIN PARAMETROS
// ESTA EN EL .h
//***********************************************************************
// CONSTRUCTORES CON PARAMETROS
Fila::Fila(unsigned int nro) {
	this->nombreFila = nro;
	this->listaDeExpresiones = new ListaImp<Asociacion<int, ExpresionImp>>();
}
//------------------------------------------------------------------------
Fila::Fila(const Fila &f) {
	this->nombreFila = f.nombreFila;
	this->listaDeExpresiones = f.listaDeExpresiones;
}
//***********************************************************************
// DESTRUCTOR
Fila::~Fila() {
	this->listaDeExpresiones->Vaciar();
	this->listaDeExpresiones = NULL;
}
//***********************************************************************
// OPERADOR ASIGNACION
Fila &Fila::operator=(const Fila &f) {
	if (this->GetNombreFila()!=f.GetNombreFila()) {
		this->nombreFila = f.nombreFila;
		this->listaDeExpresiones = f.listaDeExpresiones;
	}
	return *this;
}
//***********************************************************************
// SETS Y GETS
unsigned int Fila::GetNumero() const {
	return this->GetNombreFila();
}
//***********************************************************************
// ASIGNAR EXPRESION
void Fila::AsignarExpresion(const Expresion &exp, int col) {
	//NO IMPLEMENTADO	
}
//***********************************************************************
// ELIMINAR EXPRESION
void Fila::EliminarExpresion(int col) {
	//NO IMPLEMENTADO	
}
//***********************************************************************
// EVALUAR CELDA
int Fila::EvaluarCelda(InterfazDelSistema *interfaz, int col, bool &error) {

	//NO IMPLEMENTADO	
	return 0;
}
//***********************************************************************
// OPERADOR ==
bool Fila::operator==(const Fila &f) const {
	if(this->GetNombreFila()==f.GetNombreFila()) {
		return true;
	}
	return false;
}
//***********************************************************************
//OPERADOR !=
bool Fila::operator!=(const Fila &f) const {
	if(this->GetNombreFila()!=f.GetNombreFila()) {
		return true;
	}	
	return false;
}
//***********************************************************************
// OPERADOR <
bool Fila::operator<(const Fila &f) const {
	if(this->GetNombreFila()<f.GetNombreFila()) {
		return true;
	}	
	return false;
}
//***********************************************************************
// OPERADOR >
bool Fila::operator>(const Fila &f) const {
	if(this->GetNombreFila()>f.GetNombreFila()) {
		return true;
	}	
	return false;
}
//***********************************************************************
// OPERADOR <=
bool Fila::operator<=(const Fila &f) const {
	if(this->GetNombreFila()<=f.GetNombreFila()) {
		return true;
	}	
	return false;
}
//***********************************************************************
// OPERADOR >=
bool Fila::operator>=(const Fila &f) const {
	if(this->GetNombreFila()>=f.GetNombreFila()) {
		return true;
	}	
	return false;
}
//***********************************************************************
// IMPRIMIR FORMULA
void Fila::ImprimirFormula(int columna) const {

	if(columna>0) {
		IteradorListaImp<Asociacion<int, ExpresionImp>>* it = new IteradorListaImp<Asociacion<int, ExpresionImp>>();
		bool seguir = true;
		while(!(it->EsFin()) && seguir) {
			if(it->Elemento()==columna) {
				
				seguir = false;
			}
			it->Resto();
		}
		if(seguir) {
			cout<<"ERROR: No existe expresion "<<endl;
		}
	}
	else {
		
	}
}
//***********************************************************************
// IMPRIMIR CELDAS EVALUADAS
void Fila::ImprimirCeldasEvaluadas(InterfazDelSistema *interfaz, int columnaDesde, int columnaHasta) const {
	//NO IMPLEMENTADO	
}
//***********************************************************************
void Fila::SetNombre(int nombreFila) {
	this->nombreFila = nombreFila;
}
//***********************************************************************
int Fila::GetNombreFila() const {
	return this->nombreFila;
}
//***********************************************************************


#endif*/