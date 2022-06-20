#pragma once
#include "Object.h"
#include<iostream>
#include<vector>
using namespace std;
class Worker
	:public Object
{
protected:
	string lastName;
	int id;
	string nameDepartment;
	string mail;
	bool isDebtor; // domyslnie false

public:
	//constructors
	Worker(int id, string lastName, string nameDepartment, string mail, bool isDebtor)
		:id(id), lastName(lastName), nameDepartment(nameDepartment), mail(mail), isDebtor(isDebtor) {}
	void Print();
	void PrintToFile(ostream& stream);
	void setDepartment(string nameDepartment);
	void setLastName(string lastName);
	void setId(int id);
	void setMail(string mail);
	void setIsDebtor(bool isDebtor);
	int getId();
	string getLastName();
	string getDepartment();
	string getMail();
	bool getIsDebtor();

	//operator przeciazony 
	friend ostream& operator<<(ostream& os, const Worker& dt)
	{
		os << dt.id << '/' << dt.lastName << '/' << dt.nameDepartment << '/' << dt.mail;
		return os;
	}
	//nie czulam potrzeby wykorzystac go w projekcie, ale powyzsza funkcja opisuje jego dzialanie

};