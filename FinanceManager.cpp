#include "FinanceManager.h"
#include <fstream>

void FinanceManager::saveDataToFile() {
    std::ofstream outFile("finance_data.csv");

    // Write expenses
    for (const auto& expense : expenses) {
        outFile << "Expense," << expense.category << "," 
                << expense.amount << ","
                << expense.date << "\n";
    }

    // Write income
    for (const auto& income : incomes) {
        outFile << "Income," << income.source << "," 
                << income.amount << "," 
                << income.date << "\n";
    }

    outFile.close();
}

void FinanceManager::loadDataFromFile() {
    std::ifstream inFile("finance_data.csv");
    std::string line;

    while (getline(inFile, line)) {
        // Parse each line and populate the expenses and incomes vectors
        // For simplicity, we'll just print it out for now
        std::cout << line << std::endl;
    }

    inFile.close();
}