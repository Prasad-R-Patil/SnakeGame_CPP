#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

// Game variables
bool gameOver;
const int width = 30;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

// Setup the game
void Setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    nTail = 0;
}

// Draw the board
void Draw() {
    system("cls");

    // Top border
    for (int i = 0; i < width + 2; i++)
        cout << "*";
    cout << endl;

    // Main grid
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) cout << "*";

            if (i == y && j == x)
                cout << "O"; // Snake head
            else if (i == fruitY && j == fruitX)
                cout << "$"; // Food
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o"; // Tail
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }

            if (j == width - 1)
                cout << "*";
        }
        cout << endl;
    }

    // Bottom border
    for (int i = 0; i < width + 2; i++)
        cout << "*";
    cout << endl;

    // Score
    cout << "Score: " << score << endl;
    cout << "W/A/S/D to move | X to exit" << endl;
}

// Input handling
void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a': case 'A':
            dir = LEFT;
            break;
        case 'd': case 'D':
            dir = RIGHT;
            break;
        case 'w': case 'W':
            dir = UP;
            break;
        case 's': case 'S':
            dir = DOWN;
            break;
        case 'x': case 'X':
            gameOver = true;
            break;
        }
    }
}

// Game logic
void Logic() {
    // Move tail
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;

    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // Move head
    switch (dir) {
        case LEFT: x--; break;
        case RIGHT: x++; break;
        case UP: y--; break;
        case DOWN: y++; break;
    }

    // Wall collision
    if (x < 0 || x >= width || y < 0 || y >= height)
        gameOver = true;

    // Self collision
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }

    // Eat food
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}

// Main function
int main() {
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(100); // Adjust speed
    }

    // Game over screen
    system("cls");
    cout << "\n\n\t*** GAME OVER ***\n";
    cout << "\tFinal Score: " << score << "\n\n";
    system("pause");
    return 0;
}
