#pragma once
#include "NodoARN.h"
class ARNTree
{
private:
	NodoARN* root;
	NodoARN* b;
public:
	ARNTree();
	~ARNTree();

	/*GETTER*/
	NodoARN* getRoot();
	NodoARN* getB();
	/*SETTER*/
	void setRoot(NodoARN*);
	void setB(NodoARN*);
	/*OPERATIONS*/
	//void insert(NodoARN*);
	NodoARN* insert(NodoARN*);
	void balance(NodoARN*);
	void rightRotate(NodoARN*);
	void leftRotate(NodoARN*);
	void print(NodoARN*);
	Canton* find(string, NodoARN*);
	bool modDistrict(string, string);
	bool modPop(int, string);
	bool modMajor(string, string);
	void consultDistrict(string);
	void consultPop(string);
	void consultMajor(string);
	void consultData(string);
	void showInverseDetailsCanton(ARNTree&, NodoARN*);
	void showDetailsCarton(ARNTree&, NodoARN*);
};

