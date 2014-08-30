#ifndef TUPLA_H
#define TUPLA_H

class DatoNulo
{
public:
	bool operator==(const DatoNulo& d) const { return true; }
};

template <class T1, class T2, class T3 = DatoNulo, class T4 = DatoNulo>
class Tupla
{
public:
	Tupla(const T1& dato1 = T1(), const T2& dato2 = T2(), const T3& dato3 = T3(), const T4& dato4 = T4());
	Tupla(const Tupla<T1,T2,T3,T4>& tupla);
	virtual ~Tupla();

	const Tupla<T1,T2,T3,T4>& operator=(const Tupla<T1,T2,T3,T4>& tupla);
	bool operator==(const Tupla<T1,T2,T3,T4>& tupla) const;
	bool operator!=(const Tupla<T1,T2,T3,T4>& tupla) const;

	__declspec(property(get = ObtenerDato1, put = AsignarDato1)) T1& Dato1;
	T1& ObtenerDato1();
	void AsignarDato1(const T1& dato1);
	__declspec(property(get = ObtenerDato2, put = AsignarDato2)) T2& Dato2;
	T2& ObtenerDato2();
	void AsignarDato2(const T2& dato2);
	__declspec(property(get = ObtenerDato3, put = AsignarDato3)) T3& Dato3;
	T3& ObtenerDato3();
	void AsignarDato3(const T3& dato3);
	__declspec(property(get = ObtenerDato4, put = AsignarDato4)) T4& Dato4;
	T4& ObtenerDato4();
	void AsignarDato4(const T4& dato4);

	__declspec(property(get = ObtenerDato1)) const T1& Dato1;
	const T1& ObtenerDato1() const;
	__declspec(property(get = ObtenerDato2)) const T2& Dato2;
	const T2& ObtenerDato2() const;
	__declspec(property(get = ObtenerDato3)) const T3& Dato3;
	const T3& ObtenerDato3() const;
	__declspec(property(get = ObtenerDato4)) const T4& Dato4;
	const T4& ObtenerDato4() const;

	template <class U1, class U2, class U3, class U4>
	operator Tupla<U1,U2,U3,U4>() const;

private:
	T1 m_Dato1;
	T2 m_Dato2;
	T3 m_Dato3;
	T4 m_Dato4;
};

#include "Tupla.cpp"

#endif