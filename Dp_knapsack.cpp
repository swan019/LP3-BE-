#include <iostream>
#include <vector>
using namespace std;

/*

 Write a program to solve a 0-1 Knapsack problem using dynamic programming strategy.

*/

int knapsack(int W, vector<int> &weights, vector<int> &values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the dp array
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w)  // Check if the weight of the item can be included
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];  // Maximum value that can be achieved with the given capacity
}

int main() {
    int W = 50;  // Knapsack capacity
    vector<int> values = {60, 100, 120};  // Item values
    vector<int> weights = {10, 20, 30};  // Item weights
    int n = values.size();

    int maxValue = knapsack(W, weights, values, n);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}












--------------------------------------------------------------------------------------------------------------------------------------------
 #include <bits/stdc++.h>
using namespace std;

// Function to solve the unbounded knapsack problem
int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp) {
    // Base case: if we're at the first item
    if (ind == 0) {
        // Calculate and return the maximum value for the given weight limit
        return (W / wt[0]) * val[0];
    }
    
    // If the result for this index and weight limit is already calculated, return it
    if (dp[ind][W] != -1)
        return dp[ind][W];
        
    // Calculate the maximum value without taking the current item
    int notTaken = 0 + knapsackUtil(wt, val, ind - 1, W, dp);
    
    // Calculate the maximum value by taking the current item
    int taken = INT_MIN;
    if (wt[ind] <= W)
        taken = val[ind] + knapsackUtil(wt, val, ind, W - wt[ind], dp);
        
    // Store the maximum value in the DP table and return it
    return dp[ind][W] = max(notTaken, taken);
}

// Function to solve the unbounded knapsack problem
int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<vector<int>> dp(n, vector<int>(W + 1, -1)); // Create a DP table
    
    // Call the utility function to calculate the maximum value
    return knapsackUtil(wt, val, n - 1, W, dp);
}

int main() {
    vector<int> wt = {2, 4, 6}; // Weight of items
    vector<int> val = {5, 11, 13}; // Value of items
    int W = 10; // Weight capacity of the knapsack
    int n = wt.size(); // Number of items
    
    // Call the function to calculate and output the maximum value the thief can steal
    cout << "The Maximum value of items the thief can steal is " << unboundedKnapsack(n, W, val, wt) << endl;

    return 0; // Return 0 to indicate successful program execution
}



-----------------------------------------------------N Queen--------------------------------------------------------------------------------

 #include <bits/stdc++.h>
using namespace std;

// A utility function to print solution
void printSolution(vector<vector<int>>& board) {
    int n = board.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if(board[i][j])
                cout << "Q ";
            else
                cout << ". ";
        cout << "\n";
    }
}

// A utility function to check if a queen can
// be placed on board[row][col]. Note that this
// function is called when "col" queens are
// already placed in columns from 0 to col -1.
// So we need to check only left side for
// attacking queens
bool isSafe(vector<vector<int>>& board, 
                    int row, int col) {
    int n = board.size();
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && 
         j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && 
         i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// A recursive utility function to solve N
// Queen problem
bool solveNQUtil(vector<vector<int>>& board, int col) {
    int n = board.size();
  
    // base case: If all queens are placed
    // then return true
    if (col >= n)
        return true;

    // Consider this column and try placing
    // this queen in all rows one by one
    for (int i = 0; i < n; i++) {

        // Check if the queen can be placed on
        // board[i][col]
        if (isSafe(board, i, col)) {

            // Place this queen in board[i][col]
            board[i][col] = 1;

            // recur to place rest of the queens
            if (solveNQUtil(board, col + 1))
                return true;

            // If placing queen in board[i][col]
            // doesn't lead to a solution, then
            // remove queen from board[i][col]
            board[i][col] = 0; // BACKTRACK
        }
    }

    // If the queen cannot be placed in any row in
    // this column col then return false
    return false;
}

// This function solves the N Queen problem using
// Backtracking. It mainly uses solveNQUtil() to
// solve the problem. It returns false if queens
// cannot be placed, otherwise, return true and
// prints placement of queens in the form of 1s.
// Please note that there may be more than one
// solutions, this function prints one of the
// feasible solutions.
bool solveNQ(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solveNQUtil(board, 0) == false) {
        cout << "Solution does not exist";
        return false;
    }

    printSolution(board);
    return true;
}

// Driver program to test above function
int main() {
    int n = 4;
    solveNQ(n);
    return 0;
}


----------------------------------------------------Haffman coding-----------------------------------------------------------------------------------
 #include<bits/stdc++.h>
using namespace std;

// A Huffman tree node



struct Node {
    char ch; // Character
    int freq; // Frequency of the character
    Node* left; // Left child
    Node* right; // Right child

    Node(char character, int frequency) {
        ch = character;
        freq = frequency;
        left = right = nullptr;
    }
};

// Comparator to order the priority queue (min-heap) based on frequency
struct compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

// Function to print Huffman codes from the root of Huffman Tree
void printCodes(Node* root, string str, unordered_map<char, string>& huffmanCode) {
    if (!root)
        return;

    // If the node is a leaf (contains a character), store the code
    if (!root->left && !root->right)
        huffmanCode[root->ch] = str;

    printCodes(root->left, str + "0", huffmanCode);
    printCodes(root->right, str + "1", huffmanCode);
}

// Function to implement Huffman Encoding
void huffmanEncoding(const vector<char>& characters, const vector<int>& frequencies) {
    // Priority queue to store the tree nodes (min-heap)
    priority_queue<Node*, vector<Node*>, compare> pq;

    // Create leaf nodes for each character and push into the priority queue
    for (int i = 0; i < characters.size(); ++i) {
        pq.push(new Node(characters[i], frequencies[i]));
    }

    // Iterate until there is only one node left in the priority queue
    while (pq.size() != 1) {
        // Extract the two nodes with the smallest frequencies
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        // Create a new internal node with frequency equal to the sum of the two nodes' frequencies
        // The new node's character is a special marker (like '\0')
        Node* newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        // Push the new node back into the priority queue
        pq.push(newNode);
    }

    // The root of the Huffman Tree is the only remaining node in the priority queue
    Node* root = pq.top();

    // Generate and print the Huffman codes by traversing the Huffman tree
    unordered_map<char, string> huffmanCode;
    printCodes(root, "", huffmanCode);

    // Display the Huffman codes
    cout << "Huffman Codes:\n";
    for (auto& pair : huffmanCode) {
        cout << pair.first << " : " << pair.second << "\n";
    }
}

int main() {
    // Input characters and their respective frequencies
    vector<char> characters = { 'a', 'b', 'c', 'd', 'e', 'f' };
    vector<int> frequencies = { 5, 9, 12, 13, 16, 45 };

    // Perform Huffman encoding
    huffmanEncoding(characters, frequencies);

    return 0;
}
