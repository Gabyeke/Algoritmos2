#pragma once

#include "Iteracion.h"
#include "Puntero.h"

template <class T>
class Iterador
{
public:
	Iterador(Iteracion<T>* iteracion = NULL);
	Iterador(const Puntero<Iteracion<T>>& iteracion);
	Iterador(const Iterador<T>& iterador);

	const Iterador<T>& operator=(Iteracion<T>* iteracion);
	const Iterador<T>& operator=(const Puntero<Iteracion<T>>& iteracion);
	const Iterador<T>& operator=(const Iterador<T>& iterador);

	void Reiniciar();
	bool HayElemento() const;
	const T& ElementoActual() const;
	void Avanzar();

	inline Iterador<T>& operator++();
	inline Iterador<T>& operator++(int);
	inline const T& operator*() const;

	template <class U> operator Iterador<U>() const;

	template <class U, typename Conv>
	Iterador<U> Convert() const;

private:
	Puntero<Iteracion<T>> m_Iteracion;
};

#include "Iterador.cpp"