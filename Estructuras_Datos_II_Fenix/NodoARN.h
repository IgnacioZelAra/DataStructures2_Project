#pragma once
#include "Canton.h"
class NodoARN
{
private:
	Canton* canton;
	char color;
	NodoARN* preNode;
	NodoARN* left;
	NodoARN* right;
public:
	NodoARN();
	NodoARN(Canton*);
	~NodoARN();

	/*SETTERS*/
	void setCanton(Canton* pCanton);
	void setColor(char pColor);
	void setPreNode(NodoARN* pPreNode);
	void setLeft(NodoARN* pLeft);
	void setRight(NodoARN* pRight);


	/*GETTERS*/
	Canton* getCanton();
	char getColor();
	NodoARN* getPreNode();
	NodoARN* getLeft();
	NodoARN* getRight();
};

