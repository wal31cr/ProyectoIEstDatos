#pragma once
#include "NodoS.h"
class ListaS
{
private:
	NodoS * cab;
	int largo;
	NodoS * first();
	NodoS * end();
	NodoS * next(int);
	NodoS * previous(int);
	NodoS * locateP(int);
	NodoS * locateI(int);
	
public:
	int getLargo();
	void setLargo(int);
	ListaS(void);
	~ListaS(void);
	NodoS * getCab();
	void *SetCab(NodoS*);

	bool insert(int,int);

	bool erase(int);

	Producto* retrieve(int);

	void show();

	bool empty();
	int size(); 
	Producto* iFfirst(); 
	Producto* iFend(); 
	bool store(Producto*,int);
};


ListaS::ListaS(void){ 
	SetCab(NULL);
	setLargo(0);
}
ListaS::~ListaS(void){ 

}
 
NodoS * ListaS::first(){
	return getCab();
}
NodoS * ListaS::end(){ 
	if (empty())
		return NULL;
	else{
		return locateP(size());
	}
}
NodoS * ListaS::next(int _info){ //Devuelve la direccion del nodo siguiente al que se encuentra _info
	if (empty())
		return NULL;
	else {
		NodoS*aux=locateI(_info);
		if(aux!=NULL)
			return aux->getSgte();
		else
			return NULL;
		}
}
NodoS * ListaS::previous(int _id){ //Devolver la direccion del nodo que se encuentra antes del prodcuto de id _id
	if(empty())
		return NULL;
	else{
		NodoS*aux=getCab();
		if(aux->getProd()->getId()==_id){
			return NULL;
			while(aux->getSgte()!=NULL){
				if(aux->getSgte()->getProd()->getId()==_id)
					return aux;
				else
					aux=aux->getSgte();
			}
			return NULL;
		}
	}
}
NodoS * ListaS::locateP(int _pos){ //Recibe una posicion y devuelve la direccion del nodo donde se ubica la informacion
	if(empty()){
		return NULL;
	NodoS*aux=getCab();
	if(_pos<=0 || _pos>size())
		return NULL;
	while(aux!=NULL){
		int cont=1;
		if(cont==_pos)
			return aux;
		 aux=aux->getSgte();
		 cont++;	
	}
	return NULL;
}
}
NodoS * ListaS::locateI(int _id){ //Devuelve la direccion del nodo donde se ubica la informacion por id de producto
	if(empty())
		return NULL;
	else{
	NodoS*aux=getCab();
	while(aux!=NULL){
	  if(aux->getProd()->getId()==_id)
		  return aux;
	  else
		  aux=aux->getSgte();
 	}
	return NULL;
	}
}
NodoS * ListaS::getCab(){
	return this->cab;
}
void *  ListaS::SetCab(NodoS*_cab){
	this->cab=_cab;
}
int ListaS::getLargo(){
	return this->largo;
}
void ListaS::setLargo(int _largo){
	this->largo=_largo;
}
//METODOS FUNDAMENTALES 
//AGREGAR
bool ListaS::insert(int _info,int _pos){
	//Se va a insertar un nuevo nodo a la estructura con el valor de _info en la posicion _pos
	bool seInserto=true;
	if((_pos <= 0 || _pos > size()+1) || (empty()&&_pos > 1))
		seInserto=false;
	else{
		//Paso #1 crear el Nodo
		NodoS*temp=new NodoS();
		NodoS*ant=locateP(_pos-1);
		NodoS*aux=ant->getSgte();

		if(_pos==1){ //Agregar al inicio de la lista
		//Paso #2. Enlazar el nuevo nodo a la lista
			temp->setSgte(getCab());
			SetCab(temp); //Paso #3. Reacomodar la lista con el nuevo nodo
		} else{
			//Paso #2
			temp->setSgte(aux);
			//Paso #3
			ant->setSgte(temp);
		}
		
		setLargo(getLargo()+1);
	}
	return seInserto;
}
//ELIMINAR
bool ListaS::erase(int _pos){ //Elimina el nodo que esta en la posicion ingresada
	bool seBorro=true;
	if(empty()|| (_pos<1||_pos>size())) 
		seBorro=false;
	else{
		NodoS*aux;
		if(_pos==1){
			aux=getCab();
			SetCab(getCab()->getSgte());
		}
		else{
			//Paso #1. Apunte el nodo a eliminar 
			NodoS*ant=locateP(_pos-1);
			NodoS*auc=ant->getSgte();
			//Paso #2. Reacomode la lista sin el nodo
			ant->setSgte(aux->getSgte());
		}
		//Paso #3. Elimine el nodo
		delete aux;
		setLargo(getLargo()-1);
	}
	return seBorro;
}
//OBTENER
Producto* ListaS::retrieve(int _pos){ //Devuelve el dato en la posicion _pos
	NodoS * aux=locateP(_pos);
	if(aux==NULL)
		return NULL;
	else
		return aux->getProd();

}
//MOSTRAR 
void ListaS::show(){ //Mostrar todos los datos de la lista
	if(empty())
		cout<<"Lista Vacia"<<endl;
	else{ 
		NodoS*aux=getCab();
		while(aux!=NULL){
			cout<<"Valor: "<<aux->getProd()<<endl;
			aux=aux->getSgte();
		}
	}
}
//OTROS
bool ListaS::empty(){ //Saber cuando esta vacio
	return getCab()==NULL;
}
int ListaS::size(){ //Saber cual es el tamaño
	return getLargo();
}
Producto* ListaS::iFfirst(){ //Retorna el valor del primer dato
	if(getCab()!=NULL)
		return getCab()->getProd();
	else
		return NULL;
}
Producto* ListaS::iFend(){ //Retorna el valor del ultimo dato
	if(empty())
		return NULL;
	else
	return end()->getProd();
}
bool ListaS::store(Producto* _inf,int _pos){ //En el nodo de la posicion _pos le asigna el valor de _inf, devuelve true si lo inserto correctamente
	NodoS*aux=locateP(_pos);
	bool loActualizo=true;
	if(aux==NULL)
		loActualizo=false;
	else
		aux->setProd(_inf);
	return loActualizo;
}