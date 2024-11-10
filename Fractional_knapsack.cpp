#include <iostream>
#include <vector>
using namespace std;

/*

Write a program to solve a fractional Knapsack problem using a greedy method.

*/

struct Item {
    int value, weight;
    Item(int v, int w) : value(v), weight(w) {}
};

// Comparison function to sort items by value-to-weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item> &items) {
    sort(items.begin(), items.end(), compare);  // Sort items by value-to-weight ratio
    double maxValue = 0.0;

    for (auto &item : items) {
        if (W >= item.weight) {  // If full item can be taken
            W -= item.weight;
            maxValue += item.value;
        } else {  // Take fractional part
            maxValue += item.value * ((double)W / item.weight);
            break;
        }
    }
    return maxValue;
}

int main() {
    int W = 50;  // Knapsack capacity
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};  // {value, weight}

    double maxValue = fractionalKnapsack(W, items);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}