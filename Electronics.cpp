#include "Electronics.h"

using namespace std;
void Electronics::Print()
{
	cout << "ID: "<< this->idObject << ", nazwa: " << this->name << ", marka: " << this->brand;
}
void Electronics::PrintToFile(ostream& stream)
{
	stream << "ID: " << this->idObject << ", nazwa: " << this->name << ", marka: " << this->brand;
}
void Electronics::setBrand(string brand)
{
	this->brand = brand;
}
string Electronics::getBrand()
{
	return brand;
}
