#ifndef IMPORT_DATA_HPP
#define IMPORT_DATA_HPP

#include <vector>
#include <string>

// Define a struct to hold the stock data
struct StockData {
    time_t timestamp;
    double open;
    double high;
    double low;
    double close;
    double volume;
};

// Function declarations
StockData parseLine(std::string line);
std::vector<StockData> readStockData(std::string filename);

#endif // IMPORT_DATA_HPP