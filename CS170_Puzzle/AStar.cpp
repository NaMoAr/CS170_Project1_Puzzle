#include "AStar.h"

AStar::AStar()
{
}

void AStar::graph_search(Problem problem, string heuristic_type)
{
	vector<int> cost;
	int level = 0;
	frontier.push_back(problem.get_Init_state());

	while (true) {
		if (frontier.empty()) {
			cout << "failure" << endl;
		}
		else {
			if (frontier.size() == 1) {//if there is only the root node in the graph
				frontier.pop_back();
				explored.push_back(problem.get_Init_state());
				if (problem.get_Init_state() == problem.get_final_state()) {
					problem.print();
				}
				else {
					vector<vector<vector<int>>> children = problem.getChildren(problem.get_Init_state());
					++level;
					for (int i = 0; i < children.size(); i++) {
						frontier.push_back(children.at(i));

					}
				}
			}
			else {//ther are several nodes so we should choose the one with least cost
				for (int i = 0; i < frontier.size(); i++) {
					if (heuristic_type == "2") { cost[i] = problem.Misplaced(frontier.at(i)) + level; }
				}
			}
		}
	}
}