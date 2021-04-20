#include "Problem.h"

Problem::Problem()
{
	initial_state = { {2,1,4},{3,6,5},{7,8,0} };
	current_state = initial_state;
}

Problem::Problem(int first, int second, int third, int forth, int fifth, int sixth, int seventh, int eighth, int ninth)
{
	initial_state = { {first,second,third},{forth,fifth,sixth},{seventh,eighth,ninth} };
	current_state = initial_state;
}

vector<vector<int>> Problem::getState()
{
	return current_state;
}

void Problem::setState(vector<vector<int>> problem)
{
	current_state = problem;
}

int Problem::getTile(int i, int j)
{
	return current_state[i][j];
}

void Problem::setTile(int i, int j, int value)
{
	current_state[i][j] = value;
}

bool Problem::isGoal(vector<vector<int>> problem)
{
	if (current_state == final_state) {
		return true;
	}
	else {
		return false;
	}
}

pair<int, int> Problem::getBlank(vector<vector<int>> problem)
{
	pair<int, int> my_pair;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (problem[i][j] == 0)
				my_pair.first = i;
			my_pair.first = j;
		}
	}
	return my_pair;
}

void Problem::swap(pair<int, int> operand_1, pair<int, int> operand_2)
{
	int temp = current_state[operand_1.first][operand_1.second];
	current_state[operand_1.first][operand_1.second] = current_state[operand_2.first][operand_2.second];
	current_state[operand_2.first][operand_2.second] = temp;
}

vector<vector<vector<int>>> Problem::getChildren(vector<vector<int>> problem)
{
	vector<vector<vector<int>>> children;
	pair<int, int> blank_pos = getBlank(problem);
	pair<int, int> temp;

	if (blank_pos.first == 0 && blank_pos.second == 0) {
		temp.first = 0;
		temp.second = 1;
		swap(blank_pos,temp);
		children.push_back(current_state);
		temp.first = 1;
		temp.second = 0;
		swap(blank_pos, temp);
		children.push_back(current_state);

	}
	else if (blank_pos.first == 0 && blank_pos.second == 1) {

	}
	else if (blank_pos.first == 0 && blank_pos.second == 2) {

	}
	else if (blank_pos.first == 1 && blank_pos.second == 0) {

	}
	else if (blank_pos.first == 1 && blank_pos.second == 1) {

	}
	else if (blank_pos.first == 1 && blank_pos.second == 2) {

	}
	else if (blank_pos.first == 2 && blank_pos.second == 0) {

	}
	else if (blank_pos.first == 2 && blank_pos.second == 1) {
		
	}
	else if (blank_pos.first == 2 && blank_pos.second == 2) {

	}
	
	return children;
}

int Problem::Euclidian_dis()
{
	int total = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			total += pow((current_state[i][j] - final_state[i][j]), 2);

		}
	}
	return sqrt(total);
}

int Problem::Misplaced(vector<vector<int>> problem)
{
	int mis_place = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (problem[i][j] != final_state[i][j])
				++mis_place;
		}
	}
	return mis_place;
}

void Problem::print()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << current_state[i][j] << " ";
		}
		cout << endl;
	}
}

vector<vector<int>> Problem::get_Init_state()
{
	return initial_state;
}

vector<vector<int>> Problem::get_final_state()
{
	return final_state;
}
