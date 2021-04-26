#pragma once
#include <vector>
#include <string>
#include <math.h>
#include <iostream>
using namespace std;

class Problem
{
private:

	
	vector<vector<int>> current_state;
	const vector<vector<int>> final_state = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 0},
	};


public:
	/* Default Constructor */
	Problem();
	/* Overloaded Constructor */
	Problem(int first, int second, int third, int forth, int fifth, int sixth, int seventh, int eighth, int ninth);
	vector<vector<int>> getState();
	pair<int, int> getBlank(vector<vector<int>> problem);
	vector<vector<int>> swap(pair<int, int> operand_1, pair<int, int> operand_2, vector<vector<int>> problem);
	vector<vector<int>> up(vector<vector<int>> problem);
	vector<vector<int>> down(vector<vector<int>> problem);
	vector<vector<int>> left(vector<vector<int>> problem);
	vector<vector<int>> right(vector<vector<int>> problem);
	double Euclidean_dis(vector<vector<int>> problem);
	int Misplaced(vector<vector<int>> problem);
	void print_state(vector<vector<int>> problem);
	vector<vector<int>> get_final_state();

};

