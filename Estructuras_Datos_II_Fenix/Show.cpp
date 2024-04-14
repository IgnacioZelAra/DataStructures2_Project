#include "ARNTree.h"

ARNTree::ARNTree()
{
	root = NULL;
	b = NULL;
}

ARNTree::~ARNTree()
{
}

NodoARN* ARNTree::getRoot()
{
	return this->root;
}

void ARNTree::setRoot(NodoARN* root)
{
	root->setPreNode(NULL);
	this->root = root;
}

NodoARN* ARNTree::insert(NodoARN* node)
{	
	NodoARN* insertedNode = NULL;

	if (this->getRoot() == NULL) {
		node->setColor('n');
		this->setRoot(node);
		this->getRoot()->setPreNode(NULL);
		insertedNode = this->getRoot();
	}
	else {
		NodoARN* aux = getRoot();
		while (aux != NULL) {
			b = aux;
			if (aux->getCanton()->getNombreCanton() < node->getCanton()->getNombreCanton()) {
				aux = aux->getRight();
			}
			else {
				aux = aux->getLeft();
			}
		}

		node->setPreNode(b);

		if (b->getCanton()->getNombreCanton() < node->getCanton()->getNombreCanton())
		{
			b->setRight(node);
			insertedNode = b->getRight();
		}
		else {
			b->setLeft(node);
			insertedNode = b->getLeft();
		}
		balance(node);
	}

	return insertedNode;
}

//NodoARN* ARNTree::insert(NodoARN* node)
//{	
//	NodoARN* insertedNode = NULL;  
//
//	if (this->getRoot() == NULL) {
//		this->setRoot(node);
//		this->getRoot()->setPreNode(NULL);
//		insertedNode = this->getRoot();  
//	}
//	else {
//		NodoARN* aux = getRoot();
//		NodoARN* b = NULL;  
//
//		while (aux != NULL) {
//			b = aux;
//			if (aux->getCanton()->getNombreCanton() < node->getCanton()->getNombreCanton()) {
//				aux = aux->getRight();
//			}
//			else {
//				aux = aux->getLeft();
//			}
//		}
//
//		node->setPreNode(b);
//
//		if (b->getCanton()->getNombreCanton() < node->getCanton()->getNombreCanton())
//		{
//			b->setRight(node);
//			insertedNode = b->getRight();
//		}
//		else {
//			b->setLeft(node);
//			insertedNode = b->getLeft();  
//		}
//	}
//
//	balance(node);
//	//cout << "insertado" + insertedNode->getCanton()->getNombreCanton() << "\n  ";
//	return insertedNode;  // Return the pointer to the just inserted node
//}


void ARNTree::balance(NodoARN* node)
{
	NodoARN* u;
	while (node->getPreNode()->getColor() == 'r') {
		if (node->getPreNode()->getPreNode() != NULL && node->getPreNode() == node->getPreNode()->getPreNode()->getRight()) {
			u = node->getPreNode()->getPreNode()->getLeft();
			if (u != NULL && u->getColor() == 'r') {
				u->setColor('n');
				node->getPreNode()->setColor('r');
				node->getPreNode()->getPreNode()->setColor('r');
				node = node->getPreNode()->getPreNode();
			}
			else {
				if (node == node->getPreNode()->getLeft()) {
					node = node->getPreNode();
					rightRotate(node);
				}
				node->getPreNode()->setColor('n');
				node->getPreNode()->getPreNode()->setColor('r');
				leftRotate(node->getPreNode()->getPreNode());
			}
		}else {
			u = node->getPreNode()->getPreNode()->getRight();

			if (u != NULL && u->getColor() == 'r') {
				u->setColor('n');
				node->getPreNode()->setColor('n');
				node->getPreNode()->getPreNode()->setColor('r');
				node = node->getPreNode()->getPreNode();
			}
			else {
				if (node == node->getPreNode()->getRight()) {
					node = node->getPreNode();
					leftRotate(node);
				}
				node->getPreNode()->setColor('n');
				node->getPreNode()->getPreNode()->setColor('r');
				rightRotate(node->getPreNode()->getPreNode());
			}
		}
		if (node == this->getRoot()){
			break;
		}
	}
	this->getRoot()->setColor('n');
}

void ARNTree::rightRotate(NodoARN* node)
{
	if (node->getLeft() == NULL) {
		return;
	}
	else {
		NodoARN* temp = node->getLeft();
		if (temp->getRight() != NULL) {
			node->setLeft(temp->getLeft());
			temp->getRight()->setPreNode(node);
		}
		else {
			node->setLeft(NULL);
		}

		if (node->getPreNode() != NULL) {
			temp->setPreNode(node->getPreNode());
		}
		if (node->getPreNode() == NULL)
		{
			setRoot(temp);
			getRoot()->setPreNode(NULL);
		}
		else {
			if (node == node->getPreNode()->getLeft()) {
				node->getPreNode()->setLeft(temp);
			}
			else {
				node->getPreNode()->setRight(temp);
			}
		}
		temp->setRight(node);
		node->setPreNode(temp);
	}
}

void ARNTree::leftRotate(NodoARN* node)
{
	if (node->getRight() == NULL) {
		return;
	}
	else {
		NodoARN* temp = node->getRight();
		if (temp->getLeft() != NULL) {
			node->setRight(temp->getLeft());
			temp->getLeft()->setPreNode(node);
		}
		else {
			node->setRight(NULL);
		}

		if (node->getPreNode() != NULL) {
			temp->setPreNode(node->getPreNode());
		}
		if (node->getPreNode() == NULL)
		{
			setRoot(temp);
			getRoot()->setPreNode(NULL);
		}
		else {
			if (node == node->getPreNode()->getLeft()) {
				node->getPreNode()->setLeft(temp);
			}
			else {
				node->getPreNode()->setRight(temp);
			}
		}
		temp->setLeft(node);
		node->setPreNode(temp);
	}
	
}

