#ifndef HOJA_CPP
#define HOJA_CPP
#define TABULADOR "\t"

#include "Hoja.h"
#include "Cadena.h"
#include "Celda.h"
#include "IteradorListaImp.h"

#include <iostream>
using namespace std;

//***********************************************************************
ostream &operator<<(ostream& out, const Hoja &h) {
	out << h.GetNombre();
	return out;
}
//***********************************************************************
// CONSTRUCTOR SIN PARAMETROS
Hoja::Hoja() {
	Cadena* vacia = new Cadena(" ");
	this->nombre = *vacia;
}
//***********************************************************************
// CONSTRUCTORES CON PARAMETROS
Hoja::Hoja(const Cadena &nombre) {
	this->nombre = nombre;
	this->listaDeCeldas = NULL;
}
//------------------------------------------------------------------------
Hoja::Hoja(const Cadena &nombre, ListaImp<Celda> *listaCeldas) {
	this->nombre = nombre;
	this->listaDeCeldas = listaCeldas;
}
//------------------------------------------------------------------------
Hoja::Hoja(const Hoja &h) {
	this->nombre = h.nombre;
	if(h.listaDeCeldas!=NULL){
		this->listaDeCeldas = h.listaDeCeldas;
	}
	else{
		this->listaDeCeldas= new ListaImp<Celda>();
	}
}
//***********************************************************************
// DESTRUCTOR
Hoja::~Hoja() {
	listaDeCeldas->Vaciar();
}
//***********************************************************************
// OPERADOR ASIGNACION
Hoja &Hoja::operator=(const Hoja &h) {
	if (this != &h) {
		this->nombre = h.nombre;
		if (!(h.listaDeCeldas->EsVacia())){
			this->listaDeCeldas = h.listaDeCeldas;	
		}
	}
	return *this;
}
//***********************************************************************
// SETS Y GETS 
const Cadena &Hoja::GetNombre() const {	
	return this->nombre;
}
//------------------------------------------------------------------------
void Hoja::SetNombre(const Cadena &nombre) {
	this->nombre = nombre;
}
//------------------------------------------------------------------------
void Hoja::SetNombreHoja(char* nombreHoja) {
	Cadena* nombre = new Cadena(nombreHoja);
	this->nombre = *nombre;
}
//------------------------------------------------------------------------
char* Hoja::GetNombreHoja() const {
	return this->nombre.GetS();
}
//***********************************************************************
/// ASIGNAR EXPRESION
void Hoja::AsignarExpresion(const Expresion &exp, int col, int fil) {
	bool seguir=true;
	IteradorListaImp<Celda>* it = new IteradorListaImp<Celda>(*this->listaDeCeldas);
	while(!(it->EsFin())&&seguir) {
		if(it->Elemento().GetFila()==fil && it->Elemento().GetColumna()==col) {
			it->ElementoInseguro().EliminarExpresion();
			Celda *nueva = new Celda(fil, col, *(exp.Clon()));
			it->ElementoInseguro() = *nueva;
			seguir=false;
		}
		it->Resto();
	}
	if(seguir){
		Celda *auxiliar = new Celda(fil, col, *(exp.Clon()));
		this->listaDeCeldas->AgregarFin(*auxiliar);
	}
}
//***********************************************************************
// ELIMINAR EXPRESION
void Hoja::EliminarExpresion(int col, int fil) {
	if(col>0 && fil>0){
		bool seguir=true;
		IteradorListaImp<Celda>* it = new IteradorListaImp<Celda>(*this->listaDeCeldas);
		while(!(it->EsFin())&&seguir) {
			if(it->Elemento().GetFila()==fil && it->Elemento().GetColumna()==col) {
				it->ElementoInseguro().EliminarExpresion();
				seguir=false;
			}
			it->Resto();
		}
		if(seguir){
			cout<<"ERROR: No existe expresion en dicha celda"<<endl;	
		}
	}
	else{
		cout<<"ERROR: Las coordenadas son invalidas"<<endl;	
	}
}
//***********************************************************************
// EVALUAR CELDA
int Hoja::EvaluarCelda(InterfazDelSistema *interfaz, int col, int fil, bool &error) {
	IteradorListaImp<Celda>* it = new IteradorListaImp<Celda>(*this->listaDeCeldas);
	bool seguir = true;
	int resultado = 0;
	while(!(it->EsFin()) && seguir) {
		if(it->Elemento().GetFila()==fil && it->Elemento().GetColumna()==col) {
			Celda aux = it->Elemento();
			resultado = aux.EvaluarCelda(interfaz, error);
			seguir=false;
		}
	}
	if(seguir){
		cout<<"ERROR: No existe expresion en dicha celda para evaluar"<<endl;	
	}
	return resultado;
}
//***********************************************************************
// OPERADOR ==
bool Hoja::operator==(const Hoja &h) const {
	if(this->nombre==h.nombre) {
		return true;
	}	
	return false;
}
//***********************************************************************
// OPERADOR !=
bool Hoja::operator!=(const Hoja &h) const {
	if(this->nombre!=h.nombre) {
		return true;
	}	
	return false;
}

