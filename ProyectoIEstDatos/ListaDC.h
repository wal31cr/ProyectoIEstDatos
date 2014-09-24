#pragma once
#include "NodoD.h"
#include "TipoProd.h"

class ListaDC{
private:
	NodoD<TipoProd> * cab; //cabeza de la lista 
	int largo;
	//METODOS MISCÉLANEOS 
	NodoD<TipoProd> * first();
	NodoD<TipoProd> * end();
	NodoD<TipoProd> * next(string);
	NodoD<TipoProd> * previous(string);
	NodoD<TipoProd> * locateP(int);
	NodoD<TipoProd> * locateI(string);
	
public:
	int getLargo();
	void setLargo(int);
	ListaDC(void);
	~ListaDC(void);
	NodoD<TipoProd> * getCab();
	void setCab(NodoD<TipoProd>*);
	//METODOS FUNDAMENTALES 
	//AGREGAR
	bool insert(TipoProd*,int);
	//ELIMINAR
	bool erase(int);
	//OBTENER
	TipoProd* retrieve(int);
	//MOSTRAR 
	void show();
	//OTROS
	bool empty(); //Saber cuando esta vacio
	int size(); //Saber cual es el tamaño
	TipoProd* iFfirst(); //Retorna el valor del primero
	TipoProd* iFend(); //Retorna el valor del ultimo
	bool store(TipoProd*,int);
};

NodoD<TipoProd> * ListaDC::first(){
	return getCab();
}
NodoD<TipoProd> * ListaDC::end(){
	if(empty())
		return NULL;
	else
		return getCab()->getAnte();
}
NodoD<TipoProd> * ListaDC::next(string _info){ //tarea
		if (empty())
		return NULL;
	else {
		NodoD<TipoProd>*aux=locateI(_info);
		if(aux!=NULL)
			return aux->getSgte();
		else
			return NULL;
		}
}
NodoD<TipoProd> * ListaDC::previous(string _info){ //tarea
	NodoD<TipoProd> *aux =locateI(_info);
	if(aux!=NULL)
		return aux->getAnte();
	else
		return NULL;

}
NodoD<TipoProd> * ListaDC::locateP(int _pos){ //tarea
		int cont=1;
	if(empty())
		return NULL;
	else{
	NodoD<TipoProd>*aux=getCab();
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
NodoD<TipoProd> * ListaDC::locateI(string _info){ //tarea
		if(empty())
		return NULL;
	else{
	NodoD<TipoProd>*aux=getCab();
	while(aux!=NULL){
		if(aux->getPtrInfo()->getNombre()==_info)
		  return aux;
	  else
		  aux=aux->getSgte();
 	}
	return NULL;
	}
}
int ListaDC::getLargo(){
	return this->largo;
}
void ListaDC::setLargo(int largo){
	this->largo=largo;
}
ListaDC::ListaDC(){
	setCab(NULL);
	setLargo(0);
}
ListaDC::~ListaDC(){
}
NodoD<TipoProd> * ListaDC::getCab(){
	return this->cab;
}
void ListaDC::setCab(NodoD<TipoProd>*_cab){
	this->cab=_cab;
}
//METODOS FUNDAMENTALES 
//AGREGAR
bool ListaDC::insert(TipoProd* tprod,int _pos){
//Agregar nuevo nodo en la posicion especifica de 
	if(_pos<1 || (_pos>size()+1) || (empty()&&_pos!=1))
		return false;
	else{
		//Paso1.Crear nodo
		NodoD<TipoProd>*temp=new NodoD<TipoProd>(tprod);
		
		//Paso2.Enlazar el nuevo nodo a lista
		if(empty()){
			temp->setSgte(temp);
			temp->setAnte(temp);
		}else{
			NodoD<TipoProd>*aux;
			if(_pos==1)
				aux=end();//referencia el nodo anterior de donde se desea insertar
			else
				aux=locateP(_pos-1); //Localizar la posicion a insertar

			temp->setSgte(aux->getSgte());
			temp->setAnte(aux);
			//Enlaza el nuevo nodo a la lista
			aux->getSgte()->setAnte(temp);
			aux->setSgte(temp);
			//Reacomoda la lista con el nuevo nodo
			if(_pos==1)
				setCab(temp);
		}
		setLargo(getLargo()+1);
		return true;
	}
}
//ELIMINAR
bool ListaDC::erase(int _pos){
	bool borrado;
	NodoD<TipoProd>*aux=getCab();
	if((_pos>=1)&&(_pos<=size())){
		if(size()==1){
			aux=getCab();
			setCab(NULL);
		}else{
			NodoD<TipoProd>*aux=locateP(_pos);
			aux->getAnte()->setSgte(aux->getSgte());
			aux->getSgte()->setAnte(aux->getAnte());
			if(_pos==1){
			setCab(getCab()->getSgte());
			}
		}
		setLargo(getLargo()+1);
		delete aux;
		borrado=true;
	}else{
		borrado=false;
	}
	return borrado;
}
//OBTENER
TipoProd* ListaDC::retrieve(int _pos){ //tarea
		NodoD<TipoProd> * aux=locateP(_pos);
	if(aux==NULL)
		return NULL;
	else
		return aux->getPtrInfo();
}
//MOSTRAR 
void ListaDC::show(){
//Recorrer un estructura circular
	if(empty())
		cout<<"La lista doble circular esta vacia";
	else{
		NodoD<TipoProd>*aux=getCab();
		do{
			cout<<aux->getPtrInfo()<<endl;
			aux=aux->getSgte();
		}while(aux!=getCab());
	}
	system("pause");
}
//OTROS
bool ListaDC::empty(){ //Saber cuando esta vacio
	return (getCab()==NULL);
}
int ListaDC::size(){ //Saber cual es el tamaño
	return this->getLargo();
}
TipoProd*  ListaDC::iFfirst(){ //Retorna el valor del primero //tarea
	if(getCab()!=NULL)
		return getCab()->getPtrInfo();
	else
		return NULL;
}
TipoProd* ListaDC::iFend(){ //Retorna el valor del ultimo //tarea
	if(empty())
		return NULL;
	else
	return end()->getPtrInfo();
}
bool ListaDC::store(TipoProd* _inf,int _pos){ //tarea 
	NodoD<TipoProd>*aux=locateP(_pos);
	bool loActualizo=true;
	if(aux==NULL)
		loActualizo=false;
	else
		aux->setPtrInfo(_inf);
	return loActualizo;
}
