#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include <import_data.h>

using namespace std;


// Define a function to parse a line of stock data from the text file
StockData parseLine(string line) {
    StockData data;

    // Split the line into tokens
    istringstream iss(line);
    vector<string> tokens;
    string token;
    while (iss >> token) {
        tokens.push_back(token);
    }

    // Parse the tokens into a StockData object
    data.timestamp = stoi(tokens[0]);
    data.open = stod(tokens[1]);
    data.high = stod(tokens[2]);
    data.low = stod(tokens[3]);
    data.close = stod(tokens[4]);
    data.volume = stod(tokens[5]);

    return data;
}

// Define a function to read in the stock data from the text file
vector<StockData> readStockData(string filename) {
    vector<StockData> data;

    ifstream infile(filename);
    string line;
    while (getline(infile, line)) {
        StockData stockData = parseLine(line);
        data.push_back(stockData);
    }

    return data;
}