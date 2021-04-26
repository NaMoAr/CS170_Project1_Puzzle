#include "AStar.h"

//check to see if a node exist in the explored vector
bool AStar::is_explored(vector<vector<int>> state) {
	for (int i = 0; i < explored.size(); i++) {
		if (explored.at(i).problem== state) {
			return true;
		}
	}
	return false;
}

//if the graph_search function finds a path to the goal, this function would be 
//called and prints the nodes along the successful path, total number of nodes and number of nodes in queue
void AStar::successfull_path(Node state, int num_nodes, int algorithm_expansion) {
	Node current_state = state;
	stack <Node> s;
	s.push(current_state);					
	while (current_state.parent != NULL) {			
		current_state = *current_state.parent;
		s.push(current_state);				
	}
	
	cout << "Expanding state" << endl;
	s.top().print();
	cout << endl;
	s.pop();
	while (s.size() > 1) {				
		cout << "The best state to expand with a g(n) = ";
		cout << s.top().uniform_cost;
		cout << " and h(n) = " << s.top().heuristic_cost << " is..." << endl;
		s.top().print();
		cout << "Expanding this node ..." << endl;
		cout << endl;
		s.pop();
	}
	cout << "Goal!!" << endl;
	cout << endl;
	cout << "To solve this problem the search algorithm expanded a total of ";
	cout << algorithm_expansion << " nodes." << endl;
	cout << "The maximum number of nodes in the queue at any one time was ";
	cout << num_nodes << "." << endl;
	
}

/* Main method for everything? */
void AStar::graph_search(vector<vector<int>> problem, string algorithm_option) {
	Problem p;
	Node state = Node(problem);
	
	explored.push_back(state);
	frontier.push(state);

	int depth = 0;
	int num_nodes = 1;
	int algorithm_expansion = 0;
	while (!frontier.empty()) {			
		Node* current_node = new Node(frontier.top());
		if (frontier.top().problem == p.get_final_state()) {			
			depth = frontier.top().uniform_cost;	
			successfull_path(frontier.top(), num_nodes, algorithm_expansion);
			break;
		}
		else {
			explored.push_back(frontier.top());	
			
			num_nodes = frontier.size();
			algorithm_expansion++;

			frontier.pop();

			
			Node* child_3 = new Node(p.left(current_node->problem), current_node->uniform_cost + 1);
			Node* child_4 = new Node(p.right(current_node->problem), current_node->uniform_cost + 1);
			Node* child_1 = new Node(p.down(current_node->problem), current_node->uniform_cost + 1);
			Node* child_2 = new Node(p.up(current_node->problem), current_node->uniform_cost + 1);
			
			
			if (algorithm_option == "2") { 
				child_1->heuristic_cost = p.Misplaced(child_1->problem);
				child_2->heuristic_cost = p.Misplaced(child_2->problem);
				child_3->heuristic_cost = p.Misplaced(child_3->problem);
				child_4->heuristic_cost = p.Misplaced(child_4->problem);
			}
			if (algorithm_option == "3") {
				child_1->heuristic_cost = p.Euclidean_dis(child_1->problem);
				child_2->heuristic_cost = p.Euclidean_dis(child_2->problem);
				child_3->heuristic_cost = p.Euclidean_dis(child_3->problem);
				child_4->heuristic_cost = p.Euclidean_dis(child_4->problem);
			}
			
			
			child_1->total_cost = child_1->uniform_cost + child_1->heuristic_cost;
			child_2->total_cost = child_1->uniform_cost + child_2->heuristic_cost;
			child_3->total_cost = child_1->uniform_cost + child_3->heuristic_cost;
			child_4->total_cost = child_1->uniform_cost + child_4->heuristic_cost;

			if (!is_explored(child_1->problem)) {		
				current_node->child_1 = child_1;
				child_1->parent = current_node;
				frontier.push(*child_1);
			}
			if (!is_explored(child_2->problem)) {
				current_node->child_2 = child_2;
				child_2->parent = current_node;
				frontier.push(*child_2);
			}
			if (!is_explored(child_3->problem)) {
				current_node->child_3 = child_3;
				child_3->parent = current_node;
				frontier.push(*child_3);
			}
			if (!is_explored(child_4->problem)) {
				current_node->child_4 = child_4;
				child_4->parent = current_node;
				frontier.push(*child_4);
			}
		}
	}
	if (frontier.empty()) {		
		cout << "No Solution" << endl;
	}
}