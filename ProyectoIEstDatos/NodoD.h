#pragma once
#include "stdafx.h"
#include"Pasillo.h"

template<class T>
class NodoD{
private:
	T* p;
	NodoD<T>* sgte;
	NodoD<T>* ante;

public:
	NodoD(void);
	virtual ~NodoD(void);
	NodoD(T*);
	NodoD*getSgte();
	void setSgte(NodoD*);
	NodoD*getAnte();
	void setAnte(NodoD*);
	void setPtrInfo(T*);
	T* getPtrInfo();
};

template<class T>
NodoD<T>::NodoD(void){
  setPtrInfo(NULL);
  setSgte(NULL);
  setAnte(NULL);
}

template<class T>
NodoD<T>::~NodoD(void){

}

template<class T>
NodoD<T>* NodoD<T>::getSgte(){
}

template<class T>
NodoD<T>::NodoD(T* _info){
	setPtrInfo(_info);
	setSgte(NULL);
}

template<class T>
NodoD<T>* NodoD<T>::getAnte(){
	return this->ante;
}

template<class T>
void NodoD<T>::setAnte(NodoD*_ante){
	this->ante=_ante;
}

template<class T>
NodoD<T>* NodoD<T>::getSgte(){
	return this->sgte;
}

template<class T>
void NodoD<T>::setSgte(NodoD*_sgte){
	this->sgte=_sgte;
}

template<class T>
void NodoD<T>::setPtrInfo(T* _info){
	this->p=_info;
}

template<class T>
T* NodoD<T>::getPtrInfo(){
	return this->p;
}