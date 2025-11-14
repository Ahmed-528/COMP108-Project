#include <iostream>
using namespace std;


int find_max_sales(double sales[]) {
    int max = 0; // Assume the first day has the highest sales.
    
    for(int i = 1; i < SIZE; i++) {
        if(sales[i] > sales[max]) {
            max = i; // Save the index of the highest sales day.
        }
    }

    cout << "Highest sales is on Day " << (max + 1)
         << " with amount: " << sales[max] << endl;

    return max; // Return the index of the highest day.
}
