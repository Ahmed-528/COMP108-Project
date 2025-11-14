#include <iostream>
using namespace std;

int find_lowest_sales(double sales[]) {
    int lowest = 0; // Assume the first day has the lowest sales.
    
    for(int i = 1; i < SIZE; i++) {
        if(sales[i] < sales[lowest]) {
            lowest = i; // Save the index of the lowest sales day.
        }
    }

    cout << "Lowest sales is on Day " << (lowest + 1)
         << " with amount: " << sales[lowest] << endl;

    return lowest; // Return the index of the lowest day.
}
