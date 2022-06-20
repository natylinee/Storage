#include "Storage.h"



void Storage::printWorkerWithId(int workerId)
{
	shared_ptr<Worker> found = findWorkerWithId(workerId);
	if (found != nullptr)
	{
		found->Print();
	}
	else
	{
		cout << "Brak pracownika o takim id" << endl;
	}
}

void Storage::PrintObjectWithId(int objectId)
{
	for (int i = 0; i < this->listObjects.size(); i++)
	{
		if (listObjects[i]->getId() == objectId)
		{
			listObjects[i]->Print();
			if (listObjects[i]->getOwnerId() == -1)
			{
				cout << " w magazynie" << endl;
			}
			else
			{
				auto worker = findWorkerWithId(listObjects[i]->getOwnerId());
				if (worker)
				{
					cout << " ";
					worker->Print();
				}

			}
			return;
		}
	}
	cout << "Nie znaleziono przedmiotu o takim id" << endl;
}

void Storage::changeObjectOwner(int objectId, int newOwnerId)
{
	for (auto object : this->listObjects)
	{
		if (object->getId() == objectId)
		{
			//sprawdzic czy istnieje worker o takim id
			shared_ptr<Worker> found = this->findWorkerWithId(newOwnerId);
			
			if (found != nullptr)//istnieje taki
			{
				object->setOwnerId(newOwnerId);
			}
			else // nie istnieje pracownik o takim id
			{
				cout << "Nie istnieje pracownik o takim id" << endl;
			}

			return;
		}
	}
}

//INIT BLOCK//
bool Storage::init(string nameFileWorkers, string nameFileFurniture, string nameFileElectronics, string nameFileEquipment)
{
	try
	{
		// bez watkow
		this->initWorkers(nameFileWorkers);
		this->initFurniture(nameFileFurniture);
		this->initElectronics(nameFileElectronics);
		this->initEquipment(nameFileEquipment);


		 //wczytywanie danych za pomoca watkow 
		//thread thr1(&Storage::initWorkers, this, nameFileWorkers);
		//thread thr2(&Storage::initObjects, this, nameFileFurniture,nameFileElectronics,nameFileEquipment);
		
		/*thread thr1(&Storage::initWorkers,nameFileWorkers);
		thread thr2(&Storage::initObjects, nameFileFurniture, nameFileElectronics, nameFileEquipment);

		thr1.join();
		thr2.join();*/

		//async
		//auto f1=async(&Storage::initWorkers, this, nameFileWorkers);
		//auto f2 = async(&Storage::initFurniture, this, nameFileFurniture);
		//auto f3 = async(&Storage::initElectronics, this, nameFileElectronics);
		//auto f4 = async(&Storage::initEquipment, this, nameFileEquipment);

		//auto res1 = f1.get();
		//auto res2 = f2.get();
		//auto res3 = f3.get();
		//auto res4 = f4.get();

	}
	catch (const char* e) //OR case (std::exception& e)
	{
		cout << "Initiation of data went wrong." << endl;
		return false;
	}
	return true;
}

bool Storage::initWorkers(const string& nameFileWorkers)
{
	fs::path pth = fs::current_path();
	cout << pth << endl;
	pth /= "pliki_txt";
	pth.append("Workers.txt");
	cout << pth << endl;
	
	ifstream file(pth);
	if (file.good())
	{
		string line;
		while (getline(file, line))
		{
			stringstream ss(line);
			string lastName;
			int id;
			string nameDepartment;
			string mail;
			bool isDebtor;
			ss >> id;
			ss >> lastName;
			ss >> nameDepartment;
			ss >> mail;
			ss >> isDebtor;
			//SPRAWD CZY GIT
			if (mailCorrect(mail)) 
			{
				this->listWorkers.push_back(shared_ptr <Worker>(new Worker(id, lastName, nameDepartment, mail, isDebtor)));
				countWorkers++;
			}
			else
			{
				cout << "Niepoprawny format maila pracownika " << lastName << " id " << id << " Nie wczytano do bazy." << endl;
			}
		}
		file.close();
	}
	else
	{
		cout << "Initiation of Workers went wrong.";
		return false;
	}
	return true;
}

