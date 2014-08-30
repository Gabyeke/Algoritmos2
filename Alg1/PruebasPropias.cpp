#ifndef PRUEBASPROPIAS_CPP
#define PRUEBASPROPIAS_CPP
#include "PruebasPropias.h"

#include <iostream>
using namespace std;

PruebasPropias::PruebasPropias(ConductorPrueba* conductor)
:Prueba(conductor)
{
	interfaz = new InterfazDelSistemaImp();
}

PruebasPropias::~PruebasPropias()
{
	delete interfaz;
}
char* PruebasPropias::getNombre()const
{
	return "PruebasPropias";
}

void PruebasPropias::correrPruebaConcreta()
{


	cout<<"\n\n";
	std::cout<<"****************** PRUEBAS PROPIAS ********************\n";
	cout<<"************************************************************\n\n";
	
	pruebasPropiasOK();
	pruebasPropiasERROR();

	cout<<"----------------------------------------------------------------------"<<endl;
	cout<<"Fin PRUEBAS PROPIAS."<<endl;
	cout<<"----------------------------------------------------------------------"<<endl;

}


void PruebasPropias::pruebasPropiasOK(){
	cout<<"\n\n";
	std::cout<<"********************* PRUEBAS OK **********************\n";
	cout<<"************************************************************\n\n";

	Prueba_OK1_EXPRESIONES();
	Prueba_OK2_EXPRESIONES();
	Prueba_OK3_EXPRESIONES();	

	Prueba_OK1_PLANILLA();
	Prueba_OK2_PLANILLA();
	Prueba_OK3_PLANILLA();	
	Prueba_OK4_PLANILLA();	
	Prueba_OK5_PLANILLA();	
	Prueba_OK6_PLANILLA();	


	cout<<"----------------------------------------------------------------------"<<endl;
	cout<<"Fin Pruebas OK."<<endl;
	cout<<"----------------------------------------------------------------------"<<endl;
}

void PruebasPropias::pruebasPropiasERROR() {
	
	cout<<"\n\n";
	std::cout<<"******************** PRUEBAS ERROR ********************\n";
	cout<<"************************************************************\n\n";

	Prueba_ERROR1_PLANILLA();
	
	cout<<"----------------------------------------------------------------------"<<endl;
	cout<<"Fin Pruebas ERROR."<<endl;
	cout<<"----------------------------------------------------------------------"<<endl;
}


void PruebasPropias::Prueba_OK1_EXPRESIONES(){

	cout<<"\n\n";
	std::cout<<"********* PRUEBA_OK1_EXPRESIONES - CONSTANTES *********\n";
	cout<<"************************************************************\n\n";

	ExpresionImp a(5);
	ExpresionImp b(6);
	ExpresionImp c(1);
	ExpresionImp d(5);
	ExpresionImp e(6);
	ExpresionImp f(1);
	ExpresionImp g(4);
	ExpresionImp h(1);
	TipoRet retorno = ERROR;

	cout<<"a:"<<a<<endl;
	cout<<"b:"<<b<<endl;
	cout<<"c:"<<c<<endl;
	cout<<"d:"<<d<<endl;
	cout<<"e:"<<e<<endl;
	cout<<"f:"<<f<<endl;
	cout<<"g:"<<g<<endl;
	cout<<"h:"<<h<<endl;

	c=a+(b+d*b-e/f)*d/a*b+d+c*d+a+b/e;
	retorno = ERROR;
	bool error = false;
	cout<<"El resultado es c:"<<c<<endl;
	cout<<"c ="<<c.Evaluar(error)<<endl;

	if(c.Evaluar(error) == 201 && error==false) retorno = OK;
	ver(retorno, OK, "Expresion c = 26");


	c=a+b;
	bool error1 = false;
	retorno = ERROR;
	cout<<"El resultado es c:"<<c<<endl;
	cout<<"c ="<<c.Evaluar(error1)<<endl;

	if(c.Evaluar(error1) == 11 && error1==false) retorno = OK;
	ver(retorno, OK, "Expresion c = 11");


	d=(a-a)/(a-a);
	bool error2 = false;
	retorno = ERROR;
	cout<<"El resultado es d:"<<d<<endl;
	cout<<"d ="<<d.Evaluar(error2)<<endl;
	
	if(d.Evaluar(error2) == 0 && error2==false) retorno = OK;
	ver(retorno, ERROR, "No se puede dividir entre 0");


	a=(a+((g*c+((b*c)+a)/f)/a)/((c*c/c)-(e-e+e/(e-e*f)/(e+b/b-h))));	
	bool error3 = false;
	retorno = ERROR;
	cout<<"El resultado es a:"<<a<<endl;
	cout<<"a ="<<a.Evaluar(error3)<<endl;
	
	if(a.Evaluar(error3) == 0 && error3==false) retorno = OK;
	ver(retorno, ERROR, "No se puede dividir entre 0");


	std::cout<<"************* FIN PRUEBA_OK1_EXPRESIONES **************\n";
	cout<<"************************************************************\n\n";
}



