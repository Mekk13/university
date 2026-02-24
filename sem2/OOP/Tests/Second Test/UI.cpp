#include "UI.h"
#include "Human.h"

UI::~UI()
{
}

void UI::addFamily()
{
	int bd, nr, a;
	std::cout << "Enter the number of years in America: ";
	std::cin >> bd;
	std::cout << "Enter the number of family members: ";
	std::cin >> nr;
	std::cout << "Enter the number of Americans in the family: ";
	std::cin >> a;
	Family* f = new Family(bd, nr, a);
	this->c->addFamily(f);
}

void UI::addPerson()
{
	int bd;
	bool a;
	std::cout << "Enter the number of years in America: ";
	std::cin >> bd;
	std::cout << "Is the person American? (1 for yes, 0 for no): ";
	std::cin >> a;
	Person* p = new Person(bd, a);
	this->c->addPerson(p);
}

void UI::showAll()
{
	std::vector<std::shared_ptr<Human>> filtered = this->c->getall();
	for (auto& a : filtered) {
		std::cout << a->toString() << std::endl;
	}
}

void UI::showAllCitizenship()
{
	std::vector<std::shared_ptr<Human>> filtered = this->c->getallcitizenship();
	for (auto& a : filtered) {
		std::cout << a->toString() << std::endl;
	}
}

void UI::saveFile()
{
	this->c->saveFile("c.txt","d.txt");
	std::cout << "File saved successfully.\n";
}

void UI::menu()
{
	std::cout << "1. Add family\n";
	std::cout << "2. Add person\n";
	std::cout << "3. Show all\n";
	std::cout << "4. Show all with citizenship\n";
	std::cout << "5. Save to file\n";
	std::cout << "6. Exit\n";
}

void UI::start()
{
	this->c->addFamily(new Family(15, 10, 7));
	this->c->addFamily(new Family(10, 5, 2));
	this->c->addFamily(new Family(12, 3, 1));
	this->c->addPerson(new Person(2, 1));
	this->c->addPerson(new Person(2, 0));
	while (1) {
		menu();
		int choice;
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		switch (choice) {
		case 1:
			addFamily();
			std::cout << "Family added successfully.\n";
			break;
		case 2:
			addPerson();
			std::cout << "Person added successfully.\n";
			break;
		case 3:
			showAll();
			break;
		case 4:
			showAllCitizenship();
			break;
		case 5:
			saveFile();
			break;
		case 6:
			exit(0);
		default:
			std::cout << "Invalid choice, try again.\n";
		}
	}
}
