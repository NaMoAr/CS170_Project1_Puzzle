#include "Node.h"


void print_state(vector<vector<int>> problem)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << problem[i][j] << " ";
		}
		cout << endl;
	}
}




Node::Node(vector<vector<int>> p) {			
	problem = p;
	uniform_cost = 0;
	heuristic_cost = 0;
	steps = "";
};
Node::Node(vector<vector<int>> p, int uniformCost) {		
	problem = p;
	uniform_cost = uniformCost;
	heuristic_cost = 0;
	steps = "";
};


string Node::getSteps()
{
	return steps;
}

void Node::print() {
	print_state(problem);
}






