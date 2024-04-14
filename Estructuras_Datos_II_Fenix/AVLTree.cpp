#include "AVLTree.h"
#include<iostream>
#define SPACE 15
using namespace std;

AVLTree::AVLTree() {
	this->root = NULL;
}

AVLTree::~AVLTree()
{
}

NodoAVL* AVLTree::getRoot()
{
	return this->root;
}

void AVLTree::setRoot(NodoAVL* ptr)
{
	this->root = ptr;
}

int AVLTree::height(NodoAVL* r)
{
	if (r == NULL)
		return -1;
	else {

		int lheight = height(r->getLeft());
		int rheight = height(r->getRight());

		if (lheight > rheight)
			return (lheight + 1);
		else return (rheight + 1);
	}
}

int AVLTree::getBalanceFactor(NodoAVL* n)
{
	if (n == NULL)
		return -1;
	return height(n->getLeft()) - height(n->getRight());
}

NodoAVL* AVLTree::rightRotate(NodoAVL* y)
{
	NodoAVL* x = y->getLeft();
	NodoAVL* T2 = x->getRight();

	// Perform rotation  
	x->setRight(y);
	y->setLeft(T2);

	return x;
}

NodoAVL* AVLTree::leftRotate(NodoAVL* x)
{
	NodoAVL* y = x->getRight();
	NodoAVL* T2 = y->getLeft();

	// Perform rotation  
	y->setLeft(x);
	x->setRight(T2);

	return y;
}

NodoAVL* AVLTree::insert(NodoAVL* r, NodoAVL* newNode)
{
	if (r == NULL)
		return newNode;

	//INSERTA A LA IZQUIERDA
	if (newNode->getProvincia()->getKey() < r->getProvincia()->getKey()) {

		r->setLeft(insert(r->getLeft(), newNode));

	}
	//INSERTA A LA IZQUIERDA
	else if (newNode->getProvincia()->getKey() > r->getProvincia()->getKey()) {

		r->setRight(insert(r->getRight(), newNode));
	}
	else {
		//cout << "No duplicate values allowed!" << endl;
		return r;
	}

	int bf = getBalanceFactor(r);

	// Left Left Case  
	if (bf > 1 && newNode->getProvincia()->getKey() < r->getLeft()->getProvincia()->getKey())
		return rightRotate(r);

	// Right Right Case  
	if (bf < -1 && newNode->getProvincia()->getKey() > r->getRight()->getProvincia()->getKey())
		return leftRotate(r);

	// Left Right Case  
	if (bf > 1 && newNode->getProvincia()->getKey() > r->getLeft()->getProvincia()->getKey())
	{
		r->setLeft(leftRotate(r->getLeft()));
		return rightRotate(r);
	}

	// Right Left Case  
	if (bf < -1 && newNode->getProvincia()->getKey() < r->getRight()->getProvincia()->getKey())
	{
		r->setRight(rightRotate(r->getRight()));
		return leftRotate(r);
	}

	/* return the (unchanged) node pointer */
	return r;
}

void AVLTree::print2D(NodoAVL* r)
{
	if (r == NULL) // Base case  1
	{
		return;
	}
	// Increase distance between levels   2
	print2D(r->getRight()); // Process right child first 3 
	cout << endl;
	cout << r->getProvincia()->getKey() << "\n"; // 6
	print2D(r->getLeft()); // Process left child  7
}


int AVLTree::consultQuantCanton(string nProvincia, NodoAVL* node)
{
	if (node != NULL)
	{
		if (node->getProvincia()->getNombreProvincia() == nProvincia){
			return 1;
		}else {
			return consultQuantCanton(nProvincia, node->getLeft()) + consultQuantCanton(nProvincia, node->getRight());
		}
	}else {
		return 0;
	}
}





int AVLTree::consultPop(string nProvincia, NodoAVL* node){
	if (node != NULL)
	{
		if (node->getProvincia()->getNombreProvincia() == nProvincia) {
			return node->getNodoARN()->getCanton()->getCantidadHabitantes();
		}else {
			return consultPop(nProvincia, node->getLeft()) + consultPop(nProvincia, node->getRight());
		}
	}
	else {
		return 0;
	}
}
