#ifndef ITERADOR_H
#define ITERADOR_H

template <class T>
class Iterador {
private:
	Iterador<T> *ref;

protected:
	Iterador() {
		ref = NULL;
	}

public:

	Iterador(const Iterador<T> &it) {
		ref = NULL;
		*this = it;
	}

	Iterador &operator=(const Iterador<T> &it) { 
		if (this != &it) {
			delete ref;

			ref = it.Clon();
		}
		return *this;
	}

	virtual Iterador<T> *Clon() const { 
		if (ref == NULL) {
			Iterador<T> *it = new Iterador<T>();
			return it;
		}
		else
			return ref->Clon();
	}
	
	virtual ~Iterador() {
		delete this->ref; 
	}

	virtual const T &Elemento() const { 
		return ref->Elemento();
	}

	virtual T &ElementoInseguro() const { 
		return ref->ElementoInseguro();
	}

	virtual void Resto() {
		ref->Resto();
	}
	virtual bool EsFin() const {
		return ref->EsFin();
	}
	virtual void Principio() { 
		ref->Principio();
	}

	virtual const T &operator ++() { 
		Resto();
		return Elemento();
	}
	virtual const T &operator ++(int) { 
		const T &ant = Elemento();
		Resto();
		return ant;
	}
    virtual const T &operator*() { 
		return Elemento();
	}
};


#endif