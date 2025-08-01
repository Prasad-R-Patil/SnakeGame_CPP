# Snake Game - Console Application

## 📌 Overview

This project is a simple **Console-based Snake Game** written in **C++**. The game is played within a terminal/console window and uses keyboard inputs for controlling the snake's movement. The objective of the game is to eat as much food (`$`) as possible to increase the score while avoiding collisions with the walls or the snake's own tail.

This project is designed for **learning purposes**, focusing on basic game loops, input handling, and rendering in a console environment.

---

## 🎮 Features

* Snake controlled via **W, A, S, D** keys.
* Snake starts with a **longer length (5 units)** instead of just one segment.
* Food (`$`) appears randomly on the grid.
* Snake grows in length after each food is eaten.
* Score increments by **10 points** for every food consumed.
* Game ends on collision with walls or itself.
* Console-based game loop with real-time input detection.

---

## 🏗️ Technology Used

* **Language:** C++
* **Platform:** Windows Console Application
* **Libraries:**

  * `<iostream>` for input/output
  * `<conio.h>` for real-time key detection
  * `<windows.h>` for controlling game speed and console operations

---

## 🛠️ How to Run

1. Clone or download the repository.
2. Open the project in any C++ IDE or compiler (e.g., Code::Blocks, Dev-C++, Visual Studio).
3. Compile the code:

```bash
g++ snake_game.cpp -o snake_game
```

4. Run the executable:

```bash
snake_game.exe
```

---

## 🎯 Game Controls

* **W** → Move Up
* **A** → Move Left
* **S** → Move Down
* **D** → Move Right
* **X** → Exit Game

---

## 📜 Rules

* The game board has a fixed width and height.
* The snake moves continuously in the last chosen direction.
* Colliding with the wall or the snake's own body ends the game.
* Each fruit (`$`) eaten increases the snake length and adds **10 points** to the score.
* The snake starts with a **length of 5 units**, making the game more challenging from the beginning.

---

## 📄 Sample Gameplay (Console)

```
******************************
*                            *
*   Ooooo                    *
*                            *
*              $             *
*                            *
******************************
Score: 20
W/A/S/D to move | X to exit
```

---

## 👤 Author

* **Prasad Ravindra Patil**

---

## 📌 Notes

* This is a **basic version of the classic Snake Game** for console.
* Future enhancements may include difficulty levels, better UI, and sound effects.
* Compatible only with **Windows OS** due to use of `<conio.h>` and `<windows.h>` libraries.
