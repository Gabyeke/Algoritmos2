#include "PruebaPlanilla.h"

#include <iostream>
using namespace std;

PruebaPlanilla::PruebaPlanilla(ConductorPrueba* conductor)
:Prueba(conductor)
{
	interfaz = new InterfazDelSistemaImp();
}

PruebaPlanilla::~PruebaPlanilla()
{
	delete interfaz;
}
char* PruebaPlanilla::getNombre()const
{
	return "PruebaPlanilla";
}

void PruebaPlanilla::correrPruebaConcreta()
{

	PruebaCreacionHojas(); // todo bien
	PruebaRenombrarHojas(); // todo bien
	PruebaEliminarHojas(); // todo bien
	
	PruebaExpresiones1(); // todo bien
	PruebaEvaluarReferencia();// se agregaron algunas cosas para poder probar
	PruebaExpresiones2();// falta implementar evaluar en expresionvar
	PruebaExpresiones3();// todo bien
	PruebaExpresiones4(); //correr de nuevo

	PruebaError();// no sale el final correr de nuevo
	//Opcional
	//PruebaDeshacerUltimaOperacion();
}
void PruebaPlanilla::PruebaCreacionHojas()
{
	std::cout<<"\n\n";
	std::cout<<"***** PRUEBAS DE EJEMPLO DE USO EXPRESIONES ******\n";
	cout<<"**************************************\n\n";

	cout<<"\n\n";
	cout<<"*********** PRUEBAS OK ************\n";
	cout<<"**************************************\n\n";

	ver(interfaz->ListarHojas(ALFABETICO),OK,"No Hay hojas ingresadas.");

	ver(interfaz->InsertarHoja("Hoja1"),OK,"Se crea la hoja 'Hoja1'.");	
	ver(interfaz->InsertarHoja("Hoja3"),OK,"Se crea la hoja 'Hoja3'.");
	ver(interfaz->InsertarHoja("Hoja5"),OK,"Se crea la hoja 'Hoja5'.");
	ver(interfaz->InsertarHoja("Hoja2"),OK,"Se crea la hoja 'Hoja2'.");
	ver(interfaz->InsertarHoja("Hoja4"),OK,"Se crea la hoja 'Hoja4'.");

	ver(interfaz->ListarHojas(ALFABETICO),OK,"Se listan las hojas en orden alfabetico.");
	ver(interfaz->ListarHojas(DECREACION),OK,"Se listan las hojas en orden de creación.");
};
void PruebaPlanilla::PruebaRenombrarHojas()
{
	cout<<"\n\n";
	cout<<"******** PRUEBAS RENOMBRAR HOJAS *********\n";
	cout<<"***********************************\n\n";

	InsertarHojas(); //Crea nuevamente la interfaz y crea las Hojas
	
	//Renombraremos :
	//"Hoja1"
	//"Hoja3" -> "Algoritmos"
	//"Hoja5"
	//"Hoja2" -> "Discreta"
	//"Hoja4" -> "Calculo5"

	ver(interfaz->RenombrarHoja("Hoja2","Discreta"),OK,"Se cambia el nombre de 'Hoja2' a 'Discreta'");
	ver(interfaz->RenombrarHoja("Hoja3","Algoritmos"),OK,"Se cambia el nombre de 'Hoja3' a 'Algoritmos'");
	ver(interfaz->RenombrarHoja("Hoja4","Calculo5"),OK,"Se cambia el nombre de 'Hoja4' a 'Calculo5'");

	//Algoritmos,Calculo5,Discreta,Hoja1,Hoja5
	ver(interfaz->ListarHojas(ALFABETICO),OK,"Se listan las hojas en orden alfabetico.");

	//Hoja1,Algoritmos,Hoja5,Discreta,C5
	ver(interfaz->ListarHojas(DECREACION),OK,"Se listan las hojas en orden de creación.");
};
void PruebaPlanilla::PruebaEliminarHojas()
{
	cout<<"\n\n";
	cout<<"******** PRUEBAS ELIMINAR HOJAS *********\n";
	cout<<"***********************************\n\n";

	CrearHojas(); //Crea nuevamente la interfaz y Hojas necesarias para la prueba
	//"Hoja1"
	//"Algoritmos"
	//"Hoja5"
	//"Discreta"
	//"Calculo5"
	//"Hoja7"
	//"Hoja6"

	//A,C,D,H1,H5,H6,H7
	ver(interfaz->ListarHojas(ALFABETICO),OK,"Se listan las hojas en orden alfabetico.");

	//Hoja1,Algoritmos,Hoja5,Discreta,C5,H7,H6
	ver(interfaz->ListarHojas(DECREACION),OK,"Se listan las hojas en orden de creación.");

	ver(interfaz->EliminarHoja("Hoja1"), OK, "Se elimina la hoja 'Hoja1'");
	//ver(interfaz->EliminarHoja("Hoja5"), OK, "Se elimina la hoja 'Hoja5'");
	ver(interfaz->EliminarHoja("Hoja6"), OK, "Se elimina la hoja 'Hoja6'");
	
	//A,C,D,H7
	ver(interfaz->ListarHojas(ALFABETICO),OK,"Se listan las hojas en orden alfabetico.");

	//Agregamos nosotros
	ver(interfaz->EliminarHoja("Discreta"), OK, "Se elimina la hoja 'Discreta'");


	//A,D,C5,Hoja7
	ver(interfaz->ListarHojas(DECREACION),OK,"Se listan las hojas en orden de creación.");

};
void PruebaPlanilla::PruebaDeshacerUltimaOperacion()
{
	cout<<"\n\n";
	cout<<"******** PRUEBAS DESHACER ÚLTIMA OPERACIÓN *********\n";
	cout<<"***********************************\n\n";
	
	InsertarHojas(); //Crea nuevamente la interfaz y crea las Hojas
	
	ver(interfaz->EliminarHoja("Hoja2"),OK,"Se elimina la hoja 2");
	ver(interfaz->ListarHojas(ALFABETICO),OK,"Se listan las hojas en orden alfabetico.");
	ver(interfaz->DeshacerUltimaOperacion(),OK,"Se deshace la última operación realizada");
	ver(interfaz->ListarHojas(ALFABETICO),OK,"Se listan las hojas en orden alfabetico.");


	ver(interfaz->RenombrarHoja("Hoja1","HojaRenombrada"),OK,"Se renombra la hoja 1 a HojaRenombrada");
	ver(interfaz->ListarHojas(ALFABETICO),OK,"Se listan las hojas en orden alfabetico.");
	ver(interfaz->DeshacerUltimaOperacion(),OK,"Se deshace la última operación realizada");
	ver(interfaz->ListarHojas(ALFABETICO),OK,"Se listan las hojas en orden alfabetico.");
	
	interfaz->InsertarHoja("Hoja7");

	Expresion* a1 = new ExpresionImp(5);
	ver(interfaz->AsignarExpresionACelda("Hoja5",1,1,*a1),OK,"Se inserta en 'Hoja5' en celda 1:1 la expresion: 5");
	ver(interfaz->ListarCeldasEvaluadas("Hoja5",1,1,3,3),OK,"Se lista las celdas evaluadas de 'Hoja7' desde 1:1 hasta 3:3");
	ver(interfaz->DeshacerUltimaOperacion(),OK,"Se deshace la última operación realizada");
	ver(interfaz->ListarCeldasEvaluadas("Hoja5",1,1,3,3),OK,"Se lista las celdas evaluadas de 'Hoja7' desde 1:1 hasta 3:3");

};
void PruebaPlanilla::PruebaExpresiones1()
{	
	cout<<"\n\n";
	cout<<"******** PRUEBAS EXPRESIONES1 *********\n";
	cout<<"***********************************\n\n";

	CrearHojas(); //Crea nuevamente la interfaz y Hojas necesarias para la prueba
	//"Hoja1"
	//"Algoritmos"
	//"Hoja5"
	//"Discreta"
	//"Calculo5"
	//"Hoja7"
	//"Hoja6"

	Expresion* a1 = new ExpresionImp(5);
	Expresion* a2 = new ExpresionImp(3);
	Expresion* b2 = &(*a1 * *a2);
	Expresion* c1 = &((*a1 + *a2)* (*a1 - *a2));

	ver(interfaz->AsignarExpresionACelda("Hoja7",1,1,*a1),OK,"Se inserta en 'Hoja7' en celda 1:1 la expresion: 5");
	ver(interfaz->AsignarExpresionACelda("Hoja7",1,2,*a2),OK,"Se inserta en 'Hoja7' en celda 1:2 la expresion: 3");
	ver(interfaz->AsignarExpresionACelda("Hoja7",2,2,*b2),OK,"Se inserta en 'Hoja7' en celda 2:2 la expresion: (5*3)");
	ver(interfaz->AsignarExpresionACelda("Hoja7",3,1,*c1),OK,"Se inserta en 'Hoja7' en celda 3:1 la expresion: (5+3)*(5-3)");


	ver(interfaz->ListarCeldasEvaluadas("Hoja7",1,1,3,3),OK,"Se lista las celdas evaluadas de 'Hoja7' desde 1:1 hasta 3:3");
	ver(interfaz->ListarCeldaSinEvaluar("Hoja7",3,1),OK,"Se lista la celda sin evaluar: (5+3)*(5-3)");	


};
void PruebaPlanilla::PruebaExpresiones2()
{	
	cout<<"\n\n";
	cout<<"******** PRUEBAS EXPRESIONES2 *********\n";
	cout<<"***********************************\n\n";

	//Se agrega lo que se encuentra en el siguiente parrafo para poder probar las pruebas
	CrearHojas(); //Crea nuevamente la interfaz y Hojas necesarias para la prueba
	//fin de lo agregado

	//"Hoja1"
	//"Hoja3" -> "Algoritmos"
	//"Hoja5"
	//"Hoja2" -> "Discreta"
	//"Hoja4" -> "Calculo5"
	//"Hoja7"
	//"Hoja6"

	Expresion* b1 = new ExpresionImp("Hoja7!1:1");
	Expresion* b2 = new ExpresionImp("Hoja7!3:1");
	ver(interfaz->AsignarExpresionACelda("Hoja7",2,1,*b1),OK,"Se inserta en 'Hoja7' en celda 2:1 referencia a Hoja7!1:1");
	ver(interfaz->AsignarExpresionACelda("Hoja7",2,2,*b2),OK,"Se inserta en 'Hoja7' en celda 2:2 referencia a Hoja7!3:1");
	
	ver(interfaz->ListarCeldasEvaluadas("Hoja7",1,1,3,3),OK,"Se lista las celdas evaluadas desde 1:1 hasta 3:3");
	ver(interfaz->ListarCeldaSinEvaluar("Hoja7",2,2),OK,"Se lista la celda sin evaluar:(referencia a 'Hoja7!3:1')");

	Expresion* a1 = new ExpresionImp(55);
	Expresion* c1 = new ExpresionImp(66);
	ver(interfaz->AsignarExpresionACelda("Hoja7",1,1,*a1),OK,"Se inserta en 'Hoja7' en celda 1:1 '55'");
	ver(interfaz->AsignarExpresionACelda("Hoja7",3,1,*c1),OK,"Se inserta en 'Hoja7' en celda 3:1 '66'");

	ver(interfaz->ListarCeldasEvaluadas("Hoja7",1,1,3,3),OK,"Se lista las celdas evaluadas desde 1:1 hasta 3:3 (Nota. Cambiaron celdas referenciadas en 2:1 y 2:2.)");
};
void PruebaPlanilla::PruebaExpresiones3()
{	
	cout<<"\n\n";
	cout<<"******** PRUEBAS EXPRESIONES3 *********\n";
	cout<<"***********************************\n\n";

	interfaz->InsertarHoja("Hoja9");	
	
	Expresion* b1 = new ExpresionImp("Hoja7!1:1");
	Expresion* c2 = new ExpresionImp("Hoja7!3:1");
	ver(interfaz->AsignarExpresionACelda("Hoja9",2,1,*b1),OK,"Se inserta en 'Hoja9' en celda 2:1 referencia a Hoja7!1:1");
	ver(interfaz->AsignarExpresionACelda("Hoja9",3,2,*c2),OK,"Se inserta en 'Hoja9' en celda 3:2 referencia a Hoja7!3:1");
	
	ver(interfaz->ListarCeldaSinEvaluar("Hoja9",2,1),OK,"Se lista la celda sin evaluar:(referencia a 'Hoja7!1:1')");
	ver(interfaz->ListarCeldasEvaluadas("Hoja9",2,1,3,2),OK,"Se lista las celdas evaluadas desde 2:1 hasta 3:2");	
};
void PruebaPlanilla::PruebaExpresiones4()
{		
	cout<<"\n\n";
	cout<<"******** PRUEBAS EXPRESIONES4 *********\n";
	cout<<"***********************************\n\n";

	//Se agrega lo que se encuentra en el siguiente parrafo para poder probar las pruebas
	CrearHojas(); //Crea nuevamente la interfaz y Hojas necesarias para la prueba
	Expresion* a1 = new ExpresionImp(5);
	Expresion* a2 = new ExpresionImp(3);
	Expresion* b2 = &(*a1 * *a2);
	Expresion* c1 = &((*a1 + *a2)* (*a1 - *a2));
	//fin de lo agregado

	ver(interfaz->AsignarExpresionACelda("Hoja7",1,1,*a1),OK,"Se inserta en 'Hoja7' en celda 1:1 la expresion: 5");
	ver(interfaz->AsignarExpresionACelda("Hoja7",1,2,*a2),OK,"Se inserta en 'Hoja7' en celda 1:2 la expresion: 3");
	ver(interfaz->AsignarExpresionACelda("Hoja7",2,2,*b2),OK,"Se inserta en 'Hoja7' en celda 2:2 la expresion: (5*3)");
	ver(interfaz->AsignarExpresionACelda("Hoja7",3,1,*c1),OK,"Se inserta en 'Hoja7' en celda 3:1 la expresion: (5+3)*(5-3)");

	ver(interfaz->EliminarCelda("Hoja7",1,2),OK,"Se elimina la celda 1:2 en 'Hoja7'.");
	ver(interfaz->EliminarCelda("Hoja7",2,2),OK,"Se elimina la celda 2:2 en 'Hoja7'.");

	ver(interfaz->ListarCeldasEvaluadas("Hoja7",1,1,3,3),OK,"Se lista las celdas evaluadas desde 1:1 hasta 3:3 (Nota. Cambiaron celdas referenciadas en 2:1 y 2:2.)");
	
	cout<<"----------------------------------------------------------------------"<<endl;
	cout<<"Fin Pruebas OK."<<endl;
	cout<<"----------------------------------------------------------------------"<<endl;

	cout<<"----------------------------------------------------------------------"<<endl;
	cout<<"Fin PRUEBAS DE EJEMPLO DE USO EXPRESIONES."<<endl;
	cout<<"----------------------------------------------------------------------"<<endl;
};

	void PruebaPlanilla::PruebaEvaluarReferencia()
	{		
		cout<<"\n\n";
		cout<<"******** PRUEBAS EVALUAR REFERENCIA *********\n";
		cout<<"***********************************\n\n";

		//Se agrega lo que se encuentra en el siguiente parrafo para poder probar las pruebas
		CrearHojas(); //Crea nuevamente la interfaz y Hojas necesarias para la prueba
		Expresion* a1 = new ExpresionImp(15);
		ver(interfaz->AsignarExpresionACelda("Hoja7",2,2, *a1),OK,"Se inserta en 'Hoja7' en celda 2:2 referencia a Hoja7!1:1");
		//fin de lo agregado

		TipoRet retorno = ERROR;
		bool ret=false;
		int res = interfaz->EvaluarReferencia("Hoja7!2:2",ret);
		if(res == 15 && ret ==false) retorno = OK;
		ver(retorno,OK,"Se evalua la Referencia a Hoja 7 Celda 2:2 (Expresion = 15)");
	};

