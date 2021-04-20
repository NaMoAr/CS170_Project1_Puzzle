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

vector<vector<int>> Problem::getProblem()
{
	return current_state;
}

void Problem::setProblem(vector<vector<int>> problem)
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

pair<int, int> Problem::getBlank()
{
	pair<int, int> my_pair;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (current_state[i][j] == 0)
				my_pair.first = i;
			my_pair.first = j;
		}
	}
	return my_pair;
}

void Problem::swap(pair<int, int> operand_1, pair<int, int> operand_2, vector<vector<int>> problem)
{
	int temp = problem[operand_1.first][operand_1.second];
	problem[operand_1.first][operand_1.second] = problem[operand_2.first][operand_2.second];
	problem[operand_2.first][operand_2.second] = temp;
}

vector<vector<int>> Problem::getChildren(vector<vector<int>> problem)
{
	return problem;
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

int Problem::Misplaced()
{
	int mis_place = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (current_state[i][j] != final_state[i][j])
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
