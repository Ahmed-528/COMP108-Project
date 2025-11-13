#include <iostream>
using namespace std;

const int MAX_SALES = 7;
double sales[MAX_SALES];

void inputSales()
{

    for (int i = 0; i < MAX_SALES; i++)
    {
        cout << "Enter sale amount for day " << (i + 1) << ": ";
        cin >> sales[i];
    }

    cout << "\nSales data stored in the array successfully.\n";
}
