//*************************************************************************************************
//
//      This program demonstrates a simple bank program using basic functions. The program allows 
//      the user to view their account balance, deposit money, and withdraw money. The program 
//      continues to run until the user chooses to quit.
//
//*************************************************************************************************


//*************************************************************************************************

#include <iostream>
#include <iomanip>
#include <limits>

//*************************************************************************************************

void showBalance(double balance);
double deposit();
double withdraw(double balance);

//*************************************************************************************************

/**
 * @brief Main entry point of the program. This is the main menu of the program. It
 *        continues to run until the user chooses to quit.
 * 
 */
int main(){

    double balance = 0;
    int choice = 0;

    do {
        std::cout << "Enter your choice: \n";
        std::cout << "1. Show balance \n";
        std::cout << "2. Deposit Money \n";
        std::cout << "3. Withdraw Money \n";
        std::cout << "4. Exit \n";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear(); // Reset error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cout << "Invalid input! Please enter a number between 1 and 4.\n";
            continue; // Go back to the start of the loop
        }

        switch (choice) {

            case 1: showBalance(balance);
                break;
            case 2: balance += deposit();
                showBalance(balance);
                break;
            case 3: balance -= withdraw(balance);
                showBalance(balance);
                break;
            case 4: std::cout << "Thanks for visiting!\n";
                break;
            default: std::cout << "Invalid response";
        }
    } while (choice != 4);
    
    return 0;
}

//*************************************************************************************************


/**
 * @brief shows the current balance of the account in the console.
 *        The balance will be displayed with 2 decimal places.
 * 
 */

void showBalance (double balance) { // display up 2 decimal points
    std::cout << "Your balance is: $" << std::setprecision(2)<< std::fixed << balance << "\n";
}

//*************************************************************************************************

/**
 * @brief Asks the user to input an amount to deposit into their account.
 * 
 */
double deposit () {

    double amount = 0;

    std::cout << "Enter amount to be deposited: ";
    std::cin >> amount;

    if (std::cin.fail()) {
        std::cin.clear(); // Reset error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
        std::cout << "Invalid input! Please enter a valid number.\n";
        return 0;
    }

    if(amount > 0) {
        return amount;
    }
    else{
        std::cout << "That's not a valid amount";
        return 0;
    }
    
}

//*************************************************************************************************

/**
 * @brief Asks the user to input an amount to withdraw from their account.
 * 
 */

double withdraw(double balance) {

    double amount = 0;

    std::cout << "Enter amount to be withdrawed: ";
    std::cin >> amount;

    if (std::cin.fail()) {
        std::cin.clear(); // Reset error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
        std::cout << "Invalid input! Please enter a valid number.\n";
        return 0;
    }
    
    if(amount > balance) {
        std::cout << "Insufficient funds";
        return 0; 
    }
    else if(amount < 0) {
        std::cout << "That's not a valid amount";
        return 0;
    }
    else{
        return amount;
    }
}

//*************************************************************************************************