void ARNTree::print(NodoARN* node)
{

	cout << "Imprimi Algo";
		if (getRoot() == NULL) {
			cout << "\n El arbol esta vacio.";
		}
		else {
			cout << "\n Nodo:";
			cout << "\n Canton: " << node->getCanton()->getNombreCanton();
			cout << "\n Color: " << node->getColor();

			if (node->getPreNode() != NULL)
			{
				cout << "\n Nodo anterior: " << node->getPreNode()->getCanton()->getNombreCanton();
			}
			else {
				cout << "\n Esta es la raiz.";
			}

			if (node->getLeft() != NULL) {
				cout << "\n Canton del Nodo izq: " << node->getLeft()->getCanton()->getNombreCanton();
			}

			if (node->getRight() != NULL) {
				cout << "\n Canton del Nodo der: " << node->getRight()->getCanton()->getNombreCanton();
			}

			cout << endl;

			if (node->getLeft()) {
				cout << "\n Izq: ";
				print(node->getLeft());
			}

			if (node->getRight()) {
				cout << "\n Der: ";
				print(node->getRight());
			}
		}

}

Canton* ARNTree::find(string nCanton, NodoARN* node)
{
	if (node == NULL || nCanton == node->getCanton()->getNombreCanton()) {
		return node->getCanton();
	}

	if (nCanton < node->getCanton()->getNombreCanton()) {
		return find(nCanton, node->getLeft());
	}
	return find(nCanton, node->getRight());
}

bool ARNTree::modDistrict(string newName, string nCanton)
{
	Canton* aux = find(nCanton, this->getRoot());

	if (aux != NULL){
		aux->setNombreDistritoCabecera(newName);
		return true;
	}

	return false;
}

bool ARNTree::modPop(int newPop, string nCanton)
{
	Canton* aux = find(nCanton, this->getRoot());

	if (aux != NULL){
		aux->setCantidadHabitantes(newPop);
		return true;
	}

	return false;
}

bool ARNTree::modMajor(string newMajor, string nCanton){
	Canton* aux = find(nCanton, this->getRoot());

	if (aux != NULL) {
		aux->setNombreAlcalde(newMajor);
		return true;
	}

	return false;
}

void ARNTree::consultDistrict(string nCanton)
{
	Canton* aux = find(nCanton, this->getRoot());

	if (aux != NULL) {
		cout << "El nombre del distrio cabecera de "<< nCanton << " es:" << aux->getNombreDistritoCabecera();
		return;
	}

	cout << "No se pudo consultar.";
}

void ARNTree::consultPop(string nCanton)
{
	Canton* aux = find(nCanton, this->getRoot());

	if (aux != NULL) {
		cout << "La cantidad de habitantes del " << nCanton << " es:" << aux->getCantidadHabitantes();
		return;
	}

	cout << "No se pudo consultar.";
}

void ARNTree::consultMajor(string nCanton)
{
	Canton* aux = find(nCanton, this->getRoot());

	if (aux != NULL) {
		cout << "El nombre del alcalde de " << nCanton << " es:" << aux->getNombreAlcalde();
		return;
	}

	cout << "No se pudo consultar.";
}

void ARNTree::consultData(string nCanton)
{
	Canton* aux = find(nCanton, this->getRoot());

	if (aux != NULL) {
		cout << "Nombre: " << aux->getNombreCanton() << "\n";
		cout << "Provincia: " << aux->getProvincia() << "\n";
		consultDistrict(nCanton); 
		cout << "\n";
		consultPop(nCanton);
		cout << "\n";
		consultMajor(nCanton);
		cout << "\n";
		return;
	}



	cout << "No se pudo consultar.";
}


///Parte 5
void showDetailsCarton(ARNTree& arnTree, NodoARN* node)
{
    if (node != nullptr)
    {
        showDetailsCarton(arnTree, node->getLeft());

        Canton* canton = node->getCanton(); 

        // Mostrar los detalles del cantón
        std::cout << "Nombre Cantón: " << canton->getNombreCanton() << std::endl;
        std::cout << "Provincia: " << canton->getProvincia() << std::endl;
        std::cout << "Distrito Cabecera: " << canton->getNombreDistritoCabecera() << std::endl;
        std::cout << "Cantidad de Habitantes: " << canton->getCantidadHabitantes() << std::endl;
        std::cout << "Nombre del Alcalde: " << canton->getNombreAlcalde() << std::endl;
        std::cout << "---------------------" << std::endl;

        showDetailsCarton(arnTree, node->getRight());
    }
}


//Parte 6

void showInverseDetailsCanton(ARNTree& arnTree, NodoARN* node){
    if (node != nullptr)
    {
        showInverseDetailsCanton(arnTree, node->getRight());

        Canton* canton = node->getCanton(); 

        // Mostrar los detalles del cantón
        std::cout << "Nombre Cantón: " << canton->getNombreCanton() << std::endl;
        std::cout << "Provincia: " << canton->getProvincia() << std::endl;
        std::cout << "Distrito Cabecera: " << canton->getNombreDistritoCabecera() << std::endl;
        std::cout << "Cantidad de Habitantes: " << canton->getCantidadHabitantes() << std::endl;
        std::cout << "Nombre del Alcalde: " << canton->getNombreAlcalde() << std::endl;
        std::cout << "---------------------" << std::endl;

        showInverseDetailsCanton(arnTree, node->getLeft());
    }
}


