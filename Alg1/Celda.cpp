#ifndef CELDA_CPP
#define CELDA_CPP

class InterfazDelSistema;

#include <assert.h>
#include "Expresion.h"
#include "ExpresionImp.h"
#include "ListaImp.h"
#include "Celda.h"

#include <iostream>
using namespace std;

//***********************************************************************
// CONSTRUCTOR SIN PARAMETROS
	Celda::Celda() { 
		fila = 1;
		columna= 1;
		exp=NULL;
	};
//***********************************************************************
// CONSTRUCTORES CON PARAMETROS
// Constructor. Recibe el numero de fila y columna
	Celda::Celda(int fila, int columna) {
		this->fila = fila;
		this->columna=columna;
		exp=NULL;
		
	}
//------------------------------------------------------------------------
	Celda::Celda(int fila, int columna, Expresion &e) {
		this->fila = fila;
		this->columna = columna;
		this->exp = &e;
	}
//------------------------------------------------------------------------
// Constructor copia
	Celda::Celda(const Celda &c) {
		this->fila = c.fila;
		this->columna = c.columna;
		this->exp = c.exp->Clon();
	}
//***********************************************************************
// DESTRUCTOR
	Celda::~Celda() {
		this->fila = this->columna = 0;
		delete this->exp;
		this->exp = NULL;
	}
//***********************************************************************
// OPERADOR ASIGNACION
	Celda& Celda::operator=(const Celda &c) {
		if(this!=&c) {
			this->fila = c.fila;
			this->columna = c.columna;
			this->exp = c.exp->Clon();
		}
		return *this;
	}
//***********************************************************************
// SETS Y GETS
//------------------------------------------------------------------------
// Retorna el numero de fila
	unsigned int Celda::GetFila() const{
		return this->fila;
	}
//------------------------------------------------------------------------
// Retorna el numero de columna
	unsigned int Celda::GetColumna()const{
		return this->columna;
	}
//------------------------------------------------------------------------
// 
Expresion* Celda::GetExpresion() {
	return this->exp;
}
//***********************************************************************
// ELIMINAR EXPRESION
// Elimina la expresion de un columna determinada
void Celda::EliminarExpresion(){
		this->exp->EliminarExpresion();
		this->exp = NULL;
	}
//***********************************************************************
//EVALUAR CELDA
// Retorna el resultado de evaluar una celda en una fila y columna determinada
// El parametro error devuelve si ocurrio un error o no 
	int Celda::EvaluarCelda(InterfazDelSistema *interfaz, bool &error){
		if(this->exp==NULL) {return 0;}
		else {return this->exp->Evaluar(interfaz, error);}
	}
//***********************************************************************
// OPERADORES DE COMPARACION
//------------------------------------------------------------------------
// OPERADOR ==
// Operadores de comparacion. Comparan las celdas
	bool Celda::operator==(const  Celda& c) const{
		if(this->fila==c.fila && this->columna==c.columna) {
			return true;
		}
		return false;
	}
//------------------------------------------------------------------------
// OPERADOR !=
	bool Celda::operator!=(const Celda &c) const{
		if(this->fila!=c.fila && this->columna!=c.columna) {
			return true;
		}
		return false;
	}
//------------------------------------------------------------------------
// OPERADOR <
	bool Celda::operator<(const Celda &c) const{
		if(this->fila<c.fila && this->columna<c.columna) {
			return true;
		}
		return false;
	}
//------------------------------------------------------------------------
// OPERADOR >
	bool Celda::operator>(const Celda &c) const{
		if(this->fila>c.fila && this->columna>c.columna) {
			return true;
		}
		return false;
	}
//------------------------------------------------------------------------
// OPERADOR <=
	bool Celda::operator<=(const Celda &c) const{
		if(this->fila<=c.fila && this->columna<=c.columna) {
			return true;
		}
		return false;
	}
//------------------------------------------------------------------------
// OPERADOR >=
	bool Celda::operator>=(const Celda &c) const{
		if(this->fila>=c.fila && this->columna>=c.columna) {
			return true;
		}
		return false;
	}
//***********************************************************************
// IMPRIMIR FORMULA
// Imprime la formula en la columna determinada
	void Celda::ImprimirFormula() const{
		cout<<this->exp->Formula()<<endl;
	}
//***********************************************************************

#endif