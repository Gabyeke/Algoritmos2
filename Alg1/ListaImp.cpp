#ifndef LISTAIMP_CPP
#define LISTAIMP_CPP

#include "Iterador.h"
#include "ListaImp.h"

#include <iostream>
using namespace std;

template <class T>
class ListaImp;

template <class T>
class NodoLista;

//***********************************************************************
template <class T>
ostream &operator<< <>(ostream& out, const ListaImp<T> &l) {
	for (Iterador<T> &i = l.GetIterador(); !i.EsFin();) {
		out << i++ << " ";
	}
	return out;
}
//***********************************************************************
//CONSTRUCTOR SIN PARAMETROS
template <class T>
ListaImp<T>::ListaImp(){
    ppio = fin = NULL;
    largo = 0;
	tope = 200;
}
//***********************************************************************
//CONSTRUCTOR CON PARAMETROS
template <class T>
ListaImp<T>::ListaImp(const ListaImp<T> &l) {
	
	ppio = lista->ppio;
	fin = lista->fin;
	largo = lista->largo;
	*this=l;
}

//***********************************************************************
// OPERADOR ASIGNACION
template <class T>
Lista<T> &ListaImp<T>::operator=(const Lista<T> &l) { 
	if (this != &l) {
		this->Vaciar();

		for (Iterador<T> &i = l.GetIterador(); !i.EsFin();) {
			AgregarFin(i++);
		}
	}
	return *this;
}
//***********************************************************************
//DESTRUCTOR
template <class T>
ListaImp<T>::~ListaImp(){
	Vaciar();
}
//***********************************************************************
// AGREGAR PRINCIPIO
//PRE- lista no llena 
//POST se agrega un elemento al ppio de la misma
template <class T>
void ListaImp<T>::AgregarPpio(const T &e){
	if(!(this->EsLlena())) {
		NodoLista<T> * aux = new NodoLista<T>(e, NULL, NULL);
		
		if(this->EsVacia()) {
			ppio = aux;
			fin = aux;
		}
		else {			
			aux -> sig = ppio;
			ppio -> ant = aux;
			ppio = aux;
		}
		largo++;
	}
}
//***********************************************************************
// AGREGAR FIN
//PRE- lista no llena 
//POST se agrega un elemento al final de la misma
template <class T>
void ListaImp<T>::AgregarFin(const T &e){
	if(!(this->EsLlena())) {
		NodoLista<T> *aux = new NodoLista<T>(e, NULL, NULL);
		if(this->EsVacia()) {
			this->ppio = aux;
			this->fin = aux;
		}
		else {
			aux->ant = this->fin;
			this->fin->sig = aux;
			this->fin = aux;
		}
		largo++;
	}
}

//***********************************************************************
// AGREGAR ORDENADO
//PRE- lista no llena 
//POST se agrega un elemento en la posicion adecuada de forma de mantener el orden de la lista
template <class T>
void ListaImp<T>::AgregarOrd(const T &e){
	NodoLista<T>* nodoActual = ppio;
	if(!(this->EsLlena())) {		
		if(this->largo==0 || (ppio->dato)>=e) {
			AgregarPpio(e);
		}
		else if(fin->dato<=e) {
			AgregarFin(e);
		}
		else {
			bool seguir = true;
			while(nodoActual!=NULL && seguir) {
				if(e<=nodoActual->dato) {
					NodoLista<T> *nodoAgregar = new NodoLista<T>(e, NULL, NULL);
					nodoAgregar->ant = nodoActual->ant;
					nodoAgregar->sig = nodoActual;
					nodoActual->ant->sig = nodoAgregar;
					nodoActual->ant = nodoAgregar;
					largo++;
					seguir=false;
				}
				else {
					nodoActual = nodoActual->sig;
				}				
			}
		}
	}
}
//***********************************************************************
//BORRAR PRINCIPIO
// PRE-
//POST Se borra el primer elemento de la lista y se decrementa el largo de la lista en una unidad
template <class T>
void ListaImp<T>::BorrarPpio(){
	if(!(this->EsVacia())) {
		NodoLista<T> *aux = ppio;

		if(largo==1){
			delete aux;
			ppio = fin = aux = NULL;
		}
		else {
			ppio = ppio->sig;
			delete aux;
			aux = NULL;
			ppio->ant = NULL;
		}	
		largo--;
	}
}
//***********************************************************************
//BORRA FIN
//PRE-
//POST Se borra el ultimo elemento de la lista y se decrementa el largo de la lista en una unidad
template <class T>
void ListaImp<T>::BorrarFin(){
	if(!(this->EsVacia())) {
		NodoLista<T> * aux = fin;
		if(largo==1) {
			delete aux;
			ppio = fin = aux = NULL;
		}
		else {
			fin = fin->ant;
			fin->sig = NULL;
			delete aux;
			aux = NULL;
		}		
		largo--;
	}
}
//***********************************************************************
// BORRAR 
//PRE-
//POST Se elimina el elemento e y se decrementa el largo de la lista en una unidad,
//si el elemento no pertenece a la lista no se hace nada.
template <class T>
void ListaImp<T>::Borrar(const T &e){		
	NodoLista<T>* nodoAEliminar = ppio;
	if(!(this->EsVacia())) {		
		if(this->largo==0 || ppio->dato==e) {
			this->BorrarPpio();
		}
		else if(fin->dato==e) {
			this->BorrarFin();
		}
		else {
			bool seguir = true;
			while(nodoAEliminar!=NULL && seguir) {
				if(e==nodoAEliminar->dato) {
					NodoLista<T> *nodoAEliminarAux = nodoAEliminar;
					nodoAEliminar->ant->sig = nodoAEliminar->sig;
					nodoAEliminar->sig->ant = nodoAEliminar->ant;
					delete nodoAEliminarAux;
					nodoAEliminar = nodoAEliminarAux = NULL;
					largo--;
					seguir=false;
				}
				else {
					nodoAEliminar = nodoAEliminar->sig;
				}				
			}
			if(seguir) {
				cout<<"ERROR: No se encuentra elemento en la lista"<<endl;
			}
		}
	}
	else {
		cout<<"ERROR: La lista esta vacia"<<endl;
	}

}
//***********************************************************************
//RECUPERAR
//PRE- 
//POST Se devuelve el primer elemento igual al elemento buscado, si no se 
//encuentra este se devuelve un elemento NULL ??????????

