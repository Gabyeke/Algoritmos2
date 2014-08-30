#ifndef CONVERTITERACION_CPP
#define CONVERTITERACION_CPP

#include "ConvertIteracion.h"
#include "Conversor.h"

template <class T, class U, typename Conv>
ConvertIteracion<T,U,Conv>::ConvertIteracion(Puntero<Iteracion<T>> toConvert)
{
	assert(toConvert);
	m_ToConvert = toConvert;
}

template <class T, class U, typename Conv>
void ConvertIteracion<T,U,Conv>::Reiniciar()
{
	m_ToConvert->Reiniciar();
}

template <class T, class U, typename Conv>
bool ConvertIteracion<T,U,Conv>::HayElemento() const
{
	return m_ToConvert->HayElemento();
}

template <class T, class U, typename Conv>
const U& ConvertIteracion<T,U,Conv>::ElementoActual() const
{
	Conversor<T,U>& conv = Conv();
	m_Actual = conv(m_ToConvert->ElementoActual());
	return m_Actual;
}

template <class T, class U, typename Conv>
void ConvertIteracion<T,U,Conv>::Avanzar()
{
	m_ToConvert->Avanzar();
}

#endif