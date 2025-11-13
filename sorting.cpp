#include <iostream>
using namespace std;

const int MAX_SALES = 7;
double sales[MAX_SALES];
double sortsales[MAX_SALES];
string days[MAX_SALES] = {"Day 1", "Day 2", "Day 3", "Day 4", "Day 5", "Day 6", "Day 7"};
string sortDays[MAX_SALES];

void sortArray()
{
    for (int i = 0; i < MAX_SALES; ++i)
    {
        sortsales[i] = sales[i];
    }
    for (int i = 0; i < MAX_SALES; ++i)
    {
        sortDays[i] = days[i];
    }

    for (int i = 0; i < MAX_SALES - 1; ++i)
    {
        for (int j = 0; j < MAX_SALES - i - 1; ++j)
        {
            if (sortsales[j] > sortsales[j+1])
            {
                double tempVal = sortsales[j];
                sortsales[j] = sortsales[j+1];
                sortsales[j+1] = tempVal;

               
                string tempDay = sortDays[j];
                sortDays[j] = sortDays[j+1];
                sortDays[j+1] = tempDay;
            }
        }
    }

     cout << "Sorted sales (ascending):\n";
    for (int i = 0; i < MAX_SALES; ++i) {
        cout << sortDays[i] << "\t|   " << sortsales[i] << "\n";
    }
    cout << "\n";

}
