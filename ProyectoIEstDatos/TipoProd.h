#include"ListaS.h"

class TipoProd{
private:
	ListaS* productos;
	string nombre;
public:
	TipoProd(){
		productos= new ListaS(); 
		TipoProd("no_definido");
	}

	TipoProd(string nombre){
		this->nombre=nombre;
	}

	string getNombre(){
		return nombre;
	}
};