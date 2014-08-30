#ifndef CADENAS_H
#define CADENAS_H

#include <string.h>

#include <iostream>
using namespace std;

class Cadenas {
	// Entrada y salida de flujo
	friend ostream &operator<<(ostream&, const Cadenas &);
	friend istream &operator>>(istream&, Cadenas &);
public:

	// Constructor por defecto (string vacio)
	Cadenas();

	// Constructor que recibe un string terminado por /0 
	// y si los operadores de comparacion deben ser case sensitive o no 
	// (por defecto case-insensitive)
	Cadenas(char *cad, bool ignoreCase = true);

	// Constructor copia
	Cadenas(const Cadenas &c);

	// Destructor
	virtual ~Cadenas();

	// Operador de asignacion
	Cadenas &operator=(const Cadenas &c);

	// Operadores de comparacion
	bool operator==(const Cadenas &c) const;
	bool operator!=(const Cadenas &c) const ;
	bool operator<(const Cadenas &c) const;
    bool operator>(const Cadenas &c) const ;
    bool operator<=(const Cadenas &c) const ;
	bool operator>=(const Cadenas &c) const ;

	// Retorna un nuevo vector de caracteres sin compartir memoria con this
	// El que llame a esta funcion es responsable de la liberacion del retorno con delete []
	char *GetNewCharPtr();

protected:
	char *s;
	bool ignoreCase;
};

#endif