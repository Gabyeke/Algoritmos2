#ifndef PERSONA_H
#define PERSONA_H

#include "Cadena.h"

class Persona
{
	friend ostream &operator<<(ostream&, const Persona &p);

	protected:

		Cadena nombre;
		int edad;
	public:

		Persona(char *nom,int ed);

		~Persona();

		Cadena getNombre()const {return nombre;}

		int getEdad()const {return edad;}

		bool operator==(const Persona &p) const;

		Persona &operator=(const Persona &p);

		bool operator<(const Persona &p) const;

		bool operator>(const Persona &p) const;

		Persona operator++();

		Persona operator++(int);
};

#endif
