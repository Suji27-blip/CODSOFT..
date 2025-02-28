#include <iostream>
using namespace std;

// Function to draw the Tic-Tac-Toe board
void drawBoard(char board[3][3]) {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

// Function to check if a player has won
bool checkWin(char board[3][3], char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check if the game is a draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char board[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
    char player = 'X';

    while (true) {
        drawBoard(board);
        cout << "Player " << player << ", enter your move (row and column, 0-2): ";
        int row, col;
        cin >> row >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2) {
            cout << "Invalid move, try again." << endl;
            continue;
        }

        if (board[row][col] != '-') {
            cout << "Space already occupied, try again." << endl;
            continue;
        }

        board[row][col] = player;

        if (checkWin(board, player)) {
            drawBoard(board);
            cout << "Player " << player << " wins!" << endl;
            break;
        }

        if (checkDraw(board)) {
            drawBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
