#ifndef TUPLA_CPP
#define TUPLA_CPP

#include "Tupla.h"
#include "Comparador.h"

template <class T1, class T2, class T3, class T4>
Tupla<T1,T2,T3,T4>::Tupla(const T1& dato1, const T2& dato2, const T3& dato3, const T4& dato4)
: m_Dato1(dato1), m_Dato2(dato2), m_Dato3(dato3), m_Dato4(dato4)
{
}

template <class T1, class T2, class T3, class T4>
Tupla<T1,T2,T3,T4>::Tupla(const Tupla<T1,T2,T3,T4>& tupla)
: m_Dato1(tupla.m_Dato1), m_Dato2(tupla.m_Dato2), m_Dato3(tupla.m_Dato3), m_Dato4(tupla.m_Dato4)
{
}

template <class T1, class T2, class T3, class T4>
Tupla<T1,T2,T3,T4>::~Tupla()
{
}

template <class T1, class T2, class T3, class T4>
const Tupla<T1,T2,T3,T4>& Tupla<T1,T2,T3,T4>::operator=(const Tupla<T1,T2,T3,T4>& tupla)
{
	m_Dato1 = tupla.m_Dato1;
	m_Dato2 = tupla.m_Dato2;
	m_Dato3 = tupla.m_Dato3;
	m_Dato4 = tupla.m_Dato4;
	return *this;
}

template <class T1, class T2, class T3, class T4>
bool Tupla<T1,T2,T3,T4>::operator==(const Tupla<T1,T2,T3,T4>& tupla) const
{
	return Comparador<T1>::Default.SonIguales(m_Dato1, tupla.m_Dato1)
		&& Comparador<T2>::Default.SonIguales(m_Dato2, tupla.m_Dato2)
		&& Comparador<T3>::Default.SonIguales(m_Dato3, tupla.m_Dato3)
		&& Comparador<T4>::Default.SonIguales(m_Dato4, tupla.m_Dato4);
}

template <class T1, class T2, class T3, class T4>
bool Tupla<T1,T2,T3,T4>::operator!=(const Tupla<T1,T2,T3,T4>& tupla) const
{
	return !(*this == tupla);
}

template <class T1, class T2, class T3, class T4>
T1& Tupla<T1,T2,T3,T4>::ObtenerDato1()
{
	return m_Dato1;
}

template <class T1, class T2, class T3, class T4>
void Tupla<T1,T2,T3,T4>::AsignarDato1(const T1& dato1)
{
	m_Dato1 = dato1;
}

template <class T1, class T2, class T3, class T4>
T2& Tupla<T1,T2,T3,T4>::ObtenerDato2()
{
	return m_Dato2;
}

template <class T1, class T2, class T3, class T4>
void Tupla<T1,T2,T3,T4>::AsignarDato2(const T2& dato2)
{
	m_Dato2 = dato2;
}

template <class T1, class T2, class T3, class T4>
T3& Tupla<T1,T2,T3,T4>::ObtenerDato3()
{
	return m_Dato3;
}

template <class T1, class T2, class T3, class T4>
void Tupla<T1,T2,T3,T4>::AsignarDato3(const T3& dato3)
{
	m_Dato3 = dato3;
}

template <class T1, class T2, class T3, class T4>
T4& Tupla<T1,T2,T3,T4>::ObtenerDato4()
{
	return m_Dato4;
}

template <class T1, class T2, class T3, class T4>
void Tupla<T1,T2,T3,T4>::AsignarDato4(const T4& dato4)
{
	m_Dato4 = dato4;
}

template <class T1, class T2, class T3, class T4>
const T1& Tupla<T1,T2,T3,T4>::ObtenerDato1() const
{
	return m_Dato1;
}

template <class T1, class T2, class T3, class T4>
const T2& Tupla<T1,T2,T3,T4>::ObtenerDato2() const
{
	return m_Dato2;
}

template <class T1, class T2, class T3, class T4>
const T3& Tupla<T1,T2,T3,T4>::ObtenerDato3() const
{
	return m_Dato3;
}

template <class T1, class T2, class T3, class T4>
const T4& Tupla<T1,T2,T3,T4>::ObtenerDato4() const
{
	return m_Dato4;
}

template <class T1, class T2, class T3, class T4>
template <class U1, class U2, class U3, class U4>
Tupla<T1,T2,T3,T4>::operator Tupla<U1,U2,U3,U4>() const
{
	return Tupla<U1,U2,U3,U4>(m_Dato1, m_Dato2, m_Dato3, m_Dato4);
}

#endif