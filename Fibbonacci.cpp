#include <iostream>
#include <vector>
using namespace std;

/*

Write a program non-recursive and recursive program to calculate Fibonacci numbers and analyze 
their time and space complexity. 


*/

int recursiveStepCount = 0;  // To keep track of steps in recursive method

// Recursive Fibonacci function with step counting
int fibonacciRecursive(int n) {
    recursiveStepCount++;  
    if (n <= 1)
        return n;
        
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Iterative Fibonacci function with step counting
void fibonacciIterative(int n) {
    int stepCount = 0;  // To keep track of steps in iterative method
    int a = 0, b = 1;
    cout << "Fibonacci Series (Iterative): ";
    for (int i = 0; i < n; i++) {
        stepCount++;  // Increment step count for each loop iteration
        cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
    }
    cout << "\nTotal Step Count (Iterative) = " << stepCount << endl;
}

int main() {
    int n, choice;
    cout << "Enter the number of terms in the Fibonacci series: ";
    cin >> n;

    cout << "Choose Fibonacci method:\n";
    cout << "1. Recursive\n";
    cout << "2. Iterative\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        // Recursive method

        cout << "Fibonacci Series (Recursive): ";
        for (int i = 0; i < n; i++) {
            cout << fibonacciRecursive(i) << " ";
           
        }
       
    } else if (choice == 2) {
        // Iterative method
        fibonacciIterative(n);
    } else {
        cout << "Invalid choice!" << endl;
    }
    
    cout << recursiveStepCount << endl;

    return 0;
}
