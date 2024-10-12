// implement budgetfileio.cpp functions here.

#include <iostream>
#include <fstream>
#include "../include/budgetfileio.hpp"
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

double grossIncome = 0.0;
double totalExpenses = 0.0;
double rent = 0.0;
double utilities = 0.0;
double groceries = 0.0;
double entertainment = 0.0;
double transportation = 0.0;

string readExpensesCSV(const string& inputFilename,
    double& grossIncome,
    double& totalExpenses,
    double& rent,
    double& utilities,
    double& groceries,
    double& entertainment,
    double& transportation)
    {
    ifstream inFile;
    inFile.open(inputFilename);
    if (!inFile.is_open()){
        return "Error: Cannot open file "+inputFilename;
    }

    string line;
    while (getline(inFile, line)){
        stringstream currentline(line);
        string category, type, amount_str, date;

        getline(currentline, category, ',');
        getline(currentline, type, ',');
        getline(currentline, amount_str, ',');
        getline(currentline, date, ',');

        if (category == "Rent"){
            rent = stod(amount_str);
        }else if (category == "Utilities"){
            utilities = stod(amount_str);
        }else if (category == "Groceries"){
            groceries = stod(amount_str);
        }else if (category == "Entertainment"){
            entertainment = stod(amount_str);
        }else if (category == "Transportation"){
            transportation = stod(amount_str);
        }

        if (type == "Expense"){
            totalExpenses += stod(amount_str);
        } else if (type == "Income"){
            grossIncome += stod(amount_str);
        }
    }

    inFile.close();

    return "";
}


string writeBudgetReport(
    const std::string& outFilename,
    double grossIncome,
    double totalExpenses,
    double rent,
    double utilities,
    double groceries,
    double entertainment,
    double transportation
) {
    ofstream outFile;
    outFile.open(outFilename);
    if (!outFile.is_open()){
        return "Error: Cannot open file "+outFilename;
    }
    double rentPercentage = (rent / grossIncome) * 100;
    double utilitiesPercentage = (utilities / grossIncome) * 100;
    double groceriesPercentage = (groceries / grossIncome) * 100;
    double entertainmentPercentage = (entertainment / grossIncome) * 100;
    double transportationPercentage = (transportation / grossIncome) * 100;
    double incomePercentage = (totalExpenses / grossIncome) * 100;
    double netChange = grossIncome - totalExpenses;

    outFile << fixed << setprecision(2);

    outFile << "+---------------------------------------------+\n";
    outFile << "|             Budget Analysis Report          |\n";
    outFile << "+---------------------------------------------+\n";
    outFile << "| Expenses        | Total Spent | %of Income  |\n";
    outFile << "+---------------------------------------------+\n";
    outFile << "| Rent            | $" << setw(10) << rent << " | " << setw(10) << right << rentPercentage << "% |\n";
    outFile << "| Utilities       | $" << setw(10) << utilities << " | " << setw(10) << right << utilitiesPercentage << "% |\n";
    outFile << "| Groceries       | $" << setw(10) << groceries << " | " << setw(10) << right << groceriesPercentage << "% |\n";
    outFile << "| Entertainment   | $" << setw(10) << entertainment << " | " << setw(10) << right << entertainmentPercentage << "% |\n";
    outFile << "| Transportation  | $" << setw(10) << transportation << " | " << setw(10) << right << transportationPercentage << "% |\n";
    outFile << "+---------------------------------------------+\n";

    outFile << "Gross Income: $" << grossIncome << "\n";
    outFile << "Total Expenses: $" << totalExpenses << "\n";
    outFile << "Net Change: $" << netChange << "\n";
    outFile << "Income Percentage: " << incomePercentage << "%\n";

    outFile.close();

    return "";
}