void PruebasPropias::Prueba_OK2_EXPRESIONES(){


	cout<<"\n\n";
	std::cout<<"********** PRUEBA_OK2_EXPRESIONES - BINARIAS **********\n";
	cout<<"************************************************************\n\n";

	ExpresionImp a(9);
	ExpresionImp b(2);
	ExpresionImp c(7);
	ExpresionImp d(-9);
	ExpresionImp e(6);
	ExpresionImp f;
	ExpresionImp g(1);
	ExpresionImp h(4);
	TipoRet retorno = ERROR;
	
	cout<<"a:"<<a<<endl;
	cout<<"b:"<<b<<endl;
	cout<<"c:"<<c<<endl;
	cout<<"d:"<<d<<endl;
	cout<<"e:"<<e<<endl;
	cout<<"f:"<<f<<endl;
	cout<<"h:"<<h<<endl;


	a=((((g+c+d)*e)/((h)))-d);
	bool error = false;
	retorno = ERROR;
	cout<<"El resultado es a:"<<a<<endl;
	cout<<"a ="<<a.Evaluar(error)<<endl;

	if(a.Evaluar(error) == 8 && error==false) retorno = OK;
	ver(retorno, OK, "Expresion a = 8");

	
	c=d*((a+h-c)/(d+b));
	bool error1 = false;
	retorno = ERROR;
	cout<<"El resultado es c:"<<c<<endl;
	cout<<"c ="<<c.Evaluar(error1)<<endl;

	if(c.Evaluar(error1) == 0 && error1==false) retorno = OK;
	ver(retorno, OK, "Expresion c = 0");

	e=(e-e+e-e-e)/(a+e-a);
	bool error2 = false;
	retorno = ERROR;
	cout<<"El resultado es e:"<<e<<endl;
	cout<<"e ="<<e.Evaluar(error2)<<endl;

	if(e.Evaluar(error2) == -1 && error2==false) retorno = OK;
	ver(retorno, OK, "Expresion e = -1");


	std::cout<<"************* FIN PRUEBA_OK2_EXPRESIONES **************\n";
	cout<<"************************************************************\n\n";

}


void PruebasPropias::Prueba_OK3_EXPRESIONES(){


	cout<<"\n\n";
	std::cout<<"********** PRUEBA_OK3_EXPRESIONES - BINARIAS **********\n";
	cout<<"************************************************************\n\n";

	ExpresionImp a(9);
	ExpresionImp b(2);
	ExpresionImp c(7);
	ExpresionImp d(-9);
	ExpresionImp e(6);
	ExpresionImp f;
	ExpresionImp g(1);
	ExpresionImp h(4);
	TipoRet retorno = ERROR;
	
	cout<<"a:"<<a<<endl;
	cout<<"b:"<<b<<endl;
	cout<<"c:"<<c<<endl;
	cout<<"d:"<<d<<endl;
	cout<<"e:"<<e<<endl;
	cout<<"f:"<<f<<endl;
	cout<<"h:"<<h<<endl;

	c=((((((((((((((((d/d)/d)/d)/d)/d)/d)/d)/d)/d)/d)/d)/d)/d)/d)/d)/d);
	bool error3 = false;
	retorno = ERROR;
	cout<<"El resultado es c:"<<c<<endl;
	cout<<"c ="<<c.Evaluar(error3)<<endl;

	if(c.Evaluar(error3) == 0 && error3==false) retorno = OK;
	ver(retorno, OK, "Expresion c = 0");

	a=(e+e+e+e+e+e+e+e+e+e+e+e+e+e)/((((b))));
	bool error4 = false;
	retorno = ERROR;
	cout<<"El resultado es a:"<<c<<endl;
	cout<<"a ="<<a.Evaluar(error4)<<endl;

	if(a.Evaluar(error4) == 42 && error4==false) retorno = OK;
	ver(retorno, OK, "Expresion a = 42");


	std::cout<<"************* FIN PRUEBA_OK3_EXPRESIONES **************\n";
	cout<<"************************************************************\n\n";

}


