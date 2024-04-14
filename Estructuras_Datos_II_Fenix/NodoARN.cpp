#include "NodoARN.h"
#include"Canton.h"

enum Color { RED, BLACK };



NodoARN::NodoARN()
{
	this->canton = NULL;
	color = NULL;
	preNode = nullptr;
	left = nullptr;
	right = nullptr;
}

NodoARN::NodoARN(Canton* c)
{
	this->canton = c;
	color = 'r';
	preNode = NULL;
	left = NULL;
	right = NULL;
}

NodoARN::~NodoARN()
{
}

void NodoARN::setCanton(Canton* pCanton)
{
	this->canton = pCanton;
}

void NodoARN::setColor(char pColor)
{
	this->color = pColor;
}

void NodoARN::setPreNode(NodoARN* pPreNode)
{
	this->preNode = pPreNode;
}

void NodoARN::setLeft(NodoARN* pLeft)
{
	this->left = pLeft;
}

void NodoARN::setRight(NodoARN* pRight)
{
	this->right = pRight;
}

Canton* NodoARN::getCanton()
{
	return this->canton;
}

char NodoARN::getColor()
{
	return this->color;
}

NodoARN* NodoARN::getPreNode()
{
	return this->preNode;
}

NodoARN* NodoARN::getLeft()
{
	return this->left;
}

NodoARN* NodoARN::getRight()
{
	return this->right;
}
