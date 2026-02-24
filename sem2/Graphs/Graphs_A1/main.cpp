#pragma once
#include "Graph.h"
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
std::ofstream fout("date.out");
using namespace std;

void menu() {
	printf("\n       -- MENU -- \n");
	printf("1. Generate a random graph\n");
	printf("2. Read a graph from a file\n");
	printf("3. Print graph in a file\n");
	printf("4. Vertex operations \n");
	printf("5. Edge operations \n");
	printf("6. Make a deep copy of a graph\n");
	printf("7. Replace graph with former copy\n");
	printf("8. Print graph on screen\n");
	printf("0. Exit\n");
}

void menu_vertex() {
	printf("\n     --VERTEX MENU--\n");
	printf("1. Add vertex \n");
	printf("2. Remove vertex\n");
	printf("3. In-degree of a vertex\n");
	printf("4. Out-degree of a vertex\n");
	printf("5. See all vertices\n");
	printf("6. Outbound neighbours\n");
	printf("7. Inbound neighbours\n");
	printf("8. Number of vertices in the graph\n");
	printf("9. Does vertex exist?\n");
	printf("0. Back\n");
}

void menu_edge() {
	printf("\n     --EDGE MENU--\n");
	printf("1. Add edge\n");
	printf("2. Remove edge\n");
	printf("3. Does edge exist?\n");
	printf("4. Get edge cost\n");
	printf("5. Set edge cost\n");
	printf("0. Back\n");
}

Graph generate_random_graph(int nr_vertices, int nr_edges) {
	if (nr_edges > nr_vertices * nr_vertices) {
		cout << "The number of edges cannot exceed the nr. of vertices squared!\n";
		return Graph(0);
	}
	Graph graph(nr_vertices);
	int i = 0;
	while(i<nr_edges){
		int x = rand() % nr_vertices;
		int y = rand() % nr_vertices;
		int c = rand() % 101;
		if (graph.add_edge(x, y, c))
			i++;
	}
	printf("Successfully generated a random graph with %d vertices and %d edges!\n", nr_vertices, nr_edges);
	return graph;
}

void get_vertices_and_edges_input(int &v, int &e) {
	while (1) {
		cout << "Enter the number of vertices:";
		cin >> v;
		if (!cin>>v) {
			cin.clear();
			string temp;
			getline(cin, temp);
			cout << "Invalid input! Please enter a valid integer. \n";
			continue;
		}
		cout << "Enter the number of edges: ";
		cin >> e;
		if (!cin >> e) {
			cin.clear();
			string temp;
			getline(cin, temp);
			cout << "Invalid input! Please enter a valid integer. \n";
			continue;
		}
		else
			return;
	}
}

int get_choice() {
	while (1) {
		int choice;
		cout << "Your choice: ";
		cin >> choice;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input! Please enter a valid integer. \n";
		}
		else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return choice;
		}
	}
}


Graph read_from_file(char file[200]) {
	ios::sync_with_stdio(false);
	ifstream fin(file);
	if (!fin.is_open()) {
		cout << "Could not find specified file!";
		return Graph(0);
	}
	int v, e;
	fin >> v >> e;
	Graph graph(v);
	int x, y, c;
	/*string line;
	getline(fin, line);
	while (getline(fin, line)) {
		stringstream ss(line);
		ss >> x >> y >> c;
		graph.add_edge(x, y, c);
	}*/
	for (int i = 0; i < e; i++) {
		fin >> x >> y >> c;
		graph.add_edge(x, y, c);
		
	}
	fin.close();
	return graph;

}

bool is_numerical(string input) {
	for (char a : input) {
		if (!isdigit(a))
		{
			return false;
		}
	}
	return true;
}

int handle_read_vertex(const char message[200]) {
	while (1) {
		string v;
		cout << message;
		getline(cin, v);
		if (is_numerical(v)) {
			int v1 = stoi(v);
			return v1;
		}
		cout << "Invalid input! Try again.\n";
		continue;
	}
}