void PruebasPropias::Prueba_OK1_PLANILLA(){

	CreacionDeHojas();

	cout<<"\n\n";
	cout<<"*********** PRUEBA_OK1_PLANILLA - INSERTAR HOJAS ***********\n";
	cout<<"************************************************************\n\n";

	// Insertar hojas - al principioo - al final - y en el medio de la lista
	// Listar alfabetico y en orden de creacion
	ver(interfaz->ListarHojas(DECREACION),OK,"Se listan las hojas en orden de creación.");
	ver(interfaz->ListarHojas(ALFABETICO),OK,"Se listan las hojas en orden alfabetico.");

	// Insertamos una hoja al principio de la lista
	ver(interfaz->InsertarHoja("A-2-Hoja"),OK,"Se crea la hoja 'A-2-Hoja'.");
	ver(interfaz->ListarHojas(ALFABETICO),OK,"Se listan las hojas en orden alfabetico.");
	ver(interfaz->InsertarHoja("A-1-Hoja"),OK,"Se crea la hoja 'A-1-Hoja'.");
	ver(interfaz->ListarHojas(ALFABETICO),OK,"Se listan las hojas en orden alfabetico.");

	// Insertamos una hoja al final de la lista
	ver(interfaz->InsertarHoja("Z-4-Hoja"),OK,"Se crea la hoja 'Z-4-Hoja'.");
	ver(interfaz->ListarHojas(ALFABETICO),OK,"Se listan las hojas en orden alfabetico.");
	ver(interfaz->InsertarHoja("Z-5-Hoja"),OK,"Se crea la hoja 'Z-5-Hoja'.");
	ver(interfaz->ListarHojas(ALFABETICO),OK,"Se listan las hojas en orden alfabetico.");

	// Insertamos una hoja en el medio de la lista
	ver(interfaz->InsertarHoja("H-0-Hoja"),OK,"Se crea la hoja 'H-0-Hoja'.");
	ver(interfaz->ListarHojas(ALFABETICO),OK,"Se listan las hojas en orden alfabetico.");
	ver(interfaz->InsertarHoja("F-5-Hoja"),OK,"Se crea la hoja 'F-5-Hoja'.");
	ver(interfaz->ListarHojas(ALFABETICO),OK,"Se listan las hojas en orden alfabetico.");

	ver(interfaz->ListarHojas(DECREACION),OK,"Se listan las hojas en orden de creación.");
	ver(interfaz->ListarHojas(ALFABETICO),OK,"Se listan las hojas en orden alfabetico.");

	std::cout<<"************* FIN PRUEBA_OK1_PLANILLA *****************\n";
	cout<<"************************************************************\n\n";
}

void PruebasPropias::Prueba_OK2_PLANILLA(){

	CreacionDeHojas();

	cout<<"\n\n";
	cout<<"********** PRUEBA_OK2_PLANILLA - RENOMBRAR HOJAS ************\n";
	cout<<"*************************************************************\n\n";

	// Renombrar
	// Listar alfabetico y en orden de creacion
	ver(interfaz->ListarHojas(DECREACION),OK,"Se listan las hojas en orden de creación.");
	ver(interfaz->ListarHojas(ALFABETICO),OK,"Se listan las hojas en orden alfabetico.");

	// Renombrar una hoja como otra ya eliminada
	ver(interfaz->EliminarHoja("G-hoja"), OK, "Se elimina la hoja 'G-hoja'");
	ver(interfaz->RenombrarHoja("F-hoja","G-hoja"),OK,"Se cambia el nombre de 'F-hoja' a 'G-hoja'");

	// Renombrar varias veces seguidas una misma hoja
	ver(interfaz->RenombrarHoja("G-hoja","M-hoja"),OK,"Se cambia el nombre de 'G-hoja' a 'M-hoja'");
	ver(interfaz->RenombrarHoja("M-hoja","N-hoja"),OK,"Se cambia el nombre de 'M-hoja' a 'N-hoja'");
	ver(interfaz->RenombrarHoja("N-hoja","O-hoja"),OK,"Se cambia el nombre de 'N-hoja' a 'O-hoja'");
	
	// Listamos las hojas
	ver(interfaz->ListarHojas(ALFABETICO),OK,"Se listan las hojas en orden alfabetico.");

	std::cout<<"************* FIN PRUEBA_OK2_PLANILLA *****************\n";
	cout<<"************************************************************\n\n";
}

