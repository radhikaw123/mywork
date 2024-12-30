/*Develop a program to implement Graph Coloring using backtracking 
method.*/
#include <iostream>
using namespace std;

// Define maximum number of vertices
#define MAX_V 10

void printSolution(int color[], int V);

/* A utility function to check if the current color assignment
   is safe for vertex v */
bool isSafe(int v, bool graph[MAX_V][MAX_V], int color[], int c, int V) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

/* A recursive utility function to solve m coloring problem */
bool graphColoringUtil(bool graph[MAX_V][MAX_V], int m, int color[], int v, int V) {
    if (v == V) // base case: If all vertices are assigned a color
        return true;

    // Try different colors for vertex v
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c, V)) {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1, V)) // Recur to assign colors to rest
                return true;

            color[v] = 0; // Backtrack
        }
    }
    return false;
}

/* This function solves the m Coloring problem using Backtracking */
bool graphColoring(bool graph[MAX_V][MAX_V], int m, int V) {
    int color[MAX_V] = {0};  // Initialize all vertices' colors to 0

    if (!graphColoringUtil(graph, m, color, 0, V)) {
        cout << "Solution does not exist\n";
        return false;
    }

    printSolution(color, V);
    return true;
}

/* A utility function to print solution */
void printSolution(int color[], int V) {
    cout << "Solution Exists: Following are the assigned colors\n";
    for (int i = 0; i < V; i++)
        cout << "Vertex " << i << " ---> Color " << color[i] << endl;
}

// Driver code
int main() {
    int V;
    cout << "Enter the number of vertices (max " << MAX_V << "): ";
    cin >> V;

    if (V > MAX_V) {
        cout << "Number of vertices exceeds the maximum limit (" << MAX_V << "). Exiting.\n";
        return 1;
    }

    // Input adjacency matrix
    bool graph[MAX_V][MAX_V] = {0};  // Initialize with 0s
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    int m;
    cout << "Enter the number of colors: ";
    cin >> m;

    // Function call
    graphColoring(graph, m, V);
    return 0;
}
/*Enter the number of vertices (max 10): 4
Enter the adjacency matrix:
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
Enter the number of colors: 2
Solution Exists: Following are the assigned colors
Vertex 0 ---> Color 1
Vertex 1 ---> Color 2
Vertex 2 ---> Color 2
Vertex 3 ---> Color 1
PS F:\DAA>  */