void PruebaPlanilla::PruebaError()
{
	cout<<"\n\n";
	cout<<"*********** PRUEBAS ERROR ************\n";
	cout<<"**************************************\n\n";

	CrearHojas(); //Crea nuevamente la interfaz y Hojas necesarias para la prueba

	ver(interfaz->InsertarHoja("HojaRepetida"),OK,"Se inserta 'HojaRepetida'");
	ver(interfaz->InsertarHoja("HojaRepetida"),ERROR,"Ya Existe 'HojaRepetida'");

	ver(interfaz->EliminarHoja("HojaNoExistente"),ERROR,"No existe la hoja 'HojaNoExistente'");
	interfaz->EliminarHoja("HojaRepetida");
	ver(interfaz->EliminarHoja("HojaRepetida"),ERROR,"No existe 'HojaRepetida'");

	ver(interfaz->RenombrarHoja("HojaNull","Hoja100"),ERROR,"No existe la hoja 'HojaNull'");

	interfaz->InsertarHoja("Hoja99");
	interfaz->InsertarHoja("Hoja100");

	ver(interfaz->RenombrarHoja("Hoja99","Hoja100"),ERROR,"Ya existe una hoja de nombre 'Hoja100'");

	ver(interfaz->InsertarHoja("HojaRepetida"),OK,"Se inserta 'HojaRepetida' (Se habia borrado antes)");


	Expresion* a1 = new ExpresionImp(5);
	ver(interfaz->AsignarExpresionACelda("Hoja50",1,1,*a1),ERROR,"No existe 'Hoja50");
	ver(interfaz->AsignarExpresionACelda("Hoja100",1,-1,*a1),ERROR,"Fila Fuera de rango.");

	ver(interfaz->EliminarCelda("Hoja50",1,1),ERROR,"No existe 'Hoja50");
	ver(interfaz->EliminarCelda("Hoja100",1,-1)	,ERROR,"Fila Fuera de rango.");

	ver(interfaz->ListarCeldasEvaluadas("Hoja100",3,3,1,1),ERROR,"Rango mal definido.");
	ver(interfaz->ListarCeldaSinEvaluar("Hoja100",1,-1),ERROR,"Fila Fuera de rango.");

	cout<<"----------------------------------------------------------------------"<<endl;
	cout<<"Fin Pruebas ERROR."<<endl;
	cout<<"----------------------------------------------------------------------"<<endl;


};

