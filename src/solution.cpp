#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void extract_logs(const string& date) {
    ifstream log_file("../logs_2024.log");

    ofstream out_file("../output/output_" + date + ".txt");

    if (!log_file.is_open()) {
        cerr << "Error: The log file 'logs_2024.log' was not found." << endl;
        return;
    }

    if (!out_file.is_open()) {
        cerr << "Error: Could not open output file." << endl;
        return;
    }

    string line;
    
    while (getline(log_file, line)) {
        if (line.substr(0, 10) == date) {
            out_file << line << endl;
        }
    }

    cout << "Logs for " << date << " have been written to output/output_" << date << ".txt" << endl;
}

int main() {
    string date;
    
    cout << "Enter the date (YYYY-MM-DD): ";
    cin >> date;
    
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        cerr << "Error: Invalid date format. Please enter a valid date in YYYY-MM-DD format." << endl;
        return 1;
    }

    extract_logs(date);
    
    return 0;
}
