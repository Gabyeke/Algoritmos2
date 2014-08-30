#include "ManejadorImpresionTxt.h"

ManejadorImpresionTxt::ManejadorImpresionTxt()
{
	seccionAbierta = false;
}

void ManejadorImpresionTxt::ImprimirResultado(TipoRetorno retorno, TipoRetorno retornoEsperado, Cadena comentario) const
{
	cout << endl;
	cout << "----------------------------- Testeo --------------------------------" << endl;
	ImprimirComentario(comentario);
	ImprimirRetorno(retorno, retornoEsperado);
	cout << "---------------------------------------------------------------------" << endl;
}

void ManejadorImpresionTxt::ImprimirTotalResultados(const Puntero<EstadisticaPrueba>& estadistica) const
{
	cout << endl;
	cout << "  +------------------------------+" << endl;
	cout << "    Pruebas Correctas : " << estadistica->GetCantidadCorrectas() << endl;
	cout << "    Pruebas Incorrectas: " << estadistica->GetCantidadIncorrectas() << endl;
	cout << "    Pruebas NI: " << estadistica->GetCantidadNoImplementadas() << endl;
	cout << "  +------------------------------+" << endl;
}

void ManejadorImpresionTxt::IniciarPrueba() const
{
	PasarSalidaArchivo();
}

void ManejadorImpresionTxt::CerrarPrueba() const
{
}

Cadena ManejadorImpresionTxt::ObtenerExtension() const
{
	return "txt";
}

void ManejadorImpresionTxt::IniciarSeccion(Cadena nombreSeccion, TipoRetorno tipoPrueba) const
{
	if (seccionAbierta)
		cout << endl << endl << endl;
	cout << "********************************************* Pruebas ";
	cout << nombreSeccion;
	if (tipoPrueba == OK)
		cout << " OK";
	else
		cout << " ERROR";
	cout << " *********************************************";
	cout << endl << endl << endl;
	seccionAbierta = true;
}

void ManejadorImpresionTxt::ImprimirComentario(Cadena comentario)const
{
	if (comentario != "")
		cout << "  Comentario: " << comentario << endl;
}

void ManejadorImpresionTxt::ImprimirRetorno(TipoRetorno retorno, TipoRetorno retornoEsperado) const
{
	cout << "  Retorno obtenido "<< GetStringRetorno(retorno);
	if (retorno != retornoEsperado)
		cout << ", se esperaba " << GetStringRetorno(retornoEsperado);
	cout << endl;
}
