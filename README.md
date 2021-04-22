# Maze-Game
Maze game is a well-known problem, where we are given a grid of 0’s and 1’s, 0’s corresponds to a place that can be traversed, and 1 corresponds to a place that cannot be traversed (i.e. a wall or barrier); the problem is to find a path from bottom left corner of grid to top right corner; immediate right, immediate left, immediate up and immediate down only are possible (no diagonal moves). We consider a variant of the maze problem where a cost (positive value) or profit (negative value) is attached to visiting each location in the maze, and the problem is to find a path of least cost through the maze.
One may solve the problem after imposing/relaxing other restrictions on the above problem on ---

- Values of cost/profit (but not same cost/profit for all traversable cells in the grid
- Moves possible (but you cannot trivialize the problem by making the grid linear or partly linear in any way
- No. of destinations possible

The task is to choose the most efficient algorithm possible for the specific case.
<hr>

## Approach
Convert the maze to a weighted graph G (V, E). Each location (i, j) in the maze corresponds to a node in the graph. The problem can have multiple solutions. One can use any design technique such as greedy method, backtracking, dynamic programming. Students can choose their own conditions, positive or negative costs for the graph.
<hr>

## Proposed Solution
We must find the 'single source shortest path', with one vertex in a directed weighted graph as source and find shortest path to all other vertices. The presence of negative edges prevents us from using the Dijkstra's Algorithm as it does not give a correct solution in case of negative edges. 
However, we may use the 'Bellman-Ford Algorithm' for our purpose. The 'Bellman-Ford Algorithm' assumes one vertex as the source and finds the shortest path to all other vertices even when negative edges are present, i.e. finds the path with minimum cost. 

### Bellman-Ford Algorithm
Bellman–Ford proceeds by relaxation, in which approximations to the correct distance are replaced by better ones until they eventually reach the solution. The Bellman–Ford algorithm simply relaxes all the edges, and does this |V|-1 times, where |V| is the number of vertices in the graph. In each of these repetitions, the number of vertices with correctly calculated distances grows, from which it follows that eventually all vertices will have their correct distances.

<img src = "assets/algo.png">

The algorithm initializes the distance to the source to 0 and all other nodes to infinity. Then for all edges, if the distance to the destination can be shortened by taking the edge, the distance is updated to the new lower value. At each iteration i that the edges are scanned, the algorithm finds all shortest paths of at most length i edges (and possibly some paths longer than i edges). Since the longest possible path without a cycle can be |V|-1 edges, the edges must be scanned |V|-1 times to ensure the shortest path has been found for all nodes. A final scan of all the edges is performed and if any distance is updated, then a path of length |V| edges has been found
