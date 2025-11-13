#include <iostream>
#include <fstream>
using namespace std;

double sales[100];
int nSales = 0;

void saveSalesToTxt() {
    if (nSales == 0) {
        cout << "No data to save! Please input sales first.\n";
        return;
    }

    ofstream file("sales.txt");

    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    file << "Sales Data\n";
    file << "===========\n";

    for (int i = 0; i < nSales; i++) {
        file << "Day " << (i + 1) << ": " << sales[i] << "\n";
    }

    file.close();
    cout << "Data saved successfully to sales.txt\n";
}
