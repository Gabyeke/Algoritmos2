#ifndef PLANILLA_CPP
#define PLANILLA_CPP

#include "Planilla.h"
#include "Hoja.h"
#include "ListaImp.h"
#include "Cadena.h"
#include "Iterador.h"
#include "InterfazDelSistemaImp.h"

#include <iostream>
using namespace std;

//***********************************************************************
//CONSTRUCTOR SIN PARAMETROS
Planilla::Planilla()
{
	listaDeHojas = new ListaImp<Hoja>();		
}
//***********************************************************************
//CONSTRUCTOR CON PARAMETROS
Planilla::Planilla(const Planilla &p) {
	listaDeHojas = p.listaDeHojas;	
}
//***********************************************************************
//DESTRUCTOR
Planilla::~Planilla()
{
	this->listaDeHojas->Vaciar();
}
//***********************************************************************
//OPERADOR ASIGNACION
Planilla &Planilla::operator=(const Planilla &p) {
	if (this != &p) {
		this->listaDeHojas=p.listaDeHojas;	
	}
	return *this;
}
//***********************************************************************
//INSERTAR HOJA
TipoRet Planilla::InsertarHoja(char *nombreHoja)
{	
	TipoRet resultado = ERROR;
	//Guardar en Pila
	Hoja* encontrada = this->BuscarHoja(nombreHoja);
	if(encontrada->EsHojaVacia()) {		
		Cadena* nombre = new Cadena(nombreHoja);
		Hoja* hoja = new Hoja(*nombre);
		this->listaDeHojas->AgregarFin(*hoja);
		resultado = OK;
	}
	else {
		cout<<"ERROR: Ya existe una hoja con ese nombre"<<endl;
	}

	return resultado;
}
//***********************************************************************
//ELIMINAR HOJA
TipoRet Planilla::EliminarHoja(char *nombreHoja)
{
	TipoRet resultado = ERROR;
	//Guardar en Pila
	Hoja* encontrada = this->BuscarHoja(nombreHoja);
	if(encontrada->EsHojaVacia()) {
		cout<<"ERROR: No existe una hoja con ese nombre"<<endl;		
	}
	else {
		this->listaDeHojas->Borrar(*encontrada);
		encontrada = NULL;
		resultado = OK;
	}

	return resultado;
}
//***********************************************************************
//RENOMBRAR HOJA
TipoRet Planilla::RenombrarHoja(char *nombreActual, char *nombreNuevo)
{
	TipoRet resultado = ERROR;
	Hoja* encontrada = this->BuscarHoja(nombreActual);
	Hoja* existeHoja = this->BuscarHoja(nombreNuevo);
	if(encontrada->EsHojaVacia()) {
		cout<<"ERROR: No existe la hoja buscada"<<endl;
	}
	else if(!(existeHoja->EsHojaVacia())) {
		cout<<"ERROR: Ya existe una hoja con el nuevo nombre"<<endl;
	}
	else {
		encontrada->SetNombreHoja(nombreNuevo);
		resultado = OK;
	}
	return resultado;
}
//***********************************************************************
//LISTAR HOJAS
TipoRet Planilla::ListarHojas(OrdenListado orden)
{
	//se verifica si es vacia y si lo es que se imprima un mensaje
	TipoRet resultado = ERROR;
	if(this->listaDeHojas->EsVacia()) {
		cout<<"No Hay hojas ingresadas."<<endl;
	}
	else if(orden == ALFABETICO) {
		ImprimirListaOrdenada();
	}
	else {
		ImprimirLista(this->listaDeHojas);
	}
	resultado = OK;

	return resultado;
}

