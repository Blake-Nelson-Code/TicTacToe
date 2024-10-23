#include<iostream>
#include<ctime>

/*
    Variables
*/
void makeBoard(char *spaces);
void userMove(char *spaces, char player);
void compMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

/*
    The game
*/
int main() 
{
    char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};

    char player = 'X';
    char computer ='O';
    bool running = true;

    makeBoard(spaces);

    while(running) {
        userMove(spaces, player);
        makeBoard(spaces);
        if(checkWinner(spaces, player, computer)){
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            running = false;
            break;
        }

        compMove(spaces, computer);
        makeBoard(spaces);
        if(checkWinner(spaces, player, computer)){
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            running = false;
            break;
        }
    }
    std::cout << "Thanks for playing.\n";

    return 0;
}
/*
    This manually makes the game creates slots with index point in spaces
*/
void makeBoard(char *spaces) {
    
    std::cout << '\n';
    std::cout << "1    |2    |3    " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "4    |5    |6    " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "7    |8    |9    " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << '\n';

}
/*
    The user input
*/
void userMove(char *spaces, char player) {

    int number;
    do {
        std::cout << "Enter the square number you want to do (1-9): ";
        std::cin >> number;
        number--;
        if(spaces[number] == ' ') {
            spaces[number] = player;
            break;
        }
    }while(!number > 0 || !number < 8);

}
/*
    The computer input
*/
void compMove(char *spaces, char computer) {
    int number;
    srand(time(0));

    while(true){
        number = rand() % 9;
        if(spaces[number] == ' ') {
            spaces[number] = computer;
            break;
        }
    }
}
/*
    returns boolean based on all win conditions
*/
bool checkWinner(char *spaces, char player, char computer) {
  
    /*
        Horizontal win / lose conditions
    */
    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])){
        spaces[0] == player ? std::cout << "YOU WIN\n" : std:: cout << "YOU LOSE\n";
    }
    else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])){
        spaces[0] == player ? std::cout << "YOU WIN\n" : std:: cout << "YOU LOSE\n";
    }
    else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])){
        spaces[0] == player ? std::cout << "YOU WIN\n" : std:: cout << "YOU LOSE\n";
    }
    /*
        Vertical win / lose conditions
    */
   else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])){
        spaces[0] == player ? std::cout << "YOU WIN\n" : std:: cout << "YOU LOSE\n";
    }
    else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])){
        spaces[1] == player ? std::cout << "YOU WIN\n" : std:: cout << "YOU LOSE\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])){
        spaces[2] == player ? std::cout << "YOU WIN\n" : std:: cout << "YOU LOSE\n";
    }
    /*
        Diagonal win / lose conditions
    */
    else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])){
        spaces[0] == player ? std::cout << "YOU WIN\n" : std:: cout << "YOU LOSE\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])){
        spaces[2] == player ? std::cout << "YOU WIN\n" : std:: cout << "YOU LOSE\n";
    }
    else {
        return false;
    }
    
    return true;
    
}
/*
    sees if there are any empty spaces. if not its a tie
*/
bool checkTie(char *spaces) {

    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    std::cout << "It's a Tie.\n";
    return true;

}