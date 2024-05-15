#include <iostream>
#include <vector>
using namespace std;

class TicTacToe {
public:
    TicTacToe() {
        board.resize(3, vector<char>(3, ' '));
    }

    void playGame() {
        char currentPlayer = 'X';
        bool gameEnded = false;

        while (!gameEnded) {
            printBoard();
            playerMove(currentPlayer);
            gameEnded = checkWin(currentPlayer);

            if (!gameEnded) {
                gameEnded = checkDraw();
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        printBoard();
        if (gameEnded) {
            cout << "Player " << ((currentPlayer == 'X') ? 'O' : 'X') << " wins!" << endl;
        } else {
            cout << "The game is a draw!" << endl;
        }
    }

private:
    vector<vector<char>> board;

    void printBoard() {
        cout << "  0 1 2" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << i << " ";
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j];
                if (j < 2) cout << "|";
            }
            cout << endl;
            if (i < 2) cout << "  -+-+-" << endl;
        }
    }

    void playerMove(char player) {
        int row, col;
        while (true) {
            cout << "Player " << player << ", enter your move (row and column): ";
            cin >> row >> col;
            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
                board[row][col] = player;
                break;
            } else {
                cout << "This move is not valid. Try again." << endl;
            }
        }
    }

    bool checkWin(char player) {
        // Check rows
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
                return true;
            }
        }

        // Check columns
        for (int i = 0; i < 3; ++i) {
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
                return true;
            }
        }

        // Check diagonals
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
            return true;
        }
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
            return true;
        }

        return false;
    }

    bool checkDraw() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    char playAgain;
    do {
        TicTacToe game;
        game.playGame();

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