void PruebasPropias::Prueba_OK3_PLANILLA(){

	CreacionDeHojas();

	cout<<"\n\n";
	cout<<"********** PRUEBA_OK3_PLANILLA - ELIMINAR HOJAS *************\n";
	cout<<"*************************************************************\n\n";

	// Eliminar - al principio - al final y en el medio de la lista
	// Listar alfabetico y en orden de creacion

	// Eliminar una hoja que se encuentra al principio de la lista
	ver(interfaz->EliminarHoja("b-Hoja"), OK, "Se elimina la hoja 'b-Hoja'");
	ver(interfaz->EliminarHoja("C-Hoja"), OK, "Se elimina la hoja 'C-Hoja'");

	// Eliminar una hoja que se encuentra al final de la lista
	ver(interfaz->EliminarHoja("Z-2-Hoja"), OK, "Se elimina la hoja 'Z-2-Hoja'");
	ver(interfaz->EliminarHoja("xy-Hoja"), OK, "Se elimina la hoja 'XY-Hoja'");

	// Eliminar una hoja que se encuentra en el medio de la lista
	ver(interfaz->EliminarHoja("D1-HOja"), OK, "Se elimina la hoja 'D1-Hoja'");
	ver(interfaz->EliminarHoja("D2-HOja"), OK, "Se elimina la hoja 'D2-Hoja'");

	std::cout<<"************* FIN PRUEBA_OK3_PLANILLA *****************\n";
	cout<<"************************************************************\n\n";
}

void PruebasPropias::Prueba_OK4_PLANILLA(){

	CreacionDeHojas();

	cout<<"\n\n";
	cout<<"*** PRUEBA_OK4_PLANILLA - ASIGNAR EXPRESION A CELDA *********\n";
	cout<<"*************************************************************\n\n";

	// Asignar expresion - Cte, Bin y Var 

	// Asignar una expresion constante a una celda
	Expresion* a = new ExpresionImp(0);
	ver(interfaz->AsignarExpresionACelda("B-Hoja",9,7,*a),OK,"Se inserta en 'B-Hoja' en celda 1:1 la expresion: 0");
	ver(interfaz->ListarCeldasEvaluadas("b-hOjA",1,2,10,13),OK,"Se lista las celdas evaluadas de 'B-Hoja' desde 1:2 hasta 10:13");
	
	Expresion* b = new ExpresionImp(15990);
	ver(interfaz->AsignarExpresionACelda("Z-2-Hoja",4,5,*b),OK,"Se inserta en 'Z-2-Hoja' en celda 4:5 la expresion: 15990");
	ver(interfaz->ListarCeldasEvaluadas("Z-2-Hoja",3,3,8,8),OK,"Se lista las celdas evaluadas de 'Z-2-Hoja' desde 3:3 hasta 8:8");

	// Asignar una expresion binaria a una celda
	Expresion* c = new ExpresionImp(10);
	Expresion* d = new ExpresionImp(2);
	Expresion* e = &(*c * *c);
	Expresion* f = &((*e + *c)* (*e - *d));
	Expresion* g = &(*c-*c);
	Expresion* h = &(*g+*g);

	ver(interfaz->AsignarExpresionACelda("D1-HOJA",7,5,*e),OK,"Se inserta en 'D1-Hoja' en celda 7:5 la expresion: (*c * *c)");
	ver(interfaz->AsignarExpresionACelda("D1-Hoja",8,1,*f),OK,"Se inserta en 'D1-Hoja' en celda 8:1 la expresion: ((*e + *c)* (*e - *d))");
	ver(interfaz->AsignarExpresionACelda("D1-HOja",19,4,*g),OK,"Se inserta en 'D1-Hoja' en celda 19:4 la expresion: (*c-*c)");
	// asignamos una nueva expresion binaria a la misma celda
	ver(interfaz->AsignarExpresionACelda("D1-Hoja",19,4,*h),OK,"Se inserta en 'D1-Hoja' en celda 19:4 la expresion: (*g+*g)");
	ver(interfaz->ListarCeldasEvaluadas("D1-HoJa",1,1,20,20),OK,"Se lista las celdas evaluadas de 'D1-Hoja' desde 1:1 hasta 20:20");

	// Asignar una expresion var a una celda
	Expresion* m = new ExpresionImp("D1-Hoja!5:3");
	Expresion* n = new ExpresionImp("D1-HOJA!9:5");
	ver(interfaz->AsignarExpresionACelda("C-HOJA",6,8,*m),OK,"Se inserta en 'C-Hoja' en celda 6:8 la expresion:'D1-Hoja!5:3");
	ver(interfaz->AsignarExpresionACelda("C-HOJA",6,8,*n),OK,"Se inserta en 'C-Hoja' en celda 6:8 la expresion:'D1-HOJA!9:5");
	ver(interfaz->ListarCeldasEvaluadas("C-Hoja",2,2,7,9),OK,"Se lista las celdas evaluadas de 'C-Hoja' desde 2:2 hasta 7:9");

	std::cout<<"************* FIN PRUEBA_OK4_PLANILLA *****************\n";
	cout<<"************************************************************\n\n";

}

