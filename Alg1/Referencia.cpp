#ifndef REFERENCIA_CPP
#define REFERENCIA_CPP

#include "Referencia.h"

template <class T>
ostream &operator<< <>(ostream &out, const Referencia<T> &ref)
{
	out << *(ref.puntero);
	return out;
}

//template <class T>
//Referencia<T>::Referencia(T* ptr)
//{
//	puntero = ptr;
//	contador = new int(1);
//}

template <class T>
Referencia<T>::Referencia(const T& dato)	
{
	puntero = new T(dato);
	contador = new int(1);
}

template <class T>
Referencia<T>::Referencia()
{
	puntero = NULL;
	contador = NULL;
}

template <class T>
Referencia<T>::Referencia(const Referencia<T> &ref)
{
	puntero = ref.puntero;
	contador = ref.contador;

	if (contador != NULL)
		(*contador)++;
}

template <class T>
Referencia<T>& Referencia<T>::operator=( const Referencia<T>& ref)
{
	if (&ref != this)
	{
		if (contador != NULL)
		{
			(*contador)--;
			if (*contador == 0)
			{
				delete puntero;
				delete contador;
			}
		}

		puntero = ref.puntero;
		contador = ref.contador;
		
		if (contador != NULL)
			(*contador)++;
	}
	
	return *this;
}

template <class T>
Referencia<T>::~Referencia()
{
	if (contador != NULL)
	{
		(*contador)--;
		if (*contador == 0)
		{
			delete puntero;
			delete contador;
		}
	}
}

//template <class T>
//void Referencia<T>::SetPuntero(T* ptr)
//{
//	if (contador != NULL)
//	{
//		(*contador)--;
//		if (*contador == 0)
//		{
//			delete puntero;
//			delete contador;
//		}
//	}
//
//	puntero = ptr;
//	contador = NULL;
//}
//
//template <class T>
//void Referencia<T>::SetDato(const T& dato)
//{
//	if (contador != NULL)
//	{
//		(*contador)--;
//		if (*contador == 0)
//		{
//			delete puntero;
//			delete contador;
//		}
//	}
//
//	puntero = new T(dato);
//	contador = new int(1);
//}
//
//template <class T>
//T* Referencia<T>::GetPuntero() const
//{
//	return puntero;
//}

template <class T>
T& Referencia<T>::GetDato() const
{
	return *puntero;
}

template <class T>
bool Referencia<T>::operator==(const Referencia<T>& ref)const
{
	return *puntero == *(ref.puntero);
}

template <class T>
bool Referencia<T>::operator!=(const Referencia<T>& ref)const
{
	return *puntero != *(ref.puntero);
}

template <class T>
bool Referencia<T>::operator<=(const Referencia<T>& ref)const
{
	return *puntero <= *(ref.puntero);
}

template <class T>
bool Referencia<T>::operator<(const Referencia<T>& ref)const
{
	return *puntero < *(ref.puntero);
}

template <class T>
bool Referencia<T>::operator>(const Referencia<T>& ref)const
{
	return *puntero > *(ref.puntero);
}

template <class T>
bool Referencia<T>::operator>=(const Referencia<T>& ref)const
{
	return *puntero >= *(ref.puntero);
}


#endif