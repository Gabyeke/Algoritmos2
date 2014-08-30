#include "PruebaMemoria.h"

PruebaMemoria::PruebaMemoria()
{
	m_PrimerPasada = true;
	m_Comentario = "No se liberó memoria del tipo: {0}. Contador de referencias: {1}";
	m_Puntero = "Puntero<";
	m_Array = "Array<";
	m_Cierre = ">";
	m_CierreEsp = "> ";
	m_Struct = "struct ";
	m_Class = "class ";
	m_Enum = "enum ";
	m_UnsignedInt = "unsigned int";
	m_Nat = "nat";
	m_DatoNulo = ",DatoNulo";
	m_Cadena = "Array<char>";
}

void PruebaMemoria::CorrerPruebaConcreta()
{
	if (m_PrimerPasada)
		m_PrimerPasada = false;
	else
	{
		IniciarSeccion("Memoria", ERROR);
		bool memoryLeaks = false;
		for (int i = 0; i < MEMORY_BUCKETS; i++)
		{
			MemoryShare::MemoryUsage* start = MemoryShare::s_GeneralUse[i];
			MemoryShare::MemoryUsage* end = MemoryShare::s_FirstCheck[i];
			memoryLeaks |= start != end;
			while (start != end)
			{
				Cadena tipo = NombrarTipo(start);
				if (tipo != m_Cadena)
					Verificar(ERROR, OK, m_Comentario.DarFormato(tipo, Nro2Cadena(start->Contador)));
				start = start->NextUsage;
			}
		}
		if (!memoryLeaks)
			Verificar(OK, OK, "Los Punteros y Arrays usados se liberaron correctamente");
		CerrarSeccion();
	}
	for (int i = 0; i < MEMORY_BUCKETS; i++)
		MemoryShare::s_FirstCheck[i] = MemoryShare::s_GeneralUse[i];
}

Cadena PruebaMemoria::GetNombre() const
{
	return "Memoria";
}

Cadena PruebaMemoria::Nro2Cadena(unsigned int nro) const
{
	switch (nro)
	{
	case 0:
		return "0";
	case 1:
		return "1";
	case 2:
		return "2";
	case 3:
		return "3";
	case 4:
		return "4";
	case 5:
		return "5";
	case 6:
		return "6";
	case 7:
		return "7";
	case 8:
		return "8";
	case 9:
		return "9";
	default:
		Cadena ret = "";
		while (nro != 0)
		{
			ret = Nro2Cadena(nro % 10) + ret;
			nro /= 10;
		}
		return ret;
	}
}

Cadena PruebaMemoria::NombrarTipo(MemoryShare::MemoryUsage* usage) const
{
	Cadena ret = Cadena(usage->TypeName)
		.Reemplazar(m_UnsignedInt, m_Nat)
		.Reemplazar(m_Struct, "")
		.Reemplazar(m_Class, "")
		.Reemplazar(m_Enum, "")
		.Reemplazar(m_DatoNulo, "")
		.Reemplazar(m_CierreEsp, m_Cierre);
	if ((usage->Info & MemoryShare::PUNTERO) == MemoryShare::PUNTERO)
		return m_Puntero + ret + m_Cierre;
	else
		return m_Array + ret + m_Cierre;
}