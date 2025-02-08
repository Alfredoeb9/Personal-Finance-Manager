#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

struct Expense {
    std::string category;
    float amount;
    std::string date;

    Expense(const std::string& cat, float amt, const std::string& date)
        : category(cat), amount(amt), date(date) {}
};

struct Income {
    std::string source;
    float amount;
    std::string date;

    Income(const std::string& src, float amt, const std::string& date)
        : source(src), amount(amt), date(date) {}
};

class FinanceManager {
    public:
        std::vector<Expense> expenses;
        std::vector<Income> incomes;

        // Predefined categories for expenses
        std::vector<std::string> predefinedCategories = {"Food", "Entertainment", "Transportation", "Bills", "Health", "Other"};

        // Budgets for each category
        std::unordered_map<std::string, float> categoryBudgets;

        // Handler for saveDatatoFile
        void saveDataToFile();
        void loadDataFromFile();

        // the & here makes it read-only access to the input string
        void addExpense(const std::string& category, float amount, const std::string& date) {
            expenses.push_back(Expense(category, amount, date));
        }

        void addIncome(const std::string& category, float amount, const std:: string& date) {
            incomes.push_back(Income(category, amount, date));
        }

        // Set budget for a category
        void setBudget(const std::string& category, float budget) {
            categoryBudgets[category] = budget;
        }

        void displayReport() {
            float totalExpenses = 0;
            float totalIncome = 0;

            std::cout << "Expenses:\n";

            for (const auto& expense : expenses) {
                std::cout << "Category: " << expense.category 
                        << ", Amount: $" << expense.amount 
                        << ", Date: " << expense.date 
                        << std::endl;
                totalExpenses += expense.amount;
            }

            std::cout << "Income:\n";

            for (const auto& income : incomes) {
                std::cout << "Source: " << income.source 
                        << ", Amount: $" << income.amount 
                        << ", Date: " << income.date 
                        << std::endl;
                totalIncome += income.amount;
            }

            // Optionally display budgeting details
            std::cout << "\nBudget Report:\n";

            for (const auto& budgetPair : categoryBudgets) {
                float spend = 0;
                
                for (const auto& expense : expenses) {
                    if (expense.category == budgetPair.first) {
                        spend += expense.amount;
                    }
                }

                std::cout << "Category: " << budgetPair.first
                            << ", Budget: $" << budgetPair.second
                            << ", Spend: $" << spend << "\n";
            }

            std::cout << "\nTotal Income: $" << totalIncome << std::endl;
            std::cout << "Total Expenses: $" << totalExpenses << std::endl;
            std::cout << "Balance: $" << (totalIncome - totalExpenses) << std::endl;
        }
    
        // Display predefined categories for expenses
    void displayCategories() {
        std::cout << "Available Categories:\n";
        for (const auto& category : predefinedCategories) {
            std::cout << "- " << category << std::endl;
        }
    }
};
