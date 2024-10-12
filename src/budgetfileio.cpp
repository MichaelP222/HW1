// implement budgetfileio.cpp functions here.
#include <iostream>
#include <fstream>
#include "../include/budgetfileio.hpp"
#include <string>
using namespace std;

ifstream inFile;
ofstream outFile;

std::string readExpensesCSV(const std::string& inputFilename,
    double& grossIncome,
    double& totalExpenses,
    double& rent,
    double& utilities,
    double& groceries,
    double& entertainment,
    double& transportation)
    {
    ifstream file(inputFilename);
    if (!file.is_open()){
        return "Error: Cannot open file $OUTPUTFILENAME"
    }

    string line;
    getline(file, line);
    
}

std::string writeBudgetReport(
    const std::string& outFilename,
    double grossIncome,
    double totalExpenses,
    double rent,
    double utilities,
    double groceries,
    double entertainment,
    double transportation
) {

}


int main() {
    string inputFilename;
    cout << "Please enter the path of CSV file:"
    cin >> inputFilename;

}