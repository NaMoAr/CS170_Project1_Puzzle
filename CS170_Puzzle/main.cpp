#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "Node.h"
#include "Problem.h"
#include "AStar.h"

using namespace std;



int main() {

	AStar astar;
	cout << "Welcome to XXX (change this to your student ID) 8 puzzle solver." << endl;
	cout << "Type 1 to use a default puzzle, or 2 to enter your own puzzle." << endl;
	int puzzle_option = 0;
	
	cin >> puzzle_option;
	
	int first; int second; int third; int forth; int fifth; int sixth; int seventh; int eighth; int ninth;
	if (puzzle_option == 1) {
		first = 1; second = 2; third = 3; 
		forth = 4; fifth = 8; sixth = 0; 
		seventh = 7; eighth = 6; ninth = 5;
	}
	else {
		cout << "Enter your puzzle, use 0 to represent the blank" << endl;
		cout << "Enter the first row, use space or tabs between numbers" << endl;
		cin >> first >> second >> third;
		cout << "Enter the second row, use space or tabs between numbers" << endl;
		cin >> forth >> fifth >> sixth;
		cout << "Enter the third row, use space or tabs between numbers" << endl;
		cin >> seventh >> eighth >> ninth;
		cout << "Your given puzzle is:" << endl;
	}

	Problem problem = Problem(first, second, third, forth, fifth, sixth, seventh, eighth, ninth);
	problem.print_state(problem.getState());
	
	string algorithm_option;
	cout << "Enter your choice of algorithm" << endl;
	cout << "1. Uniform Cost Search" << endl;
	cout << "2. A* with the Misplaced Tile heuristic." << endl;
	cout << "3. A* with the Eucledian distance heuristic." << endl;
	
	
	cin >> algorithm_option;
	cout << endl;

	astar.graph_search(problem.getState(), algorithm_option);
	

	return 0;
}