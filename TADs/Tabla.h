template <class D, class R>
class Tabla
{
	public:
		virtual ~Tabla(){};
		
		virtual Puntero<Tabla<D,R>> clone() const abstract;
		//Pre: -
		//Pos: Retorna una copia de this que no comparte memoria.
		
		virtual Puntero <Tabla<D,R>> crearVacia() const abstract;
		//Pre: -
		//Pos: Retorna una tabla vacia.
		
		virtual bool estaLlena() const {return false;};
		//Pre: -
		//Pos: Retorna true sii la tabla esta llena.
		
		virtual bool esVacia() const;
		//Pre: -
		//Pos: Retorna true sii la tabla no tiene elementos.
		
		virtual bool operator< (const Tabla<D,R> &t) const;
		//Pre: -
		//Pos: retorna true sii la tabla t esta contenida en this.
		{
			Iterador<D> it = getIterador();
			while (! it.EsFin())
			{
				
			}
		}
		virtual bool operator== (const Tabla<D,R> &t) const;
		//Pre: -
		//Pos: retorna true sii (t contenida en this && this contenida en t)
		{
			return *this < t && t < *this;
		}
}