//***********************************************************************
// OPERADOR <
bool Hoja::operator<(const Hoja &h) const {
	if(this->nombre<h.nombre) {
		return true;
	}	
	return false;
}
//***********************************************************************
// OPERADOR >
bool Hoja::operator>(const Hoja &h) const {
	if(this->nombre>h.nombre) {
		return true;
	}	
	return false;
}
//***********************************************************************
// OPERADOR <=
bool Hoja::operator<=(const Hoja &h) const {
	if(this->nombre<=h.nombre) {
		return true;
	}	
	return false;
}
//***********************************************************************
// OPERADOR >=
bool Hoja::operator>=(const Hoja &h) const {
	if(this->nombre>=h.nombre) {
		return true;
	}	
	return false;
}
//***********************************************************************
// IMPRIMIR FORMULA
void Hoja::ImprimirFormula(int columna, int fila) const {
	if(columna>0 && fila>0) {
		IteradorListaImp<Celda>* it = new IteradorListaImp<Celda>(*this->listaDeCeldas);
		while(!(it->EsFin())) {
			if(it->Elemento().GetColumna()==columna && it->Elemento().GetFila()==fila) {
				Celda aux = it->Elemento();
				Expresion *exp = aux.GetExpresion();
				cout<<exp->Formula()<<endl;;
			}
			it->Resto();
		}
	}
	else {
		cout<<"ERROR: Coordenadas invalidas"<<endl;
	}
}
//***********************************************************************
// IMPRIMIR CELDAS EVALUADAS
void Hoja::ImprimirCeldasEvaluadas(InterfazDelSistema *interfaz, int columnaDesde, int filaDesde, int columnaHasta, int filaHasta, bool celdasEvaluadas) const {
	
	IteradorListaImp<Celda>	*it = new IteradorListaImp<Celda>(*(this->listaDeCeldas));
	bool seguir = true;
	bool pasePorAca = false;
	if(columnaDesde>0 && filaDesde>0 && columnaHasta>0 && filaHasta>0 && filaDesde<=filaHasta && columnaDesde<=columnaHasta) {
		cout<<this->nombre<<endl;
		cout<<endl;

		for(int k=columnaDesde; k<=columnaHasta; k++){
			cout<<"\t"<<k;
		}
		cout<<endl;
		for(int i=filaDesde; i<=filaHasta; i++){
			cout<<i<<"\t";
			for(int j=columnaDesde; j<=columnaHasta; j++) {
				if(it->EsFin() && !pasePorAca){
					cout<<"0"<<"\t";
				}
				else if(!(it->EsFin())){
					pasePorAca = true;
					while(!(it->EsFin()) && seguir) {
						if(it->Elemento().GetColumna()==j && it->Elemento().GetFila()==i) {
							bool error = false;
							Celda *aux = &(it->ElementoInseguro());
							int res = aux->EvaluarCelda(interfaz, error);
							if(error) {
								cout<<"#REF"<<"\t";
							}
							else {
								cout<<res<<"\t";
							}
							seguir = false;
						}
						else {							
							it->Resto();
						}
					}
					if(seguir) {
						cout<<"0"<<"\t";
					}
					it = new IteradorListaImp<Celda>(*(this->listaDeCeldas));
					seguir=true;
				}
			}
			cout<<endl;
		}
	}
	else if(columnaDesde>0 && filaDesde>0 && columnaHasta>0 && filaHasta>0 ){
			cout<<"ERROR: Las coordenadas no son validas"<<endl;
		}
	else if (filaDesde<=filaHasta && columnaDesde<=columnaHasta){
			cout<<"ERROR: El rango no es valido"<<endl;
	}
}

//***********************************************************************
// IMPRIMIR CELDAS SIN EVALUAR
void Hoja::ListarCeldaSinEvaluar(int columna,int fila) const {
	IteradorListaImp<Celda>	*it = new IteradorListaImp<Celda>(*(this->listaDeCeldas));
	bool seguir = true;
	if(columna>0 && fila>0) {
		while(!(it->EsFin()) && seguir) {
			if(it->Elemento().GetFila()==fila && it->Elemento().GetColumna()==columna) {
				cout<<this->nombre<<"!"<<it->Elemento().GetColumna()<<":"<<it->Elemento().GetFila()<<" = ";
				it->Elemento().ImprimirFormula(); 
				seguir = false;
			}
			it->Resto();					
		}
	}
	else{
		cout<<"ERROR: Las coordenadas no son validas"<<endl;
	}
}

//***********************************************************************
// COPIAR HOJA
Hoja* Hoja::CopiarHoja() {
	Hoja* aux = new Hoja(*this);	
	return aux;
}
//***********************************************************************
// ES HOJA VACIA
bool Hoja::EsHojaVacia() const {
	Cadena* vacia = new Cadena(" ");
	if(this->nombre==*vacia) {
		return true;
	}
	return false;
}
//***********************************************************************
// BUSCAR CELDA
Celda* Hoja :: BuscarCelda(int fila, int columna) {
	Celda* resultado = new Celda(0,0);

	IteradorListaImp<Celda>* it = new IteradorListaImp<Celda>(*this->listaDeCeldas);
	bool seguir = true;

	while(!(it->EsFin()) && seguir) {
		if(it->Elemento().GetColumna()==columna && it->Elemento().GetFila()==fila) {
			resultado = &(it->ElementoInseguro());
			seguir = false;
		}
		it->Resto();
	}	
	return resultado;
}
//***********************************************************************

#endif