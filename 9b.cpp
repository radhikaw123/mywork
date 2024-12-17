/*Develop a program to implement 0/1 Knapsack problem using branch and 
bound. */
#include <bits/stdc++.h> 
using namespace std; 
 
// Structure to store information about a node in the state space tree 
struct Node { 
    int level;    // Level of the node in the tree (item index) 
    int profit;   // Total profit up to this node 
    int weight;   // Total weight up to this node 
    float bound;  // Upper bound on the maximum profit achievable from this node 
}; 
 
// Comparator for sorting nodes based on their bound values (higher bound, higher priority) 
struct CompareBound { 
    bool operator()(Node const& n1, Node const& n2) { 
        return n1.bound < n2.bound;  // Use for max-heap (greater bound, higher priority) 
    } 
}; 
 
// Function to calculate the upper bound on profit for a node 
float calculateBound(Node u, int n, int m, int W[], int P[]) { 
    if (u.weight >= m) return 0; // If weight exceeds capacity, bound is 0 (invalid) 
 
    float profitBound = u.profit; 
    int totalWeight = u.weight; 
    int j = u.level + 1; 
 
    // Calculate upper bound using a greedy approach (fractional knapsack) 
    while (j < n && totalWeight + W[j] <= m) { 
        totalWeight += W[j]; 
        profitBound += P[j]; 
        j++; 
    } 
 
    // If there's still room in the knapsack, add fractional profit from the next item 
    if (j < n) { 
        profitBound += (m - totalWeight) * ((float)P[j] / W[j]); 
    } 
 
    return profitBound; 
} 
 
// Function to solve the 0/1 Knapsack problem using Branch and Bound 
int knapsackBranchAndBound(int n, int W[], int P[], int m) { 
    // Create a priority queue to explore nodes (max-heap based on bound) 
    priority_queue<Node, vector<Node>, CompareBound> pq; 
 
    // Initial root node (level = -1, profit = 0, weight = 0) 
    Node u, v; 
    u.level = -1; 
    u.profit = 0; 
    u.weight = 0; 
    u.bound = calculateBound(u, n, m, W, P); 
 
    pq.push(u); 
 
    int maxProfit = 0; 
 
    while (!pq.empty()) { 
        u = pq.top(); // Get the node with the highest bound 
        pq.pop(); 
 
        // If bound is less than current max profit, prune the node 
        if (u.bound <= maxProfit) continue; 
 
        // Explore the next level (next item) 
        v.level = u.level + 1; 
 
        // Case 1: Include the current item in the knapsack 
        v.weight = u.weight + W[v.level]; 
        v.profit = u.profit + P[v.level]; 
 
        if (v.weight <= m && v.profit > maxProfit) { 
            maxProfit = v.profit; // Update the maximum profit 
        } 
 
        v.bound = calculateBound(v, n, m, W, P); 
 
        if (v.bound > maxProfit) { 
            pq.push(v); // Only add the node if it has potential for better profit 
        } 
 
        // Case 2: Exclude the current item from the knapsack 
        v.weight = u.weight; 
        v.profit = u.profit; 
        v.bound = calculateBound(v, n, m, W, P); 
 
        if (v.bound > maxProfit) { 
        pq.push(v); 
        } 
    } 
 
    return maxProfit; 
} 
 
int main() { 
    int P[10], W[10], n, m; 
 
    cout << "Enter No. of elements: "; 
    cin >> n; 
 
    cout << "Enter the capacity of knapsack: "; 
    cin >> m; 
 
    for (int i = 0; i < n; i++) { 
        cout << "Enter the Profit and Weight of Object " << i + 1 << ": "; 
        cin >> P[i] >> W[i]; 
    } 
 
    cout << "\nMaximum Profit using Branch and Bound: " << 
knapsackBranchAndBound(n, W, P, m) << endl; 
 
    return 0; 
}