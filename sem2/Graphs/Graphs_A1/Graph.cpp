#include "Graph.h"

Graph::Graph(int nrVertices)
{
	for (int i = 0; i < nrVertices; i++) {
		in_v[i] = std::vector <int>();
		out_v[i] = std::vector <int>();
	}
}

Graph::~Graph() {}

Graph::Graph(const Graph& other) : in_v{ other.in_v }, out_v{ other.out_v }, e_values{ other.e_values } {}

Graph& Graph::operator=(const Graph& other)
{
	if (this != &other) {
		in_v = other.in_v;
		out_v = other.out_v;
		e_values = other.e_values;
	}
	return *this;
}

void Graph::PrintGraphFile(std::ostream& out)
{
	out << get_nr_vertices() << " " << get_nr_edges()<<"\n";
	for (auto& pair : e_values) {
		out << pair.first.first << " " << pair.first.second << " " << pair.second<< "\n";
	}
}

void Graph::PrintGraph()
{
	std::cout << get_nr_vertices() << " " << get_nr_edges() << "\n";
	for (auto& pair : e_values) {
		std::cout << pair.first.first << " " << pair.first.second << " " << pair.second << "\n";
	}
}


bool Graph::add_edge(const int& x, const int& y, int cost) {
	if (!in_v.contains(x) || !in_v.contains(y) || e_values.contains({ x, y }))
		return false;

	in_v[y].push_back(x);
	out_v[x].push_back(y);
	e_values.try_emplace({ x, y }, cost);  // Faster than e_values[{x, y}] = cost
	return true;
}


/// O(deg(x)) + O(deg(y))
bool Graph::remove_edge(const int& x, const int& y)
{
	if (!is_vertex(x) || !is_vertex(y) || !is_edge(x, y)) ///O(deg(x))
		return 0;
	auto& out_x = out_v[x];
	auto& in_y = in_v[y];
	
	out_x.erase(std::remove(out_x.begin(), out_x.end(), y), out_x.end());
	in_y.erase(std::remove(in_y.begin(), in_y.end(), x), in_y.end());

	e_values.erase({ x,y });//O(log(nr_edges))
	return 1;
}

/// O(deg(x)+deg(y)) 
bool Graph::is_edge(const int& x, const int& y)
{
	return e_values.contains({ x,y });
}

bool Graph::add_vertex(const int& x)
{
	if (is_vertex(x))
		return false;
	in_v[x] = std::vector<int>();
	out_v[x] = std::vector<int>();
	return true;
}

bool Graph::remove_vertex(const int& x)
{
	if (!is_vertex(x))
		return false;
	
	std::vector<std::pair<int, int>> edges_to_remove;
	for ( auto& pair : e_values) {
		if (pair.first.first == x || pair.first.second == x) {
			edges_to_remove.push_back(pair.first);
		}
	}
	for (auto& edge : edges_to_remove) {
		e_values.erase(edge);
	}

	for (auto& pair : out_v) {
		auto& v = pair.second;
		v.erase(std::remove(v.begin(), v.end(), x), v.end());
	}

	for (auto& pair : in_v) {
		auto& v = pair.second;
		v.erase(std::remove(v.begin(), v.end(), x), v.end());
	}

	in_v.erase(x);
	out_v.erase(x);
	return true;
}


bool Graph::is_vertex(const int& x)
{
	return in_v.contains(x);
}

long long Graph::degree_in(const int& x)
{
	if (!is_vertex(x))
		return -1;
	return in_v[x].size();
}

long long Graph::degree_out(const int& x)
{
	if (!is_vertex(x))
		return -1;
	return out_v[x].size();
}

std::vector<int> Graph::parse_out(const int& x)
{
	return out_v.at(x);
}

std::vector<int> Graph::parse_in(const int& x)
{
	return in_v.at(x);
}

std::vector<int> Graph::parse_vertices()
{
	std::vector<int> vertices;
	for (auto& pair : out_v) {
		vertices.push_back(pair.first);
	}
	return vertices;
}

long long Graph::get_nr_vertices()
{
	return out_v.size();
}

int Graph::get_edge_cost(const int& x, const int& y)
{
	if (!is_vertex(x) || !is_vertex(y) || !is_edge(x, y))
		return- 1;
	return e_values[std::make_pair(x, y)];
}

bool Graph::set_edge_cost(const int& x, const int& y, const int& cost)
{
	if (!is_vertex(x)||!is_vertex(y)||!is_edge(x, y))
		return 0;
	e_values[std::make_pair(x, y)] = cost;
	return 1;
}

long long Graph::get_nr_edges()
{
	return e_values.size();
}
