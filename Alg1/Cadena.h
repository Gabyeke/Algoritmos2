#ifndef CADENA_H
#define CADENA_H

#include <string.h>

#include <iostream>
using namespace std;

class Cadena {
	// Entrada y salida de flujo
	friend ostream &operator<<(ostream&, const Cadena &);
	friend istream &operator>>(istream&, Cadena &);
public:

	// Constructor por defecto (string vacio)
	Cadena();

	// Constructor que recibe un string terminado por /0 
	// y si los operadores de comparacion deben ser case sensitive o no 
	// (por defecto case-insensitive)
	Cadena(char *cad, bool ignoreCase = true);

	// Constructor copia
	Cadena(const Cadena &c);

	// Destructor
	virtual ~Cadena();

	// Operador de asignacion
	Cadena &operator=(const Cadena &c);

	// Operadores de comparacion
	bool operator==(const Cadena &c) const;
	bool operator!=(const Cadena &c) const ;
	bool operator<(const Cadena &c) const;
    bool operator>(const Cadena &c) const ;
    bool operator<=(const Cadena &c) const ;
	bool operator>=(const Cadena &c) const ;

	// Retorna un nuevo vector de caracteres sin compartir memoria con this
	// El que llame a esta funcion es responsable de la liberacion del retorno con delete []
	char *GetNewCharPtr();

	char* GetS() const;

protected:
	char *s;
	bool ignoreCase;
};

#endif