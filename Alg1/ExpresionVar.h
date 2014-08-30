#ifndef EXPRESIONVAR_H
#define EXPRESIONVAR_H

#include "InterfazDelSistema.h"
#include "ExpresionImp.h"

#include <iostream>
using namespace std;

class ExpresionVar : public ExpresionImp {
public:
	ExpresionVar();
	ExpresionVar(char* referencia);

	ExpresionVar(const ExpresionImp &e);

	~ExpresionVar();

	char* GetDireccion()const;
	int Evaluar(bool &error) const;
	int Evaluar(InterfazDelSistema* interfaz, bool &error) const;
	char* Formula() const;
	Expresion* Clon() const;
	void EliminarExpresion();

private:
	//Atributos
	char* direccion;
};



#endif