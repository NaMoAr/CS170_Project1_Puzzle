I.  Introduction

<br /> In this project, we created a program which solves the eight-puzzle problem. The problem is
solved using Uniform Cost Search, A* with the Misplaced Tile heuristic, and A* with the
Euclidean Distance heuristic. The user can enter their own eight-puzzle or use a hard-coded
puzzle. The language of choice for creating this program is C++.
<br />The three algorithms have slight differences between each other in which the heuristic differers.
In Uniform Cost Search, h(n) is simply hardcoded to 0 and will only expand the cheapest node,
which has a cost of g(n). The expansions do not have any weights. In A* with the Misplaced Tile
heuristic algorithm, the heuristic is calculated by the number of tiles not in the goal state
position excluding 0. When g(n) is assigned a number, a priority queue will expand the node with
the cheapest cost. In A* with Euclidean Distance heuristic, the heuristic uses the Euclidean
distance formula, which calculates the straight-line distance between the current node and the
destination. In such a case, the g(n) will be assigned a straight-line distance number however,
the Euclidean can overestimate the cost.


II. Project Design

<br />You can see the diagram of our design below. We have three classes including AStar, Node, and
Problem along with the Driver Class. Astar is the class that contains the search algorithm
implementation. Inside of the graph_serach() method in Astar class, we declared two objects of
type Node and Problem so we can call the functions from these two classes inside of the
graph_search() method.
<br />The Problem class contains the problem space including state representation, start state, goal
state and operations. Also, the Euclidean and Misplaced heuristic function’s definitions are in
the Problem class.
<br />The Node class contains the implementation for the tree that is generated by graph_serach()
algorithm. Each Node object holds a state of the puzzle, its costs (uniform, heuristic), its parent,
and its four possible children. (Every blank tile has four directions to move so at most there are
four children for each node). The Node object also contains a steps variable to keep track of
which direction the 0 square has to ultimately move each time so at the end, the steps to solve
the puzzle can be printed out.
![p1](https://user-images.githubusercontent.com/59351131/124996699-44916a80-dffe-11eb-8278-210c4596cf31.PNG)


III. Challenges

<br />The design and implementations changed many times as the project progressed to come up
with the best solution. For example, there was originally one single function to generate the
children of a given node. Later, four different functions (the up, down, left, right operations) were
implemented to handle this task.
<br />One of the challenges was to figure out the implementation of Euclidean Distance since the
examples from the class were done using the Manhattan distance, but I figured it out by reading
about Euclidean Distance in ML as listed in the citations.
<br />Another challenge was to figure out the best way to implement printing out the steps to solve
the puzzle. Our first solution seemed to work, however seemed to print out extra steps. Later, we
defined one more class member in the Node class as “steps”. This way every Node carries out
the way that it has been generated (Up, Down, Left, otr Right).


IV. Data structures

<br />We used a 2D vector to hold each puzzle state. The explored set is a vector that holds the Node
objects. Vectors are a useful data structure in this case as they are able to dynamically expand
to hold larger puzzle states and Node objects. Vectors are also used to hold the steps needed to
reach the final states. The frontier is a priority queue as it allows us to expand the nodes at thelowest cost. We also implemented a tree in the Node class, which allows the best
representation of the problem to solve.


V. Graph Search/ Tree Search

<br />We only implemented a graph search. We had an explored set to make sure to not generate a
node which is already in the explored set. As a result, there is no need to worry about loops or
inserting repeated nodes in the frontier. This process is more efficient, but comes at the cost of
more memory compared to Tree Search.


VI. Comparing Heuristic Functions

![p2](https://user-images.githubusercontent.com/59351131/124996797-6c80ce00-dffe-11eb-862a-f917c9852cb4.PNG)

![p3](https://user-images.githubusercontent.com/59351131/124996870-90441400-dffe-11eb-8188-75f8d52887c3.PNG)

![p4](https://user-images.githubusercontent.com/59351131/124996943-b10c6980-dffe-11eb-8905-8ce9304a9872.PNG)

![p5](https://user-images.githubusercontent.com/59351131/124997028-ce413800-dffe-11eb-92b4-b23087dabec8.PNG)

<br />We can see in the above figure, as the puzzle gets harder, the Euclidean Distance Heuristic
spends less time than Misplaces Tile Heuristic and Uniform Cost Search (with value of zero for
the Heuristic function) to reach to the final state.


VII. Conclusion

<br />After applying the three different algorithms for the provided test cases, it is evident that
there is a substantial difference between the algorithms in regards to use cases and
efficiency. For the more simpler problems, it seems using Misplaced Tile Heuristic is the
best algorithm as it expands few nodes and minimizes the frontier. Likewise, for more
complex puzzles, Euclidean Distance Heuristic is better for the same aforementioned
reasons. Uniform Cost Search is only practical for trivial puzzles and becomes quickly
inefficient as the complexity of the puzzle increases. Overall, heuristics help more and
more as problems get harder.


VIII. Citations

<br />1. Lecture slides: To learn the concept of the Heuristic search
<br />2. http://www.cplusplus.com/ : To review the priority queue and stack STL.3. http://neutrofoton.github.io/blog/2016/12/29/c-plus-plus-priority-queue-with-comparato
r/ : To familiarize myself with the implementation of priority queue with a comparator
<br />4. https://medium.com/@kunal_gohrani/different-types-of-distance-metrics-used-in-machi
ne-learning-e9928c5e26c7: To learn more about the Euclidean Distance in ML.
