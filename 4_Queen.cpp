/*4-Queen matrix is stored having first queen placed; use backtracking to 
place remaining queens to generate the final 4-queen matrix using python. */
#include <iostream> 
using namespace std; 
 
// Function to print the board with queens placed 
void print(int board[10][10], int n) 
{ 
    for (int i = 0; i < n; i++) 
    { 
        for (int j = 0; j < n; j++) 
        { 
            if (board[i][j]) 
                cout << "Q "; // Queen represented by 'Q' 
            else 
                cout << ". "; // Empty cell represented by '.' 
        } 
        cout << "\n"; 
    } 
} 
 
// Function to check if a queen can be placed at board[row][col] 
bool safe(int board[10][10], int row, int col, int n) 
{ 
    // Check the row on the left 
    for (int i = 0; i < col; i++) 
        if (board[row][i]) 
            return false; 
 
    // Check the upper diagonal on the left 
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j]) 
            return false; 
 
    // Check the lower diagonal on the left 
    for (int i = row, j = col; j >= 0 && i < n; i++, j--) 
        if (board[i][j]) 
            return false; 
 
    return true; 
} 
 
// Recursive function to place queens 
bool soln(int board[10][10], int col, int n) 
{ 
    // Base case: if all queens are placed, return true 
    if (col >= n) 
        return true; 
 
    // Try placing a queen in each row of the current column 
    for (int i = 0; i < n; i++) 
    { 
        if (safe(board, i, col, n)) 
        { 
            board[i][col] = 1; // Place queen 
 
            // Recur to place rest of the queens 
            if (soln(board, col + 1, n)) 
                return true; 
 
            board[i][col] = 0; // Backtrack if no solution found 
        } 
    } 
    return false; 
} 
 
// Function to solve the N-Queens problem 
bool solve(int n) 
{ 
    int board[10][10] = {0}; // Initialize the board with all 0s 
 
    if (!soln(board, 0, n)) 
    { 
        cout << "No Solution\n"; 
        return false; 
    } 
 
    print(board, n); 
    return true; 
} 
 
int main() 
{ 
    int n = 4; // Set n to 4 for the 4-Queens problem 
    solve(n); 
    return 0; 
} 
 /*           F:\DAA\7.exe
. . Q . 
Q . . .
. . . Q
. Q . .
PS F:\DAA> */
