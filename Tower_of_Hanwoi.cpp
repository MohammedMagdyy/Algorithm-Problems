#include <iostream>
using namespace std;

int count = 0;          // Global variable to keep track of the total number of moves
int arr[10]={0};            // Global array to store the number of moves for each number of disks

/**
 * Recursive function to solve the Tower of Hanoi puzzle.
 *
 * @param n         Number of disks to move.
 * @param from_rod  Name of the rod from which to move the disks.
 * @param to_rod    Name of the rod to which to move the disks.
 * @param aux_rod1  Name of the first auxiliary rod.
 * @param aux_rod2  Name of the second auxiliary rod.
 */
void towerOfHanoi(int n, char from_rod, char to_rod,
                  char aux_rod1, char aux_rod2)
{
    // If the number of moves for this 'n' has already been calculated, return
    if (arr[n] != 0 )
    {
        count += arr[n];    // Update the total count
        return;
    }
    else
    {
        // Base case: if there are 2 disks, it takes 3 moves to solve
        if (n == 2)
        {
            count += 3;         // Update the total count
            arr[n] = count;     // Update the number of moves for this 'n'
            return;
        }

        // Move (n-3) disks from 'from_rod' to 'aux_rod1' using 'aux_rod2' as auxiliary
        towerOfHanoi(n - 3, from_rod, aux_rod1, aux_rod2, to_rod);

        count += 7;     // Update the total count for moving the remaining disks

        // Move (n-3) disks from 'aux_rod1' to 'to_rod' using 'from_rod' as auxiliary
        towerOfHanoi(n - 3, aux_rod1, to_rod, from_rod, aux_rod2);

        arr[n] = count; // Update the number of moves for this 'n'
    }
}

/**
 * Main function.
 */
int main()
{
    int n = 3; // Number of disks

    // A, D, B, and C are names of rods
    towerOfHanoi(n, 'A', 'D', 'B', 'C');

    // Print the total number of moves
    cout << "\nNumber Of Moves = " << ::count;

    return 0;
}
