#ifndef EXPRESIONIMP_CPP
#define EXPRESIONIMP_CPP

#include "ExpresionImp.h"
#include "ExpresionCte.h"
#include "ExpresionBin.h"
#include "ExpresionVar.h"
#include "Expresion.h"

#include <iostream>
using namespace std;

//***********************************************************************
ostream &operator<<(ostream &out, const Expresion &exp)
{	
	out << exp.Formula();
	return out;
}
//***********************************************************************
//CONSTRUCTOR SIN PARAMETROS
ExpresionImp::ExpresionImp()
{
	this->punteroExp = NULL; //new ExpresionCte(0);
}
//***********************************************************************
//CONSTRUCTORES CON PARAMETROS
ExpresionImp::ExpresionImp(int numero)
{
	this->punteroExp = new ExpresionCte(numero);
}
//------------------------------------------------------------------------
ExpresionImp::ExpresionImp(char *referencia)
{
	this->punteroExp = new ExpresionVar(referencia);
}
//------------------------------------------------------------------------
ExpresionImp::ExpresionImp(const Expresion &exp)
{	
	this->punteroExp = exp.Clon();
}
//------------------------------------------------------------------------

ExpresionImp::ExpresionImp(Expresion *exp)
{
	this->punteroExp = exp->Clon();	
}

//------------------------------------------------------------------------
ExpresionImp::ExpresionImp(const ExpresionImp &exp)
{	
	this->punteroExp = (exp.punteroExp)->Clon();/////////////////////////////////???	
}
//***********************************************************************

ExpresionImp::ExpresionImp(ExpresionImp *exp)
{	
	this->punteroExp = exp->Clon();	
}
//***********************************************************************
// OPERADOR ASIGNACION
//PRE
//POST
Expresion &ExpresionImp::operator=(const Expresion &exp)
{	
	if(this != &exp) {
		delete this->punteroExp;
		//this->punteroExp->EliminarExpresion();
		this->punteroExp = exp.Clon();
	}
	return *this;
}
//------------------------------------------------------------------------
Expresion &ExpresionImp::operator=(const ExpresionImp &exp)
{
	if(this != &exp) {
		delete this->punteroExp;// ultimo descomentado!!
		if(exp.punteroExp!=NULL) {this->punteroExp = exp.punteroExp->Clon();}	
	}
	return *this;
}
//***********************************************************************
// DESTRUCTOR
// PRE
// POST
ExpresionImp::~ExpresionImp()
{	
this->EliminarExpresion();
	delete this->punteroExp;
	this->punteroExp = NULL;
}
//***********************************************************************
// OPERADOR ==
// PRE
// POST
bool ExpresionImp::operator==(const Expresion &exp) const {
	bool aux=false;
	if(&exp!=NULL) {
		if(this->Evaluar(aux)==exp.Evaluar(aux)) {
			return true;
		}
	}
	return false;
}
//***********************************************************************
// MISMO TEXTO
// PRE
// POST Devuelve true si los textos comparados son iguales
bool ExpresionImp::MismoTexto(char* texto1, char* texto2) const {
	bool mismoTexto = false;
	//copiar metodo mismoTexto del obligatorio anterior
	return mismoTexto;
}
//***********************************************************************
// OPERADOR !=
// PRE
// POST
bool ExpresionImp::operator!=(const Expresion &exp) const {
	bool aux=false;
	if(&exp!=NULL) {
		if(this->Evaluar(aux)!=exp.Evaluar(aux)) {
			return true;
		}
	}
	return false;
}
//***********************************************************************
// OPERADOR <
// PRE
// POST
bool ExpresionImp::operator<(const Expresion &exp) const {
	bool aux=false;
	if(&exp!=NULL) {
		if(this->Evaluar(aux)<exp.Evaluar(aux)) {
			return true;
		}
	}
	return false;
}
//***********************************************************************
// OPERADOR <=
// PRE
// POST
bool ExpresionImp::operator<=(const Expresion &exp) const {
	bool aux=false;
	if(&exp!=NULL) {
		if(this->Evaluar(aux)<=exp.Evaluar(aux)) {
			return true;
		}
	}
	return false;
}
//***********************************************************************
// OPERADOR >
// PRE
// POST
bool ExpresionImp::operator>(const Expresion &exp) const {
	bool aux=false;
	if(&exp!=NULL) {
		if(this->Evaluar(aux)>exp.Evaluar(aux)) {
			return true;
		}
	}
	return false;
}
//***********************************************************************
// OPERADOR >=
// PRE
// POST
bool ExpresionImp::operator>=(const Expresion &exp) const {
	bool aux=false;
	if(&exp!=NULL) {
		if(this->Evaluar(aux)>=exp.Evaluar(aux)) {
			return true;
		}
	}
	return false;
}
//***********************************************************************
// OPERADOR +
// PRE
// POST
Expresion& ExpresionImp::operator+(const Expresion &exp) const
{	
	return *(new ExpresionImp(new ExpresionBin(*this,'+',exp)));
}

//***********************************************************************
// OPERADOR -
// PRE
// POST
Expresion& ExpresionImp::operator-(const Expresion &exp) const
{	
	return *(new ExpresionImp(new ExpresionBin(*this,'-',exp)));
}
//***********************************************************************
// OPERADOR *
// PRE
// POST
Expresion& ExpresionImp::operator*(const Expresion &exp) const
{
	return *(new ExpresionImp(new ExpresionBin(*this,'*',exp)));
}

//***********************************************************************
// OPERADOR /
// PRE
// POST
Expresion& ExpresionImp::operator/(const Expresion &exp) const
{
	return *(new ExpresionImp(new ExpresionBin(*this,'/',exp)));
}

//***********************************************************************
// EVALUAR
// PRE
// POST Devuelve el valor correspondiente a la evaluacion si no hay errores, 
// si hay errores devuelve -1 e imprime un mensaje de error
int ExpresionImp::Evaluar(bool &error) const
{
	if(this->punteroExp!=NULL){
		int r1 = this->punteroExp->Evaluar(error);
		if (error==true){
			//cout<< "Error: Hay errores en el calculo "<<endl;
			return (-1);
		}
		return r1;
	}
	else{
		return 0;
	}
}
//------------------------------------------------------------------------
int ExpresionImp::Evaluar(InterfazDelSistema* interfaz, bool &error) const
{
	return this->punteroExp->Evaluar(interfaz, error);
}
//***********************************************************************
// FORMULA
// PRE
// POST Devuelve la formula de una expresion
char* ExpresionImp::Formula() const
{
	if(this!=NULL){
		if(this->punteroExp!=NULL){
			return (this->punteroExp->Formula());
		}
		else {
			return "0";
		}
	}
	return "0";
}
//***********************************************************************
// CLON
// PRE
// POST Devuelve una expresion identica a la original sin compartir
// espacio de memoria con esta.
Expresion* ExpresionImp::Clon() const
{
	return new ExpresionImp(punteroExp->Clon());
}

//***********************************************************************

void ExpresionImp::EliminarExpresion() {
	if(this->punteroExp!=NULL) {
		this->punteroExp->EliminarExpresion();
	}
	this->punteroExp = NULL;
	
}

//***********************************************************************




#endif