void PruebaPlanilla::InsertarHojas(){

	delete interfaz;
	interfaz = new InterfazDelSistemaImp();

	interfaz->InsertarHoja("Hoja1");	
	interfaz->InsertarHoja("Hoja3");
	interfaz->InsertarHoja("Hoja5");
	interfaz->InsertarHoja("Hoja2");
	interfaz->InsertarHoja("Hoja4");
};

void PruebaPlanilla::RenombrarHojas(){
	interfaz->RenombrarHoja("Hoja2","Discreta");
	interfaz->RenombrarHoja("Hoja3","Algoritmos");
	interfaz->RenombrarHoja("Hoja4","Calculo5");
};

void PruebaPlanilla::EliminarHojas() {
	interfaz->InsertarHoja("Hoja7");	
	interfaz->InsertarHoja("Hoja6");
	interfaz->EliminarHoja("Hoja1");
	interfaz->EliminarHoja("Hoja5");
	interfaz->EliminarHoja("Hoja6");
};

void PruebaPlanilla::CrearHojas(){
delete interfaz;
	interfaz = new InterfazDelSistemaImp();
	interfaz->InsertarHoja("Hoja1");	
	interfaz->InsertarHoja("Algoritmos");
	interfaz->InsertarHoja("Hoja5");
	interfaz->InsertarHoja("Discreta");
	interfaz->InsertarHoja("Calculo5");
	interfaz->InsertarHoja("Hoja7");	
	interfaz->InsertarHoja("Hoja6");
}