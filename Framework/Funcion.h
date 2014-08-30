#pragma once

#include <iostream>
using namespace std;


template <class T>
class Funcion abstract
{
public:
	virtual ~Funcion(){}
	T operator()() const { return Evaluar(); }
protected:
	virtual T Evaluar() const abstract;
};

template <class T1, class T>
class Funcion1 abstract
{
public:
	virtual ~Funcion1(){}
	T operator()(const T1& t1) const { return Evaluar(t1); }
protected:
	virtual T Evaluar(const T1& t1) const abstract;
};

template <class T1, class T2, class T>
class Funcion2 abstract
{
public:
	virtual ~Funcion2(){}
	T operator()(const T1& t1, const T2& t2) const { return Evaluar(t1, t2); }
protected:
	virtual T Evaluar(const T1& t1, const T2& t2) const abstract;
};

template <class T1, class T2, class T3, class T>
class Funcion3 abstract
{
public:
	virtual ~Funcion3(){}
	T operator()(const T1& t1, const T2& t2, const T3& t3) const { return Evaluar(t1, t2, t3); }
protected:
	virtual T Evaluar(const T1& t1, const T2& t2, const T3& t3) const abstract;
};

template <class T1, class T2, class T3, class T4, class T>
class Funcion4 abstract
{
public:
	virtual ~Funcion4(){}
	T operator()(const T1& t1, const T2& t2, const T3& t3, const T4& t4) const { return Evaluar(t1, t2, t3, t4); }
protected:
	virtual T Evaluar(const T1& t1, const T2& t2, const T3& t3, const T4& t4) const abstract;
};
