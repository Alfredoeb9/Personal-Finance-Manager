#include "FinanceManager.h"
#include <iostream>
using namespace std;

void showMenu() {
    std::cout << "1. Add Expense\n";
    std::cout << "2. Add Income\n";
    std::cout << "3. View Report\n";
    std::cout << "4. Save Data\n";
    std::cout << "5. Load Data\n";
    std::cout << "6. Exit\n";
}

int main() {
    FinanceManager manager;
    bool running = true;

    while (running) {
        showMenu();

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string category, date;
                float amount;
                std::cout << "Enter category: ";
                std::cin >> category;
                std::cout << "Enter amount: ";
                std::cin >> amount;
                std::cout << "Enter date (YYYY-MM-DD): ";
                std::cin >> date;
                manager.addExpense(category, amount, date);
                break;
            }
            case 2: {
                std::string source, date;
                float amount;
                std::cout << "Enter source: ";
                std::cin >> source;
                std::cout << "Enter amount: ";
                std::cin >> amount;
                std::cout << "Enter date (YYYY-MM-DD): ";
                std::cin >> date;
                manager.addIncome(source, amount, date);
                break;
            }
            case 3:
                manager.displayReport();
                break;
            case 4:
                manager.saveDataToFile();
                break;
            case 5:
                manager.loadDataFromFile();
                break;
            case 6:
                running = false;
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}