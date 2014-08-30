#include "PruebaExpresiones.h"

#include <iostream>
using namespace std;

PruebaExpresiones::PruebaExpresiones(ConductorPrueba* conductor)
:Prueba(conductor)
{
}

PruebaExpresiones::~PruebaExpresiones()
{
}

void PruebaExpresiones::correrPruebaConcreta()
{
	

	cout<<"\n\n";
	cout<<"***** PRUEBAS DE EJEMPLO DE USO EXPRESIONES ******\n";
	cout<<"**************************************\n\n";

	pruebasEjemploOK();
	pruebasEjemploERROR();

	cout<<"----------------------------------------------------------------------"<<endl;
	cout<<"Fin PRUEBAS DE EJEMPLO DE USO EXPRESIONES."<<endl;
	cout<<"----------------------------------------------------------------------"<<endl;
	
}
void PruebaExpresiones::pruebasEjemploOK(){
	cout<<"\n\n";
	cout<<"*********** PRUEBAS OK ************\n";
	cout<<"**************************************\n\n";

	PruebaSimple1();
	Prueba1();
	Prueba2();
	Prueba3();	

	cout<<"----------------------------------------------------------------------"<<endl;
	cout<<"Fin Pruebas OK."<<endl;
	cout<<"----------------------------------------------------------------------"<<endl;
}

void PruebaExpresiones::pruebasEjemploERROR() {
	
	cout<<"\n\n";
	cout<<"*********** PRUEBAS ERROR ************\n";
	cout<<"**************************************\n\n";

	PruebaERROR1();
	

	cout<<"----------------------------------------------------------------------"<<endl;
	cout<<"Fin Pruebas ERROR."<<endl;
	cout<<"----------------------------------------------------------------------"<<endl;

}
char* PruebaExpresiones::getNombre()const
{
	return "PruebaExpresiones";
}

void PruebaExpresiones::PruebaSimple1()
{
	cout<<"----------------------------------------------------------------------"<<endl;
	cout<<"PRUEBA EXPRESIONES SIMPLES."<<endl;
	cout<<"----------------------------------------------------------------------"<<endl;

	ExpresionImp a(10);
	ExpresionImp b(0);
	ExpresionImp c(-8);	
	ExpresionImp d;
	
	TipoRet retorno = ERROR;
	bool error = false;
	cout<< a <<endl;
	if(a.Evaluar(error) == 10 && error==false) retorno = OK;
	ver(retorno, OK, "Expresion a = 10");
	
	retorno = ERROR;
	cout<< b <<endl;
	if(b.Evaluar(error) == 0 && error==false) retorno = OK;
	ver(retorno, OK, "Expresion b = 0");

	retorno = ERROR;
	cout<< c <<endl;
	if(c.Evaluar(error) == -8 &&error==false) retorno = OK;
	ver(retorno, OK, "Expresion c = -8");

	retorno = ERROR;
	cout<< d <<endl;
	if(d.Evaluar(error) == 0 &&error==false) retorno = OK;
	ver(retorno, OK, "Expresion d (default = 0)");
};


