#pragma once
#include"stdafx.h"

class Producto{
private:
	int id;
	string nombre;
	string marca;
	//pila
public:
	Producto(){
		Producto(0,"no_disponible","sin_marca");
	}
	Producto(int i, string n, string m){
		id= i;
		nombre=n;
		marca=m;
	}
	
	int getId(){
		return this->id;
	}

	string getNombre(){
		return this->nombre;
	}

	string getMarca(){
		return this->marca;
	}

	void setId(int i){
		this->id=i;
	}

	void setNombre(string n){
		this->nombre=n;
	}

	void setMarca(string m){
		this->marca=m;
	}

};