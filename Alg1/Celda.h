#ifndef CELDA_H
#define CELDA_H

class InterfazDelSistema;

#include <iostream>
using namespace std;
#include <assert.h>
#include "Expresion.h"
#include "ExpresionImp.h"
#include "Asociacion.h"
#include "ListaImp.h"

class Celda {
public:

	Celda();

	// Constructor. Recibe el numero de fila y columna
	Celda(int fila, int columna);

	Celda(int fila, int columna, Expresion &e);

	// Constructor copia
	Celda(const Celda &c);

	// Destructor
	~Celda();

	// Operador de asignacion
	Celda &operator=(const Celda &c);

	// Retorna el numero de fila
	unsigned int GetFila()const;
	Expresion* GetExpresion();
	void SetExpresion(const Expresion &e);
	
	// Retorna el numero de columna
	unsigned int GetColumna()const;

	// Elimina la expresion de un columna determinada
	void EliminarExpresion();

	// Retorna el resultado de evaluar una celda en una columna determinada
	// El parametro error devuelve si ocurrio un error o no 
	int EvaluarCelda(InterfazDelSistema *interfaz, bool &error);

	// Operadores de comparacion. Comparan las celdas
	bool operator==(const  Celda& c) const;
	bool operator!=(const Celda &c) const;
	bool operator<(const Celda &c) const;
	bool operator>(const Celda &c) const;
	bool operator<=(const Celda &c) const;
	bool operator>=(const Celda &c) const;

	// Imprime la formula en la columna determinada
	void ImprimirFormula() const;

	
private:
	// Atributos
	int fila;
	int columna;
	Expresion *exp;
};



#endif