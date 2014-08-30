#include "Cadena.h"

ostream& operator<<(ostream& out, const Cadena& c)
{
	nat largo = c.Largo;
	if (c.ajustar > 0 && c.ajustar < largo)
		largo = c.ajustar;

	for (nat i = 0; i < largo; i++)
		out << c[i];

	for (nat i = largo; i < c.ajustar; i++)
		out << ' ';

	return out;
}

istream& operator>>(istream& in, Cadena& c)
{
	char aux[MAX_CADENA];
	in >> aux;
	c = Cadena(aux);
	return in;
}

Cadena::Cadena(const char* cadena)
{
	ini = 0;
	largo = 0;
	ajustar = 0;
	if (cadena != NULL)
	{
		while (cadena[largo] != '\0')
			largo++;
	}
	if (largo == 0)
		*this = Cadena(s_ArrayVacio, 0, 0);
	else
	{
		string = Array<char>(largo + 1);
		for (nat i = 0; i < largo; i++)
			string[i] = cadena[i];
		string[largo] = '\0';
	}
}

Cadena::Cadena(const Cadena& c)
{
	*this = c;
	ajustar = c.ajustar;
}

Cadena::Cadena(const Array<char>& string, nat desde, nat largo)
{
	assert(desde + largo < string.Largo);
	if (largo > 0)
	{
		ini = desde;
		this->largo = largo;
		this->string = string;
	}
	else
	{
		ini = 0;
		this->largo = 0;
		this->string = string.Largo == 1 ? string : s_ArrayVacio;
	}
	ajustar = 0;
}

char Cadena::operator[](nat index) const
{
	assert(index < largo);
	return string[ini + index];
}

nat Cadena::ObtenerLargo() const
{
	return largo;
}

bool Cadena::operator==(const Cadena& c) const
{
	if (largo == c.Largo)
	{
		nat i;
		for (i = 0; i < largo && (*this)[i] == c[i]; i++);
		return i == largo;
	}
	return false;
}

bool Cadena::operator!=(const Cadena& c) const
{
	return !(*this == c);
}

bool Cadena::operator<(const Cadena& c) const
{
	nat largoMin = Largo < c.Largo ? Largo : c.Largo;
	for (nat i = 0; i < largoMin; i++)
		if ((*this)[i] < c[i])
			return true;
		else if ((*this)[i] > c[i])
			return false;
	return Largo < c.Largo;
}

bool Cadena::operator>(const Cadena& c) const
{
	nat largoMin = Largo < c.Largo ? Largo : c.Largo;
	for (nat i = 0; i < largoMin; i++)
		if ((*this)[i] > c[i])
			return true;
		else if ((*this)[i] < c[i])
			return false;
	return Largo > c.Largo;
}

bool Cadena::operator<=(const Cadena& c) const
{
	return (*this == c) || (*this < c);
}

bool Cadena::operator>=(const Cadena& c) const
{
	return (*this == c) || (*this > c);
}

Cadena& Cadena::operator=(const Cadena& c)
{
	if (&c != this)
	{
		string = c.string;
		ini = c.ini;
		largo = c.largo;
	}
	return *this;
}

Cadena Cadena::operator+(const Cadena& c) const
{
	if (c.Largo == 0)
		return *this;
	if (Largo == 0)
		return c;
	Array<char> concated = Array<char>(Largo + c.Largo + 1);
	Array<char>::Copiar(string, ini, Largo, concated);
	Array<char>::Copiar(c.string, c.ini, concated, Largo);
	return Cadena(concated, 0, concated.Largo - 1);
}

Cadena& Cadena::operator+=(const Cadena& c)
{
	nat ajustar = this->ajustar;
	*this = *this + c;
	this->ajustar = ajustar;
	return *this;
}

Cadena Cadena::operator^(nat largo) const
{
	Cadena cad = Cadena(string, ini, Largo);
	cad.ajustar = largo;
	return cad;
}

Cadena Cadena::SubCadena(nat desde) const
{
	return SubCadena(desde, Largo - desde);
}

Cadena Cadena::SubCadena(nat desde, nat largo) const
{
	return Cadena(string, ini + desde, largo);
}

Cadena Cadena::LTrim() const
{
	nat posIni = 0;
	while (posIni < Largo && (*this)[posIni] == ' ')
		posIni++;
	return SubCadena(posIni);
}

Cadena Cadena::RTrim() const
{
	nat posFin = Largo - 1;
	while (posFin >= 0 && (*this)[posFin] == ' ')
		posFin--;
	return SubCadena(0, posFin + 1);
}

Cadena Cadena::Trim() const
{
	return LTrim().RTrim();
}

Cadena Cadena::DarFormato(Cadena c0) const
{
	Cadena c = "";
	return DarFormato(c0, c, c, c);
}

