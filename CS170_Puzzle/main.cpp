#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "Node.h"
#include "Problem.h"
#include "AStar.h"


/* Class contains user input and contains links to all other classes and functions */

using namespace std;

int main() {
	/* Create AStar object */
	AStar astar;

	cout << "Welcome to 862216499(nmoha034) && 862152050(sbatr009) 8 puzzle solver." << endl;

	/* User input, ask user for default or allow them to create their own */
	cout << "Welcome to XXX (change this to your student ID) 8 puzzle solver." << endl;

	cout << "Type 1 to use a default puzzle, or 2 to enter your own puzzle." << endl;
	int puzzle_option = 0;
	int default_option = 0;
	cin >> puzzle_option;
	
	int first, second, third, forth, fifth, sixth, seventh, eighth, ninth;
	if (puzzle_option == 1) {
		cout << "1. Trival" << endl;
		cout << "2. Very Easy" << endl;
		cout << "3. Easy" << endl;
		cout << "4. Doable" << endl;
		cout << "5. Oh Boy" << endl;
		cout << "6. Impossible" << endl;
		cin >> default_option;
		if (default_option == 1) {
			first = 1; second = 2; third = 3;
			forth = 4; fifth = 5; sixth = 6;
			seventh = 7; eighth = 8; ninth = 0;
		}
		if (default_option == 2) {
			first = 1; second = 2; third = 3;
			forth = 4; fifth = 5; sixth = 6;
			seventh = 7; eighth = 0; ninth = 8;
		}
		if (default_option == 3) {
			first = 1; second = 2; third = 0;
			forth = 4; fifth = 5; sixth = 3;
			seventh = 7; eighth = 8; ninth = 6;
		}
		if (default_option == 4) {
			first = 0; second = 1; third = 2;
			forth = 4; fifth = 5; sixth = 3;
			seventh = 7; eighth = 8; ninth = 6;
		}
		if (default_option == 5) {
			first = 8; second = 7; third = 1;
			forth = 6; fifth = 0; sixth = 2;
			seventh = 5; eighth = 4; ninth = 3;
		}
		if (default_option == 6) {
			first = 1; second = 2; third = 3;
			forth = 4; fifth = 5; sixth = 6;
			seventh = 8; eighth = 7; ninth = 0;
		}
		
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
    /* Insert inputs into problem object */
	Problem problem = Problem(first, second, third, forth, fifth, sixth, seventh, eighth, ninth);
	problem.print_state(problem.getState());
	
	string algorithm_option;
	cout << "Enter your choice of algorithm" << endl;
	cout << "1. Uniform Cost Search" << endl;
	cout << "2. A* with the Misplaced Tile heuristic." << endl;
	cout << "3. A* with the Euclidean  distance heuristic." << endl;
	
	
	cin >> algorithm_option;
	cout << endl;
    /* Method takes in problem state and user input and uses algorithm to solve 8 puzzle */
	astar.graph_search(problem.getState(), algorithm_option);
	

	return 0;
}