// Copyright (c) 2022 Peter Sobowale All rights reserved.
//
// This program asks for the users age and tells you if you could
// date their grandchild
#include <iostream>
#include <chrono>
#include <thread>



void solveForY(float m, float x, float b) {
    float solveY = m * x + b;
    std::cout << "The value of y is " << solveY << "." << "\n"
    << "The equation is y = "
    << m << "x + " << b << "." << "\n" << "\n";
}


void solveForY2(float m, float x, float b) {
    float solveY2 = m * x - b;
    std::cout << "The value of y is " << solveY2 << "."
    << "\n" << "The equation is y = "
    << m << "x - " << abs(b) << "." << "\n" << "\n";
}


void solveForX(float y, float b, float m) {
    float solveX = (y - b) / m;
    std::cout << "The value of x is " << solveX << "."
    << "\n" << "The equation is y = "
    << m << "x + " << b << "." << "\n" << "\n";
}


void solveForX2(float y, float b, float m) {
    float solveX2 = (y + b) / m;
    std::cout << "The value of x is " << solveX2 << "."
    << "\n" << "The equation is y = "
    << m << "x + " << abs(b) << "." << "\n" << "\n";
}


void solveForM(float y, float b, float x) {
    float m = (y - b) / x;
    std::cout << "The value of m is " << m << "." << "\n"
    << "The equation is y = "
    << m << "x + " << b << "." << "\n" << '\n';
}


void solveForM2(float y, float b, float x) {
    float m2 = (y + b) / x;
    std::cout << "The value of m is " << m2 << "." << "\n"
    << "The equation is y = "
    << m2 << "x + " << abs(b) << "." << "\n" << '\n';
}

void solveForB(float y, float m, float x) {
    float solveB = y - (m * x);
    if (0 <= solveB) {
        std::cout << "The value of b is " << solveB << "."
        << "\n" << "The equation is y = "
        << m << "x + " << solveB << "." << "\n" << "\n";
    } else {
        std::cout << "The value of b is " << solveB << "."
        << "\n" << "The equation is y = "
        << m << "x - " << abs(solveB) << "." << "\n" << "\n";
    }
}


