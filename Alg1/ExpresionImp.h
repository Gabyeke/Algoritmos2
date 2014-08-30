#ifndef EXPRESIONIMP_H
#define EXPRESIONIMP_H

#include "Expresion.h"
#include "Cadena.h"
#include "ListaImp.h"
#include "Referencia.h"

#include <iostream>
using namespace std;

class ExpresionImp : public Expresion
{
public:
	ExpresionImp();
	ExpresionImp(int valor);
	ExpresionImp(char *referencia);
	ExpresionImp(const Expresion &exp);
	ExpresionImp(const ExpresionImp &exp);
	ExpresionImp( ExpresionImp *exp);
	ExpresionImp(Expresion *exp);
	
	bool MismoTexto(char* texto1, char* texto2) const;


	Expresion &operator=(const Expresion &exp);
	Expresion &operator=(const ExpresionImp &exp);

	~ExpresionImp();

	bool operator==(const Expresion &exp) const;
	bool operator!=(const Expresion &exp) const;
	bool operator<(const Expresion &exp) const;
	bool operator<=(const Expresion &exp) const;
	bool operator>(const Expresion &exp) const;
	bool operator>=(const Expresion &exp) const;
	
	Expresion &operator+(const Expresion &exp) const;
	Expresion &operator-(const Expresion &exp) const;
	Expresion &operator*(const Expresion &exp) const;
	Expresion &operator/(const Expresion &exp) const;

	int Evaluar(bool &error) const;
	int Evaluar(InterfazDelSistema* interfaz, bool &error) const;

	char *Formula() const;
	Expresion *Clon() const;
	void EliminarExpresion();


private:
	//Atributos
	Expresion* punteroExp;
};

#endif