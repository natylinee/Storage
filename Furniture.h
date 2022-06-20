#pragma once
#include "Object.h"
#include<iostream>
using namespace std;
enum furnitureType
{
	none,
	biurko,
	krzeslo,
	lampka,
	szafa
};
const string furnitureTypeNames[] =
{
	"none",
	"biurko",
	"krzeslo",
	"lampka",
	"szafa"
};

class Furniture
	:public Object
{
private:
	enum furnitureType type;
public:
	void Print();
	void PrintToFile(ostream& stream);
	Furniture(int idObject, furnitureType type, string name, int idOwner);

};
