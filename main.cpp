#include <iostream>       // For standard input and output
#include <filesystem>     // For filesystem operations
#include <string>         // For string operations
#include <vector>         // For using the vector container
#include <fstream>        // For file input and output

namespace fs = std::filesystem; // Alias for the filesystem namespace

// Function to check if a card number is in the file
bool isCardNumberInFile(const std::string& filePath, const std::string& cardNumber) {
    std::ifstream file(filePath); // Open the file
    std::string line;
    while (std::getline(file, line)) { // Read each line
        if (line == cardNumber) { // Check if the line matches the card number
            return true; // Card number found
        }
    }
    return false; // Card number not found
}

int main() {
    std::string directory = "cards"; // Default directory path
    std::string cardNumber; // Variable to store the card number

    // Input the card number
    std::cout << "Enter the card number to search for: ";
    std::cin >> cardNumber;

    // Get the first digit of the card number to determine the file to search in
    char firstDigit = cardNumber[0];
    std::string fileName = std::string(1, firstDigit) + "_valid_cards.csv";
    std::string filePath = directory + "/" + fileName;

    try {
        // Check if the card number is in the determined file
        if (isCardNumberInFile(filePath, cardNumber)) {
            std::cout << "\033[42mCard number " << cardNumber << " is valid and found in the file " << fileName << ".\033[0m" << std::endl;
        } else {
            std::cout << "\033[41mCard number " << cardNumber << " is not found in the file " << fileName << ".\033[0m" << std::endl;
        }
    } catch (const std::exception& e) {
        // Handle any exceptions that occur during the file search
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0; // Return 0 to indicate successful execution
}
