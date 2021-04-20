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
	

public:
	/* Default Constructor */
	Problem();
	/* Overloaded Constructor */
	Problem(int first, int second, int third, int forth, int fifth, int sixth, int seventh, int eighth, int ninth);
	/* Get Specific Tile  */
	vector<vector<int>> getState();
	void setState(vector<vector<int>> problem);
	int getTile(int i, int j);
	void setTile(int i, int j, int value);
	bool isGoal(vector<vector<int>> problem);
	pair<int, int> getBlank(vector<vector<int>> problem);
	void swap(pair<int, int> operand_1, pair<int, int> operand_2);
	vector<vector<vector<int>>> getChildren(vector<vector<int>> problem);
	int Euclidian_dis();
	int Misplaced(vector<vector<int>> problem);
	void print();
	vector<vector<int>> get_Init_state();
	vector<vector<int>> get_final_state();

};

