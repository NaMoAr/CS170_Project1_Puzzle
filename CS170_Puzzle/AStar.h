#pragma once
#include "Problem.h"
#include <queue>
class AStar
{
	private:
		Problem problem;
		vector<vector<vector<int>>> explored;
		
		vector<vector<vector<int>>> frontier;
	public:
		AStar();
		void graph_search(Problem problem, string heuristic_type);


};

