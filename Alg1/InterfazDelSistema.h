#ifndef INTERFAZ_DEL_SISTEMA_H
#define INTERFAZ_DEL_SISTEMA_H

#include "Constantes.h"
#include "Expresion.h"
//#include "Planilla.h"

#include <iostream>
using namespace std;

/*	
	Todos los m�todos retornan un enumerado correspondiente a si la operaci�n 
	se pudo realizar correctamente, hubo un error o no fue implementada.

	NOTA:
			Ver la especificaci�n completa de los diferentes comandos en 
			la letra del obligatorio.

*/

class Expresion;

class InterfazDelSistema abstract
{
	
	public:

		virtual ~InterfazDelSistema() {};

		/*
		*	Crea e inserta una hoja de c�lculo en la planilla, 
		*	la cual tendr� como nombre nombreHoja
		*/
		virtual TipoRet InsertarHoja(char *nombreHoja) abstract;
		
		/*
		*	Elimina la hoja de nombre nombreHoja de la planilla, 
		*	si �sta existe, y todos los datos que est�n almacenados en ella.  
		*/
		virtual TipoRet EliminarHoja(char *nombreHoja) abstract;
		
		/*
		*	Renombra la hoja de nombre nombreActual a nombreNuevo, si existe 
		*	una hoja de nombre nombreActual y no existe una hoja de nombre nombreNuevo. 
		*	Si nombreActual es igual a nombreNuevo, la operaci�n queda sin efecto.
		*/
		virtual TipoRet RenombrarHoja(char *nombreActual, char *nombreNuevo) abstract;

		/*
		*	Lista todas las hojas que forman la planilla (solo el nombre) en orden alfab�tico (orden = ALFABETICO)
		*	o en el orden en que se crearon (orden = DECREACION). Se deber� mostrar cada hoja en una nueva l�nea.
		*	Si no existen hojas, se deber� mostrar un mensaje que lo indique.
		*/
		virtual TipoRet ListarHojas(OrdenListado orden) abstract;

		/*
		*	Este comando permite deshacer la �ltima operaci�n que modific� el sistema. Se podr�n deshacer
        *   todas las operaciones efectuadas en el sistema desde su inicio. Las operaciones que podr�n
        *   deshacerse son:
        *   InsertarHoja, AsignarExpresionACelda, EliminarHoja, RenombrarHoja y EliminarCelda.
		*/
		virtual TipoRet DeshacerUltimaOperacion() abstract;

		/*
		*	Asigna la expresi�n aExp en la hoja, columna y fila recibidas como par�metro.
		*	Si la celda ya contiene una expresi�n, se debe eliminar e insertar la nueva expresi�n.
		*/
		virtual TipoRet AsignarExpresionACelda(char *nombreHoja, int columna, int fila, const Expresion &aExp) abstract;

		/*
		*	Retorna la celda a su valor por defecto (0), en la hoja, columna y fila recibidas como par�metro.
		*/
		virtual TipoRet EliminarCelda(char *nombreHoja, int columna, int fila) abstract;
		
		/*
		*	Muestra el resultado de evaluar las celdas del rango especificado.
		*	Los datos de cada columna se mostrar�n separados por un tabulador y las filas separadas por un fin de l�nea.
		*/
		virtual TipoRet ListarCeldasEvaluadas(char *nombreHoja, int columnaDesde, int filaDesde, int columnaHasta, int filaHasta) abstract;

		/*
		*	Muestra la f�rmula de la celda en la hoja y posici�n especificada.
		*/
		virtual TipoRet ListarCeldaSinEvaluar(char *nombreHoja, int columna, int fila) abstract;

		/*
		*	Eval�a la referencia recibida. La referencia es un string que contiene el nombre de una hoja, el nombre de una columna y el n�mero de fila. 
		*	Recordar que la celda por defecto tiene el valor cero. El formato es el siguiente, primero se encuentra el nombre de la hoja, 
		*	luego un car�cter signo de exclamaci�n '!', luego el n�mero de columna, el car�cter dos puntos ':' y finalmente el n�mero de fila.
		*/
		virtual int EvaluarReferencia(char *referencia, bool &error) abstract;

		/*virtual TipoRet SetPlanilla(const Planilla &p) abstract;
		virtual Planilla& GetPlanilla() const abstract;*/
	
};

#endif 