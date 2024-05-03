#include <iostream>  
#include <vector>    

using namespace std;  // Using standard namespace for convenience

// Function to compute the maximum of two integers
int Max(int a, int b) {
    if (a == b)
        return a;
    else if (a > b)
        return a;
    else
        return b;
}

int main() {
    // Values and weights of items
    int p[5] = {0, 1, 2, 5, 6};  // Values of items (index 0 is not used)
    int wt[5] = {0, 2, 3, 4, 5}; // Weights of items (index 0 is not used)

    int m = 8;  // Maximum weight capacity of the knapsack
    int n = 4;  // Number of items

    int k[5][9];  // Table to store maximum values for subproblems

    // Dynamic programming loop to fill the table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                k[i][j] = 0;  // Base case: no items or knapsack capacity is 0
            else if (wt[i] <= j)
                // If current item can be included in the knapsack, compute maximum value
                k[i][j] = Max(p[i] + k[i - 1][j - wt[i]], k[i - 1][j]);
            else
                // If current item cannot be included, use the value without including it
                k[i][j] = k[i - 1][j];
        }
    }

    vector<int> selectedItems;  // Vector to store indices of selected items
    int i = n;
    int j = m;

    // Backtracking to find the selected items
    while (i > 0 && j > 0) {
        if (k[i][j] != k[i - 1][j]) {
            selectedItems.push_back(i);  // Include item i in the selected items
            j = j - wt[i];  // Reduce knapsack capacity by weight of item i
        }
        i--;  // Move to the previous item
    }

    // Printing the selected items and maximum value
    int max_value = 0;
    cout << "Selected items of index i: ";
    for (int i = selectedItems.size() - 1; i >= 0; i--) {
        max_value += p[selectedItems[i]];  // Accumulate value of selected items
        cout << selectedItems[i] << " ";   // Print index of selected item
    }
    cout << endl;

    cout << "Max value achievable: " << max_value << endl;  // Print maximum value

    return 0;  // Indicates successful completion
}