bool Storage::initFurniture(const string& nameFileFurniture)
{
	fs::path pth = fs::current_path();
	cout << pth << endl;
	pth /= "pliki_txt";
	pth.append("Furniture.txt");
	cout << pth << endl;

	ifstream file(pth);
	if (file.good())
	{
		string line;
		int x = 0;
		furnitureType type = none;
		while (getline(file, line))
		{
			stringstream ss(line);
			int idObject;
			const string furnitureTypeNames;
			string name;
			int idOwner;
			ss >> idObject;
			ss >> x;
			ss >> name;
			ss >> idOwner;
			//SPRAWD CZY GIT
			this->listObjects.push_back(shared_ptr <Object>(new Furniture(idObject, furnitureType(x), name, idOwner)));
			countObjects++;
		}
		file.close();
	}
	else
	{
		cout << "Initiation of Furniture went wrong.";
		return false;
	}
	return true;
}

bool Storage::initElectronics(const string& nameFileElectronics)
{
	fs::path pth = fs::current_path();
	cout << pth << endl;
	pth /= "pliki_txt";
	pth.append("Electronics.txt");
	cout << pth << endl;

	ifstream file(pth);
	if (file.good())
	{
		string line;
		while (getline(file, line))
		{
			stringstream ss(line);
			int idObject;
			string name;
			string brand;
			int idOwner;
			ss >> idObject;
			ss >> name;
			ss >> brand;
			ss >> idOwner;
			//SPRAWD CZY GIT
			this->listObjects.push_back(shared_ptr <Object>(new Electronics(idObject, name, brand, idOwner)));
			countObjects++;
		}
		file.close();
	}
	else
	{
		cout << "Initiation of Electronics went wrong.";
		return false;
	}
	return true;
}

bool Storage::initEquipment(const string& nameFileEquipment)
{
	
	fs::path pth = fs::current_path();
	cout << pth << endl;
	pth /= "pliki_txt";
	pth.append("Equipment.txt");
	cout << pth << endl;
	
	ifstream file(pth);
	if (file.good())
	{
		string line;
		while (getline(file, line))
		{
			stringstream ss(line);
			int idObject;
			string name;
			string specification;
			int value;
			string unit;
			int idOwner;
			ss >> idObject;
			ss >> name;
			ss >> specification;
			ss >> value;
			ss >> unit;
			ss >> idOwner;
			//SPRAWD CZY GIT
			this->listObjects.push_back( shared_ptr <Object> (new Equipment(idObject, name, specification, value, unit, idOwner))); 
			countObjects++;
		}
		file.close();
	}
	else
	{
		cout << "Initiation of Equipment went wrong.";
		return false;
	}
	return true;
}

//bool Storage::initObjects(string nameFileFurniture, string nameFileElectronics, string nameFileEquipment)
//{
//	try
//	{
//		// bez watkow
//		this->initFurniture(nameFileFurniture);
//		this->initElectronics(nameFileElectronics);
//		this->initEquipment(nameFileEquipment);
//	}
//	catch (const char* e) //OR case (std::exception& e)
//	{
//		cout << "Initiation of data went wrong." << endl;
//		return false;
//	}
//	return true;
//}

void Storage::ShowAll()
{
	cout << "PRACOWNICY" << endl;
	cout << "------------------------------------------------------------------------------------" << endl;
	for (auto& worker : this->listWorkers)
	{
		worker->Print();
		cout << endl;
	}
	cout << endl << endl;


	cout << "PRZEDMIOTY" << endl;
	cout << "------------------------------------------------------------------------------------" << endl;
	for (auto& object : this->listObjects)
	{
		object->Print();
		if (object->getOwnerId() == -1)
		{
			cout << ", stan: w magazynie, przedmiot przypisany do pracownika - brak" << endl;
		}
		else
		{
			cout << ", przedmiot przypisany do pracownika - ";
			(findWorkerWithId(object->getOwnerId()))->Print();
			cout << endl;
		}
	}

}

