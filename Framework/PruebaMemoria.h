#pragma once

#include "Prueba.h"
#include "MemoryShare.h"
#include "Cadena.h"

class PruebaMemoria : public Prueba
{
public:
	PruebaMemoria();

protected:
	void CorrerPruebaConcreta();
	Cadena GetNombre() const;

private:
	bool m_PrimerPasada;
	Cadena m_Comentario;
	Cadena m_Puntero;
	Cadena m_Array;
	Cadena m_Cierre;
	Cadena m_CierreEsp;
	Cadena m_Struct;
	Cadena m_Class;
	Cadena m_Enum;
	Cadena m_UnsignedInt;
	Cadena m_Nat;
	Cadena m_DatoNulo;
	Cadena m_Cadena;

	Cadena Nro2Cadena(unsigned int nro) const;
	Cadena NombrarTipo(MemoryShare::MemoryUsage* usage) const;
};
