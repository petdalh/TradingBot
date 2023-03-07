#include <iostream>
#include <cstdlib>
#include "import_data.h"

int main() {
  // Call the Python script to download the data
  std::cout << "Calling Python script to download data" << std::endl;
  //system("python3 src/download_data.py");

  // Read in the data from the text file
  std::vector<StockData> data = readStockData("../data/AAPL.txt");
  std::cout << "Number of data points read: " << data.size() << std::endl;

  // Print out the data to verify that it was read in correctly
  for (StockData d : data) {
    std::cout << d.timestamp << " " << d.open << " " << d.high << " " << d.low << " " << d.close << " " << d.volume << std::endl;
  }

  // Continue with your C++ program logic here
  return 0;
}

