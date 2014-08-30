#ifndef EXPRESIONBIN_CPP
#define EXPRESIONBIN_CPP

#include "ExpresionBin.h"
#include "InterfazDelSistema.h"
#include "Expresion.h"

#include <iostream>
using namespace std;

//***********************************************************************
// CONSTRUCTOR SIN PARAMETROS
ExpresionBin::ExpresionBin() {
	assert(false);
}
//***********************************************************************
// CONSTRUCTORES CON PARAMETROS
ExpresionBin::ExpresionBin(const Expresion &exp1, char operador, const Expresion &exp2) {
	this->izq = exp1.Clon();
	this->der = exp2.Clon();
	this->operador = operador;	
}
//------------------------------------------------------------------------
ExpresionBin::ExpresionBin(Expresion &e) {
	cout<<"No deberias pasar por aqui 1"<<endl;
	assert(false);
}
//------------------------------------------------------------------------
ExpresionBin::ExpresionBin(ExpresionImp &e) {
	cout<<"No deberias pasar por aqui 2"<<endl;
	assert(false);
}
//***********************************************************************
// DESTRUCTOR
ExpresionBin::~ExpresionBin() {
	this->izq->EliminarExpresion();
	this->der->EliminarExpresion();
	this->izq=NULL;
	this->der=NULL;
}
//***********************************************************************
// EVALUAR
int ExpresionBin::Evaluar(bool &error) const {
	bool error1 = error;
	bool error2 = error;
	int r1 = this->izq->Evaluar(error1);
	int r2 = this->der->Evaluar(error2);
	int resultado = 0;

	if(!error1 && !error2) {
		
		switch(operador) {
			case '+': {
				resultado = r1+r2;
				break;
			}
			case '-': {
				resultado = r1-r2;
				break;
			}
			case '*': {
				resultado = r1*r2;
				break;
			}
			case '/': {
				if(r2==0) {
					cout<<"ERROR: No se puede dividir entre CERO"<<endl;
					error = true;
				}
				else {resultado=r1/r2;}
				break;
			}
		}
	}
	else if(error1) {error = error1; resultado=-1;}
	else if(error2) {error = error2; resultado=-1;}
	return resultado;
}
//------------------------------------------------------------------------
int ExpresionBin::Evaluar(InterfazDelSistema* interfaz, bool &error) const {
	return this->Evaluar(error);
}
//***********************************************************************
// FORMULA
char * ExpresionBin::Formula() const {
	char* r1 = this->izq->Formula();
	char* r2 = this->der->Formula();
	char* ret = Concatenar(r1,operador,r2);
	return ret;
}
//***********************************************************************
// CONCATENAR
// PRE - Se pasan dos char
// POST - Se devuelve la concatenacion de los dos char
char* ExpresionBin::Concatenar(char* exp1, char operador, char* exp2) const {
	
	int indiceExp1 = strlen(exp1);
	int indiceExp2 = strlen(exp2);
	
	// a aux le sumamos 2 por el operador y el '/0' y 2 por los parentesis ()
	char* aux = new char[indiceExp1+indiceExp2+2+2];
		aux [0]= '(';
		
		for(int i=0; i<indiceExp1; i++) {
		aux[i+1]=exp1[i];
		}
		aux[indiceExp1+1] = operador;
		int indiceAux = 0;

		for(int i=indiceExp1+1+1; i<indiceExp1+indiceExp2+1+1; i++) {
			aux[i]=exp2[indiceAux];
			indiceAux++;
		}

		aux [indiceExp1+indiceExp2+1+1] = ')';
		aux[indiceExp1+indiceExp2+1+1+1]='\0';

	return aux;
}
//***********************************************************************
// CLON
Expresion * ExpresionBin::Clon() const{
	return new ExpresionBin(*izq,operador,*der);
}
//***********************************************************************

void ExpresionBin::EliminarExpresion() {
	if(this->der!=NULL && this->izq!=NULL){
		this->der->EliminarExpresion();
		this->izq->EliminarExpresion();
		this->der = NULL;
		this->izq = NULL;
	}
}


#endif