void handle_vertex_menu(Graph& graph) {
	while (1) {
		menu_vertex();
		int choice = get_choice();
		switch (choice) {
			case 1: {
				int v = handle_read_vertex("Enter the vertex you wish to add:");
				int ok = graph.add_vertex(v);
				if (ok == false) {
					cout << "Vertex could not be added - it may already exist\n";
				}
				else {
					cout << "Vertex added successfully!\n";
				}
				break;
			}
			case 2: {
				int v = handle_read_vertex("Enter the vertex you wish to remove:");
				int ok = graph.remove_vertex(v);
				if (ok == false) {
					cout << "Vertex could not be removed - it may not exist\n";
				}
				else {
					cout << "Vertex removed successfully!\n";
				}
				break;
			}
			case 3: {
				int v = handle_read_vertex("Vertex: ");
				printf("The in-degree of the vertex %d is %lld.\n",v,graph.degree_in(v));
				break;
			}
			case 4: {
				int v = handle_read_vertex("Vertex: ");
				printf("The out-degree of the vertex %d is %lld.\n", v, graph.degree_out(v));
				break;
			}
			case 5: {
				vector<int> v;
				v = graph.parse_vertices();
				for (int i = 0; i < v.size();i++) {
					cout << v[i] << "\n";
				}
				break;
			}
			case 6: {
				vector<int> v;
				int x = handle_read_vertex("Vertex: ");
				v = graph.parse_out(x);
				printf("The outbound neighbours of %d are:\n", x);
				for (int i = 0; i < v.size(); i++) {
					cout << v[i] << "\n";
				}
				break;
			}
			case 7: {
				vector<int> v;
				int x = handle_read_vertex("Vertex: ");
				v = graph.parse_in(x);
				printf("The inbound neighbours of %d are:\n", x);
				for (int i = 0; i < v.size(); i++) {
					cout << v[i] << "\n";
				}
				break;
			}
			case 8: {
				printf("There are %lld vertices in the graph.\n", graph.get_nr_vertices());
				break;
			}
			case 9:
			{
				int v = handle_read_vertex("Vertex you wish to check: ");
				if (graph.is_vertex(v))
					cout << "yes.\n";
				else
					cout << "no.\n";
				break;
			}
			case 0:
			{
				return;
			}
			default: {
				cout << "Invalid choice. \n";
				break;
			}
		}
	}
}


int input_cost() {
	string c;
	while (1) {
		cout << "Cost: ";
		getline(cin, c);
		if (is_numerical(c) ){
			int c1 = stoi(c);
			return c1;
		}
		cin.clear();
		cout << "Invalid cost. Try again.\n";
		continue;

	}
}

void get_edge(int& x, int& y,int &c,const char message[200],bool nocost) {
	cout << message <<"\n";
	x = handle_read_vertex("First vertex:");
	y = handle_read_vertex("Second vertex:");
	if (nocost)
		return;
	c = input_cost();
}

void handle_edge_menu(Graph& graph) {
	while (1) {
		menu_edge();
		int choice = get_choice();
		switch (choice) {
			case 1: {
				int x, y,c;
				get_edge(x, y,c,"Enter the edge you wish to add: ",0);
				int ok = graph.add_edge(x, y, c);
				if (ok)
					cout << "Edge added successfully!\n\n";
				else
					cout << "Edge was not added - it may already exist.\n\n";
				break;
			}
			case 2: {
				int x, y, c;
				get_edge(x, y, c, "Enter the edge you wish to remove: ",1);
				int ok = graph.remove_edge(x,y);
				if (ok)
					cout << "Edge removed successfully!\n\n";
				else
					cout << "Edge was not removed - it may not exist.\n\n";
				break;
			}
			case 3: {
				int x, y, c;
				get_edge(x, y, c, "Enter the edge you wish to check: ",1);
				int ok = graph.is_edge(x, y);
				if (ok)
					cout << "Edge exists!\n\n";
				else
					cout << "Edge does not exist.\n\n";
				break;
			}
			case 4:
			{
				int x, y, c;
				get_edge(x, y, c, "Enter the edge you wish to check the cost of: ", 1);
				int ok = graph.get_edge_cost(x, y);
				if(ok!=-1)
					printf("The cost of the given edge is %d.\n\n", ok);
				else
					cout<<"Edge not found.\n\n";
				break;
			}
			case 5: {
				int x, y, c;
				get_edge(x, y, c, "Enter the edge you wish to set the cost of: ", 1);
				int ok = graph.is_edge(x, y);
				if (ok) {
					c = input_cost();
					(void)graph.set_edge_cost(x, y, c);
					cout << "success.\n\n";
				}
				else
					cout << "Edge cost was not changed - it may not exist.\n\n";
				break;
			}
			case 0: {
				return;
			}
			default: {
				cout << "Invalid choice! Pick one of the menu choices.\n";
				break;
			}
		}
	}
}

void handle_menu(Graph& graph) {
	Graph copy(graph);
	while (1) {
		menu();
		int choice = get_choice();
		switch (choice) {
			case 1: 
			{
				int v, e;
				get_vertices_and_edges_input(v, e);
				graph=generate_random_graph(v, e);
				break;
			}
			case 2:
			{
				char filename[200];
				cout << "Enter filename: ";
				cin >> filename;
				graph = read_from_file(filename);
				break;
			}
			case 3:
			{
				graph.PrintGraphFile(fout);
				break;
			}
			case 4:
			{
				handle_vertex_menu(graph);
				break;
			}
			case 5:
			{
				handle_edge_menu(graph);
				break;
			}
			case 6:
			{
				copy = graph;
				cout << "Copy successfully created!\n";
				break;
			}
			case 7:
			{
				graph = copy;
				cout << "Graph was replaced with former copy!\n";
				break;
			}
			case 8:
			{
				graph.PrintGraph();
				break;
			}
			case 0: {
				return;
			}
			default:
			{
				cout << "Invalid choice! Pick one of the menu choices.\n";
				break;
			}
		}
	}
}


int main() {

	Graph graph(0);
	handle_menu(graph);
	return 0;
}