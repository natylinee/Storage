#include "Furniture.h"

Furniture::Furniture(int idObject, furnitureType type, string name, int idOwner)
{
	this->idObject = idObject;
	this->type = type;
	this->name = name;
	this->idOwner = idOwner;
}

void Furniture::Print()
{
	cout << "ID: " << this->idObject << ", typ: " << furnitureTypeNames[this->type] << ", nazwa: " << this->name;
}

void Furniture::PrintToFile(ostream& stream)
{
	stream << "ID: " << this->idObject << ", typ: " << furnitureTypeNames[this->type] << ", nazwa: " << this->name;
}