//***********************************************************************
//ASIGNAR EXPRESION A CELDA
TipoRet Planilla::AsignarExpresionACelda(char *nombreHoja, int columna, int fila,  const Expresion &exp)
{
	TipoRet resultado = ERROR;
	Hoja* encontrada = this->BuscarHoja(nombreHoja);
	if(columna>0 && fila>0) {
		if(encontrada->EsHojaVacia()) {
			cout<<"ERROR: No existe la hoja buscada"<<endl;
		}
		else {
			encontrada->AsignarExpresion(exp, columna, fila);
			resultado = OK;
		}
	}
	else {
		cout<<"ERROR: Coordenadas fuera de rango"<<endl;
	}
	return resultado;
}
//***********************************************************************
//ELIMINAR CELDA
TipoRet Planilla::EliminarCelda(char *nombreHoja, int columna, int fila)
{
	TipoRet resultado = ERROR;
	Hoja* encontrada = this->BuscarHoja(nombreHoja);
	bool puedoBorrar= true;
	bool seguir = true;
	if(columna>0 && fila>0) {
		if(encontrada->EsHojaVacia()) {
			cout<<"ERROR: No existe la hoja buscada"<<endl;
		}
		else {
			encontrada->EliminarExpresion(columna, fila);
			resultado = OK;
		}
	}
	else {
		cout<<"ERROR: Coordenadas invalidas"<<endl;
	}
	return resultado;
}
//***********************************************************************
//LISTAR CELDAS EVALUADAS
TipoRet Planilla::ListarCeldasEvaluadas(char *nombreHoja, int columnaDesde, int filaDesde, 
											int columnaHasta, int filaHasta, InterfazDelSistema *interfaz)
{
	TipoRet resultado = ERROR;		
	if(columnaDesde>0 && filaDesde>0 && columnaHasta>0 && filaHasta>0 && filaDesde<=filaHasta && columnaDesde<=columnaHasta) {
		Hoja* buscada = this->BuscarHoja(nombreHoja);
		if(buscada->EsHojaVacia()) {
			cout<<"ERROR: No se encuentra la hoja buscada"<<endl;
		}
		else {
			buscada->ImprimirCeldasEvaluadas(interfaz, columnaDesde, filaDesde, columnaHasta, filaHasta, true);
			resultado = OK;
		}
	}
	else {
		cout<<"ERROR: Coordenadas invalidas"<<endl;
	}

	return resultado;
}
//***********************************************************************
//LISTAR CELDAS SIN EVALUAR 
TipoRet Planilla::ListarCeldaSinEvaluar(InterfazDelSistema *interfaz, char *nombreHoja, int columna, int fila)
{
	TipoRet resultado = ERROR;	
	if(columna>0 && fila>0) {
		Hoja* buscada = this->BuscarHoja(nombreHoja);
		if(buscada->EsHojaVacia()) {
			cout<<"ERROR: No se encuentra la hoja buscada"<<endl;
		}
		else {
			buscada->ListarCeldaSinEvaluar(columna, fila);
			resultado = OK;
		}
	}
	else {
		cout<<"ERROR: Coordenadas invalidas"<<endl;
	}

	return resultado;
}	
//***********************************************************************
//EVALUAR REFERENCIA
int Planilla::EvaluarReferencia(InterfazDelSistema *interfaz, char *referencia, bool &error)
{
	int resultadoEvaluacion = 0;

	// 1- Leemos la referencia para ubicar la expresion
	char* ruta = referencia;	
	int largo = strlen(ruta);
	char* hoja = new char[largo];	
	char* fila = new char[largo];
	char* columna = new char[largo];
	
	int count1=0; 
	int count2=0; 
	int count3=0;

	bool ok1=true;
	bool ok2=true;
	bool ok3=true;

	// guardamos el nombre de la hoja
	for(int i=0; i<largo; i++) {						
		if(ok1 && ruta[i]!='!') {
			hoja[count1] = ruta[i];
			count1++;
		}
		else if (ruta[i]=='!'){
			ok1= false;		
		}
	}
	hoja[count1] = '\0';
	// guardamos el valor de la coumna
	for(int i=count1+1; i<largo; i++) {
		if(ok2 && ruta[i]!=':') {
			columna[count2] = ruta [i];
			count2++;				
		}	
		else if (ruta [i]== ':'){
		ok2= false;
		}
	}
	columna [count2] = '\0';
	// guardamos el valor de la fila
	for(int i=count1+count2+2; i<largo; i++) {
		fila [count3] = ruta [i];
		count3++;		
	}
	fila [count3] = '\0';

	// convertimos los chars leidos a ints
	int filaInt = atoi(fila);
	int columnaInt = atoi(columna);

	// verificamos que las coordenadas fila y columna sean validas
	bool auxiliar = (filaInt>0 && columnaInt>0);
	Hoja* buscada = new Hoja();
	Hoja* nueva = new Hoja();
	
	// 2- Buscamos Hoja y Celda siempre y cuando sean validas
	if (auxiliar){
		buscada = this->BuscarHoja(hoja);
		if(buscada->EsHojaVacia()) {
			cout<<"ERROR: La hoja buscada no existe"<<endl;
		}
		else {
			//EVALUAR
			resultadoEvaluacion = (buscada->BuscarCelda(filaInt, columnaInt))->EvaluarCelda(interfaz, error);
		}
	}
	else {
		cout<<"ERROR: Coordenadas invalidas"<<endl;
	}
	return resultadoEvaluacion;
}
//***********************************************************************
// BUSCAR HOJA
Hoja* Planilla :: BuscarHoja(char* nombreHoja) {
	Cadena* vacia = new Cadena(" ");
	Hoja* resultado = new Hoja(*vacia);

	Cadena* nombre = new Cadena(nombreHoja);
	Hoja* buscada = new Hoja(*nombre);
	IteradorListaImp<Hoja>* it = new IteradorListaImp<Hoja>(*this->listaDeHojas);
	bool seguir = true;

	while(!(it->EsFin()) && seguir) {
		if(it->Elemento()==*buscada) {
			resultado = &(it->ElementoInseguro());
			seguir = false;
		}
		it->Resto();
	}
	
	return resultado;
}
//***********************************************************************
//PRECONDICION
//Se pasan dos textos
bool Planilla::MismoTexto(char* texto1, char* texto2) const {
	
bool mismoTexto = false;
bool sigo = true;

int indice1 = strlen(texto1);
int indice2 = strlen(texto2);

if(indice1==indice2) {
	while(sigo) {
		for(int i=0; i<indice1; i++) {			
			if(texto1[i]!=texto2[i]) {		
				sigo = false;				
			}			
			if(sigo) {
				mismoTexto = true;
				sigo = false;
			}
		}
	}
}
return mismoTexto;
}
//***********************************************************************
// EXISTE HOJA
// PRE-
// POST Devuelve true si existe la hoja buscada
bool Planilla::ExisteHoja(char* nombre) const {
	Hoja* auxiliar = new Hoja();
	Cadena* aux = new Cadena(nombre);
	auxiliar->SetNombre(*aux);
	bool existe = this->listaDeHojas->Existe(*auxiliar);
	return existe;
}
//***********************************************************************
// COORDENADAS VALIDAS
// PRE-
// POST Devuelve true si fila y columna son >1
bool Planilla::CoordenadasValidas(int fila, int columna) const {
	if(fila>=1 && columna>=1){
		return true;
	}
	return false;
}
//***********************************************************************
// IMPRIMIR LISTA
void Planilla::ImprimirLista(ListaImp<Hoja> *l) {
	IteradorListaImp<Hoja>* it = new IteradorListaImp<Hoja>(*l);
	while(!(it->EsFin())) {
		cout<<it->Elemento()<<endl;
		it->Resto();
	}
}

