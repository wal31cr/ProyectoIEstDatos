#pragma once
#include "NodoD.h"

class ListaD{
private:
	NodoD<Pasillo> * cab; //cabeza de la lista 
	int largo;
	//METODOS MISCÉLANEOS 
	NodoD<Pasillo> * first();
	NodoD<Pasillo> * end();
	NodoD<Pasillo> * next(int);
	NodoD<Pasillo> * previous(int);
	NodoD<Pasillo> * locateP(int);
	NodoD<Pasillo> * locateI(int);
	
public:
	int getLargo();
	void setLargo(int);
	ListaD(void);
	~ListaD(void);
	NodoD<Pasillo> * getCab();
	void setCab(NodoD<Pasillo>*);
	//METODOS FUNDAMENTALES 
	//AGREGAR
	bool insert(Pasillo*,int);
	//ELIMINAR
	bool erase(int);
	//OBTENER
	Pasillo* retrieve(int);
	//MOSTRAR 
	void show();
	//OTROS
	bool empty(); //Saber cuando esta vacio
	int size(); //Saber cual es el tamaño
	Pasillo* iFfirst(); //Retorna el valor del primero
	Pasillo* iFend(); //Retorna el valor del ultimo
	bool store(Pasillo*,int);
};

NodoD<Pasillo> * ListaD::first(){ //exactamente igual al de la lista simple
	return getCab();
}
NodoD<Pasillo> * ListaD::end(){ //exactamente igual al de la lista simple
		if (empty())
		return NULL;
	else{
		//Forma #1
		return locateP(size());
		/* Forma #2
		NodoS * aux=getCab();
		while(aux->getSgte()!=NULL)
		   aux=aux->getSgte();
		   return aux;
		*/
	}
}
NodoD<Pasillo> *ListaD:: next(int _info){ //exactamente igual al de la lista simple
		if (empty())
		return NULL;
	else {
		NodoD<Pasillo>*aux=locateI(_info);
		if(aux!=NULL)
			return aux->getSgte();
		else
			return NULL;
		}
}
NodoD<Pasillo> * ListaD::previous(int _info){
	NodoD<Pasillo> *aux =locateI(_info);
	if(aux!=NULL)
		return aux->getAnte();
	else
		return NULL;
}
NodoD<Pasillo> * ListaD::locateP(int _pos){ //iguales cambiar en a lista simplelineal, circular etc.....
	int cont=1;
		if(empty())
		return NULL;
	else{
	NodoD<Pasillo>*aux=getCab();
	if(_pos<=0 || _pos>size())
		return NULL;
	while(aux!=NULL){
		
		if(cont==_pos)
			return aux;
		 aux=aux->getSgte();
		 cont++;	
	}
	return NULL;
}
}
NodoD<Pasillo> * ListaD::locateI(int _num_pasillo){ //compara x num de pasillo
		if(empty())
		return NULL;
	else{	
	NodoD<Pasillo>*aux=getCab();
	while(aux!=NULL){
		if(aux->getPtrInfo()->getNumero()==_num_pasillo)
		  return aux;
	  else
		  aux=aux->getSgte();
 	}
	return NULL;
	}
}
int ListaD::getLargo(){
	return this->largo;
}
void ListaD::setLargo(int _largo){
	this->largo=_largo;
}
ListaD::ListaD(){ //igual al de la lista simple
	setCab(NULL);
	setLargo(0);
}
ListaD::~ListaD(){
}
NodoD<Pasillo> * ListaD::getCab(){
	return this->cab;
}
void ListaD::setCab(NodoD<Pasillo>*_cab){
	this->cab=_cab;
}
//METODOS FUNDAMENTALES 
//AGREGAR
//Paso1.Crear el nodo
//Paso2.Enlazar el nuevo nodo a la lista
//Paso3.Reacomodar la lista ocn nuevo nodo
//Analizar si es al inicio,al medio o al final
bool ListaD::insert(Pasillo* _pas,int _pos){
	NodoD<Pasillo>*temp;
	if(empty()&&(_pos==1)){
		setCab(new NodoD<Pasillo>(_pas));
		setLargo(getLargo()+1);
	}else{
		if(_pos==1){
			temp=new NodoD<Pasillo>(_pas); //1
			temp->setSgte(getCab()); //2
			getCab()->setAnte(temp); //3
			setCab(temp); //3
			setLargo(getLargo()+1);
			return true;
		}else{
			if(_pos>1 && _pos<=size()){
			NodoD<Pasillo>*aux=locateP(_pos);
			NodoD<Pasillo>*temp=new NodoD<Pasillo>(_pas);
			temp->setSgte(aux); //Paso2
			temp->setAnte(aux->getAnte()); //Paso2
			aux->getAnte()->setSgte(temp);
			aux->setAnte(temp);
			setLargo(getLargo()+1);
			return true;
			}
			if(_pos==size()+1){
				NodoD<Pasillo>*aux=locateP(size());
				NodoD<Pasillo>*temp=new NodoD<Pasillo>(_pas);
				temp->setAnte(aux);
				aux->setSgte(temp);
				setLargo(getLargo()+1);
				return true;
			}
		}
	}
}
//ELIMINAR
bool ListaD::erase(int _pos){ 
//Paso1. Apunte al nodo a eliminar
//Paso2. Reacomode la lista sin el nodo
//Eliminar
//Analizar si es el primero, el ultimo o del medio
	bool seBorro=true;
	if(empty()|| _pos<=0||_pos>size()) 
		seBorro=false;
	else{
		NodoD<Pasillo> * aux=locateP(_pos);
		if(_pos==1)
			setCab(aux->getSgte());
		else{
			aux->getSgte()->setAnte(aux->getAnte());
		if(_pos!=size())
			aux->getSgte()->setSgte(aux->getSgte());
		}
		delete aux;
		setLargo(getLargo()+1);
	}
	return seBorro;
}
//OBTENER
Pasillo* ListaD::retrieve(int _pos){ //Igual
	NodoD<Pasillo> * aux=locateP(_pos);
	if(aux==NULL)
		return NULL;
	else
		return aux->getPtrInfo();
}
//MOSTRAR 
void ListaD::show(){ //Igual
		if(empty())
		cout<<"Lista Vacia"<<endl;
	else{ 
		NodoD<Pasillo>*aux=getCab();
		while(aux!=NULL){
			cout<<"Valor: "<<aux->getPtrInfo()->toString()<<endl;
			aux=aux->getSgte();
		}
	}
	system("pause");
}
//OTROS
bool ListaD::empty(){ //Saber cuando esta vacio //Igual
		bool val=false;
	if(getCab()==NULL)
		val=true;
	return val;
}
int ListaD::size(){ //Saber cual es el tamaño //Igual
	return getLargo();
}
Pasillo* ListaD::iFfirst(){ //Retorna el valor del primero //Igual
	if(getCab()!=NULL)
		return getCab()->getPtrInfo();
	else
		return NULL;
}
Pasillo* ListaD::iFend(){ //Retorna el valor del ultimo //Igual
	if(empty())
		return NULL;
	else
		return end()->getPtrInfo();
}
bool ListaD::store(Pasillo* _pas,int _pos){ //Igual
		NodoD<Pasillo>*aux=locateP(_pos);
	bool loActualizo=true;
	if(aux==NULL)
		loActualizo=false;
	else
		aux->setPtrInfo(_pas);
	return loActualizo;
}