void PruebasPropias::Prueba_OK5_PLANILLA(){

	CreacionDeHojas();

	cout<<"\n\n";
	cout<<"*PRUEBA_OK5_PLANILLA - LISTAR CELDAS EVALUADAS Y SIN EVALUAR*\n";
	cout<<"*************************************************************\n\n";

	// LISTAR CELDAS EVALUADAS
	// Listamos antes de asignar nada, deberiamos obtener una matriz nula
	cout<<"Listamos antes de asignar nada, deberiamos obtener una matriz nula"<<endl;
	ver(interfaz->ListarCeldasEvaluadas("xy-Hoja",2,2,9,9),OK,"Se lista las celdas evaluadas de 'XY-Hoja' desde 2:2 hasta 9:9");

	AsignacionDeExpresionesACeldas();
	cout<<"Asignamos expresiones varias a las celdas y listamos a continuacion"<<endl;
	ver(interfaz->ListarCeldasEvaluadas("xy-Hoja",1,1,10,10),OK,"Se lista las celdas evaluadas de 'XY-Hoja' desde 1:1 hasta 9:9");

	// Listar celdas evaluadas que contengan expresiones con error en la evaluacion (verificar impresion de #REF)
	Expresion* m = new ExpresionImp("xy-Hoja!5:3");
	ver(interfaz->AsignarExpresionACelda("xy-HOJA",7,5,*m),OK,"Se inserta en 'XY-Hoja' en celda 7:5 la expresion: xy-Hoja!5:3");
	ver(interfaz->EliminarCelda("xy-HOJA",5,3),OK,"Se elimina la celda 5:3 en 'xy-Hoja'.");
	ver(interfaz->ListarCeldasEvaluadas("xy-Hoja",2,2,9,9),OK,"Se lista las celdas evaluadas de 'xy-Hoja' desde 2:2 hasta 9:9");

	// LISTAR CELDAS SIN EVALUAR
	ver(interfaz->ListarCeldaSinEvaluar("xy-Hoja",1,2),OK,"Se lista la celda sin evaluar:");	
	ver(interfaz->ListarCeldaSinEvaluar("xy-Hoja",2,3),OK,"Se lista la celda sin evaluar:");
	ver(interfaz->ListarCeldaSinEvaluar("xy-Hoja",2,7),OK,"Se lista la celda sin evaluar:");	
	ver(interfaz->ListarCeldaSinEvaluar("xy-Hoja",1,4),OK,"Se lista la celda sin evaluar:");	
	ver(interfaz->ListarCeldaSinEvaluar("xy-Hoja",7,7),OK,"Se lista la celda sin evaluar:");	
	
	std::cout<<"************* FIN PRUEBA_OK5_PLANILLA *****************\n";
	cout<<"************************************************************\n\n";
}

void PruebasPropias::Prueba_OK6_PLANILLA(){

	CreacionDeHojas();

	cout<<"\n\n";
	cout<<"********** PRUEBA_OK6_PLANILLA - ELIMINAR CELDAS ************\n";
	cout<<"*************************************************************\n\n";

	AsignacionDeExpresionesACeldas();

	// Se elimina una celda conteniendo una expresion constante
	ver(interfaz->EliminarCelda("Xy-HOJA",2,3),OK,"Se elimina la celda 2:3 en 'xy-Hoja'.");

	// Se elimina una celda conteniendo una expresion binaria
	ver(interfaz->EliminarCelda("xy-HOJA",4,1),OK,"Se elimina la celda 1:2 en 'xy-hOJA'.");

	// Se elimina una celda conteniendo una expresion var
	ver(interfaz->EliminarCelda("xY-HOJA",7,7),OK,"Se elimina la celda 7:7 en 'XY-Hoja'.");

	std::cout<<"************* FIN PRUEBA_OK6_PLANILLA *****************\n";
	cout<<"************************************************************\n\n";

}


