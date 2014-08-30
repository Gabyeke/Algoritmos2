#ifndef LISTAIMP_H
#define LISTAIMP_H

#include <assert.h>
#include "Lista.h"
#include "IteradorListaImp.h"
#include "Expresion.h"

template <class T>
class IteradorListaImp;

template <class U>
class NodoLista {
	public:
		U dato;
		NodoLista<U> *ant;
		NodoLista<U> *sig;
		
		NodoLista(){ ant = sig = NULL;}
		NodoLista(const U &e, NodoLista<U> *a, NodoLista<U> *s) : dato(e), ant(a), sig(s){}
		NodoLista(const NodoLista<U> &n) : dato(n.dato), ant(n.ant), sig(n.sig)  {}

		NodoLista<U> &operator=(const NodoLista<U> &n) { dato = n.dato; ant = n.ant; sig = n.sig; return *this;}

		virtual bool operator== (const NodoLista<U> &n) const {
			bool es = false;
			if(dato==n.dato) {
				return true;
				//es = true/*(this->ant==n.ant)&&(this->sig==n.sig)*/;
			}
			return false;
		}

		virtual bool operator>= (const NodoLista<U> &n) const {
			if(dato>=n.dato) {
				return true;
			}
			return false;
		}

		virtual bool operator<= (const NodoLista<U> &n) const {
			if(dato<=n.dato) {
				return true;
			}
			return false;
		}

		virtual ~NodoLista() {}
};

template <class T>
class ListaImp: public Lista<T> {
	friend class IteradorListaImp<T>; 
	friend ostream &operator<< <>(ostream& o, const ListaImp<T> & l);
public:

	// Constructor por defecto
	ListaImp();

	// Constructor copia
	ListaImp(const ListaImp<T> &l);

	// Set y Get
	void SetPpio(const T &dato);
	T GetPpio();
	void SetFin(const T &dato);
	T GetFin();
	unsigned int GetTope();

	// Operador de asignacion
	Lista<T> &operator=(const Lista<T> &l);

	// Para ver la documentacion del resto de las funciones ver la especificacion
	~ListaImp();

	void AgregarPpio(const T &e);
	void AgregarFin(const T &e);
	void AgregarOrd(const T &e/*, int (*f)(const T&, const T&)*/);	

	void BorrarPpio();	
	void BorrarFin();	
	void Borrar(const T &e);	

	const T& Recuperar(const T&) const; 
	bool Existe(const T &e) const;	

	void Vaciar();
	unsigned int Largo() const;	
	
	bool EsVacia() const;
	bool EsLlena() const;
	void AsignarTopeDeLista(int maximo);
	Iterador<T> GetIterador() const;
	void SetLargo(int dato);


protected:
	// Atributos
	NodoLista<T> *ppio; //Puntero al ppio de la lista
	NodoLista<T> *fin; //Puntero al fin de la lista
	unsigned int largo; //Lleva la cuenta de la cantidad de elementos de la lista
	unsigned int tope; //Maximo de elementos que puede contener la lista
};

#include "ListaImp.cpp"

#endif