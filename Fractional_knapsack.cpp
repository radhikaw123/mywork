/*Develop a program to solve a fractional Knapsack problem using a greedy 
method. */
#include <bits/stdc++.h>
using namespace std;

// Comparison function to sort items based on profit/weight ratio
void sortItems(int profits[], int weights[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            double r1 = (double)profits[i] / weights[i];
            double r2 = (double)profits[j] / weights[j];
            if (r1 < r2) {
                // Swap profits
                swap(profits[i], profits[j]);
                // Swap weights
                swap(weights[i], weights[j]);
            }
        }
    }
}

// Main function to solve the fractional knapsack problem
double fractionalKnapsack(int W, int profits[], int weights[], int N) {
    // Sort items based on the profit/weight ratio
    sortItems(profits, weights, N);

    double finalValue = 0.0;

    // Loop through all items
    for (int i = 0; i < N; i++) {
        // If adding the item doesn't overflow, add it completely
        if (weights[i] <= W) {
            W -= weights[i];
            finalValue += profits[i];
        }
        // If we can't add the entire item, add the fractional part of it
        else {
            double fraction = (double)W / weights[i];
            finalValue += profits[i] * fraction;
            cout << "\nThe fraction is: " << fraction;
            break;
        }
    }

    // Return the final value
    return finalValue;
    cout << endl ;
}

// Driver code
int main() {
    int N, W;

    // User input for number of items and knapsack capacity
    cout << "Enter the number of items: ";
    cin >> N;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    int profits[N], weights[N];

    // User input for profits and weights of each item
    for (int i = 0; i < N; i++) {
        cout << "Enter profit and weight for item " << i + 1 << ": ";
        cin >> profits[i] >> weights[i];
    }

    // Function call
    double maxProfit = fractionalKnapsack(W, profits, weights, N);
    cout << "\nMaximum profit: "<< maxProfit << endl;

    return 0;
}
/*Enter the capacity of the knapsack: 59
Enter profit and weight for item 1: 5 7
Enter profit and weight for item 2: 33 30
Enter profit and weight for item 3: 20 5
Enter profit and weight for item 4: 44 2
Enter profit and weight for item 5: 60 9

Maximum profit: 162*/
