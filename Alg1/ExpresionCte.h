#ifndef EXPRESIONCTE_H
#define EXPRESIONCTE_H

#include "InterfazDelSistema.h" 
#include "ExpresionImp.h"

#include <iostream>
using namespace std;

class ExpresionCte : public ExpresionImp {

public:
	ExpresionCte();
	ExpresionCte(int valor);
	ExpresionCte(const ExpresionCte&e);

	~ExpresionCte();

	int Evaluar(bool &error) const;
	int Evaluar(InterfazDelSistema* interfaz, bool &error) const;
	char *Formula() const;
	Expresion *Clon() const;
	void EliminarExpresion();

private:
	//Atributos
	int valor;
};


#endif