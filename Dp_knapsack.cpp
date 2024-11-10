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