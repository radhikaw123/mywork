/*Develop a program to implement 0/1 Knapsack problem using Dynamic 
Programming. */
#include <iostream>
using namespace std;

// Function to implement the 0/1 Knapsack Problem
int knapsack(int capacity, int weights[], int values[], int n) {
    int dp[n + 1][capacity + 1];  // 2D DP array

    // Initialize the DP table with 0 for base cases
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)  // item can be included
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else                           // item cannot be included
                dp[i][w] = dp[i - 1][w];
        }
    }
    
    return dp[n][capacity];  // The bottom-right corner contains the maximum value
}

int main() {
    int n, capacity;

    // Input number of items and knapsack capacity
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    int weights[n], values[n];

    // Input weights and values of items
    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) cin >> weights[i];
    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++) cin >> values[i];

    // Calculate maximum value that can be obtained
    int max_value = knapsack(capacity, weights, values, n);
    cout << "Maximum value in Knapsack: " << max_value << endl;

    return 0;
}
