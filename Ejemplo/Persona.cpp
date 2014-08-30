#ifndef PERSONA_CPP
#define PERSONA_CPP
#include "Persona.h"

Persona::Persona(char *nom,int ed)
{
	Cadena nomb = Cadena(nom);
	nombre = nomb;
	edad = ed;
}

Persona::~Persona()
{
}
		
bool Persona:: operator ==(const Persona &p) const{

	if (p.getNombre()==nombre)return true;
	else return false;

}
Persona & Persona:: operator=(const Persona &p){
	edad = p.getEdad();
	nombre = p.getNombre();

	return *this;
}

bool Persona:: operator>(const Persona &p) const{
	return edad>p.getEdad();
}

bool Persona:: operator<(const Persona &p) const{
	return edad<p.getEdad();	
}

ostream &operator<<(ostream &o, const Persona &p){	
	o<<p.getNombre()<<endl;
	return o;
}

Persona Persona::operator++()
{
	edad++;
	return *this;
}

Persona Persona::operator++(int cant)
{
	edad = edad + cant;
	return *this;
}
#endif