void Storage::showMenu()
{
	while (true)
	{
		cout << endl << "MENU" << endl;
		cout << "Wybierz opcje: " << endl;
		cout << "1. Szukaj przedmiotu po id. " << endl;
		cout << "2. Usun pracownika z bazy. " << endl;
		cout << "3. Dodaj przedmiot. " << endl;
		cout << "4. Przepisz przedmiot na innego pracownika./ Przypisz przedmiot. " << endl;
		cout << "5. Powroc przedmiot do magazynu. " << endl;
		cout << "6. Wyswietl liste dluznikow. " << endl;
		cout << "7. Wypisz aktualny wykaz sprzetu w konsoli. " << endl;
		cout << "8. Wydrukuj aktualny wykaz sprzetu w pliku wyjsciowym. " << endl;
		cout << "9. Koniec programu. " << endl;
		cout << "Wprowadz odpowiednia liczbe: ";
		int number;
		cin >> number;
		int identificator;
		int identificator1;
		int identificator2;
		int identificator3;

		switch (number)
		{
		case 1:
		{
			cout << "Podaj id przedmiotu: ";
			cin >> identificator;
			this->PrintObjectWithId(identificator);
			break;
		}
		case 2:
		{
			cout << "Podaj id pracownika, ktorego chcesz usunac: ";
			cin >> identificator;

			this->DeleteWorker(identificator);
			countWorkers--;
			break;
		}

		case 3:
		{
			cout << "Podaj kategorie: " << endl;
			cout << "Meble - 1 " << endl << "Elektronika - 2" << endl << "Przyrzady - 3" << endl;
			cin >> identificator;

			if (identificator == 1)
			{
				string name;
				furnitureType type = none;
				cout << "Obiekt zostanie dodany do magazynu." << endl;
				cout << "Id zostanie nadane automatycznie. " << endl;
				cout << "Podaj dane mebla: " << endl;
				cout << " id: ";
				identificator1 = listObjects.size() + 1;
				cout << identificator1;

				cout << " typ: " << endl << "[1] biurko, [2] krzeslo, [3] lampka, [4] szafa" << endl;
				cin >> identificator2;
				cout << " nazwa: ";
				cin >> name;
				identificator3 = -1;

				addFurniture(identificator1, furnitureType(identificator2), name, identificator3);
				countObjects++;
				break;
			}

			if (identificator == 2)
			{
				string name, brand;
				cout << "Obiekt zostanie dodany do magazynu." << endl;
				cout << "Id zostanie nadane automatycznie. " << endl;
				cout << "Podaj dane sprzetu: " << endl;
				cout << " id: ";
				identificator1 = listObjects.size() + 1;
				cout << identificator1;

				cout << " nazwa: ";
				cin >> name;
				cout << " marka: ";
				cin >> brand;
				identificator2 = -1;
				addElectronics(identificator1, name, brand, identificator2);
				countObjects++;
				break;
			}

			if (identificator == 3)
			{
				string name, specification, unit;
				cout << "Obiekt zostanie dodany do magazynu." << endl;
				cout << "Id zostanie nadane automatycznie. " << endl;
				cout << "Podaj dane przyrzadu: " << endl;
				cout << " id: ";
				identificator1 = listObjects.size() + 1;
				cout << identificator1;

				cout << " nazwa: ";
				cin >> name;
				cout << " specyfikacja: ";
				cin >> specification;
				cout << " wartosc: ";
				cin >> identificator2;
				cout << " jednostka: ";
				cin >> unit;
				identificator3 = -1;
				addEquipment(identificator1, name, specification, identificator2, unit, identificator3);
				countObjects++;
				break;
			}

			else
			{
				cout << "Wybrano zly numer. " << endl;
			}
			break;
		}

		case 4:
		{
			cout << "Podaj ID przedmiotu, ktorego chcesz zmienic wlasciciela: ";
			cin >> identificator;
			cout << endl;
			//wyswietl pracownikow do wyboru
			for (auto& worker : this->listWorkers)
			{
				worker->Print();
				cout << endl;
			}
			cout << "Podaj id nowego wlasciciela: ";
			cin >> identificator1;
			this->changeObjectOwner(identificator, identificator1);
			break;
		}
		case 5:
		{
			cout << "Podaj id przedmiotu, ktory ma byc zwrocony do magazynu: ";
			cin >> identificator;
			this->getObjectToStore(identificator);
			break;
		}
		case 6:
		{
			this->showDebtors();
			break;
		}
		case 7:
		{
			this->ShowAll();
			break;
		}
		case 8:
		{
			this->PrintToFile("WykazSprzetuWFirmie.txt");
			break;
		}
		case 9:
		{
			cout << "Koniec dzialania programu. " << endl;
			return;
		}
		default:
			cout << "Wybrano zly numer. " << endl;
			break;
		}
	}
}

void Storage::getObjectToStore(int objectId) //TODO
{
	for (int i = 0; i < this->listObjects.size(); i++)
	{
		if (listObjects[i]->getId() == objectId)
		{
			if (listObjects[i]->getOwnerId() == -1)
				cout << "Ten obiekt jest juz w magazynie. " << endl;
			else
			{
				//zanim zmienie owner na -1 to func sprawdzajaca czy jakikolwiek obiekt ma tego konkretnego wlasciciela
				int id;
				id = listObjects[i]->getOwnerId();
				listObjects[i]->changeOwner(-1);
				for (int i = 0; i < this->listObjects.size(); i++)
				{
					if (listObjects[i]->getOwnerId() == id) //czy jakikolwiek obiekt ma takiego wlasciciela?
					{
						return;
					}
					else //jesli teraz ten wlasciciel nie ma nic to usuwamy go z listy dluznikow, JESLI zostal na nia dodany = mial byc zwolniony
					{
						shared_ptr<Worker> toDelete = findWorkerWithId(id);
						toDelete->setIsDebtor(0);
						//vector<shared_ptr<Worker>>::iterator position = std::ranges::find(Debtors, toDelete); //jesli tam jest to usuwamy
						//if (position != Debtors.end()) // == Debtors.end() means the element was not found
						//	return; // jesli go nie ma to nie robimy nic
						//else 
						//	Debtors.erase(position);
					}
				}

			}
			return;
		}
	}

	cout << "Obiekt o takim id nie istnieje" << endl;

}

