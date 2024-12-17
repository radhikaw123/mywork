/*Develop a program to design a function for Binary Search using Divide 
and Conquer Strategies. Also compute it's time complexity. */
#include <iostream>
using namespace std;

// Function for Recursive Binary Search
int binarySearchRecursive(int arr[], int low, int high, int target) {
    if (low > high) return -1;  // base case: not found

    int mid = low + (high - low) / 2;
    if (arr[mid] == target) return mid;       // found target
    else if (arr[mid] > target)               // search in left half
        return binarySearchRecursive(arr, low, mid - 1, target);
    else                                      // search in right half
        return binarySearchRecursive(arr, mid + 1, high, target);
}

// Function for Iterative Binary Search
int binarySearchIterative(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) return mid;      // found target
        else if (arr[mid] < target)              // move to right half
            low = mid + 1;
        else                                     // move to left half
            high = mid - 1;
    }
    return -1;                                   // not found
}

int main() {
    int n, target, choice;
    
    // Input array size and elements
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Input target to search
    cout << "Enter target to search: ";
    cin >> target;

    // Choice for method selection
    cout << "Choose Binary Search method:\n";
    cout << "1. Recursive\n";
    cout << "2. Iterative\n";
    cin >> choice;

    int result = -1;
    switch (choice) {
        case 1:
            // Recursive Binary Search
            result = binarySearchRecursive(arr, 0, n - 1, target);
            break;
        case 2:
            // Iterative Binary Search
            result = binarySearchIterative(arr, n, target);
            break;
        default:
            cout << "Invalid choice!" << endl;
            return 0;
    }

    // Display result
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found in array." << endl;

    return 0;
}
/*output:PS F:\DAA> F:\DAA\1.cpp
PS F:\DAA> F:\DAA\1.exe
Enter number of elements: 5
Enter sorted array elements: 1 6 7 9 10
Enter target to search: 7
Choose Binary Search method:
1. Recursive
2. Iterative
1
Element found at index 2*/