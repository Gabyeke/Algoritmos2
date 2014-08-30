#ifndef EXPRESIONVAR_CPP
#define EXPRESIONVAR_CPP

#include "ExpresionVar.h"
#include "Expresion.h"
#include "InterfazDelSistemaImp.h"

#include <iostream>
using namespace std;

//***********************************************************************
// CONSTRUCTOR SIN PARAMETROS
ExpresionVar::ExpresionVar() {
	this->direccion = "";
}
//***********************************************************************
// CONSTRUCTORES CON PARAMETROS
ExpresionVar::ExpresionVar(char* referencia) {
	this->direccion = referencia;
}
//------------------------------------------------------------------------
ExpresionVar::ExpresionVar(const ExpresionImp &e) {
	cout<<"No deberias pasar por aqui 3"<<endl;
}
//***********************************************************************

char* ExpresionVar::GetDireccion()const{
	return this->direccion;
}

//***********************************************************************
// DESTRUCTOR
ExpresionVar::~ExpresionVar() {
	delete this->direccion;
	this->direccion = NULL;
}
//***********************************************************************
// EVALUAR
int ExpresionVar::Evaluar(bool &error) const {
	//InterfazDelSistemaImp *aux = new InterfazDelSistemaImp(); 
	error = true;
	return 0;//this->Evaluar(aux, error);
}
//------------------------------------------------------------------------
int ExpresionVar::Evaluar(InterfazDelSistema* interfaz, bool &error) const {	
	return interfaz->EvaluarReferencia(this->direccion, error);
}
//***********************************************************************
// FORMULA
char* ExpresionVar::Formula() const {
	return this->direccion;
}
//***********************************************************************
// CLON
Expresion* ExpresionVar::Clon() const {
	char* mismaDireccion = this->direccion;
	return new ExpresionVar(mismaDireccion);
}

//***********************************************************************
// ELIMINAR EXPRESION
void ExpresionVar::EliminarExpresion() {
	//delete this->direccion;
	this->direccion = NULL;
}


#endif