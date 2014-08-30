#pragma once

template <class T>
class Array;

template <class T>
class Puntero;

#include "Iterable.h"

typedef unsigned int nat;

template <class T>
class Matriz : public Iterable<const Array<T>>
{
public:
	Matriz(nat largo = 0);
	Matriz(nat largo, nat ancho);
	Matriz(const Matriz<T>& m);

	__declspec(property(get = ObtenerLargo)) nat Largo;
	nat ObtenerLargo() const;
	__declspec(property(get = ObtenerAncho)) nat Ancho;
	nat ObtenerAncho() const;

	const Array<T>& operator[](nat index) const;

	Matriz<T>& operator=(const Matriz<T>& m);

	virtual Iterador<const Array<T>> ObtenerIterador() const;

private:
	void Inicializar(nat largo, nat ancho);

	Array<Array<T>> matrizReal;
};

#include "Matriz.cpp"
