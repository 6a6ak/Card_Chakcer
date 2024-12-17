#include <iostream>       // For standard input and output
#include <filesystem>     // For filesystem operations
#include <string>         // For string operations
#include <vector>         // For using the vector container
#include <fstream>        // For file input and output
#include <chrono>         // For measuring time

namespace fs = std::filesystem; // Alias for the filesystem namespace

// Function to find files in a directory that start with a given prefix
std::vector<std::string> findFilesStartingWith(const std::string& directory, const std::string& numberPrefix) {
    std::vector<std::string> matchingFiles; // Vector to store matching file names

    // Iterate through the directory
    for (const auto& entry : fs::directory_iterator(directory)) {
        // Check if the entry is a file and the name starts with the prefix
        if (entry.is_regular_file()) {
            std::string fileName = entry.path().filename().string(); // Get the file name
            if (fileName.find(numberPrefix) == 0) { // Check if the file name starts with the prefix
                matchingFiles.push_back(fileName); // Add the matching file name to the vector
            }
        }
    }
    // Return the vector of matching file names
    return matchingFiles;
}

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

    // Start measuring time
    auto start = std::chrono::high_resolution_clock::now();

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

    // Stop measuring time
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;

    return 0; // Return 0 to indicate successful execution
}
