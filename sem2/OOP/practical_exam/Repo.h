#pragma once
#include <vector>
#include "Domain.h"

class Repo {
private:
	vector<Researcher> researchers;
	vector<Idea> ideas;
public:
	Repo() {};
	~Repo() {};
	void read_file();
	void write_file();
	void save_accepted();
	void addIdea(Idea i);
	void acceptIdea(Idea i);
	vector<Idea> getIdeas() {
		return ideas;
	}
	vector<Researcher> getResearchers() {
		return researchers;
	}
	void update_idea(Idea old, Idea newi) {
		for (auto& idea : ideas) {
			if (idea.getTitle() == old.getTitle() && idea.getCreator() == old.getCreator()) {
				idea.setDescription(newi.getDescription());
				return;
			}
		}
	}

	void save_idea_to_file(Idea i);
};