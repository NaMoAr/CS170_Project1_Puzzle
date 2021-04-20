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
};
Node::Node(vector<vector<int>> p, int uniformCost) {		
	problem = p;
	uniform_cost = uniformCost;
	heuristic_cost = 0;
};
Node::Node(const Node& p) {			
	problem = p.problem;
	uniform_cost = p.uniform_cost;
	heuristic_cost = p.heuristic_cost;
	total_cost = p.total_cost;
	parent = p.parent;
	child_1 = p.child_1;
	child_2 = p.child_2;
	child_3 = p.child_3;
	child_4 = p.child_4;
	
}
void Node::operator=(const Node& p) {		
	problem = p.problem;
	uniform_cost = p.uniform_cost;
	heuristic_cost = p.heuristic_cost;
	total_cost = p.total_cost;
	parent = p.parent;
	child_1 = p.child_1;
	child_2 = p.child_2;
	child_3 = p.child_3;
	child_4 = p.child_4;

}
void Node::print() {				
	print_state(problem);
}






