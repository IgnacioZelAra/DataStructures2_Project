#include "Canton.h"
#include<string>
using namespace std;

Canton::Canton(string nombre, string provincia, string distrito, int habitantes, string alcalde)
{
    this->nombreCanton = nombre;
    this->Provincia = provincia;
    this->nombreDistritoCabecera = distrito;
    this->cantidadHabitantes = habitantes;
    this->nombreAlcalde = alcalde;
}

std::string Canton::getNombreCanton()
{
    return this->nombreCanton;
}

string Canton::getProvincia()
{
    return this->Provincia;
}

std::string Canton::getNombreDistritoCabecera()
{
    return this->nombreDistritoCabecera;
}

int Canton::getCantidadHabitantes()
{
    return this->cantidadHabitantes;
}

std::string Canton::getNombreAlcalde()
{
    return this->nombreAlcalde;
}

void Canton::setNombreCanton(string pNombreCanton)
{
    this->nombreCanton = pNombreCanton;
}

void Canton::setProvincia(string pProvincia)
{
    this->Provincia = pProvincia;
}

void Canton::setNombreDistritoCabecera(string pNombreDistrito)
{
    this->nombreDistritoCabecera = pNombreDistrito;
}

void Canton::setCantidadHabitantes(int pCantidadHabitantes)
{
    this->cantidadHabitantes = pCantidadHabitantes;
}

void Canton::setNombreAlcalde(string pNombreAlcalde)
{
    this->nombreAlcalde = pNombreAlcalde;
}