void PruebasPropias::Prueba_OK7_PLANILLA(){

	//	cout<<"\n\n";
//	cout<<"****** PRUEBA_OK7_PLANILLA - DESHACER ULTIMA OPERACION ******\n";
//	cout<<"*************************************************************\n\n";
//	// Deshacer una operacion
//	// Deshacer varias veces consecutivas
//	// Deshacer una operacion, rehacerla y deshacerla nuevamente
//	ver(interfaz->DeshacerUltimaOperacion(),OK,"Se deshace la última operación realizada");
//	cout<<"**************** FIN PRUEBA_OK7_PLANILLA ********************\n";
//	cout<<"*************************************************************\n\n";
//
}
void PruebasPropias::Prueba_ERROR1_PLANILLA(){

	CreacionDeHojas();

	cout<<"\n\n";
	cout<<"***************** PRUEBA_ERROR1_PLANILLA ********************\n";
	cout<<"*************************************************************\n\n";

	// PRUEBAS ERROR INSERTAR HOJA
//----------------------------------------------------------------------------------------
	// Insertar una hoja con el mismo nombre que una hoja ya existente
	ver(interfaz->InsertarHoja("b-Hoja"),ERROR,"ERROR: No es posible insertar la hoja, ya existe una hoja con ese nombre .");
	// Insertar una hoja sin nombre ??????
	//ver(interfaz->InsertarHoja(" "),ERROR,"ERROR: No es posible insertar una hoja sin nombre.");

	// PRUEBAS ERROR RENOMBRAR HOJA
//----------------------------------------------------------------------------------------
	// Renombrar una hoja dejandola sin nombre ????
	//ver(interfaz->RenombrarHoja("F-hoja"," "),ERROR,"ERROR: El nombre de la hoja no puede ser vacio");

	// Renombrar una hoja previamente renombrada
	cout<<"aca"<<endl;
	ver(interfaz->RenombrarHoja("G-hoja","M-hoja"),OK,"Se renombra la hoja G-Hoja a M-Hoja");	
	ver(interfaz->RenombrarHoja("G-hoja","N-hoja"),ERROR,"ERROR: La hoja no existe");	

	// Renombrar una hoja como una ya existente
	ver(interfaz->RenombrarHoja("D2-hoja","b-Hoja"),ERROR,"ERROR: Ese nombre ya existe para otra hoja");

	// PRUEBAS ERROR ELIMINAR HOJA
//----------------------------------------------------------------------------------------
	// Eliminar una hoja no existente
	ver(interfaz->EliminarHoja("R-Hoja"), ERROR, "ERROR: No existe la hoja a eliminar");

	// Eliminar una hoja previamente renombrada
	ver(interfaz->RenombrarHoja("D1-hoja","K-hoja"),OK,"ERROR: No existe la hoja a eliminar");	
	ver(interfaz->EliminarHoja("R-Hoja"), ERROR, "ERROR: No existe la hoja a eliminar");

	// Eliminar una hoja previamente eliminada	
	ver(interfaz->EliminarHoja("Z-2-Hoja"), OK, "La hoja 'Z-2-Hoja ha sido eliminada'");
	ver(interfaz->EliminarHoja("Z-2-Hoja"), ERROR, "ERROR: No exitste la hoja a eliminar");


	// PRUEBA ERROR ASIGNAR EXPRESION A UNA CELDA
//----------------------------------------------------------------------------------------
	// Asignar una expresion a una hoja que no existe
	Expresion* m = new ExpresionImp("xy-Hoja!5:3");
	ver(interfaz->AsignarExpresionACelda("Uruguay",7,5,*m),ERROR,"Se inserta en 'XY-Hoja' en celda 7:5 la expresion: xy-Hoja!5:3");


	// PRUEBA ERROR LISTAR CELDAS EVALUADAS Y SIN EVALUAR
//----------------------------------------------------------------------------------------
	// LISTAR CELDAS EVALUADAS
	// Listar - Cte, Bin y Var - Rango invalido - coordenadas invalidas 
	// Rango invalido (Numero de columna desde < nro de columna hasta - Numero de fila desde < nro de fila hasta)
	ver(interfaz->ListarCeldasEvaluadas("b-Hoja",21,13,20,20),ERROR,"ERROR: Coordenadas invalidas");
	ver(interfaz->ListarCeldasEvaluadas("c-Hoja",11,21,20,20),ERROR,"ERROR: Coordenadas invalidas");

	// Coordenadas invalidas (Nro de fila <0 Nro de columna <0)
	ver(interfaz->ListarCeldasEvaluadas("D1-Hoja",1,-19,20,20),ERROR,"ERROR: Rango invalido");
	ver(interfaz->ListarCeldasEvaluadas("D2-Hoja",-8,19,20,20),ERROR,"ERROR: Rango invalido");
	
	// Hoja inexistente
	ver(interfaz->ListarCeldasEvaluadas("Hoja7",1,1,20,20),ERROR,"ERROR: la hoja a eliminar no existe");

	// LISTAR CELDA SIN EVALUAR
	// Nro de fila -columna invalidos
	ver(interfaz->ListarCeldaSinEvaluar("xy-Hoja",-1,-2),ERROR,"ERROR: Coordenadas invalidas");	
	// Hoja inexistente
	ver(interfaz->ListarCeldaSinEvaluar("Uruguay",1,2),ERROR,"ERROR: la hoja a eliminar no existe");	

	// PRUEBA ERROR ELIMINAR CELDA
//----------------------------------------------------------------------------------------
	// Eliminar celda de una hoja no existente
	ver(interfaz->EliminarCelda("Hoja7",1,2),ERROR, "ERROR: la hoja a eliminar no existe");

	// Eliminar celda con nro de columna y fila invalidos
	ver(interfaz->EliminarCelda("A-Hoja",-1,2),ERROR,"ERROR: Coordenadas invalidas");
	ver(interfaz->EliminarCelda("A-Hoja",1,-2),ERROR,"ERROR: Coordenadas invalidas");

	// PRUEBAS ERROR DESHACER ULTIMA OPERACION
//----------------------------------------------------------------------------------------
	// No existen operaciones
	// No es posible deshacer mas operaciones

		cout<<"**************** FIN PRUEBA_ERROR1_PLANILLA *****************\n";
		cout<<"*************************************************************\n\n";
}


