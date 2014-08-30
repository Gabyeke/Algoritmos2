#pragma once

#include "Array.h"

#include <iostream>
using namespace std;

#define MAX_CADENA 256

class Cadena
{
	friend ostream& operator<<(ostream& out, const Cadena& c);
	friend istream& operator>>(istream& in, Cadena& c);

public:
	Cadena(const char* cadena = NULL);
    Cadena(const Cadena& c);

	char operator[](nat index) const;

	__declspec(property(get = ObtenerLargo)) nat Largo;
	nat ObtenerLargo() const;

	bool operator==(const Cadena& c) const;
	bool operator!=(const Cadena& c) const;
	bool operator<(const Cadena& c) const;
    bool operator>(const Cadena& c) const;
    bool operator<=(const Cadena& c) const;
	bool operator>=(const Cadena& c) const;

	Cadena& operator=(const Cadena& c);
	Cadena operator+(const Cadena& c) const;
	Cadena& operator+=(const Cadena& c);

	/*/ Ajusta la Cadena al ser impresa
	 *  Si el parámetro largo es menor que el largo de la cadena, se
	 *  imprimen la cantidad de caracteres indicados por el parámetro
	 *  Si el parámetro largo es mayor que el largo de la cadena, se
	 *  imprime la cadena completa, y se rellena la salida con espacios
	/*/
	Cadena operator^(nat largo) const;

	Cadena SubCadena(nat desde) const;
	Cadena SubCadena(nat desde, nat largo) const;

	Cadena LTrim() const;
	Cadena RTrim() const;
	Cadena Trim() const;

	Cadena DarFormato(Cadena c0) const;
	Cadena DarFormato(Cadena c0, Cadena c1) const;
	Cadena DarFormato(Cadena c0, Cadena c1, Cadena c2) const;
	Cadena DarFormato(Cadena c0, Cadena c1, Cadena c2, Cadena c3) const;

	Cadena Reemplazar(Cadena vieja, Cadena nueva) const;

private:
	static Array<char> s_ArrayVacio;

	Cadena(const Array<char>& string, nat desde, nat largo);
	int BuscarPos(Cadena buscar) const;
	int BuscarPos(Cadena buscar, nat desde) const;
	void OrdenarPos(int& pos1, Cadena& c1, int& pos2, Cadena& c2) const;
	void CopiarFormateado(Array<char> formateado, nat& lastPosC, nat& lastPosF, nat pos, Cadena cad, nat largoViejo) const;

	Array<char> string;
	nat ini;
	nat largo;

	nat ajustar;
};
