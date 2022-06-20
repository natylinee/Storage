//DONE
#pragma once
#include <string>
using namespace std;


class Object
{
protected:
	int idObject = 0;
	string name;
	int idOwner = -1;

public:
	void changeOwner(int newOwnerId);
	void setId(int idObject);
	void setName(string name);
	void setOwnerId(int newOwnerId);
	int getId();
	int getOwnerId();
	string getName();
	//POLIMORFIZM
	//czyste funkcje wirtualne
	virtual void Print() = 0; 
	virtual void PrintToFile(ostream& stream) = 0;
};
