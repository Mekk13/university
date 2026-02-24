#pragma once
#include <utility>
#include <map>
#include <vector>
#include <iostream>
#include <unordered_map>

struct pair_hash {
	template <class T1, class T2>
	std::size_t operator()(const std::pair<T1, T2>& p) const {
		return std::hash<T1>()(p.first) ^ (std::hash<T2>()(p.second) << 1);
	}
};

class Graph {

private:
	/// vertices
	std::unordered_map<int, std::vector<int>> in_v, out_v;

	/// weights map
	std::unordered_map<std::pair<int, int>, int, pair_hash> e_values;

public:
	explicit Graph(int nrVertices); //constructor :D
	~Graph(); //destructor
	Graph(const Graph& other); //Copy constructor
	Graph& operator=(const Graph& other);
	void PrintGraphFile(std::ostream& out); //prints a graph in a file
	void PrintGraph(); //prints graph on screen

	/// edges
	bool add_edge(const int& x,const int& y, int cost); // adds edge from x to y returns 1 if successful 0 otherwise
	bool remove_edge(const int& x, const int& y);//removes edge , true if successful , false if else
	bool is_edge(const int& x,const int& y);//returns true if there si an edge between x and y
	int get_edge_cost(const int& x, const int& y); //getter for cost of edge
	bool set_edge_cost(const int& x, const int& y, const int& cost); //setter for cost of edge
	long long get_nr_edges();

	/// vertices
	bool add_vertex(const int& x);
	bool remove_vertex(const int& x);
	bool is_vertex(const int& x); //returns true if x is a vertex
	long long degree_in(const int& x); //returns the inbound degree of x
	long long degree_out(const int& x); //returns the outbound degree of x
	std::vector<int> parse_out(const int& x);//Returns an iterable containing all the outbound neighbors of x
	std::vector<int> parse_in(const int& x) ; //Returns an iterable containing all the inbound neighbors of x
	std::vector<int> parse_vertices() ; //Returns an iterable containing all the vertices
	long long get_nr_vertices();


};