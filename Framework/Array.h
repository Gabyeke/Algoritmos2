#pragma once

template <class T>
class Puntero;

#include "Iterable.h"
#include "MemoryShare.h"

typedef unsigned int nat;

template <class T>
class Array : private MemoryShare, public Iterable<T>
{
public:
	Array(nat largo = 0, const T& valorInicial = T());
	Array(const Array<T>& a);

	__declspec(property(get = ObtenerLargo)) nat Largo;
	nat ObtenerLargo() const;
	T& operator[](nat index) const;

	Array<T>& operator=(const Array<T>& a);

	virtual Iterador<T> ObtenerIterador() const;

	static void Copiar(const Array<T>& origen, Array<T>& destino);
	static void Copiar(const Array<T>& origen, Array<T>& destino, nat desdeD);
	static void Copiar(const Array<T>& origen, nat desdeO, Array<T>& destino);
	static void Copiar(const Array<T>& origen, nat desdeO, Array<T>& destino, nat desdeD);
	static void Copiar(const Array<T>& origen, nat desdeO, nat largo, Array<T>& destino);
	static void Copiar(const Array<T>& origen, nat desdeO, nat largo, Array<T>& destino, nat desdeD);

private:
	T* m_Array;
	nat m_Largo;

	static const char* s_TypeName;
	static void LiberarArray(void* memoria);
};

#include "Array.cpp"
