#include "FinanceManager.h"
#include <iostream>
using namespace std;

void showMenu() {
    std::cout << "1. Add Expense\n";
    std::cout << "2. Add Income\n";
    std::cout << "3. Set Budget\n";
    std::cout << "4. View Report\n";
    std::cout << "5. Save Data\n";
    std::cout << "6. Load Data\n";
    std::cout << "7. Exit\n";
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
                // std::cout << "Enter category: ";
                // std::cin >> category;

                // Show available categories for expense
                manager.displayCategories();
                std::cout << "Enter category (or type 'Other' to input a custom category): ";
                std::cin >> category;

                if (category == "Other") {
                    std::cout << "Enter your custom category: ";
                    std::cin >> category; // User enters a custom category
                }

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
            case 3: {
                std::string budgetCategory;
                float budgetAmount;

                manager.displayCategories();

                std::cout << "Enter category for setting budget: ";
                std::cin >> budgetCategory;
                
                std::cout << "Enter budget amount: ";
                std::cin >> budgetAmount;

                manager.setBudget(budgetCategory, budgetAmount);
                std::cout << "Budget set for " << budgetCategory << " at $" << budgetAmount << "\n";
                break;
            }
            case 4:
                manager.displayReport();
                break;
            case 5:
                manager.saveDataToFile();
                break;
            case 6:
                manager.loadDataFromFile();
                break;
            case 7:
                running = false;
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}