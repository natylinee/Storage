#include <string>
#include "Worker.h"

using namespace std;

void Worker::Print()
{
	cout << "ID pracownika: " << this->id << ", nazwisko: " << this->lastName << ", dzial: " << this->nameDepartment << ", adres e-mail: " << this->mail;
}
void Worker::PrintToFile(ostream& stream)
{
	stream << "ID pracownika: " << this->id << ", nazwisko: " << this->lastName << ", dzial: " << this->nameDepartment << ", adres e-mail: " << this->mail<< " ";
}
void Worker::setLastName(string lastName)
{
	this->lastName = lastName;
}
string Worker::getLastName()
{
	return lastName;
}
void Worker::setId(int id)
{
	this->id = id;
}
void Worker::setMail(string mail)
{
	this->mail = mail;
}
void Worker::setIsDebtor(bool isDebtor)
{
	this->isDebtor = isDebtor;
}
int Worker::getId()
{
	return id;
}

void Worker::setDepartment(string nameDepartment)
{
	this->nameDepartment = nameDepartment;
}
string Worker::getDepartment()
{
	return nameDepartment;
}

string Worker::getMail()
{
	return mail;
}

bool Worker::getIsDebtor()
{
	return isDebtor;
}


