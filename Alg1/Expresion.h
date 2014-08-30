#ifndef EXPRESION_H
#define EXPRESION_H

#include "Constantes.h"
#include "InterfazDelSistema.h"

#include <iostream>
using namespace std;


//class Referencia;
//class Planilla;
class InterfazDelSistema;

class Expresion;
ostream &operator<<(ostream &out, const Expresion &exp);

class Expresion abstract
{
public:
	virtual Expresion &operator=(const Expresion &exp) abstract;

	virtual ~Expresion() {}

	virtual bool operator==(const Expresion &exp) const abstract;
	virtual bool operator!=(const Expresion &exp) const abstract;
	virtual bool operator<(const Expresion &exp) const abstract;
	virtual bool operator<=(const Expresion &exp) const abstract;
	virtual bool operator>(const Expresion &exp) const abstract;
	virtual bool operator>=(const Expresion &exp) const abstract;

	virtual Expresion &operator+(const Expresion &exp2) const abstract;
	virtual Expresion &operator-(const Expresion &exp) const abstract;
	virtual Expresion &operator*(const Expresion &exp) const abstract;
	virtual Expresion &operator/(const Expresion &exp) const abstract;

	virtual int Evaluar(bool &error) const abstract;
	virtual int Evaluar(InterfazDelSistema* interfaz, bool &error) const abstract;

	virtual char *Formula() const abstract;
	virtual Expresion *Clon() const abstract;
	virtual void EliminarExpresion() abstract;

protected:

	Expresion() { }
	Expresion(const Expresion &exp) { }

};


#endif