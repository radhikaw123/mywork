/*Develop a program for Job Assignment Problem using Branch and Bound. */
#include <iostream>
#include <limits.h>
using namespace std;

const int MAX = 20;  // Maximum number of jobs/workers

// Function to calculate the current assignment cost up to the current worker
int calculateCost(int costMatrix[][MAX], int assignedJobs[], int worker) {
    int cost = 0;
    for (int i = 0; i <= worker; i++) {
        cost += costMatrix[i][assignedJobs[i]];
    }
    return cost;
}

// Function to check if a job has already been assigned
bool isAssigned(int assignedJobs[], int job, int worker) {
    for (int i = 0; i < worker; i++) {
        if (assignedJobs[i] == job) return true;
    }
    return false;
}

// Branch and Bound recursive function to find the minimum cost
void branchAndBound(int costMatrix[][MAX], int assignedJobs[], int worker, int N, int &minCost, int currentCost, int bestAssignment[]) {
    if (worker == N) {
        if (currentCost < minCost) {
            minCost = currentCost;
            for (int i = 0; i < N; i++) {
                bestAssignment[i] = assignedJobs[i];  // Copy current assignment to best assignment
            }
        }
        return;
    }

    for (int job = 0; job < N; job++) {
        if (!isAssigned(assignedJobs, job, worker)) {
            assignedJobs[worker] = job;
            int newCost = calculateCost(costMatrix, assignedJobs, worker);

            if (newCost < minCost) {
                branchAndBound(costMatrix, assignedJobs, worker + 1, N, minCost, newCost, bestAssignment);
            }

            assignedJobs[worker] = -1; // Reset assignment
        }
    }
}

int main() {
    int N;
    cout << "Enter the number of jobs/workers: ";
    cin >> N;

    int costMatrix[MAX][MAX];
    cout << "Enter the cost matrix:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "Cost of assigning worker " << i + 1 << " to job " << j + 1 << ": ";
            cin >> costMatrix[i][j];
        }
    }

    int assignedJobs[MAX];       // Array to track job assignments for each worker
    int bestAssignment[MAX];      // Array to store the best assignment
    for (int i = 0; i < N; i++) assignedJobs[i] = -1;

    int minCost = INT_MAX;

    // Calling Branch and Bound to calculate minimum assignment cost and assignment
    branchAndBound(costMatrix, assignedJobs, 0, N, minCost, 0, bestAssignment);

    // Output results
    cout << "\nThe minimum cost of assignment is: " << minCost << endl;
    cout << "The optimal assignment of jobs to workers is:\n";
    for (int i = 0; i < N; i++) {
        cout << "Worker " << i + 1 << " is assigned to Job " << bestAssignment[i] + 1 << endl;
    }

    return 0;
}
/*output:
Enter the number of jobs/workers: 4
Enter the cost matrix:
Cost of assigning worker 1 to job 1: 9
Cost of assigning worker 1 to job 2: 2
Cost of assigning worker 1 to job 3: 7
Cost of assigning worker 1 to job 4: 8
Cost of assigning worker 2 to job 1: 6
Cost of assigning worker 2 to job 2: 4
Cost of assigning worker 2 to job 3: 3
Cost of assigning worker 2 to job 4: 7
Cost of assigning worker 3 to job 1: 5
Cost of assigning worker 3 to job 2: 8
Cost of assigning worker 3 to job 3: 1
Cost of assigning worker 3 to job 4: 8
Cost of assigning worker 4 to job 1: 7
Cost of assigning worker 4 to job 2: 6
Cost of assigning worker 4 to job 3: 9
Cost of assigning worker 4 to job 4: 4

The minimum cost of assignment is: 13
The optimal assignment of jobs to workers is:
Worker 1 is assigned to Job 2
Worker 2 is assigned to Job 1
Worker 3 is assigned to Job 3
Worker 4 is assigned to Job 4
*/