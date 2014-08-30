#ifndef EXPRESIONBIN_H
#define EXPRESIONBIN_H

#include "ExpresionImp.h"

#include <iostream>
using namespace std;

class ExpresionBin : public ExpresionImp {
public:
	ExpresionBin();

	ExpresionBin::ExpresionBin(const Expresion &exp1, char operador, const Expresion &exp2);
	ExpresionBin(Expresion&e);
	ExpresionBin(ExpresionImp&e);

	~ExpresionBin();

	int Evaluar(bool &error) const;
	int Evaluar(InterfazDelSistema* interfaz, bool &error) const;
	char *Formula() const;
	Expresion *Clon() const;
	char* Concatenar (char* exp1, char operador, char* exp2) const;
	void EliminarExpresion();

private:
	//Atributos
	Expresion *izq;
	Expresion *der;
	char operador;
};

#endif