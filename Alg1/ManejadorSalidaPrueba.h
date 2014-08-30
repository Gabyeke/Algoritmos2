#ifndef SALIDAPRUEBA_H
#define SALIDAPRUEBA_H

#include <fstream>
#include <streambuf>
#include <direct.h>

#include <iostream>
using namespace std;

class ManejadorSalidaPrueba  
{
public:
	void setSalidaArchivo(char* nombreArchivo);
	void setSalidaPantalla();

	static ManejadorSalidaPrueba* getInstancia();

	void crearDirectorio(char* nombreDirectorio);
	void cambiarDirectorio(char* nombreDirectorio);
protected:
	ManejadorSalidaPrueba();
	virtual ~ManejadorSalidaPrueba();

private:
	static ManejadorSalidaPrueba* instanciaManejador;
	
	streambuf* pantalla;
	ofstream archivoActual;
};

#endif