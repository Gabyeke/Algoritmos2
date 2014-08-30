#ifndef PILAIMP_CPP
#define PILAIMP_CPP

#include "PilaImp.h"
//#include "Lista.h"

#include <iostream>
using namespace std;

//***********************************************************************
// CONSTRUCTOR SIN PARAMETROS
template <class T>	
PilaImp<T>::PilaImp() {
	listaDeOperaciones = new ListaImp<Planilla>();
}
//***********************************************************************
//CONSTRUCTOR CON PARAMETROS
template <class T>	
PilaImp<T>::PilaImp(const Pila<T> &p){
	listaDeOperaciones = p->listaDeOperaciones;
}
//***********************************************************************
// DESTRUCTOR
template <class T>	
PilaImp<T>::~PilaImp(){
	this->listaDeOperaciones->Vaciar();
}
//***********************************************************************
// PUSH	
// Inserta un elemento en el tope	
template <class T>	
void PilaImp<T>::Push(const T &e) {
	this->listaDeOperaciones->AgregarFin(e);
}
//***********************************************************************
// TOP
// Retorna el elemento del tope, 
template <class T>	
const T& PilaImp<T>::Top() {
	return this->listaDeOperaciones->GetFin();
}

//***********************************************************************
// POP
// Extrae un elemento del tope y lo retorna
// en espanol: mueve el punterio fin, disminuye el largo y retorna el elemento que se saco de la pila, NO LO BORRA
// dicho elemento retornado sera seteado en la interfaz
template <class T>	
T PilaImp<T>::Pop() {
	//desencolar
	T aux = this->listaDeOperaciones->GetFin();
	this->listaDeOperaciones->BorrarFin();
	return aux;
}
//***********************************************************************
// VACIAR
// Vacia toda la pila
template <class T>	
void PilaImp<T>::Vaciar() {
	this->listaDeOperaciones->Vaciar();
}
//***********************************************************************
// LARGO
// Retorna la cantidad de elementos de la pila
template <class T>	
unsigned int PilaImp<T>::Largo() const{ 
	return this->listaDeOperaciones->Largo();
}
//***********************************************************************
// ES VACIA
// Reorna true si la pila esta vacia
template <class T>	
bool PilaImp<T>::EsVacia() const {
	return this->listaDeOperaciones->EsVacia();
}
//***********************************************************************
//// OPERADOR ASIGNACION	
template <class T>	
Pila<T> & PilaImp<T>::operator=(const Pila<T> &p) {
	
	return *this;
}
//***********************************************************************


#endif