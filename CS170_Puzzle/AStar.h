#pragma once
#include "Problem.h"
#include <string>
#include <queue>
#include "Node.h"
#include <stack>
using namespace std;
/* Class contains all algorithms needed to solve the puzzle */
class AStar
{
private:
	vector <Node> explored;
	priority_queue <Node, vector<Node>, compare> frontier;
public:
	bool is_explored(vector<vector<int>> state);
	void successfull_path(Node state, int num_nodes, int algorithm_expansion);
	void graph_search(vector<vector<int>> problem, string algorithm_option);


};

