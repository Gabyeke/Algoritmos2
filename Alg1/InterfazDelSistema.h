#ifndef INTERFAZ_DEL_SISTEMA_H
#define INTERFAZ_DEL_SISTEMA_H

#include "Constantes.h"
#include "Expresion.h"
//#include "Planilla.h"

#include <iostream>
using namespace std;

/*	
	Todos los métodos retornan un enumerado correspondiente a si la operación 
	se pudo realizar correctamente, hubo un error o no fue implementada.

	NOTA:
			Ver la especificación completa de los diferentes comandos en 
			la letra del obligatorio.

*/

class Expresion;

class InterfazDelSistema abstract
{
	
	public:

		virtual ~InterfazDelSistema() {};

		/*
		*	Crea e inserta una hoja de cálculo en la planilla, 
		*	la cual tendrá como nombre nombreHoja
		*/
		virtual TipoRet InsertarHoja(char *nombreHoja) abstract;
		
		/*
		*	Elimina la hoja de nombre nombreHoja de la planilla, 
		*	si ésta existe, y todos los datos que están almacenados en ella.  
		*/
		virtual TipoRet EliminarHoja(char *nombreHoja) abstract;
		
		/*
		*	Renombra la hoja de nombre nombreActual a nombreNuevo, si existe 
		*	una hoja de nombre nombreActual y no existe una hoja de nombre nombreNuevo. 
		*	Si nombreActual es igual a nombreNuevo, la operación queda sin efecto.
		*/
		virtual TipoRet RenombrarHoja(char *nombreActual, char *nombreNuevo) abstract;

		/*
		*	Lista todas las hojas que forman la planilla (solo el nombre) en orden alfabético (orden = ALFABETICO)
		*	o en el orden en que se crearon (orden = DECREACION). Se deberá mostrar cada hoja en una nueva línea.
		*	Si no existen hojas, se deberá mostrar un mensaje que lo indique.
		*/
		virtual TipoRet ListarHojas(OrdenListado orden) abstract;

		/*
		*	Este comando permite deshacer la última operación que modificó el sistema. Se podrán deshacer
        *   todas las operaciones efectuadas en el sistema desde su inicio. Las operaciones que podrán
        *   deshacerse son:
        *   InsertarHoja, AsignarExpresionACelda, EliminarHoja, RenombrarHoja y EliminarCelda.
		*/
		virtual TipoRet DeshacerUltimaOperacion() abstract;

		/*
		*	Asigna la expresión aExp en la hoja, columna y fila recibidas como parámetro.
		*	Si la celda ya contiene una expresión, se debe eliminar e insertar la nueva expresión.
		*/
		virtual TipoRet AsignarExpresionACelda(char *nombreHoja, int columna, int fila, const Expresion &aExp) abstract;

		/*
		*	Retorna la celda a su valor por defecto (0), en la hoja, columna y fila recibidas como parámetro.
		*/
		virtual TipoRet EliminarCelda(char *nombreHoja, int columna, int fila) abstract;
		
		/*
		*	Muestra el resultado de evaluar las celdas del rango especificado.
		*	Los datos de cada columna se mostrarán separados por un tabulador y las filas separadas por un fin de línea.
		*/
		virtual TipoRet ListarCeldasEvaluadas(char *nombreHoja, int columnaDesde, int filaDesde, int columnaHasta, int filaHasta) abstract;

		/*
		*	Muestra la fórmula de la celda en la hoja y posición especificada.
		*/
		virtual TipoRet ListarCeldaSinEvaluar(char *nombreHoja, int columna, int fila) abstract;

		/*
		*	Evalúa la referencia recibida. La referencia es un string que contiene el nombre de una hoja, el nombre de una columna y el número de fila. 
		*	Recordar que la celda por defecto tiene el valor cero. El formato es el siguiente, primero se encuentra el nombre de la hoja, 
		*	luego un carácter signo de exclamación '!', luego el número de columna, el carácter dos puntos ':' y finalmente el número de fila.
		*/
		virtual int EvaluarReferencia(char *referencia, bool &error) abstract;

		/*virtual TipoRet SetPlanilla(const Planilla &p) abstract;
		virtual Planilla& GetPlanilla() const abstract;*/
	
};

#endif 