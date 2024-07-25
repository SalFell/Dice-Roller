#include <iostream>
#include <random>
#include <string>

void showMainMenu() {
    std::cout << "Main Menu" << std::endl;
    std::cout << "1. Roll Dice" << std::endl;
    std::cout << "2. Exit Program" << std::endl;
    std::cout << "Enter your choice: ";
}

void showRollMenu() {
    std::cout << "Roll Menu" << std::endl;
    std::cout << "Enter the Max value of the dice.\n'M' to go back to the Main Menu." << std::endl;
    std::cout << "Input: ";
}

void rollDie(int sides) {
    // Create a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, sides);
    
    // Generate a random number within the specified range
    int randomNumber = dis(gen);
    
    // Output the random number
    std::cout << "Random number: " << randomNumber << std::endl;
}

int main() {
    int min = 1, max;
    std::string choice;

    while (choice != "2"){
        showMainMenu();
        std::cin >> choice;
        if (choice == "2") {
            break;
        } else if (choice == "1"){
            do{
                showRollMenu();
                std::cin >> choice;
                if (choice == "M" || choice == "m") {
                    break;
                } else if (std::stoi(choice)) {
                    max = std::stoi(choice);
                    std::cout << "Rolling a " << max << " sided die..." << std::endl;
                    rollDie(max);
                } else {
                    std::cout << "Invalid input. Please try again." << std::endl;
                }
            } while (choice != "M" || choice != "m");
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
    std::cout << "Exiting program..." << std::endl;
    return 0;
}
