#include "ManejadorImpresionXml.h"

ManejadorImpresionXml::ManejadorImpresionXml()
{
	ampCod = "&amp;";
	ampDec = "&";
	comCod = "&quot;";
	comDec = "\"";
	menCod = "&lt;";
	menDec = "<";
	mayCod = "&gt;";
	mayDec = ">";
	cadDefecto = "Seccion por defecto";
	m_SeccionesAbiertas = 0;
	m_PruebaAbierta = false;
}

void ManejadorImpresionXml::ImprimirResultado(TipoRetorno retorno, TipoRetorno retornoEsperado, Cadena comentario) const
{
	bool abrirSeccion = m_SeccionesAbiertas == 0;
	if (abrirSeccion)
		IniciarSeccion(cadDefecto, OK);
	PasarSalidaArchivo();
	for (nat i = 0; i <= m_SeccionesAbiertas; i++)
		cout << '\t';
	cout << "<Prueba";
	if (comentario != "")
		cout << " comentario=\"" << Codificar(comentario) << "\"";
	cout << " obtenido=\"" << GetStringRetorno(retorno) << "\"";
	cout << " esperado=\"" << GetStringRetorno(retornoEsperado) << "\"/>" << endl;
	PasarSalidaPantalla();
	if (abrirSeccion)
		CerrarSeccion();
}

void ManejadorImpresionXml::ImprimirTotalResultados(const Puntero<EstadisticaPrueba>& estadistica) const
{
	PasarSalidaArchivo();
	cout << "\t<Resumen";
	cout << " correctas=\"" << estadistica->GetCantidadCorrectas() << "\"";
	cout << " incorrectas=\"" << estadistica->GetCantidadIncorrectas() << "\"";
	cout << " no_implementadas=\"" << estadistica->GetCantidadNoImplementadas() << "\"";
	cout << "/>" << endl;
	PasarSalidaPantalla();
}

void ManejadorImpresionXml::IniciarPrueba() const
{
	assert(!m_PruebaAbierta);
	PasarSalidaArchivo();
	cout << "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>" << endl;
	cout << "<Pruebas>" << endl;
	m_PruebaAbierta = true;
	PasarSalidaPantalla();
}

void ManejadorImpresionXml::IniciarSeccion(Cadena nombreSeccion, TipoRetorno tipoPrueba) const
{
	PasarSalidaArchivo();
	m_SeccionesAbiertas++;
	for (nat i = 0; i < m_SeccionesAbiertas; i++)
		cout << '\t';
	cout << "<Seccion nombre=\"" << Codificar(nombreSeccion) << "\" tipo=\"" << GetStringRetorno(tipoPrueba) << "\">" << endl;
	PasarSalidaPantalla();
}

Cadena ManejadorImpresionXml::Codificar(Cadena c) const
{
	return c
		.Reemplazar(ampDec, ampCod)
		.Reemplazar(comDec, comCod)
		.Reemplazar(menDec, menCod)
		.Reemplazar(mayDec, mayCod);
}

void ManejadorImpresionXml::CerrarSeccion() const
{
	assert(m_SeccionesAbiertas > 0);
	PasarSalidaArchivo();
	for (nat i = 0; i < m_SeccionesAbiertas; i++)
		cout << '\t';
	cout << "</Seccion>" << endl;
	m_SeccionesAbiertas--;
	PasarSalidaPantalla();
}

void ManejadorImpresionXml::CerrarPrueba() const
{
	if (!m_PruebaAbierta)
		return;
	assert(m_SeccionesAbiertas == 0);
	PasarSalidaArchivo();
	cout << "</Pruebas>" << endl;
	m_PruebaAbierta = false;
	PasarSalidaPantalla();
}

Cadena ManejadorImpresionXml::ObtenerExtension() const
{
	return "xml";
}
