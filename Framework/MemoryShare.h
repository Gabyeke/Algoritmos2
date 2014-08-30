#pragma once

#pragma warning(error:4150; error:4172; error:4715)

#ifndef NULL
	#define NULL 0x0
#endif

class PruebaMemoria;

#define MEMORY_BUCKETS 1031

class MemoryShare abstract
{
	friend class PruebaMemoria;

public:
	virtual ~MemoryShare();

private:
	enum MemoryInfo : unsigned char
	{
		PUNTERO = 1,
		ARRAY = 2,
		USADO = 4
	};
	struct MemoryUsage
	{
		const char* TypeName;
		unsigned int Contador;
		void* Memoria;
		void (*Liberar)(void* memoria);
		MemoryInfo Info;
		MemoryUsage* NextUsage;
	};

	MemoryUsage* m_Used;

	static void IncrementarContador(MemoryUsage* used);
	void DecrementarContador();
	bool FueUtilizado() const;

	static void RemoveFromGeneralUse(MemoryUsage* usage);
	static void AddToGeneralUse(MemoryUsage* usage);
	static MemoryUsage* GetFromGeneralUse(void* memoria);

	static MemoryUsage* s_GeneralUse[MEMORY_BUCKETS];
	static MemoryUsage* s_FirstCheck[MEMORY_BUCKETS];

protected:
	MemoryShare();
	void MarcarUtilizado() const;
	void AsignarMemoria(const char* typeName, void* memoria, void (*liberar)(void*), bool esPuntero);
};
