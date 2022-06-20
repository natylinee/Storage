//DONE
#include "Object.h"

void Object::changeOwner(int newOwnerId)
{
	this->idOwner = newOwnerId;
}
// SET
void Object::setId(int idObject)
{
	this->idObject = idObject;
}
void Object::setName(string name)
{
	this->name = name;
}
void Object::setOwnerId(int newOwnerId)
{
	this->idOwner = newOwnerId;
}
//  GET
int Object::getId()
{
	return idObject;
}
int Object::getOwnerId()
{
	return idOwner;
}
string Object::getName()
{
	return name;
}