#pragma once

#include "Repo.h"

class Service {

private:
	Repo repo;
public:
	Service(Repo r) :repo(r) { repo.read_file(); }
	~Service() = default;
	void addIdea(Idea i) {
		repo.addIdea(i);
	}
	void acceptIdea(Idea i) {
		repo.acceptIdea(i);
	}
	void readFile() {
		repo.read_file();
	}
	void writeFile() {
		repo.write_file();
	}

	void save_accepted_ideas() {
		repo.save_accepted();
	}

	bool hasAccepted(string name) {
		//if the researcher jas accepted idea ret true
		vector<Idea> ideas = getIdeas();
		for (auto& a : ideas) {
			if (a.getCreator() == name && a.getStatus()=="Accepted") {
				return true;
			}
		}
		return false;
	}

	vector<Idea> getAcceptedFrom(string name) {
		vector<Idea> acceptedIdeas;
		vector<Idea> ideas = getIdeas();
		for (auto& a : ideas) {
			if (a.getCreator() == name && a.getStatus() == "Accepted") {
				acceptedIdeas.push_back(a);
			}
		}
		return acceptedIdeas;
	}

	vector<Idea> getIdeas(){
		return repo.getIdeas();
	}
	vector<Researcher> getResearchers() {
		return repo.getResearchers();
	}
	int getIdeaCount() {
		return repo.getIdeas().size();
	}
	vector<Idea> getSortedIdeas() {
		vector<Idea> ideas = repo.getIdeas();
		sort(ideas.begin(), ideas.end(), [](Idea& a, Idea& b) {
			return a.getDuration() < b.getDuration();
			});
		return ideas;
	}

	void updateIdea(Idea oldIdea,Idea newIdea) {
		repo.update_idea(oldIdea, newIdea);
		repo.write_file();
	}

	void save_an_idea_PLS(Idea idea) {
		repo.save_idea_to_file(idea);
	}
};