template <class T>
const T& ListaImp<T>::Recuperar(const T &e) const {
	bool seguir = true;
	IteradorListaImp<T> *it = new IteradorListaImp<T>(*this);
	T aux;
	while(!(it->EsFin()) && seguir) {
		if(it->Elemento()==e) {
			aux = e;
			seguir = false;
		}
		else{
			it->Resto();
		}
	}
	return *(new T(aux)); 
}
//***********************************************************************
//EXISTE
//PRE-
//POST Se devuelve true si el elemento buscado se encuentra en la lista
template <class T>
bool ListaImp<T>::Existe(const T &e) const {
    bool existe= false;
	IteradorListaImp<T> *it = new IteradorListaImp<T>(*this);
	while(!(it->EsFin())) {
		if(it->Elemento()==e) {
			existe = true;
		}
		else{
			it->Resto();
		}
	}
	return existe;
}
//***********************************************************************
//VACIAR
//PRE-
//POST Se eliminan todos los elementos de la lista
template <class T>
void ListaImp<T>::Vaciar(){
	NodoLista<T> *aux = ppio, *aux2;
	while(aux!=NULL) {
		aux2 = aux->sig;
		delete aux;
		aux = aux2;
	}
	//delete ppio;
	ppio = fin = NULL;
	largo = 0;
}

//***********************************************************************
//LARGO
//PRE-
//POST Devuelve el largo de la lista, o sea la cantidad de elementos que hay en la misma
template <class T>
unsigned int ListaImp<T>::Largo()const {
	return largo;
}
//***********************************************************************
//ES VACIA
//PRE-
//POST Devuelve true si la lsiat esta vacia, o sea no tiene ningun elmento
template <class T>
bool ListaImp<T>::EsVacia()const { 
	return largo==0; 
}

//***********************************************************************
//ES LLENA
//PRE-
//POST Devuelve true si la lista esta llena, tiene el maximo de elementos
// que puede tener (tope)
template <class T>
bool ListaImp<T>::EsLlena()const {
	return largo==tope; 
}
//***********************************************************************

template <class T>
Iterador<T> ListaImp<T>::GetIterador() const {
	return IteradorListaImp<T>(*this);
}
//***********************************************************************
// este metodo es de pila ????????? si lo sacamos cambiar esLlena 
// ASIGNAR TOPE A LISTA
//PRE-
//POST Permite modificar el tope de la lista, al crearse la misma se le asigna un tope
// arbitrario de 100 elementos, el mismo puede ser modificado a traves de este metodo.
template <class T>
void ListaImp<T>::AsignarTopeDeLista(int maximo) {
	tope = maximo;
}

//***********************************************************************
// SETS Y GETS / PRINCIPIO-FIN
//PRE-
//POST Se crean estos metodos para poder acceder a los atributos de la lista 
//que son protected 
	template <class T>
	void ListaImp<T>::SetPpio(const T &dato) {	}
//------------------------------------------------------------------------
	template <class T>
	T ListaImp<T>::GetPpio() {return ppio->dato;}
//------------------------------------------------------------------------
	template <class T>
	void ListaImp<T>::SetFin(const T &dato) {}
//------------------------------------------------------------------------	
	template <class T>
	T ListaImp<T>::GetFin() {return fin->dato;}
//------------------------------------------------------------------------
	template <class T>
	unsigned int ListaImp<T>::GetTope() {return this->tope;}

//------------------------------------------------------------------------
	template <class T>
	void ListaImp<T>::SetLargo(int dato) {
		this->largo = dato;
	}
//***********************************************************************


#endif