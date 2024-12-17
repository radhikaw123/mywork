/*Develop a program to implement Huffman Encoding using a greedy 
strategy. */
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    char character;
    int frequency;
    Node* left;
    Node* right;

    Node(char c, int f) : character(c), frequency(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->frequency > b->frequency;
    }
};

void printCodes(Node* root, string code) {
    if (!root) return;

    if (!root->left && !root->right) {
        cout << root->character << " | " << code << '\n';
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

void HuffmanCodes(char characters[], int frequencies[], int size) {
    priority_queue<Node*, deque<Node*>, Compare> minHeap;

    for (int i = 0; i < size; ++i) {
        minHeap.push(new Node(characters[i], frequencies[i]));
    }

    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        Node* newNode = new Node('$', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        minHeap.push(newNode);
    }

    Node* root = minHeap.top();

    cout << "Char | Huffman code\n";
    cout << "-------------------\n";
    printCodes(root, "");
}

int main() {
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;

    // Dynamically allocate arrays based on the user's input
    char* characters = new char[n];
    int* frequencies = new int[n];

    cout << "Enter the characters: ";
    for (int i = 0; i < n; ++i) {
        cin >> characters[i];
    }

    cout << "Enter the corresponding frequencies: ";
    for (int i = 0; i < n; ++i) {
        cin >> frequencies[i];
    }

    HuffmanCodes(characters, frequencies, n);

    // Free the allocated memory
    delete[] characters;
    delete[] frequencies;

    return 0;
}
