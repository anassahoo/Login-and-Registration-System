#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

class UserManager {
public:
    void registerUser(const std::string& username, const std::string& password) {
        std::ofstream outfile;
        outfile.open("database.txt", std::ios::app);
        if (outfile.is_open()) {
            outfile << username << " " << password << "\n";
            outfile.close();
            std::cout << "Registration successful.\n";
        } else {
            std::cerr << "Error opening file for registration.\n";
        }
    }

    bool loginUser(const std::string& username, const std::string& password) {
        std::ifstream infile("database.txt");
        if (infile.is_open()) {
            std::string fileUsername, filePassword;
            while (infile >> fileUsername >> filePassword) {
                if (fileUsername == username && filePassword == password) {
                    infile.close();
                    return true;
                }
            }
            infile.close();
        } else {
            std::cerr << "Error opening file for login.\n";
        }
        return false;
    }
};

int main() {
    UserManager userManager;
    int choice;

    // Display welcome message
    std::cout << "Welcome to the Registration System\n";

    do {
        std::cout << "1. Register\n";
        std::cout << "2. Login\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string username, password;
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter password: ";
            std::cin >> password;
            userManager.registerUser(username, password);
        } else if (choice == 2) {
            std::string username, password;
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter password: ";
            std::cin >> password;
            if (userManager.loginUser(username, password)) {
                std::cout << "Login successful.\n";
            } else {
                std::cout << "Invalid username or password.\n";
            }
        } else if (choice == 3) {
            std::cout << "Exiting...\n";
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

