#ifndef PUNTERO_CPP
#define PUNTERO_CPP

#include <assert.h>
#include <typeinfo.h>
#include "Puntero.h"
#include "Comparador.h"

template <class T>
Puntero<T>::Puntero(T* ptr)
: m_Ptr(ptr)
{
	if (m_Ptr != NULL)
		AsignarMemoria(s_TypeName, m_Ptr, LiberarPuntero, true);
}

template <class T>
Puntero<T>::Puntero(const Puntero<T> &p)
: m_Ptr(p.m_Ptr)
{
	if (m_Ptr != NULL)
		AsignarMemoria(s_TypeName, m_Ptr, LiberarPuntero, true);
}

template <class T>
const T* Puntero<T>::operator->() const
{
	assert(m_Ptr != NULL);
	MarcarUtilizado();
	return m_Ptr;
}

template <class T>
T* Puntero<T>::operator->()
{
	assert(m_Ptr != NULL);
	MarcarUtilizado();
	return m_Ptr;
}

template <class T>
Puntero<T>& Puntero<T>::operator=(T* ptr)
{
	if (m_Ptr != ptr)
	{
		m_Ptr = ptr;
		AsignarMemoria(s_TypeName, m_Ptr, LiberarPuntero, true);
	}
	return *this;
}

template <class T>
Puntero<T>& Puntero<T>::operator=(const Puntero<T>& p)
{
	if (m_Ptr != p.m_Ptr)
	{
		m_Ptr = p.m_Ptr;
		AsignarMemoria(s_TypeName, m_Ptr, LiberarPuntero, true);
	}
	return *this;
}

template <class T>
bool Puntero<T>::operator==(const int ptr) const
{
	assert(ptr == NULL);
	MarcarUtilizado();
	return m_Ptr == NULL;
}

template <class T>
bool Puntero<T>::operator!=(const int ptr) const
{
	assert(ptr == NULL);
	MarcarUtilizado();
	return m_Ptr != NULL;
}

template <class T>
bool Puntero<T>::operator==(const Puntero<T>& p) const
{
	MarcarUtilizado();
	p.MarcarUtilizado();
	return m_Ptr == p.m_Ptr || m_Ptr != NULL && p.m_Ptr != NULL && Comparador<T>::Default.SonIguales(*m_Ptr, *p.m_Ptr);
}

template <class T>
bool Puntero<T>::operator!=(const Puntero<T>& p) const
{
	return !(*this == p);
}

template <class T>
bool Puntero<T>::operator<(const Puntero<T>& p) const
{
	MarcarUtilizado();
	p.MarcarUtilizado();
	return m_Ptr == NULL ? p.m_Ptr != NULL : p.m_Ptr != NULL && Comparador<T>::Default.EsMenor(*m_Ptr, *p.m_Ptr);
}

template <class T>
bool Puntero<T>::operator>(const Puntero<T>& p) const
{
	MarcarUtilizado();
	p.MarcarUtilizado();
	return m_Ptr != NULL && (p.m_Ptr == NULL || Comparador<T>::Default.EsMayor(*m_Ptr, *p.m_Ptr));
}

template <class T>
bool Puntero<T>::operator<=(const Puntero<T>& p) const
{
	return (*this == p) || (*this < p);
}

template <class T>
bool Puntero<T>::operator>=(const Puntero<T>& p) const
{
	return (*this == p) || (*this > p);
}

template <class T>
template <class U> Puntero<T>::operator Puntero<U>() const
{
	assert(m_Ptr == NULL || dynamic_cast<U*>(m_Ptr) != NULL);
	return static_cast<U*>(m_Ptr);
}

template <class T>
bool Puntero<T>::operator!() const
{
	MarcarUtilizado();
	return m_Ptr == NULL;
}

template <class T>
Puntero<T>::operator bool() const
{
	MarcarUtilizado();
	return m_Ptr != NULL;
}

template <class T>
ostream& operator<< <>(ostream& out, const Puntero<T>& p)
{
	p.MarcarUtilizado();
	if (p.m_Ptr != NULL)
		out << *(p.m_Ptr);
	else
		out << "NULL";
	return out;
}

template <class T>
void Puntero<T>::LiberarPuntero(void* memoria)
{
	T* ptr = (T*) memoria;
	delete ptr;
}

template <class T>
const char* Puntero<T>::s_TypeName = typeid(T).name();

#endif