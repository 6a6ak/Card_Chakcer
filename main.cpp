#include <iostream>       // For standard input and output
#include <filesystem>     // For filesystem operations
#include <string>         // For string operations
#include <vector>         // For using the vector container

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

int main() {
    std::string directory; // Variable to store the directory path
    std::string prefix;    // Variable to store the prefix

    // Input the directory path
    std::cout << "Enter the directory path: ";
    std::cin >> directory;

    // Input the prefix (number)
    std::cout << "Enter the number prefix to search for: ";
    std::cin >> prefix;

    try {
        // Find files starting with the given prefix in the specified directory
        std::vector<std::string> files = findFilesStartingWith(directory, prefix);

        // Output matching files
        if (!files.empty()) {
            std::cout << "Files starting with \"" << prefix << "\":" << std::endl;
            for (const auto& file : files) {
                std::cout << "- " << file << std::endl; // Print each matching file name
            }
        } else {
            std::cout << "No files found starting with \"" << prefix << "\" in the directory." << std::endl;
        }
    } catch (const std::exception& e) {
        // Handle any exceptions that occur during the file search
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0; // Return 0 to indicate successful execution
}