void PruebaExpresiones::Prueba1()
{	
	cout<<"----------------------------------------------------------------------"<<endl;
	cout<<"PRUEBA EXPRESIONES COMPUESTAS."<<endl;
	cout<<"----------------------------------------------------------------------"<<endl;

	ExpresionImp a(5);
	ExpresionImp b(2);
	ExpresionImp c;
	ExpresionImp d(-3);
	ExpresionImp e(6);	
	
	cout<<"Expresion a = 5"<<endl
		<<"Expresion b = 2"<<endl
		<<"Expresion d =-3"<<endl
		<<"Expresion e = 6"<<endl
		<<endl;
	TipoRet retorno = ERROR;
	bool error = false;

	retorno = ERROR;
	c = a - a;
	cout<<"Expresion c = a-a : "<< c <<endl;
	if(c.Evaluar(error) == 0 && error==false) retorno = OK;
	ver(retorno, OK, "Expresion c = 0");

	retorno = ERROR;
	c = a + b;
	cout<<"Expresion c = a+b : "<< c <<endl;
	if(c.Evaluar(error) == 7 && error==false) retorno = OK;
	ver(retorno, OK, "Expresion c = 7");

	retorno = ERROR;
	c = a - b;
	cout<<"Expresion c = a-b : "<< c <<endl;
	if(c.Evaluar(error) == 3 && error==false) retorno = OK;
	ver(retorno, OK, "Expresion c = 3");
	
	retorno = ERROR;
	c = a + d;
	cout<<"Expresion c = a+d : "<< c <<endl;
	if(c.Evaluar(error) == 2 && error==false) retorno = OK;
	ver(retorno, OK, "Expresion c = 2");

	retorno = ERROR;
	c = a - d;
	cout<<"Expresion c = a-d : "<< c <<endl;
	if(c.Evaluar(error) == 8 && error==false) retorno = OK;
	ver(retorno, OK, "Expresion c = 8");

	retorno = ERROR;
	c = a * b;
	cout<<"Expresion c = a * b : "<< c <<endl;
	if(c.Evaluar(error) == 10 && error==false) retorno = OK;
	ver(retorno, OK, "Expresion c = 10");

};
void PruebaExpresiones::Prueba2()
{	
	ExpresionImp a(5);
	ExpresionImp b(2);
	ExpresionImp c;
	ExpresionImp d(-3);
	ExpresionImp e(6);	

	cout<<"Expresion a = 5"<<endl
		<<"Expresion b = 2"<<endl
		<<"Expresion d =-3"<<endl
		<<"Expresion e = 6"<<endl
		<<endl;
	TipoRet retorno = ERROR;
	bool error = false;
	

	retorno = ERROR;
	c = a + a + a;
	cout<<"Expresion c = a+a+a : "<< c <<endl;
	if(c.Evaluar(error) == 15 && error==false) retorno = OK;
	ver(retorno, OK, "Expresion c = 15");

	retorno = ERROR;
	c = e * e * a;
	cout<<"Expresion c = e*e*a : "<< c <<endl;
	if(c.Evaluar(error) == 180 && error==false) retorno = OK;
	ver(retorno, OK, "Expresion c = 180");

	retorno = ERROR;
	c = (e + b) * b;
	cout<<"Expresion c = (e + b) * b : "<< c <<endl;
	if(c.Evaluar(error) == 16 && error==false) retorno = OK;
	ver(retorno, OK, "Expresion c = 16");

	retorno = ERROR;
	c = (a - b) * e;
	cout<<"Expresion c = (a - b) * e: "<< c <<endl;
	if(c.Evaluar(error) == 18 && error==false) retorno = OK;
	ver(retorno, OK, "Expresion c = 18");

	retorno = ERROR;
	c = ((a - b) * e)*( (e+b)- a );//18*3
	cout<<"Expresion c = ((a - b) * e)*( (e+b)- a ): "<< c <<endl;
	if(c.Evaluar(error) == 54 && error==false) retorno = OK;
	ver(retorno, OK, "Expresion c = 54");

	retorno = ERROR;
	c = ((a + a + a ) / a);// (5+5+5)/5
	cout<<"Expresion c = ((a + a + a) / a ): "<< c <<endl;
	if(c.Evaluar(error) == 3 && error==false) retorno = OK;
	ver(retorno, OK, "Expresion c = 3");

	retorno = ERROR;
	c = ((b + b + b ) / e);// (2+2+2)/6
	cout<<"Expresion c = ((b + b + b) / e ): "<< c <<endl;
	if(c.Evaluar(error) == 1 && error==false) retorno = OK;
	ver(retorno, OK, "Expresion c = 1");
};
void PruebaExpresiones::Prueba3()
{	
	ExpresionImp a(5);
	ExpresionImp b(2);
	ExpresionImp c;
	Expresion* d = new ExpresionImp(4);

	cout<<"Expresion a = 5"<<endl
		<<"Expresion b = 2"<<endl
		<<"Expresion d = 4"<<endl
		<<endl;
	TipoRet retorno = ERROR;
	bool error = false;

	retorno = ERROR;
	c = a * (a + b);
	cout<<"Expresion c = a * (a + b): "<< c <<endl;
	if(c.Evaluar(error) == 35 && error==false) retorno = OK;
	ver(retorno, OK, "Expresion c = 35");

	retorno = ERROR;
	c = c * a;
	cout<<"Expresion c = c * a [(a * (a + b) ) * a]: "<< c <<endl;
	if(c.Evaluar(error) == 175 && error==false) retorno = OK;
	ver(retorno, OK, "Expresion c = 175");

	retorno = ERROR;
	c = (a - b) * (a + b);
	cout<<"Expresion c = (a - b) * (a + b): "<< c <<endl;
	if(c.Evaluar(error) == 21 && error==false) retorno = OK;
	ver(retorno, OK, "Expresion c = 21");


	retorno = ERROR;
	b = (*d);
	cout<<"Expresion b = d"<<endl;
	cout<<"Expresion c = (a - b) * (a + b): "<< c <<endl;
	if(c.Evaluar(error) == 21 && error==false) retorno = OK;
	ver(retorno, OK, "Expresion c = 21");
	

	retorno = ERROR;
	d = c.Clon();
	cout<<"Expresion d = c.clon: "<< *d <<endl;
	if(d->Evaluar(error) == 21 && error==false) retorno = OK;
	ver(retorno, OK, "Expresion d = 21");

	retorno = ERROR;
	c = a + b;
	cout<<"Expresion c = a+b: "<< c <<endl;
	cout<<"Expresion d: "<< *d <<endl;
	if(d->Evaluar(error) == 21 && error==false) retorno = OK;
	ver(retorno, OK, "Expresion d = 21");
};

void PruebaExpresiones::PruebaERROR1()
{
	ExpresionImp a(5);
	ExpresionImp b(2);
	ExpresionImp c;
	
	cout<<"Expresion a = 5"<<endl
		<<"Expresion b = 2"<<endl
		<<endl;
	TipoRet retorno = ERROR;
	bool error = false;

	retorno = OK;
	c = (a+b) / (a-a);
	cout<<"Expresion c = (a+b) / (a-a): "<< c <<endl;
	c.Evaluar(error);
	if(error==true) retorno = ERROR;
	ver(retorno, ERROR, "No se puede dividir entre CERO");


}