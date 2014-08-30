#include "MemoryShare.h"
#include <Assert.h>

MemoryShare::MemoryShare()
: m_Used(NULL)
{
}

MemoryShare::~MemoryShare()
{
	DecrementarContador();
}

void MemoryShare::AsignarMemoria(const char* typeName, void* memoria, void (*liberar)(void*), bool esPuntero)
{
	MemoryUsage* used = NULL;
	if (memoria != NULL)
	{
		used = GetFromGeneralUse(memoria);
		if (used == NULL)
		{
			used = new MemoryUsage();
			used->TypeName = typeName;
			used->Contador = 1;
			used->Memoria = memoria;
			used->Liberar = liberar;
			used->Info = esPuntero ? PUNTERO : ARRAY;
			AddToGeneralUse(used);
		}
		else if (m_Used != used)
			IncrementarContador(used);
	}
	if (m_Used == used)
		return;
	// this dejará de usar el contador actual, por lo tanto
	// se decrementa el contador, si como resultado el contador queda en 0,
	// entonces se invoca a liberarMemoria
	DecrementarContador();
	m_Used = used;
}

void MemoryShare::IncrementarContador(MemoryUsage* used)
{
	if (used != NULL)
	{
		assert(used->Contador > 0);
		used->Contador++;
	}
}

void MemoryShare::DecrementarContador()
{
	if (m_Used != NULL)
	{
		switch (m_Used->Contador)
		{
		case 0:
			assert(false);
			break;
		case 1:
			//assert(FueUtilizado());
			m_Used->Liberar(m_Used->Memoria);
			RemoveFromGeneralUse(m_Used);
			delete m_Used;
			m_Used = NULL;
			break;
		default:
			m_Used->Contador--;
			break;
		}
	}
}

void MemoryShare::RemoveFromGeneralUse(MemoryUsage* usage)
{
	int pos = (((unsigned int) usage->Memoria) / 4) % MEMORY_BUCKETS;
	if (s_GeneralUse[pos] == NULL)
		assert(false);
	else 
	{
		if (s_GeneralUse[pos] == usage)
			s_GeneralUse[pos] = usage->NextUsage;
		else
		{
			MemoryUsage* lista = s_GeneralUse[pos];
			while (lista->NextUsage != NULL && lista->NextUsage != usage)
				lista = lista->NextUsage;
			if (lista->NextUsage != NULL)
				lista->NextUsage = usage->NextUsage;
			else
				assert(false);
		}

		if (usage == s_FirstCheck[pos])
			s_FirstCheck[pos] = s_FirstCheck[pos]->NextUsage;
	}
}

void MemoryShare::AddToGeneralUse(MemoryUsage* usage)
{
	int pos = (((unsigned int) usage->Memoria) / 4) % MEMORY_BUCKETS;
	usage->NextUsage = s_GeneralUse[pos];
	s_GeneralUse[pos] = usage;
}

MemoryShare::MemoryUsage* MemoryShare::GetFromGeneralUse(void* memoria)
{
	int pos = (((unsigned int) memoria) / 4) % MEMORY_BUCKETS;
	MemoryUsage* usage = s_GeneralUse[pos];
	while (usage != NULL)
	{
		if (usage->Memoria == memoria)
			return usage;
		usage = usage->NextUsage;
	}
	return NULL;
}

MemoryShare::MemoryUsage* MemoryShare::s_GeneralUse[MEMORY_BUCKETS];
MemoryShare::MemoryUsage* MemoryShare::s_FirstCheck[MEMORY_BUCKETS];

bool MemoryShare::FueUtilizado() const
{
	return m_Used == NULL || (m_Used->Info & USADO) == USADO;
}

void MemoryShare::MarcarUtilizado() const
{
	if (m_Used != NULL)
		m_Used->Info = (MemoryInfo) (m_Used->Info | USADO);
}
