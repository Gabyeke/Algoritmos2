#ifndef MATRIZ_CPP
#define MATRIZ_CPP

#include "Matriz.h"
#include "Array.h"
#include "Puntero.h"
#include "MatrizIteracion.h"

template <class T>
Matriz<T>::Matriz(nat largo)
{
	Inicializar(largo, largo);
}

template <class T>
Matriz<T>::Matriz(nat largo, nat ancho)
{
	Inicializar(largo, ancho);
}

template <class T>
Matriz<T>::Matriz(const Matriz& m)
{
	matrizReal = m.matrizReal;
}

template <class T>
void Matriz<T>::Inicializar(nat largo, nat ancho)
{
	assert(largo * ancho != 0 || largo + ancho == 0);
	matrizReal = Array<Array<T>>(largo);
	for (nat i = 0; i < largo; i++)
		matrizReal[i] = Array<T>(ancho);
}

template <class T>
nat Matriz<T>::ObtenerLargo() const
{
	return matrizReal.Largo;
}

template <class T>
nat Matriz<T>::ObtenerAncho() const
{
	return matrizReal.Largo == 0 ? 0 : matrizReal[0].Largo;
}

template <class T>
const Array<T>& Matriz<T>::operator[](nat index) const
{
	return matrizReal[index];
}

template <class T>
Matriz<T>& Matriz<T>::operator=(const Matriz<T>& m)
{
	matrizReal = m.matrizReal;
	return *this;
}

template <class T>
Iterador<const Array<T>> Matriz<T>::ObtenerIterador() const
{
	return new MatrizIteracion<T>(*this);
}

#endif