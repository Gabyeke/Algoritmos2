#ifndef CADENAS_CPP
#define CADENAS_CPP

#include "Cadenas.h"
using namespace std;

/****************************************************/
ostream &operator<<(ostream &os, const Cadenas &cad){
	if(cad.s)
		os << cad.s;
	return os;
}

istream &operator>>(istream &is, Cadenas &cad){
	char aux[200];
	is>>aux;
	cad = aux;
	return is;
}

/****************************************************/
Cadenas::Cadenas(char *cad, bool ignoreCase) {
	size_t len = strlen(cad)+1;
	s = new char[len];
	strcpy_s(s, len, cad);
	this->ignoreCase = ignoreCase;
}
/****************************************************/
Cadenas::Cadenas(){
	s = new char[1];
	s[0] = '\0';
	this->ignoreCase = true;
}
/****************************************************/   
Cadenas::Cadenas(const Cadenas &c) {
	s = NULL;
	*this = c;
}
/****************************************************/
Cadenas::~Cadenas() {
	if(s)
		delete[] s;
}
/****************************************************/
Cadenas &Cadenas::operator=(const Cadenas &c) {
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
bool Cadenas::operator==(const Cadenas &c) const {
	if (ignoreCase) 
		return _stricmp(s, c.s) == 0;
	else
		return strcmp(s, c.s) == 0;
}
/****************************************************/
bool Cadenas::operator!=(const Cadenas &c) const {
	if (ignoreCase) 
		return _stricmp(s, c.s) != 0;
	else
		return strcmp(s, c.s) != 0;
}
/****************************************************/
bool Cadenas::operator<(const Cadenas &c) const {
	if (ignoreCase) 
		return _stricmp(s, c.s) < 0;
	else
		return strcmp(s, c.s) < 0;
}
/****************************************************/
bool Cadenas::operator>(const Cadenas &c) const {
	if (ignoreCase) 
		return _stricmp(s, c.s) > 0;
	else
		return strcmp(s, c.s) > 0;
}
/****************************************************/
bool Cadenas::operator<=(const Cadenas &c) const {
	if (ignoreCase) 
		return _stricmp(s, c.s) <= 0;
	else
		return strcmp(s, c.s) <= 0;
}
/****************************************************/
bool Cadenas::operator>=(const Cadenas &c) const {
	if (ignoreCase) 
		return _stricmp(s, c.s) >= 0;
	else
		return strcmp(s, c.s) >= 0;
}
/****************************************************/
char *Cadenas::GetNewCharPtr() {
	size_t len = strlen(s)+1;
	char *ret = new char[len];
	strcpy_s(ret, len, s);
	return ret;
}
/****************************************************/
#endif