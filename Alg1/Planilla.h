#ifndef PLANILLA_H
#define PLANILLA_H

class InterfazDelSistema;

#include "Constantes.h"
#include "Expresion.h"
#include "Cadena.h"
#include "Hoja.h"
#include "ListaImp.h"
#include "InterfazDelSistemaImp.h"
#include "ExpresionVar.h"

#include <iostream>
using namespace std;


class Planilla 
{
public:
	
	// Constructor por defecto
	Planilla();
	
	// Constructor copia
	Planilla(const Planilla &p);

	// Destructor
	~Planilla();

	// Operador de asignacion
	Planilla &operator=(const Planilla &p);


	// VER Ver la especificación completa de los diferentes comandos en 
	// la letra del obligatorio.
	TipoRet InsertarHoja(char *nombreHoja);
	TipoRet EliminarHoja(char *nombreHoja);
	TipoRet RenombrarHoja(char *nombreActual, char *nombreNuevo);
	TipoRet ListarHojas(OrdenListado orden);
	
	TipoRet AsignarExpresionACelda(char *nombreHoja, int columna, int fila,  const Expresion &exp);
	TipoRet EliminarCelda(char *nombreHoja, int columna, int fila);

	TipoRet ListarCeldasEvaluadas(char *nombreHoja, int columnaDesde, int filaDesde, 
	int columnaHasta, int filaHasta, InterfazDelSistema *interfaz);
	TipoRet ListarCeldaSinEvaluar(InterfazDelSistema *interfaz, char *nombreHoja, int columna, int fila);	
	
	int EvaluarReferencia(InterfazDelSistema *interfaz, char *referencia, bool &error);
	Hoja* BuscarHoja(char* nombreHoja);
	bool MismoTexto(char* texto1, char* texto2) const;
	bool ExisteHoja(char* nombre) const;
	bool CoordenadasValidas(int fila, int columna) const;
	void ImprimirLista(ListaImp<Hoja> *l);
	void ImprimirListaOrdenada();
	bool HaceReferencia(char* referencia, int col, int fil, char* nombreHoja);
	bool operator==(const Planilla &pla) const;
	bool operator!=(const Planilla &pla) const;
	bool operator<(const Planilla &pla) const;
	bool operator<=(const Planilla &pla) const;
	bool operator>(const Planilla &pla) const;
	bool operator>=(const Planilla &pla) const;


private:

	// Atributos
	ListaImp<Hoja> *listaDeHojas;
};

#endif