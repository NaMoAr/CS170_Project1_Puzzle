#pragma once
#include <iostream>
#include <vector>
using namespace std;


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
	double heuristic_cost;
	double total_cost;
	string steps; 

	//constructors
	Node(vector<vector<int>> p);
	Node(vector<vector<int>> p, int uniformCost);

	string getSteps();
	void print();
};

// to compare the total cost of two nodes
struct compare {
	bool operator()(const Node& l, const Node& r) {
		return l.total_cost > r.total_cost;
	}
};
