#pragma once
#include "Equipment.h"
#include "Furniture.h"
#include"Electronics.h"
#include "Worker.h"
#include "Object.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include<filesystem>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include<regex>
#include<thread>
#include<future>

using namespace std;
namespace fs = filesystem;
class Storage
{
private:
	//structures
	vector<shared_ptr<Worker>> listWorkers;
	vector<shared_ptr<Object>> listObjects;
	
	
	//init 
	//bool initWorkers(const string& nameFileWorkers);
	bool initFurniture(const string& nameFileFurniture);
	bool initElectronics(const string& nameFileElectronics);
	bool initEquipment(const string& nameFileEquipment);
protected:
	int countObjects = 0; //liczba id obiektów
	int countWorkers = 0; //liczba id pracownikow
	
public:
	//descructor
	~Storage();

	bool initWorkers(const string& nameFileWorkers);
	void showMenu();
	void getObjectToStore(int objectId);
	void DeleteWorker(int workerId);
	void addFurniture(int idObject, furnitureType type, string name, int idOwner);
	void addEquipment(int idObject, string name, string specification, int value, string unit, int idOwner);
	void addElectronics(int idObject, string name, string brand, int idOwner);
	shared_ptr<Worker> findWorkerWithId(int workerId);
	//stare
	//Worker* findWorkerWithId(int workerId);
	void printWorkerWithId(int workerId);
	void PrintObjectWithId(int objectId);
	void changeObjectOwner(int objectId, int newOwnerId);
	bool init(string nameFileWorkers, string nameFileFurniture, string nameFileElectronics, string nameFileEquipment);
	//bool initObjects(string nameFileFurniture, string nameFileElectronics, string nameFileEquipment);
	void ShowAll();
	void PrintToFile(const string& fileName);

	bool mailCorrect(string mail);
	void showDebtors(); //z listy pracownikow pokaz tych, ktorzy isDebtor=1
};
