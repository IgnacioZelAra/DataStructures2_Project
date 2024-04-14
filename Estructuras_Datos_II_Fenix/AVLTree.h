#pragma once
# include "NodoAVL.h"
class AVLTree
{
private:
	NodoAVL* root;

public:
	AVLTree();
	~AVLTree();

	/*GETTER*/
	NodoAVL* getRoot();
	/*SETTER*/
	void setRoot(NodoAVL*);
	/*OPERATIONS*/
	int height(NodoAVL* r);
	int getBalanceFactor(NodoAVL* n);
	NodoAVL* rightRotate(NodoAVL* y);
	NodoAVL* leftRotate(NodoAVL* x);
	NodoAVL* insert(NodoAVL*, NodoAVL*);
	void print2D(NodoAVL* r);
	int consultQuantCanton(string nProvincia, NodoAVL* node);
	int consultPop(string nProvincia, NodoAVL* node);
};

