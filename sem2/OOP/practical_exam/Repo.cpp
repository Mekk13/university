#include "Repo.h"
#include <fstream>
#include <sstream>

void Repo::read_file()
{
	string filename1 = "researchers.txt";
	string filename2 = "ideas.txt";

	ifstream file2(filename1);
	if (!file2.is_open()) {
		cerr << "Error opening file for reading: " << filename1 << endl;
		return;
	}
	ifstream file1(filename2);
	if (!file1.is_open()) {
		cerr << "Error opening file for reading: " << filename2 << endl;
		return;
	}
	string line;
	while (getline(file1, line)) {
		stringstream ss(line);
		string title, description, status, creator, duration_str;
		
		if (getline(ss, title, ';') &&
			getline(ss, description, ';') &&
			getline(ss, status, ';') &&
			getline(ss, creator, ';') &&
			getline(ss, duration_str)) {

			int duration = stoi(duration_str);
			
			ideas.emplace_back(title,description,status,creator,duration);
		}
		else {
			cerr << "Error reading star data: " << line << endl;
		}
	}
	while (getline(file2, line)) {
		stringstream ss(line);
		string name, position;

		if (getline(ss, name, ';') && getline(ss, position)) {
			researchers.emplace_back(name, position);
		}
		else {
			cerr << "Error reading astronomer data: " << line << endl;
		}
	}


}

void Repo::write_file()
{
	//writes the stuff back to the files
	ofstream file2("researchers.txt");
	if (!file2.is_open()) {
		cerr << "Error opening file for writing: researchers.txt" << endl;
		return;
	}
	ofstream file1("ideas.txt");
	if (!file1.is_open()) {
		cerr << "Error opening file for writing: ideas.txt" << endl;
		return;
	}
	for ( auto& idea : ideas) {
		file1 << idea.getTitle() << ";"
			<< idea.getDescription() << ";"
			<< idea.getStatus() << ";"
			<< idea.getCreator() << ";"
			<< idea.getDuration() << endl;
	}
	for (auto & researcher : researchers) {
		file2 << researcher.getName() << ";"
			<< researcher.getPosition() << endl;
	}
	

}

void Repo::save_accepted()
{
	string filename = "accepted_ideas.txt";
	ofstream file(filename);
	if (!file.is_open()) {
		cerr << "Error opening file for writing: " << filename << endl;
		return;
	}
	for (auto& idea : ideas) {
		if (idea.getStatus() == "Accepted") {
			file << idea.getTitle() << ";"
				<< idea.getDescription() << ";"
				<< idea.getStatus() << ";"
				<< idea.getCreator() << ";"
				<< idea.getDuration() << endl;
		}
	}


}

void Repo::addIdea(Idea i)
{
	ideas.push_back(i);
	write_file();
}

void Repo::acceptIdea(Idea i)
{
	for (auto& idea : ideas) {
		if (idea.getTitle() == i.getTitle()) {
			idea.setStatus("Accepted");
			idea.setDuration(i.getDuration());
			write_file();
			return;
		}
	}
	cerr << "Idea not found: " << i.getTitle() << endl;
}

void Repo::save_idea_to_file(Idea i)
{
	//string titlle = i.getTitle();
	//string& stringlessTitle = titlle.erase(std::remove(titlle.begin(), titlle.end(), ' '), titlle.end());
	string filename = i.getTitle() + ".txt";
	ofstream file(filename);
	if (!file.is_open()) {
		cerr << "Error opening file for writing: " << filename << endl;
		return;
	}
	file << "Title: " << i.getTitle() << endl;
	file << "Description: " << i.getDescription() << endl;
	file << "Status: " << i.getStatus() << endl;
	file << "Creator: " << i.getCreator() << endl;
	file << "Duration: " << i.getDuration() << endl;
	file.close();
}


