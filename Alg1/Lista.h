#ifndef LISTA_H
#define LISTA_H

#include <iostream>
using namespace std;

#include "Iterador.h"
#include "Iterable.h"
#include "Expresion.h"

template <class T>
class Lista;

// Escribe los elementos de la lista en el flujo out
template <class T>
ostream &operator<< <>(ostream& out, const Lista<T> &l) {
	for (Iterador<T> &i = l.GetIterador(); !i.EsFin();) {
		out << i++ << " ";
	}
	return out;
}

template <class T>
class Lista abstract : public Iterable<T> {

public:

	// PRE: -
	// POS: Destructor
	virtual ~Lista() { }

	// PRE: -
	// POS: Agrega el elemento e al principio de la lista
	virtual void AgregarPpio(const T &e) abstract;
	
	// PRE: -
	// POS: Agrega el elemento e al final de la lista
	virtual void AgregarFin(const T &e) abstract;

	// PRE: -
	// POS: Agrega el elemento e en la lista ordenada de menor a mayor
	// Usa el operador < del elemento e (inserta antes de uno mayor o igual)
	virtual void AgregarOrd(const T &e/*, int (*f)(const T&, const T&)*/) abstract;

	// PRE: -
	// POS: Borra el primer elemento de la lista. Si no hay elementos no tiene efecto
	virtual void BorrarPpio() abstract;

	// PRE: -
	// POS: Borra el ultimo elemento de la lista. Si no hay elementos no tiene efecto
	virtual void BorrarFin() abstract;

	// PRE: -
	// POS: Borra el primer elemento que sea igual a e
	// Usa el operador == del elemento e para encontrar uno igual.
	// Si no encuentra no tiene efecto
	virtual void Borrar(const T &e) abstract;

	// PRE: Existe el elemento a recuperar
	// POS: Retorna el primer elemento que sea igual a e
	// Usa el operador == del elemento e para encontrar uno igual
	virtual const T& Recuperar(const T &e) const abstract;

	// PRE: -
	// POS: Busca si existe un elemento que sea igual a e
	// Usa el operador == del elemento e para encontrar uno igual
	virtual bool Existe(const T &e) const abstract;

	// PRE: -
	// POS: Vacia la lista
	virtual void Vaciar() abstract;

	// PRE: -
	// POS: Retorna true si la lista esta vacia
	virtual bool EsVacia() const abstract;

	// PRE: -
	// POS: Retorna true si la lista esta llena
	virtual bool EsLlena() const abstract;

	// PRE: -
	// POS: Retorna el largo de la lista
	virtual unsigned int Largo() const abstract;
	
	// PRE: -
	// POS: Se asigna tope a la lista, o sea, cantidad maxima de elementos que puede contener
	virtual void AsignarTopeDeLista(int maximo) abstract;

	// PRE: -
	// POS: Retorna si las 2 listas tienen los mismos elementos (comparados con el operador ==) 
	// y en el mismo orden
	virtual bool operator==(const Lista<T> &l) const { 
		Iterador<T> &i = l.GetIterador();
		Iterador<T> &i2 = this->GetIterador();
		while (!i.EsFin() && !i2.EsFin()) {
			if (!(i++ == i2++))
				return false;
		} 
		if (i.EsFin() != i2.EsFin())
			return false;

		return true;
	}

	// PRE: -
	// POS: Operador de asignacion
	virtual Lista<T> &operator=(const Lista<T> &l) {
		if (this != &l) {
			this->Vaciar();
			for (Iterador<T> &i = l.GetIterador(); !i.EsFin();) {
				AgregarFin(i++);
			}
		}
		return *this;
	}

protected:
	// CONSTRUCTORES
	Lista() { }
	Lista(const Lista &l) { }

};


#endif