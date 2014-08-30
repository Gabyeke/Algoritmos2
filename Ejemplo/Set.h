#pragma once

#include "Puntero.h"
#include "Iterable.h"
typedef unsigned int nat;

template <class T>
class Set abstract : public Iterable<T>
{
public:
	virtual ~Set(){}

	virtual nat Tamanio() const abstract;

	virtual void Insertar(const T &x) abstract;
	/* inserta el elemento x en el conjunto, si es
	que x no era ya un elemento del conjunto */

	virtual bool EsVacio() const abstract;
	// retorna true si el conjunto es vacío

	virtual bool EsLleno() const abstract;
	// retorna true si el conjunto está lleno

	virtual bool Pertenece(const T &x) const abstract;
	// retorna true si x está en el conjunto

	virtual Puntero<Set<T>> Union(Puntero<Set<T>> A) const abstract;
	/* construye el conjunto de los elementos
	que pertenecen a *A, o al conjunto al cual
	se le aplica el método, o a ambos */

	virtual Puntero<Set<T>> Interseccion(Puntero<Set<T>> A) const abstract;
	/* construye el conjunto de los elementos que
	pertenecen a *A y al conjunto al cual se le aplica el
	método */

	virtual Puntero<Set<T>> Diferencia(Puntero<Set<T>> A) const abstract;
	/* construye el conjunto de los elementos que
	pertenecen al conjunto al cual se le aplica el método
	y no pertenecen a *A */

	virtual Iterador<T> ObtenerIterador() const abstract;
	/* Obtiene el Iterador de los elementos existentes en el Set*/

	void Imprimir()
	{
		cout << "{ ";
		Iterador<T> it = ObtenerIterador();
		if (it.HayElemento())
		{
			T ult = *it;
			for (it++; it.HayElemento(); it++)
			{
				cout << ult << ", ";
				ult = *it;
			}
			cout << ult;
			cout << " }" << endl;
		}
		else
			cout << "}" << endl;
	}
};
