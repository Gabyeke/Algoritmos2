/*#ifndef FILA_H
#define FILA_H

class InterfazDelSistema;

#include <iostream>
using namespace std;
#include <assert.h>
#include "Expresion.h"
#include "ExpresionImp.h"
#include "Asociacion.h"
#include "ListaImp.h"

class Fila {
public:

	Fila() { assert(false); };

	// Constructor. Recibe el numero de fila
	Fila(unsigned int nro);

	// Constructor copia
	Fila(const Fila &h);

	// Destructor
	~Fila();

	// Operador de asignacion
	Fila &operator=(const Fila &f);

	// Retorna el numero de fila
	unsigned int GetNumero() const;

	void SetNombre(int nombreFila); 
	int GetNombreFila() const;

	// Asigna una expresion a una columna determinada
	void AsignarExpresion(const Expresion &exp, int col);

	// Elimina la expresion de un columna determinada
	void EliminarExpresion(int col);

	// Retorna el resultado de evaluar una celda en una columna determinada
	// El parametro error devuelve si ocurrio un error o no 
	int EvaluarCelda(InterfazDelSistema *interfaz, int col, bool &error);

	// Operadores de comparacion. Comparan el numero de fila
	bool operator==(const Fila &f) const;
	bool operator!=(const Fila &f) const;
	bool operator<(const Fila &f) const;
	bool operator>(const Fila &f) const;
	bool operator<=(const Fila &f) const;
	bool operator>=(const Fila &f) const;

	// Imprime la formula en la columna determinada
	void ImprimirFormula(int columna) const;

	// Imprime las celdas evaluadas en el rango especificado
	void ImprimirCeldasEvaluadas(InterfazDelSistema *interfaz, int columnaDesde, int columnaHasta) const;


private:
	// Atributos
	int nombreFila; //es el numero de la fila
	//ListaImp<Asociacion<int, ExpresionImp>>* listaDeExpresiones;
};



#endif*/