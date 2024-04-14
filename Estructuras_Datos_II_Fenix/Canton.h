#pragma once
#include <iostream>
#include<string>
using namespace std;

class Canton
{
private:
	string nombreCanton;
	string Provincia;
	string nombreDistritoCabecera;
	int cantidadHabitantes;
	string nombreAlcalde;

public:

	Canton(string, string, string, int, string);

	//GETTERS
	string getNombreCanton();
	string getProvincia();
	string getNombreDistritoCabecera();
	int getCantidadHabitantes();
	string getNombreAlcalde();

	//SETTERS
	void setNombreCanton(string);
	void setProvincia(string);
	void setNombreDistritoCabecera(string);
	void setCantidadHabitantes(int);
	void setNombreAlcalde(string);

};

