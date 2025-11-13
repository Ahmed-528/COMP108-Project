#include <iostream>
using namespace std;


const int MAX_SALES = 100;   
double sales[MAX_SALES];    
int nSales = 0;              



void inputSales() {
    cout << "\nEnter number of sales entries (1 - " << MAX_SALES << "): ";
    cin >> nSales;

    if (nSales <= 0 || nSales > MAX_SALES) {   
        cout << "Invalid number!\n";
        nSales = 0;
        return;
    }

    for (int i = 0; i < nSales; i++) {         
        cout << "Enter sale amount for day " << (i + 1) << ": ";
        cin >> sales[i];                      
    }

    cout << "\nSales data stored in the array successfully.\n";
}

