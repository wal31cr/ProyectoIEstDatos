#pragma once
#include "stdafx.h"
#include "Producto.h"
class NodoS   //Nodo Simple
{
private:
	Producto* prod;
	NodoS *sgte;

public:
	NodoS(void);
	~NodoS(void);
	NodoS(Producto*);
	NodoS*getSgte();
	void setSgte(NodoS*);
	void setProd(Producto*);
	Producto* getProd();
	void setProd(Producto*);
};

NodoS::NodoS(void){
  setProd(0);
  setSgte(NULL);
}
NodoS::~NodoS(void){
}
NodoS *NodoS::getSgte(){
}
NodoS::NodoS(Producto* _prod){
	setProd(_prod);
	setSgte(NULL);
}
NodoS*NodoS::getSgte(){
	return this->sgte;
}
void NodoS::setSgte(NodoS*_sgte){
	this->sgte=_sgte;
}
void NodoS::setProd(Producto* _prod){
	this->prod=_prod;
}
Producto* NodoS::getProd(){
	return this->prod;
}

void NodoS::setProd(Producto*p){
	this->prod=p;
}