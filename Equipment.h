#pragma once
#include "Object.h"
#include<iostream>

using namespace std;
class Equipment
	:public Object
{
	string specification;
	int value;
	string unit;
public:
	//constructors

	Equipment(int idObject, string name, string specification, int value, string unit, int idOwner)
	{
		this->idObject = idObject;
		this->name = name;
		this->specification = specification;
		this->value = value;
		this->unit = unit;
		this->idOwner = idOwner;

	};
	void Print();
	void PrintToFile(ostream& stream);
	void setSpecification(string specification);
	void setUnit();
	void setValue(int value);
	string getSpecification();
	int getValue();
	string getUnit();
};