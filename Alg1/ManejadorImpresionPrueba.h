#ifndef MANEJADORIMPRESIONPRUEBA_H
#define MANEJADORIMPRESIONPRUEBA_H


#include "TipoRetorno.h"
#include "EstadisticaPrueba.h"

#include <iostream>
using namespace std;

class ManejadorImpresionPrueba  
{
public:
	ManejadorImpresionPrueba();
	virtual ~ManejadorImpresionPrueba();

	void imprimirResultado(TipoRet retorno, TipoRet retornoEsperado, char* comentario)const;
	void imprimirTotalResultados(const EstadisticaPrueba& estadistica)const;

	static ManejadorImpresionPrueba* getInstancia();
protected:
	void imprimirComentario(char* comentario)const;
	void imprimirRetorno(TipoRet retorno, TipoRet retornoEsperado)const;

private:
	static ManejadorImpresionPrueba* instanciaManejador;
	char* getStringRetorno(TipoRet retorno)const;

};

#endif