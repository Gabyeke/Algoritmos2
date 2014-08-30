#ifndef HOJA_H
#define HOJA_H

class InterfazDelSistema;

#include <iostream>
using namespace std;
#include <assert.h>
#include "Cadena.h"
#include "ExpresionImp.h"
#include "Celda.h"


class Hoja;
	ostream &operator<<(ostream& out, const Hoja &h);	

class Hoja {
	
public:
	// Constructor por defecto (no se usa) ** estaba en protected pero la pase para public 
	//xq elimino errores al crear lista
	Hoja(); //{ assert(false); }

	// Constructor con nombre
	Hoja(const Cadena &nombre);

	// Constructor con nombre y listaDeCeldas
	Hoja(const Cadena &nombre, ListaImp<Celda> *listaCeldas);
	
	// Constructor copia
	Hoja(const Hoja &h);

	// Destructor
	~Hoja();

	// Operador de asignacion
	Hoja &operator=(const Hoja &h);

	// Retorna el nombre de la hoja
	const Cadena &GetNombre() const;

	// Modifica el nombre de la hoja
	void SetNombre(const Cadena &nombre);

	// Asigna una expresion a una columna y fila determinada
	void AsignarExpresion(const Expresion &exp, int col, int fil);

	// Elimina la expresion de un columna y fila determinada
	void EliminarExpresion(int col, int fil);

	// Retorna el resultado de evaluar una celda en una columna y fila determinada
	// El parametro error devuelve si ocurrio un error o no 
	int EvaluarCelda(InterfazDelSistema *interfaz, int col, int fil, bool &error);

	// Operadores de comparacion. Comparan el nombre de la hoja
	bool operator==(const Hoja &h) const;
	bool operator!=(const Hoja &h) const;
	bool operator<(const Hoja &h) const;
	bool operator>(const Hoja &h) const;
	bool operator<=(const Hoja &h) const;
	bool operator>=(const Hoja &h) const;

	// Imprime la formula en la columna y fila determinada (segun formato en letra del obligatorio)
	void ImprimirFormula(int columna, int fila) const;

	// Imprime las celdas evaluadas en el rango especificado (segun formato en letra del obligatorio)
	void ImprimirCeldasEvaluadas(InterfazDelSistema *interfaz, int columnaDesde, int filaDesde, int columnaHasta, int filaHasta, bool celdasEvaluadas) const;
	
	// Imprimir Celdas sin Evaluar
	void ListarCeldaSinEvaluar(int columna,int fila) const;

	//Copiar Hoja
	Hoja* CopiarHoja();

	//Es Hoja Vacia
	bool EsHojaVacia() const;

	//Set y Get Nombre
	void SetNombreHoja(char* nombreHoja);
	char* GetNombreHoja() const;
	
	// Buscar Celda
	Celda* BuscarCelda(int fila, int columna);


	//Lista GetListaDeFilas

//protected:;
	

private:

	// Atributos
	Cadena nombre;
	ListaImp<Celda> *listaDeCeldas;
};



#endif