#include "Problem.h"

Problem::Problem()
{
	
}

Problem::Problem(int first, int second, int third, int forth, int fifth, int sixth, int seventh, int eighth, int ninth)
{
	current_state = { {first,second,third},{forth,fifth,sixth},{seventh,eighth,ninth} };
	
}

vector<vector<int>> Problem::getState()
{
	return current_state;
}


//getBlank function returns the index of the tile that is zero(blank)
pair<int, int> Problem::getBlank(vector<vector<int>> problem)
{
	pair<int, int> my_pair;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (problem[i][j] == 0) {
				my_pair.first = i;
				my_pair.second = j;
			}
		}
	}
	return my_pair;
}

//swap function swap the two given tiles
vector<vector<int>> Problem::swap(pair<int, int> operand_1, pair<int, int> operand_2, vector<vector<int>> problem)
{
	int temp = problem[operand_1.first][operand_1.second];
	problem[operand_1.first][operand_1.second] = problem[operand_2.first][operand_2.second];
	problem[operand_2.first][operand_2.second] = temp;
	return problem;
}

//left functoin finds the blank tile and move it to the left if it is not located on the first column
vector<vector<int>> Problem::left(vector<vector<int>> problem) {
	//check to see if it is on the first column, if it is, it just returns the problem without any changes
	for (int i = 0; i < 3; i++) {
		if (problem[i][0] == 0) {
			return problem;
		}
	}
	//find the zero(blank) tile
	pair<int, int> blank_index = getBlank(problem);
	pair<int, int> new_blank_index;
	new_blank_index.first = blank_index.first;
	new_blank_index.second = blank_index.second - 1;
	//move the zero(blankk) tile to the left
	return swap(blank_index, new_blank_index, problem);
}

//right functoin finds the blank tile and move it to the right if it is not located on the third row
vector<vector<int>> Problem::right(vector<vector<int>> problem) {
	//check to see if it is on the third row, if it is, it just returns the problem without any changes
	for (int i = 0; i < 3; i++) {
		if (problem[i][2] == 0) {
			return problem;
		}
	}
	//find the zero(blank) tile
	pair<int, int> blank_index = getBlank(problem);
	pair<int, int> new_blank_index;
	new_blank_index.first = blank_index.first;
	new_blank_index.second = blank_index.second + 1;
	//move the zero(blankk) tile to the right
	return swap(blank_index, new_blank_index, problem);
}

//up functoin finds the blank tile and move it upward if it is not located on the first row
vector<vector<int>> Problem::up(vector<vector<int>> problem) {
	//check to see if it is on the first row, if it is, it just returns the problem without any changes
	for (int i = 0; i < 3; i++) {
		if (problem[0][i] == 0) {
			return problem;
		}
	}
	//find the zero(blank) tile
	pair<int, int> blank_index = getBlank(problem);
	pair<int, int> new_blank_index;
	new_blank_index.first = blank_index.first - 1;
	new_blank_index.second = blank_index.second;
	//move the zero(blankk) tile upward
	return swap(blank_index, new_blank_index, problem);
}

//down functoin finds the blank tile and move it downward if it is not located on the third row
vector<vector<int>> Problem::down(vector<vector<int>> problem) {
	//check to see if it is on the third row, if it is, it just returns the problem without any changes
	for (int i = 0; i < 3; i++) {
		if (problem[2][i] == 0) {
			return problem;
		}
	}
	//find the zero(blank) tile
	pair<int, int> blank_index = getBlank(problem);
	pair<int, int> new_blank_index;
	new_blank_index.first = blank_index.first + 1;
	new_blank_index.second = blank_index.second;
	//move the zero(blankk) tile downward
	return swap(blank_index, new_blank_index, problem);
}



int Problem::Euclidian_dis(vector<vector<int>> problem)
{
	int total = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			total += pow((problem[i][j] - final_state[i][j]), 2);

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

vector<vector<int>> Problem::get_final_state()
{
	return final_state;
}

void Problem::print_state(vector<vector<int>> problem)
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