void PruebasPropias::CreacionDeHojas(){

	interfaz = new InterfazDelSistemaImp();
	interfaz->InsertarHoja("G-hoja");	
	interfaz->InsertarHoja("b-Hoja");
	interfaz->InsertarHoja("C-Hoja");
	interfaz->InsertarHoja("F-hoja");
	interfaz->InsertarHoja("D2-hoja");
	interfaz->InsertarHoja("D1-Hoja");
	interfaz->InsertarHoja("Z-2-Hoja");	
	interfaz->InsertarHoja("Xy-Hoja");
}

void PruebasPropias::AsignacionDeExpresionesACeldas(){

	// Se utiliza para listar celdas evaluadas y sin evaluar
	Expresion* o = new ExpresionImp(10);
	Expresion* p = new ExpresionImp(2);
	Expresion* q = &(*o-*p);
	Expresion* r = &((*o)+(*p));
	Expresion* s = &(*r-*o);
	Expresion* t = new ExpresionImp("D1-Hoja!1:2");
	Expresion* u = new ExpresionImp("XY-Hoja!2:4");
	Expresion* v = new ExpresionImp("XY-Hoja!1:2");

	interfaz->AsignarExpresionACelda("XY-HOJA",1,2,*p);
	interfaz->AsignarExpresionACelda("Xy-HOJA",2,3,*o);
	interfaz->AsignarExpresionACelda("xy-HOJA",4,1,*p);
	interfaz->AsignarExpresionACelda("xY-HOJA",1,4,*q);
	interfaz->AsignarExpresionACelda("xY-HOJA",2,3,*r);
	interfaz->AsignarExpresionACelda("xY-HOJA",2,8,*s);
	interfaz->AsignarExpresionACelda("xY-HOJA",3,7,*t);
	interfaz->AsignarExpresionACelda("xY-HOJA",7,7,*u);
	interfaz->AsignarExpresionACelda("D1-HOJA",1,2,*v);
}

/*delete interfaz;*/

#endif