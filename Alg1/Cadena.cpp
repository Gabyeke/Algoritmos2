#ifndef CADENA_CPP
#define CADENA_CPP

#include "Cadena.h"
using namespace std;

/****************************************************/
ostream &operator<<(ostream &os, const Cadena &cad){
	if(cad.s)
		os << cad.s;
	return os;
}

istream &operator>>(istream &is, Cadena &cad){
	char aux[200];
	is>>aux;
	cad = aux;
	return is;
}

/****************************************************/
Cadena::Cadena(char *cad, bool ignoreCase) {
	size_t len = strlen(cad)+1;
	s = new char[len];
	strcpy_s(s, len, cad);
	this->ignoreCase = ignoreCase;
}
/****************************************************/
Cadena::Cadena(){
	s = new char[1];
	s[0] = '\0';
	this->ignoreCase = true;
}
/****************************************************/   
Cadena::Cadena(const Cadena &c) {
	s = NULL;
	*this = c;
}
/****************************************************/
Cadena::~Cadena() {
	if(s)
		delete[] s;
}
/****************************************************/
Cadena &Cadena::operator=(const Cadena &c) {
	if(this != &c) {
		delete [] s;

		size_t len = strlen(c.s)+1;
		s = new char[len];
		strcpy_s(s, len, c.s);

		this->ignoreCase = c.ignoreCase;
	}
	return *this;
}
/****************************************************/
bool Cadena::operator==(const Cadena &c) const {
	if (ignoreCase) 
		return _stricmp(s, c.s) == 0;
	else
		return strcmp(s, c.s) == 0;
}
/****************************************************/
bool Cadena::operator!=(const Cadena &c) const {
	if (ignoreCase) 
		return _stricmp(s, c.s) != 0;
	else
		return strcmp(s, c.s) != 0;
}
/****************************************************/
bool Cadena::operator<(const Cadena &c) const {
	if (ignoreCase) 
		return _stricmp(s, c.s) < 0;
	else
		return strcmp(s, c.s) < 0;
}
/****************************************************/
bool Cadena::operator>(const Cadena &c) const {
	if (ignoreCase) 
		return _stricmp(s, c.s) > 0;
	else
		return strcmp(s, c.s) > 0;
}
/****************************************************/
bool Cadena::operator<=(const Cadena &c) const {
	if (ignoreCase) 
		return _stricmp(s, c.s) <= 0;
	else
		return strcmp(s, c.s) <= 0;
}
/****************************************************/
bool Cadena::operator>=(const Cadena &c) const {
	if (ignoreCase) 
		return _stricmp(s, c.s) >= 0;
	else
		return strcmp(s, c.s) >= 0;
}
/****************************************************/
char *Cadena::GetNewCharPtr() {
	size_t len = strlen(s)+1;
	char *ret = new char[len];
	strcpy_s(ret, len, s);
	return ret;
}
/****************************************************/

char* Cadena::GetS() const{
	return this->s;
}

/****************************************************/


#endif