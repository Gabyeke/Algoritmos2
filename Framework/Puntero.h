#ifndef PUNTERO_H
#define PUNTERO_H

#include <iostream>
using namespace std;

#include "MemoryShare.h"

template <class T>
class Puntero : private MemoryShare
{
	friend ostream& operator<< <>(ostream& out, const Puntero<T>& p);

public:
	Puntero(T* ptr = NULL);
	Puntero(const Puntero<T>& p);

	const T* operator->() const;
	T* operator->();
	Puntero<T>& operator=(T* ptr);
	Puntero<T>& operator=(const Puntero<T>&);

	bool operator==(const int ptr) const;
	bool operator!=(const int ptr) const;
	bool operator==(const Puntero<T>& p) const;
	bool operator!=(const Puntero<T>& p) const;
	bool operator<(const Puntero<T>& p) const;
	bool operator>(const Puntero<T>& p) const;
	bool operator<=(const Puntero<T>& p) const;
	bool operator>=(const Puntero<T>& p) const;

	template <class U> operator Puntero<U>() const;

	bool operator!() const;
	operator bool() const;

private:
	T* m_Ptr;

	static const char* s_TypeName;
	static void LiberarPuntero(void* memoria);
};

#include "Puntero.cpp"

#endif