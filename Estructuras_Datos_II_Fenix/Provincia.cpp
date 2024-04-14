#include "Provincia.h"


Provincia::Provincia(std::string nombreProvincia, std::string idProvincia , std::string key)
{
    this->nombreProvincia = nombreProvincia;
    this->idProvincia = idProvincia;
    this->key = key;
    
}

std::string Provincia::getNombreProvincia()
{
    return nombreProvincia;
}

std::string Provincia::getIdProvincia()
{
    return idProvincia;
}

std::string Provincia::getKey()
{
    return key;
}

//Canton* Provincia::getCanton()
//{
//    return canton;
//}

void Provincia::setNombreProvincia(std::string nombreProvincia)
{
    this->nombreProvincia = nombreProvincia;
}

void Provincia::setIdProvincia(std::string idProvincia)
{
    this->idProvincia = idProvincia;
}

void Provincia::setKey(std::string key)
{
    this->key = key;
}

//void Provincia::setCanton(Canton* canton)
//{
//    this->canton = canton;
//}


