//*************************************************************************************************
//
//      This program demonstrates a simple command line calculator. It will ask the user
//      to enter two numbers and an operator. It will then perform the operation and 
//      display the result. 
//
//*************************************************************************************************

#include <iostream>

//*************************************************************************************************

int main() {

    char op;
    double num1;
    double num2;
    double result;

    std::cout << "*********** CALCULATOR ***********\n";

    std::cout << "Enter either (+ - * /): ";
    std::cin >> op;

    std::cout << "Enter #1: ";
    std::cin >> num1;

    std::cout << "Enter #2: ";
    std::cin >> num2;

    switch(op){
        case '+':
            result = num1 + num2;
            std::cout << "Result: " << result << '\n';
            break;
        case '-':
            result = num1 - num2;
            std::cout << "Result: " << result << '\n';
            break;
        case '*':
            result = num1 * num2;
            std::cout << "Result: " << result << '\n';
            break;
        case '/':
            result = num1 / num2;
            std::cout << "Result: " << result << '\n';
            break;   
        default:
            std::cout << "Non valid response\n";
            break;
    }
    std::cout << "**********************************";

    return 0;
}

//*************************************************************************************************