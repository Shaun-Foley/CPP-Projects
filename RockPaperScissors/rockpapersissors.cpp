//*************************************************************************************************
//
//      This program demonstrates a simple Rock-Paper-Scissors game. The program allows the user
//      to play the game until they choose to quit. The program will then display the results. 
//
//*************************************************************************************************

//*************************************************************************************************

#include <iostream>
#include <ctime>

//*************************************************************************************************

char getUserChoice(); // users choice of paper sissors rock
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player, char computer);

//*************************************************************************************************

int main() {
    char player;
    char computer;

    player = getUserChoice();
    std::cout << "Your choice: ";
    showChoice(player);

    computer = getComputerChoice();
    std::cout << "Computer's choice: ";
    showChoice(computer);

    chooseWinner(player, computer);


    return 0;
}

//*************************************************************************************************

/**
 * @brief Get the users choice of rock, paper, or scissors 
 * 
 */
char getUserChoice() {
    char player;

    do{
        std::cout << "Rock-Paper-Scissors Game! \n";
        std::cout << "**************************\n";
        std::cout << "Choose one of the following: \n";
        std::cout << "'r' for rock\n";
        std::cout << "'p' for paper\n";
        std::cout << "'s' for scissors\n";
        std::cin >> player;
    }while(player != 'r' && player != 'p' && player != 's');

    return player;
}

//*************************************************************************************************

/**
 * @brief Generate a random choice of rock, paper, or scissors for the computer
 *
 */
char getComputerChoice() {

    srand(time(0));
    int num = rand() % 3 + 1;

    switch(num){ 
        case 1: return 'r';
        case 2: return 'p';
        case 3: return 's';
    }

    return 0;
}

//*************************************************************************************************

/**
 * @brief Output the choice of the user or computer to the console
 * 
 */
void showChoice(char choice) {

    switch(choice) {
        case 'r': std::cout << "Rock\n";
                    break;
        case 'p': std::cout << "Paper\n";
                    break;
        case 's': std::cout << "Scissor\n";
                    break;
    }
}

//*************************************************************************************************

/**
 * @brief Output the result of the game to the console
 * 
 */
void chooseWinner(char player, char computer) {
    switch(player) {
        case 'r':   if(computer == 'r') {
                        std::cout << "It's a tie!\n";
                    }
                    else if(computer == 'p') {
                        std::cout << "You lose!\n";
                    }
                    else {
                        std::cout << "You win\n";
                    }
                    break;
        case 'p':   if(computer == 'p') {
                        std::cout << "It's a tie!\n";
                    }
                    else if(computer == 's') {
                        std::cout << "You lose!\n";
                    }
                    else{
                        std::cout << "You win\n";
                    }
                    break;
        case 's':   if(computer == 's') {
                        std::cout << "It's a tie!\n";
                    }
                    else if(computer == 'r') {
                        std::cout << "You lose!\n";
                    }
                    else {
                        std::cout << "You win\n";
                    }
                    break;
    }
}

//*************************************************************************************************