void Storage::DeleteWorker(int workerId)
{
	for (auto worker : listWorkers)
	{
		if (worker->getId() == workerId)
		{
			shared_ptr<Worker> toDelete = findWorkerWithId(workerId);
			if (toDelete == nullptr)
			{
				cout << "Brak pracownika o takim id" << endl;
				return;
			}

			for (auto object : listObjects)
			{
				if (object->getOwnerId() == workerId)
				{
					cout << "Prosze wys³ac wiadomosc do " << toDelete->getLastName() << " na adres e-mail: " << toDelete ->getMail() <<
						" informujaca o koniecznosci dokonania zwrotu przypisanych przedmiotów. " << endl;
					
					if (toDelete->getIsDebtor() == 0)
					{
						toDelete->setIsDebtor(1);
					}
					/*if (ranges::find(Debtors, toDelete) != Debtors.end())
						return;
					else
						Debtors.push_back(toDelete);
					return;*/
				}
			}
			for (auto worker : listWorkers)
			{
				if (toDelete->getIsDebtor() == 1)
				
				{
					cout << "Pracownik nie zostanie usuniety dopoki nie zwroci przedmiotow." << endl;
					return;
				}
				else
				{
					int pos = 0;
					for (int i = 0; i < listWorkers.size(); i++)
					{
						if (listWorkers[i] == toDelete)
						{
							listWorkers.erase(listWorkers.begin() + pos);
						}
						pos++;
					}
					return;
				}
			}
		}
	}
	
}

void Storage::addFurniture(int idObject, furnitureType type, string name, int idOwner)
{
	shared_ptr<Object> newObject (new Furniture(idObject, type, name, idOwner));
	this->listObjects.push_back(newObject);
}

void Storage::addEquipment(int idObject, string name, string specification, int value, string unit, int idOwner)
{
	shared_ptr<Object> newObject ( new Equipment(idObject, name, specification, value, unit, idOwner));
	this->listObjects.push_back(newObject);
}

void Storage::addElectronics(int idObject, string name, string brand, int idOwner)
{
	// Declare a smart pointer on stack and pass it the raw pointer.
	//unique_ptr<Song> song2(new Song(L"Nothing on You", L"Bruno Mars"));
	
	shared_ptr<Object> newObject(new Electronics(idObject, name, brand, idOwner));
	this->listObjects.push_back(newObject);
}

shared_ptr<Worker> Storage::findWorkerWithId(int workerId) //Z RANGES
{
	for(int i =0; i< std::ranges::size(this->listWorkers) ; i++)
	{
		if (this->listWorkers[i]->getId() == workerId)
			return this->listWorkers[i];
	}
	return nullptr;
	
}


void Storage::PrintToFile(const string& fileName)
{
	ofstream file(fileName);
	if (file.good())
	{

		file << "PRZEDMIOTY";
		file << "------------------------------------------------------------------------------------";
		file << endl;
		for (auto object : this->listObjects)
		{
			object->PrintToFile(file);
			if (object->getOwnerId() == -1)
			{
				file << ", stan: w magazynie, przedmiot przypisany do pracownika - brak" << endl;
			}
			else
			{
				file << ", przedmiot przypisany do pracownika - ";
				findWorkerWithId(object->getOwnerId())->PrintToFile(file);
				file << endl;
			}
		}
	}
	else
	{
		file << "Nie udalo sie zapisac danych do pliku." << endl;
	}
}

bool Storage::mailCorrect(string mail)
{
	regex wzorzec("[a-zA-Z0-9-.]{3,}@[a-z]{2,}.[a-z]{2,3}");
	
	if (regex_match(mail, wzorzec))
		return true;
	else
		return false;
}

void Storage::showDebtors() 
{
	for (auto& worker : this->listWorkers)
	{
		if (worker->getIsDebtor() == 1)
		{
			worker->Print();
		}
	}
	cout << endl << endl;
}

//descructor
Storage::~Storage()
{
	cout << "Destruktor" << endl;
}