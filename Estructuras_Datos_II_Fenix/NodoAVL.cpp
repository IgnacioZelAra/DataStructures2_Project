#include "NodoAVL.h"
#include "Provincia.h"
#include "NodoARN.h"




NodoAVL::~NodoAVL()
{
}

//NodoAVL::NodoAVL(Provincia* pProvincia) {
//	this->provincia = pProvincia;
//	left = nullptr;
//	right = nullptr;
//	/*this->arnPointer = arnPointer;*/
//}




NodoAVL::NodoAVL(Provincia* pProvincia/*, NodoARN* arnPointer*/)
{
	this->provincia = pProvincia;
	this->arnPointer = nullptr;
	this->left = nullptr;
	this->right = nullptr;
}

void NodoAVL::setProvincia(Provincia* pProvincia)
{
	this->provincia = pProvincia;
}

void NodoAVL::setLeft(NodoAVL* left)
{
	this->left = left;
}

void NodoAVL::setRight(NodoAVL* right)
{
	this->right = right;
}

void NodoAVL::setNodoARN( NodoARN* arnPointer)
{
	this->arnPointer = arnPointer;
}


Provincia* NodoAVL::getProvincia()
{
	return this->provincia;
}

NodoAVL* NodoAVL::getLeft()
{
	return this->left;
}

NodoAVL* NodoAVL::getRight()
{
	return this->right;
}

NodoARN* NodoAVL::getNodoARN()
{
	return this->arnPointer;
}