int main() {
    // initialize variables
    std::string operation, mAsAString, xAsAString, bAsAString, yAsAString;
    int check;

    // set use again to y
    std::string useAgain = "y";

    // make while loop and make it run as long as use again is y
    while (useAgain == "y") {
        // # set operation check to false and stop time to display message
        bool operationCheck = false;
        system("clear");
        std::cout << "Welcome to the world's greatest calculator!";
        std::this_thread::sleep_for(std::chrono::milliseconds(2500));

        // while loop that runs as long as operation check is false
        while (operationCheck == false) {
            system("clear");

            // display choices to the user
            std::cout << "\nChoose from one of the following options:";
            std::cout << "\n \t [1]"
                      << " Solve for y -- y=mx+b \n \t "
                      << "[2] Solve for x -- x=(y-b)/m"
                      << " \n \t"
                      << " [3] Solve for m -- m=(y-b)/x \n \t "
                      << "[4] Solve for b -- b=y-mx";

            // get operation from user
            std::cout << "\nEnter your selection: ";
            std::cin >> operation;

            // try to make sure no value or operation other than 1-5 is accepted
            try {
                check = std::stoi(operation);
                if (check >= 1 && check <= 5) {
                    operationCheck = true;
                } else {
                    operationCheck = false;
                }
            } catch (std::bad_exception) {
                operationCheck = false;
            }
        // select case to determine what code should run
        switch (check) {
            case 1:
                system("clear");
                std::cout << "******************";
                std::cout << "\nTo solve for y, you need m, x and b.";

                // get values for m, x and b
                std::cout << "\nEnter a value for m: ";
                std::cin >> mAsAString;
                std::cout << "Enter a value for x: ";
                std::cin >> xAsAString;
                std::cout << "Enter a value for b: ";
                std::cin >> bAsAString;

                // try catch to make sure inputs show no errors
                try {
                    float m = std::stof(mAsAString);
                    float x = std::stof(xAsAString);
                    float b = std::stof(bAsAString);

                    // if statement to check if 0 is greater than b
                    if (0 > b) {
                        solveForY2(m, x, b);
                    } else {
                        solveForY(m, x, b);
                    }
                } catch (std::invalid_argument) {
                    std::cout << "\nEnter a valid value.";
                }
                break;

            // case 2
            case 2:
                system("clear");
                std::cout << "******************";
                std::cout << "\nTo solve for x, you need y, b and m.";

                // Get input for y, b and m
                std::cout << "\nEnter a value for y: ";
                std::cin >> yAsAString;
                std::cout << "Enter a value for b: ";
                std::cin >> bAsAString;
                std::cout << "Enter a value for m: ";
                std::cin >> mAsAString;

                // try catch to make sure inputs show no errors
                try {
                    float y = std::stof(yAsAString);
                    float b = std::stof(bAsAString);
                    float m = std::stof(mAsAString);

                    // if statement to make sure m = 0 as thats an error
                    if (m == 0) {
                        std::cout << "\nYour m cannot be 0.";
                    } else {
                        // if statement to check if b is negative or positive
                        if (0 > b) {
                            solveForX2(y, b, m);
                        } else {
                            solveForX(y, b, m);
                        }
                    }
                } catch (std::invalid_argument) {
                    std::cout << "\nEnter a valid value.";
                }
                break;

            // case #3
            case 3:
                system("clear");
                std::cout << "******************";
                std::cout << "\nTo solve for m, you need y, b and x.";

                // get user input for value y, b and x
                std::cout << "\nEnter a value for y: ";
                std::cin >> yAsAString;
                std::cout << "Enter a value for b: ";
                std::cin >> bAsAString;
                std::cout << "Enter a value for x: ";
                std::cin >> xAsAString;

                // try catch to make sure values have no errors
                try {
                    float y = std::stof(yAsAString);
                    float b = std::stof(bAsAString);
                    float x = std::stof(xAsAString);

                    // if statement to make sure x doesn't equal 0
                    if (x == 0) {
                        std::cout << "\nYour x cannot be 0.";
                    } else {
                        // if statement to check if b is negative or positive
                        if (0 > b) {
                            solveForM2(y, b, x);
                        } else {
                            solveForM(y, b, x);
                        }
                    }
                } catch (std::invalid_argument) {
                    std::cout << "\nEnter a valid value.";
                }
                break;

            // case 4
            case 4:
                system("clear");
                std::cout << "******************";
                std::cout << "\nTo solve for b, you need y, m and x.";

                // get input for values y, m and x
                std::cout << "\nEnter a value for y: ";
                std::cin >> yAsAString;
                std::cout << "Enter a value for m: ";
                std::cin >> mAsAString;
                std::cout << "Enter a value for x: ";
                std::cin >> xAsAString;

                // try catch to make sure no errors in values
                try {
                    float y = std::stof(yAsAString);
                    float m = std::stof(mAsAString);
                    float x = std::stof(xAsAString);

                    // function solve for b
                    solveForB(y, m, x);
                } catch (std::invalid_argument) {
                    std::cout << "\nEnter a valid value.";
                }
                break;
        }

        // defining useAgain to see if user wants to use again or stop
        std::cout << "\n"
                  << "\n"
                  << "Do you want to use it again? (y/n): ";
        std::cin >> useAgain;

        // if statement that stops the program if use again == n or 
        // anything else
        if (useAgain == "n") {
            system("clear");
            std::cout << "Mrs. Raffin is the best computer science teacher.";
            break;
        } else if (useAgain == "y") {
            system("clear");
        } else {
            system("clear");
            std::cout << "Mrs. Raffin is the best computer science teacher.";
            break;
        }
        }
    }
}
