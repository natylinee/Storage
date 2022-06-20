#include "Equipment.h"
using namespace std;
void Equipment::Print()
{
	cout << "ID: " << this->idObject << ", nazwa: " << this->name << ", specyfikacja: " << this->specification << ", jednostka: " << this->unit ;
}
void Equipment::PrintToFile(ostream& stream)
{
	stream << "ID: " << this->idObject << ", nazwa: " << this->name << ", specyfikacja: " << this->specification << ", jednostka: " << this->unit;
}
void Equipment::setSpecification(string specification)
{
	this->specification = specification;
}
string Equipment::getSpecification()
{
	return specification;
}
void Equipment::setValue(int value)
{
	this->value = value;
}
int Equipment::getValue()
{
	return value;
}
void Equipment::setUnit()
{
	this->unit = unit;
}
string Equipment::getUnit()
{
	return unit;
}