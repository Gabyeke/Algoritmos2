#ifndef EXPRESIONCTE_CPP
#define EXPRESIONCTE_CPP

#include "ExpresionCte.h"
#include "Expresion.h"
#include "ExpresionImp.h"

#include <iostream>
using namespace std;

//***********************************************************************
// CONSTRUCTOR SIN PARAMETROS
ExpresionCte::ExpresionCte() {
	valor = 0;
}
//***********************************************************************
// CONSTRUCTORES CON PARAMETROS
ExpresionCte::ExpresionCte(int valor) {
	this->valor = valor;
}
//------------------------------------------------------------------------
ExpresionCte::ExpresionCte(const ExpresionCte & e) {
	this->valor = e.valor;
}
//***********************************************************************
// DESTRUCTOR
ExpresionCte::~ExpresionCte(){ valor=0;}

//***********************************************************************
// EVALUAR
int ExpresionCte::Evaluar(bool &error) const {	
	return this->valor;
}
//------------------------------------------------------------------------
int ExpresionCte::Evaluar(InterfazDelSistema* interfaz, bool &error) const {
	return this->Evaluar(error);
}
//***********************************************************************
// FORMULA
char* ExpresionCte::Formula() const {
	char* str = new char[100];
	if(this->valor>=0){
		return itoa(this->valor, str, 10);

	}
	else{
		itoa(this->valor, str, 10);
		int largo = strlen(str);
		char* aux = new char[largo+3];
		aux[0]= '(';
		
		for(int i=0; i<largo; i++ ){
			aux[i+1]= str[i];
		}
		aux[largo+1]=')';
		aux [largo+2]= '\0';

		return aux;
	}
}
//***********************************************************************
// CLON
Expresion* ExpresionCte::Clon() const {
	return new  ExpresionCte(*this);
}
//***********************************************************************
// ELIMINAR EXPRESION
void ExpresionCte::EliminarExpresion() {
	if(this!=NULL) {valor=0;}	
}



#endif