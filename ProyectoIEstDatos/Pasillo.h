#pragma once
#include"stdafx.h"

class Pasillo{
private:
	string nombre;
	int numero;
public:
	Pasillo(string n, int p){
		nombre=n;
		numero=p;
	}

	Pasillo(){
		Pasillo("no_definido",0);
	}

	string getNombre(){
		return this->nombre;
	}

	int getNumero(){
		return this->numero;
	}

	void setNombre(string n){
		this->nombre=n;
	}

	void setNumero(int p){
		this->numero=p;
	}

	string toString(){
		stringstream ss;
		ss<<"Pasillo #: "<<this->numero<<endl
			<<"Nombre: "<<this->nombre<<endl<<endl;
		return ss.str();
	}
};