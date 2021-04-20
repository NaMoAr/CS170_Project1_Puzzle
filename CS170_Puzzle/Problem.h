#pragma once
#include <vector>
#include <string>
#include <math.h>
#include <iostream>
using namespace std;

class Problem
{
private:

	vector<vector<int>> initial_state;
	vector<vector<int>> current_state;
	vector<vector<int>> final_state{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 0},
	};
	vector<Problem> explpred;

public:
	/* Default Constructor */
	Problem();
	/* Overloaded Constructor */
	Problem(int first, int second, int third, int forth, int fifth, int sixth, int seventh, int eighth, int ninth);
	/* Get Specific Tile  */
	vector<vector<int>> getProblem();
	void setProblem(vector<vector<int>> problem);
	int getTile(int i, int j);
	void setTile(int i, int j, int value);
	bool isGoal(vector<vector<int>> problem);
	pair<int, int> getBlank();
	void swap(pair<int, int> operand_1, pair<int, int> operand_2, vector<vector<int>> problem);
	vector<vector<int>> getChildren(vector<vector<int>> problem);
	int Euclidian_dis();
	int Misplaced();
	void print();

};

