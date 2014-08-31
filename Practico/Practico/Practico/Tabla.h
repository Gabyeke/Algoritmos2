#include "Puntero.h"
#include "Iterador.h"

template <class D, class R>
class Tabla
{
	public:
		virtual ~Tabla(){};
		
		/********************** ABSTRACT ********************************/

		virtual Puntero<Tabla<D,R>> clone() const abstract;
		//Pre: -
		//Pos: Retorna una copia de this que no comparte memoria.
		
		virtual Puntero <Tabla<D,R>> crearVacia() const abstract;
		//Pre: -
		//Pos: Retorna una tabla vacia.

		virtual Iterador<D> getIterador() const abstract;
		//Pre: -
		//Pos:

		virtual void agregar(const D &d, const R &r) abstract;
		//Pre: !estaLlena()
		//Pos: recuperar(d) == r

		virtual R& recuperar(const D &d) abstract;
		//Pre: estaDefinido(d)
		//Pos: retorna el valor asociado

		virtual Puntero<R> recupero(const D &d) abstract;

		virtual void eliminar(const D &d) abstract;
		//Pre: -
		//Pos: !estaDefinido(d)

		virtual D some() const abstract;
		//Pre: !esVacia()
		//Pos: retorna un elemento cualquiera
		

		/******************************************************/
		
		virtual bool estaLlena() const {
			return false;
		};
		//Pre: -
		//Pos: Retorna true sii la tabla esta llena.
		
		virtual bool esVacia() const;
		//Pre: -
		//Pos: Retorna true sii la tabla no tiene elementos.
		
		virtual bool estaDefinido(const D &d) const
		//Pre: -
		//Pos: retorna true sii d pertenece a la Tabla.
		{
			Iterador<D> it 0 getIterador();
			while(!it.HayElemento())
			{
				D dominio = it.ElementoActual();
				it++;
				if(dominio==d) {
					return true;
				}
			}
			return false;			
		}
		
		virtual void vaciar()
		//Pre: -
		//Pos: esVacia()
		{
			while (!esVacia())
			{
				eliminar(some());
			}
		}

		


		/********************** OPERATORS ********************************/
		virtual bool operator< (const Tabla<D,R> &t) const
		//Pre: -
		//Pos: retorna true sii la tabla t esta contenida en this.
		{
			Iterador<D> it = getIterador();
			while (! it.EsFin())
			{
				D d = it.ElementoActual();
				it++;
				if(! t.estaDefinido(d) || recuperar(d) != t.recuperar(d)){
					return false;
				}
			}
			return true;
		}
		virtual bool operator== (const Tabla<D,R> &t) const
		//Pre: -
		//Pos: retorna true sii (t contenida en this && this contenida en t)
		{
			return *this < t && t < *this;
		}
		/********************** FIN OPERATORS *****************************/
};