#ifndef ARRAY_CPP
#define ARRAY_CPP

#include "Array.h"
#include "ArrayIteracion.h"
#include <assert.h>
#include <typeinfo.h>

template <class T>
Array<T>::Array(nat largo, const T& valorInicial)
: m_Largo(largo), m_Array((largo == 0) ? NULL : new T[largo])
{
	if (m_Largo > 0)
		AsignarMemoria(s_TypeName, m_Array, LiberarArray, false);
	for (nat i = 0; i < largo; i++)
		m_Array[i] = valorInicial;
}

template <class T>
Array<T>::Array(const Array<T>& a)
: m_Largo(a.m_Largo), m_Array(a.m_Array)
{
	if (m_Largo > 0)
		AsignarMemoria(s_TypeName, m_Array, LiberarArray, false);
}

template <class T>
nat Array<T>::ObtenerLargo() const
{
	MarcarUtilizado();
	return m_Largo;
}

template <class T>
T& Array<T>::operator[](nat index) const
{
	assert(index < Largo);
	MarcarUtilizado();
	return m_Array[index];
}

template <class T>
Array<T>& Array<T>::operator=(const Array<T>& a)
{
	if (m_Array != a.m_Array)
	{
		m_Largo = a.m_Largo;
		m_Array = a.m_Array;
		AsignarMemoria(s_TypeName, m_Array, LiberarArray, false);
	}
	return *this;
}

template <class T>
Iterador<T> Array<T>::ObtenerIterador() const
{
	MarcarUtilizado();
	return new ArrayIteracion<T>(*this);
}

template <class T>
void Array<T>::Copiar(const Array<T>& origen, Array<T>& destino)
{
	Copiar(origen, 0, origen.Largo, destino, 0);
}

template <class T>
void Array<T>::Copiar(const Array<T>& origen, Array<T>& destino, nat desdeD)
{
	Copiar(origen, 0, origen.Largo, destino, desdeD);
}

template <class T>
void Array<T>::Copiar(const Array<T>& origen, nat desdeO, Array<T>& destino)
{
	Copiar(origen, desdeO, origen.Largo - desdeO, destino, 0);
}

template <class T>
void Array<T>::Copiar(const Array<T>& origen, nat desdeO, Array<T>& destino, nat desdeD)
{
	Copiar(origen, desdeO, origen.Largo - desdeO, destino, desdeD);
}

template <class T>
void Array<T>::Copiar(const Array<T>& origen, nat desdeO, nat largo, Array<T>& destino)
{
	Copiar(origen, desdeO, largo, destino, 0);
}

template <class T>
void Array<T>::Copiar(const Array<T>& origen, nat desdeO, nat largo, Array<T>& destino, nat desdeD)
{
	assert(desdeO + largo <= origen.Largo);
	assert(desdeD + largo <= destino.Largo);
	for (nat i = 0; i < largo; i++)
		destino[desdeD + i] = origen[desdeO + i];
}

template <class T>
void Array<T>::LiberarArray(void* memoria)
{
	T* arrayReal = (T*) memoria;
	delete[] arrayReal;
}

template <class T>
const char* Array<T>::s_TypeName = typeid(T).name();

#endif