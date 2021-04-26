#pragma once
#include <iostream>
#include <vector>
using namespace std;

/* This class allows the creation of the Node object which will continously 
update each time the state is being executed */

struct Node
{
	vector<vector<int>> problem;
	
	//at most a blank tile can move in four directions, so with a given node, there would be 4 chidren at most
	Node* parent = nullptr;
	Node* child_1 = nullptr;
	Node* child_2 = nullptr;
	Node* child_3 = nullptr;
	Node* child_4 = nullptr;
	
	int uniform_cost;
	int heuristic_cost;
	int total_cost;

	//constructors
	Node(vector<vector<int>> p);
	Node(vector<vector<int>> p, int uniformCost);
	Node(const Node& p);

	void operator=(const Node& p);

	void print();
};

// to compare the total cost of two nodes
struct compare {
	bool operator()(const Node& l, const Node& r) {
		return l.total_cost > r.total_cost;
	}
};
