/*Develop a program to implement Optimal Binary Search Tree using 
Dynamic Programming. */
#include <iostream>
#include <climits>
using namespace std;

// Node structure for the Binary Search Tree
struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Function to calculate the optimal cost of the BST based on successful and unsuccessful search probabilities
double optimalSearchTree(double p[], double q[], int n, int root[][100]) {
    // DP tables to store the costs and weights
    double cost[100][100] = {0};
    double weight[100][100] = {0};

    // Initialize weight and cost tables for base cases (unsuccessful searches)
    for (int i = 0; i <= n; i++) {
        cost[i][i] = 0;        // cost[i][i] is 0 when i == j
        weight[i][i] = q[i];    // weight[i][i] is q[i] when i == j
    }

    // Fill the DP tables for subtrees of size 1 to n
    for (int length = 1; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length;
            cost[i][j] = INT_MAX;

            // Calculate weight[i][j] based on the formula weight[i][j] = p[j-1] + q[j] + weight[i][j-1]
            weight[i][j] = p[j - 1] + q[j] + weight[i][j - 1];

            // Try making every key in this range as root (from i+1 to j)
            for (int k = i + 1; k <= j; k++) {
                double c = cost[i][k - 1] + cost[k][j];
                if (c + weight[i][j] < cost[i][j]) {
                    cost[i][j] = c + weight[i][j];
                    root[i][j] = k; // Store the root of subtree [i, j]
                }
            }
        }
    }

    return cost[0][n];
}

// Recursive function to build the OBST from the root table
Node* buildTree(int root[][100], int keys[], int i, int j) {
    if (i >= j) return nullptr;
    int r = root[i][j];
    Node* node = new Node(keys[r - 1]);  // Create a node with the selected root key
    node->left = buildTree(root, keys, i, r - 1);
    node->right = buildTree(root, keys, r, j);
    return node;
}

// Function to print the tree in pre-order traversal
void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    int n;

    // Input the number of keys
    cout << "Enter the number of keys: ";
    cin >> n;

    int keys[n];        // Array for keys
    double p[n];        // Array for probabilities of successful searches
    double q[n + 1];    // Array for probabilities of unsuccessful searches
    int root[100][100] = {0}; // Array to store roots of subtrees

    // Input the keys
    cout << "Enter the keys: ";
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }

    // Input the probabilities of successful searches
    cout << "Enter the probabilities of successful searches for each key: ";
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    // Input the probabilities of unsuccessful searches
    cout << "Enter the probabilities of unsuccessful searches (including before first key and after last key): ";
    for (int i = 0; i <= n; i++) {
        cin >> q[i];
    }

    // Calculate the minimum cost of the Optimal Binary Search Tree
    double minCost = optimalSearchTree(p, q, n, root);
    cout << "Cost of Optimal Binary Search Tree is: " << minCost << endl;

    // Build and print the tree
    /*Node* treeRoot = buildTree(root, keys, 0, n);
    cout << "Pre-order traversal of the Optimal Binary Search Tree: ";
    preOrder(treeRoot);
    cout << endl*/

    return 0;
}
/*Enter the number of keys: 4
Enter the keys: 1
3
2
4
Enter the probabilities of successful searches for each key: 3
3
1
1
Enter the probabilities of unsuccessful searches (including before first key and after last key): 2
3
1
1
1
Cost of Optimal Binary Search Tree is: 32
Pre-order traversal of the Optimal Binary Search Tree: 3 1 2 4
PS F:\DAA> */