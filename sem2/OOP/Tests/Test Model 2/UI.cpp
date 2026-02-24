#include "UI.h"
#include <iostream>

void UI::add_analysis()
{
	std::cout << "Enter the type : ";
	std::string type;
	std::cin.ignore();
	std::getline(std::cin,type);
	int systolicValue;
	int diastolicValue;
	double value;
	std::string date;
	if (type=="BP") {
		std::cout << "Enter the date: ";
		std::getline(std::cin, date);
		std::cout << "Enter the systolicValue: ";
		std::cin >> systolicValue;

		std::cout << "Enter the diastolicValue: ";
		std::cin >> diastolicValue;
		this->p.addAnalysis(new BP(systolicValue, diastolicValue, date));
		std::cout << "Blood Pressure added.\n";
	}
	else if (type == "BMI") {
		std::cout << "Enter the date: ";
		std::getline(std::cin, date);
		std::cout << "Enter the BMI: ";
		std::cin >> value;
		this->p.addAnalysis(new BMI(value, date));
		std::cout << "BMI added.\n";
	}
	else {
		std::cout << "Invalid. \n";
		return;
	}

}

void UI::show_all()
{
	this->p.getAllAnalyses();
	std::cout << "All analyses:\n";
	for (auto& a : this->p.getAllAnalyses()) {
		std::cout << a->toString() << " " << a->isResultOk() << "\n";
	}
}

void UI::show_if_ill()
{
	std::cout << "Enter the month: ";
	int month;
	std::cin >> month;
	if (this->p.isIll(month)) {
		std::cout << "The person is ill.\n";
	}
	else {
		std::cout << "The person is not ill.\n";
	}
}

void UI::save_to_file()
{
	std::cout << "Enter the date1: ";
	std::string date1;
	std::cin >> date1;
	std::cout << "Enter the date2: ";
	std::string date2;
	std::cin >> date2;
	this->p.writeToFile("output.txt", date1, date2);
	std::cout << "Saved to file.\n";
}

void UI::start()
{
	this->p.addAnalysis(new BP(120, 80, "2023-10-01"));
	this->p.addAnalysis(new BMI(22.5, "2023-10-01"));
	int choice;
	while (true) {
		menu();
		//std::cin.ignore();
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		switch (choice) {
		case 1:
			add_analysis();
			break;
		case 2:
			show_all();
			break;
		case 3:
			show_if_ill();
			break;
		case 4:
			save_to_file();
			break;
		case 5:
			std::cout << "Exiting...\n";
			return;
		default:
			std::cout << "Invalid choice. Try again.\n";
			break;
		}
	}
}

void UI::menu()
{
	std::cout << "1. Add analysis\n";
	std::cout << "2. Show all analyses\n";
	std::cout << "3. Show if ill\n";
	std::cout << "4. Save to file\n";
	std::cout << "5. Exit\n";
	
}
