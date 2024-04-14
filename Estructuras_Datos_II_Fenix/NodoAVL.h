#pragma once
#include "Provincia.h"
#include "NodoAVL.h"
#include"NodoARN.h"



class NodoAVL
{
private:
	Provincia* provincia;
	NodoAVL* left;
	NodoAVL* right;
	NodoARN* arnPointer;

public:
	
	~NodoAVL();
	/*NodoAVL(Provincia* pProvincia);*/
	NodoAVL(Provincia* pProvincia/*, NodoARN* arnPointer*/);

	/*SETTERS*/
	void setProvincia(Provincia* pProvincia);
	void setLeft(NodoAVL* left);
	void setRight(NodoAVL* right);
	void setNodoARN(NodoARN* arnPointer);

	/*GETTERS*/
	Provincia* getProvincia();
	NodoAVL* getLeft();
	NodoAVL* getRight();
	NodoARN* getNodoARN();


};