Cadena Cadena::DarFormato(Cadena c0, Cadena c1) const
{
	Cadena c = "";
	return DarFormato(c0, c1, c, c);
}

Cadena Cadena::DarFormato(Cadena c0, Cadena c1, Cadena c2) const
{
	Cadena c = "";
	return DarFormato(c0, c1, c2, c);
}

Cadena Cadena::DarFormato(Cadena c0, Cadena c1, Cadena c2, Cadena c3) const
{
	int pos0 = BuscarPos("{0}");
	int pos1 = BuscarPos("{1}");
	int pos2 = BuscarPos("{2}");
	int pos3 = BuscarPos("{3}");

	OrdenarPos(pos0, c0, pos1, c1);
	OrdenarPos(pos0, c0, pos2, c2);
	OrdenarPos(pos0, c0, pos3, c3);
	OrdenarPos(pos1, c1, pos2, c2);
	OrdenarPos(pos1, c1, pos3, c3);
	OrdenarPos(pos2, c2, pos3, c3);

	if (pos3 == -1)
		return *this;

	nat largoF = largo;
	if (pos0 != -1)
		largoF += (c0.largo - 3);
	if (pos1 != -1)
		largoF += (c1.largo - 3);
	if (pos2 != -1)
		largoF += (c2.largo - 3);
	if (pos3 != -1)
		largoF += (c3.largo - 3);

	Array<char> formateado = Array<char>(largoF + 1);
	nat lastPosC = ini;
	nat lastPosF = 0;
	CopiarFormateado(formateado, lastPosC, lastPosF, pos0, c0, 3);
	CopiarFormateado(formateado, lastPosC, lastPosF, pos1, c1, 3);
	CopiarFormateado(formateado, lastPosC, lastPosF, pos2, c2, 3);
	CopiarFormateado(formateado, lastPosC, lastPosF, pos3, c3, 3);
	CopiarFormateado(formateado, lastPosC, lastPosF, lastPosC, SubCadena(pos3 + 3), 3);
	formateado[largoF] = '\0';
	return Cadena(formateado, 0, largoF);
}

Cadena Cadena::Reemplazar(Cadena vieja, Cadena nueva) const
{
	assert(vieja.Largo > 0);
	if (vieja.Largo > Largo)
		return *this;

	nat cantOcurrencias = 0;
	int pos = BuscarPos(vieja);
	while (pos != -1)
	{
		cantOcurrencias++;
		pos = BuscarPos(vieja, pos + vieja.Largo);
	}
	if (cantOcurrencias == 0)
		return *this;

	int difLargo = nueva.Largo;
	difLargo -= vieja.Largo;
	nat largoR = Largo + cantOcurrencias * difLargo;
	Array<char> reemplazado = Array<char>(largoR + 1);
	nat lastPosC = ini;
	nat lastPosR = 0;
	pos = BuscarPos(vieja);
	nat ultimaPos = 0;
	while (pos != -1)
	{
		CopiarFormateado(reemplazado, lastPosC, lastPosR, pos, nueva, vieja.Largo);
		ultimaPos = pos;
		pos = BuscarPos(vieja, pos + vieja.Largo);
	}
	CopiarFormateado(reemplazado, lastPosC, lastPosR, lastPosC, SubCadena(ultimaPos + vieja.Largo), vieja.Largo);
	reemplazado[largoR] = '\0';
	return Cadena(reemplazado, 0, largoR);
}

int Cadena::BuscarPos(Cadena buscar) const
{
	return BuscarPos(buscar, 0);
}

int Cadena::BuscarPos(Cadena buscar, nat desde) const
{
	for (nat pos = desde; pos <= Largo - buscar.Largo; pos++)
	{
		if (SubCadena(pos, buscar.Largo) == buscar)
			return pos;
	}
	return -1;
}

void Cadena::OrdenarPos(int& pos1, Cadena& c1, int& pos2, Cadena& c2) const
{
	if (pos2 < pos1)
	{
		int posAux = pos1;
		Cadena cadAux = c1;
		pos1 = pos2;
		c1 = c2;
		pos2 = posAux;
		c2 = cadAux;
	}
}

void Cadena::CopiarFormateado(Array<char> formateado, nat& lastPosC, nat& lastPosF, nat pos, Cadena cad, nat largoViejo) const
{
	if (pos != -1)
	{
		nat largoTramo = pos + ini - lastPosC;
		Array<char>::Copiar(string, lastPosC, largoTramo, formateado, lastPosF);
		lastPosC = pos + ini + largoViejo;
		lastPosF += largoTramo;
		Array<char>::Copiar(cad.string, cad.ini, cad.largo, formateado, lastPosF);
		lastPosF += cad.largo;
	}
}

Array<char> CrearArrayVacio()
{
	Array<char> vacio = Array<char>(1);
	vacio[0] = '\0';
	return vacio;
}

Array<char> Cadena::s_ArrayVacio = CrearArrayVacio();
