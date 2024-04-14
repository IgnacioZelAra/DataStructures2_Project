#pragma once
#include <string>

class Provincia
{
private:
	std::string nombreProvincia;
	std::string idProvincia;
	std::string key;
	//Canton* canton;

public:
	Provincia(std::string nombreProvincia, std::string idProvincia , std:: string key /*,Canton* canton*/ );

	//GETTERS
	std::string getNombreProvincia();
	std::string getIdProvincia();
	std::string getKey();
	//Canton* getCanton();

	//SETTERS
	void setNombreProvincia(std::string );
	void setIdProvincia(std::string);
	void setKey(std::string);
	//void setCanton(Canton*);
};
