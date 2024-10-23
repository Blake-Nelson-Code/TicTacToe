# Tic-Tac-Toe Game

## Description
This is a simple console-based Tic-Tac-Toe game implemented in C++. The game allows a player to compete against the computer. The player is represented by 'X', and the computer is represented by 'O'. The game board consists of 9 spaces, which are numbered 1 to 9 for easy input from the user. 

The game checks for a winner after each move and will also detect a tie if the board is full and no player has won.

## How to Play
1. The player will be prompted to enter a number (1-9) corresponding to the space they want to place their 'X'.
2. The computer will randomly choose an available space for its move, placing an 'O'.
3. The game checks after every move whether a player has won or if the game has resulted in a tie.
4. The game ends when either the player or the computer wins, or when the board is full, resulting in a tie.

## Code Overview

### Variables and Functions

- `void makeBoard(char *spaces)`  
  This function prints the current state of the game board.
  
- `void userMove(char *spaces, char player)`  
  This function prompts the user to input a move and updates the board.
  
- `void compMove(char *spaces, char computer)`  
  This function randomly selects an empty space for the computer's move.
  
- `bool checkWinner(char *spaces, char player, char computer)`  
  This function checks if either the player or the computer has won the game.
  
- `bool checkTie(char *spaces)`  
  This function checks if the game has ended in a tie.

### Main Game Loop

The game loop runs while the variable `running` is set to true. In each iteration:
1. The player makes a move.
2. The board is updated and displayed.
3. The game checks if the player has won or if the game is a tie.
4. If the player hasn’t won or tied, the computer makes a move.
5. The board is updated and displayed again.
6. The game checks if the computer has won or if the game is a tie.


## Game End Conditions
- If the player wins, the message `YOU WIN` will be displayed.
- If the computer wins, the message `YOU LOSE` will be displayed.
- If all spaces are filled and no winner is found, the message `It's a Tie` will be displayed.

## License
This project is for educational purposes and is not licensed for commercial use.

