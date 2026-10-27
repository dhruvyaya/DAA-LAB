#include <iostream>
#include <vector>
using namespace std;

int N;

bool isSafe(vector<vector<int>>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    for (int i = row - 1, j = col + 1;
         i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int row) {
    if (row == N)
        return true;

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;

            if (solveNQueens(board, row + 1))
                return true;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    cout << "Enter number of queens: ";
    cin >> N;

    if (N <= 0) {
        cout << "Invalid board size." << endl;
        return 0;
    }

    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQueens(board, 0)) {
        cout << "Solution:\n";

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}