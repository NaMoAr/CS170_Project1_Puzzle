#include <iostream>;
#include <string>
#include "AStar.h";
#include "Problem.h";
using namespace std;

int main() {
	string puzzle_option;
	//string first_row;
	//string second_row;
	//string third_row;
	int first; int second; int third; int forth; int fifth; int sixth; int seventh; int eighth; int ninth;
	Problem* problem;
	cout << "Welcome to XXX (change this to your student ID) 8 puzzle solver." << endl;
	cout << "Type 1 to use a default puzzle, or 2 to enter your own puzzle." << endl;
	cin >> puzzle_option;
	if (puzzle_option == "1") {

	}
	if (puzzle_option == "2") {
		cout << "Enter your puzzle, use a zero to represent the blank." << endl;
		cout << "Enter the first row, first column" << endl;
		cin >> first;
		cout << "Enter the first row, second column" << endl;
		cin >> second;
		cout << "Enter the first row, third column" << endl;
		cin >> third;
		cout << "Enter the second row, frist column" << endl;
		cin >> forth;
		cout << "Enter the second row, second column" << endl;
		cin >> fifth;
		cout << "Enter the second row, third column" << endl;
		cin >> sixth;
		cout << "Enter the third row, first column" << endl;
		cin >> seventh;
		cout << "Enter the third row, second column" << endl;
		cin >> eighth;
		cout << "Enter the third row, third column" << endl;
		cin >> ninth;

		problem = new Problem(first, second, third, forth, fifth, sixth, seventh, eighth, ninth);
		problem->print();


	}
}