
    #include <string>
    #include <stdlib.h>
    #include <fstream>
    #include <sstream>
    #include <cctype>
    #include <iostream>
    #include "AVLTree.h"
    #include "ARNTree.h"
    #include "Provincia.h"
    #include "Canton.h"
    #include "NodoAVL.h"
    #include "NodoARN.h"
    using namespace std;

    AVLTree avlTree;
    ARNTree arnTree;


    std::string removeSpaces(std::string str) {
        std::string result = str;

        result.erase(result.begin(), std::find_if(result.begin(), result.end(), [](unsigned char ch) { return !std::isspace(ch); }));
        result.erase(std::find_if(result.rbegin(), result.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(), result.end());
        result.erase(std::remove_if(result.begin(), result.end(), [](unsigned char ch) { return std::isspace(ch); }), result.end());

        return result;
    }


   void loadData() {
        std::ifstream inputFile("data_all.txt");

        std::string idProvincia, provinciaName, nombreCanton, 
            ciudadCabecera, habitantes, nombreAlcalde;
        std::string line;
        if (inputFile.is_open()) {
            while (getline(inputFile, line)) {
                int i;
                stringstream ss(line);
                getline(ss, idProvincia, ',');
                getline(ss, provinciaName, ',');
                getline(ss, nombreCanton, ',');
                getline(ss, ciudadCabecera, ',');
                getline(ss, habitantes, ',');
                getline(ss, nombreAlcalde, ',');
                istringstream(habitantes) >> i;
                Canton* canton = new Canton(nombreCanton, provinciaName, ciudadCabecera, i, nombreAlcalde);
                NodoARN* nodoARN = new NodoARN(canton);
                //arnTree.insert(nodoARN);
                NodoARN* dir = arnTree.insert(nodoARN);
                string key = nombreCanton + provinciaName;
                Provincia* provincia = new Provincia(provinciaName, idProvincia, key);
                NodoAVL* nodoAvl = new NodoAVL(provincia);
                //  nodoAvl->setNodoARN(dir);
                nodoAvl->setNodoARN(dir);

                avlTree.setRoot(avlTree.insert(avlTree.getRoot(), nodoAvl));
            }
            inputFile.close();

        }
    }


   void menu() {
       loadData();
       bool cont = true;
       int opc;

       while (cont){
           cout << "Menu\n";
           cout << "---Opciones de Canton--- \n";
           cout << "1. Modificar Distrito Cabecera \n";
           cout << "2. Modificar Cantidad de Habitantes \n";
           cout << "3. Modificar Nombre del Alcalde \n";
           cout << "4. Consultar Nombre de Distirito Cabecera \n";
           cout << "5. Consultar Cantidad de Habitantes \n";
           cout << "6. Consultar Nombre del Alcalde \n";
           cout << "7. Mostrar Dettalles de todos los Cantones \n";
           cout << "---Opciones de Provincia--- \n";
           cout << "10. Consultar Cantidad de Cantones en una Provincia \n";
           cout << "11. Consultar Numero de Poblacion de una Provincia \n";
           cout << "Escriba la opcion:";
           cin >> opc;
           switch (opc) {
                case 1:{
                    string dist, cant;
                    cout << "Select the town: ";
                    cin >> cant;
                    cout << "write the new disctrict: ";
                    cin >> dist;
                    arnTree.modDistrict(dist, cant);
                    break;
                }
                case 2: {
                    string cant;
                    int pop;
                    cout << "Write the population: ";
                    cin >> pop;
                    cout << "Select the town: ";
                    cin >> cant;
                    arnTree.modPop(pop, cant);
                    break;
                } 
                case 3:{
                    string major, cant;
                    cout << "Select the town: ";
                    cin >> cant;
                    cout << "write the new major";
                    cin >> major;
                  arnTree.modMajor(major, cant);
                    break;
                }
                case 4:{
                    string cant;
                    cout << "Select the town: ";
                    cin >> cant;
                    arnTree.consultDistrict(cant);
                    break;
                }
                case 5: {
                    string cant;
                    cout << "Select the town: ";
                    cin >> cant;
                    arnTree.consultPop(cant);
                    break;
                }
                case 6: {
                    string town;
                    cout << "Select the town: ";
                    cin >> town;
                    arnTree.consultMajor(town);
                    break;
                }
                case 7: {
                    arnTree.print(arnTree.getRoot());
                }
                case 8: {
                    arnTree.showDetailsCarton(arnTree, arnTree.getRoot());
                }
                case 9: {
                    arnTree.showInverseDetailsCanton(arnTree, arnTree.getRoot());
                }
                case 10: {
                    string town;
                    cout << "Select the town: ";
                    cin >> town;
                    cout << avlTree.consultQuantCanton(town, avlTree.getRoot());
                }
                case 11: {
                    string town;
                    cout << "Select the town: ";
                    cin >> town;
                    cout << avlTree.consultPop(town, avlTree.getRoot());
                }
                default:
                    opc = false;
                    break;
           }
           cout << "\n\n";
           system("pause");
           system("cls");
       }
       
   }

   int main()
   {  
       menu();

        return 0;
    }