//***********************************************************************
// IMPRIMIR LISTA ORDENADA
void Planilla::ImprimirListaOrdenada() {
	IteradorListaImp<Hoja>* it = new IteradorListaImp<Hoja>(*this->listaDeHojas);
	ListaImp<Hoja>* nueva = new ListaImp<Hoja>();
	nueva->AsignarTopeDeLista(this->listaDeHojas->GetTope());
	while(!(it->EsFin())) {
		nueva->AgregarOrd(it->Elemento());
		it->Resto();
	}
	ImprimirLista(nueva);
}

//***********************************************************************

bool Planilla::HaceReferencia(char* referencia, int col, int fil, char* nombreHoja) {
	bool hace = false;

	// 1- Leemos la referencia para ubicar la expresion
	char* ruta = referencia;	
	int largo = strlen(ruta);
	char* hoja = new char[largo];	
	char* fila = new char[largo];
	char* columna = new char[largo];
	
	int count1=0; 
	int count2=0; 
	int count3=0;

	bool ok1=true;
	bool ok2=true;
	bool ok3=true;

	// guardamos el nombre de la hoja
	for(int i=0; i<largo; i++) {						
		if(ok1 && ruta[i]!='!') {
			hoja[count1] = ruta[i];
			count1++;
		}
		else if (ruta[i]=='!'){
			ok1= false;		
		}
	}
	hoja[count1] = '\0';
	// guardamos el valor de la coumna
	for(int i=count1+1; i<largo; i++) {
		if(ok2 && ruta[i]!=':') {
			columna[count2] = ruta [i];
			count2++;				
		}	
		else if (ruta [i]== ':'){
		ok2= false;
		}
	}
	columna [count2] = '\0';
	// guardamos el valor de la fila
	for(int i=count1+count2+2; i<largo; i++) {
		fila [count3] = ruta [i];
		count3++;		
	}
	fila [count3] = '\0';

	// convertimos los chars leidos a ints
	int filaInt = atoi(fila);
	int columnaInt = atoi(columna);

	// verificamos que las coordenadas fila y columna sean validas
	bool auxiliar = (filaInt>0 && columnaInt>0);


	// 2- Verificamos que la referencia sea a la celda pasada por parametro
	if (auxiliar){
		if(fil==filaInt && col==columnaInt && this->MismoTexto(hoja, nombreHoja)) {
			hace = true;
		}
	}	
	return hace;
}
//***********************************************************************

// OPERADOR ==
// PRE
// POST
bool Planilla::operator==(const Planilla &pla) const {
	if(this->listaDeHojas==pla.listaDeHojas) {
		return true;
	}	
	return false;
}
//***********************************************************************

// OPERADOR <
// PRE
// POST
bool Planilla::operator<(const Planilla &pla) const {
	if(this->listaDeHojas->Largo()<pla.listaDeHojas->Largo()) {
		return true;
	}	
	return false;
}
//***********************************************************************

// OPERADOR !=
// PRE
// POST
bool Planilla::operator!=(const Planilla &pla) const {
	if(this->listaDeHojas!=pla.listaDeHojas) {
		return true;
	}	
	return false;
}

//***********************************************************************
// OPERADOR <=
// PRE
// POST
bool Planilla::operator<=(const Planilla &pla) const {
	if(this->listaDeHojas->Largo()<=pla.listaDeHojas->Largo() && *this==pla) {
		return true;
	}	
	return false;
}
//***********************************************************************
// OPERADOR >
// PRE
// POST
bool Planilla::operator>(const Planilla &pla) const {
	if(this->listaDeHojas->Largo()>pla.listaDeHojas->Largo()) {
		return true;
	}	
	return false;
}
//***********************************************************************
// OPERADOR >=
// PRE
// POST
bool Planilla::operator>=(const Planilla &pla) const {
	if(this->listaDeHojas->Largo()>=pla.listaDeHojas->Largo() && *this==pla) {
		return true;
	}	
	return false;
}
//***********************************************************************


#endif