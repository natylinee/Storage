#pragma once
#include "Object.h"
#include <iostream>
using namespace std;
class Electronics
	:public Object
{
protected:
	string brand;
public:
	//constructor
	Electronics(int idObject, string name, string brand, int idOwner)
	{
		this->idObject = idObject;
		this->name = name;
		this->brand = brand;
		this->idOwner = idOwner;
	}
	void Print();
	void PrintToFile(ostream& stream);
	void setBrand(string brand);
	string getBrand();
};
