#include <iostream>
#include <vector>

using namespace std;

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(const vector<vector<int>>& board, int row, int col, int N) {
    // 1. Check the current column on all previous rows
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // 2. Check the upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // 3. Check the upper diagonal on the right side
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true; // Safe to place the queen
}

// Recursive utility function to solve N-Queens using Backtracking
bool solveNQueensUtil(vector<vector<int>>& board, int row, int N) {
    // Base case: If all queens are placed successfully, return true
    if (row >= N) {
        return true;
    }

    // Consider this row and try placing a queen in all columns one by one
    for (int col = 0; col < N; col++) {
        
        // Check if it is safe to place a queen here
        if (isSafe(board, row, col, N)) {
            
            // Place the queen (mark as 1)
            board[row][col] = 1;

            // Recur to place the rest of the queens in the next rows
            if (solveNQueensUtil(board, row + 1, N)) {
                return true; 
            }

            // BACKTRACKING: If placing the queen here doesn't lead to a solution,
            // remove the queen (mark as 0) and try the next column
            board[row][col] = 0;
        }
    }

    // If the queen cannot be placed in any column in this row, return false
    return false;
}

// Function to initialize the board and start the solving process
void solveNQueens() {
    int N;
    cout << "Enter the number of Queens (N): ";
    cin >> N;

    // Create an N x N matrix initialized with 0s
    vector<vector<int>> board(N, vector<int>(N, 0));

    // Start the backtracking process from row 0
    if (!solveNQueensUtil(board, 0, N)) {
        cout << "Solution does not exist for N = " << N << endl;
        return;
    }

    // Print the solution
    cout << "\nOne possible solution for " << N << " Queens is:\n" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                cout << "Q "; // Q represents a Queen
            } else {
                cout << ". "; // . represents an empty space
            }
        }
        cout << endl;
    }
}

int main() {
    cout << "--- N-Queens Problem Solver ---" << endl;
    solveNQueens();
    return 0;
}
