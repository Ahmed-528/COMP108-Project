#include <iostream>
using namespace std;
const int SIZE = 7;
string days[SIZE] = {"Sat", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri"};

int search_day();

int search_day()
{
	int day_number;
	cout << "Enter day number (1 - 7): ";
	cin >> day_number;
	if (day_number < 1 || day_number > MAX_SALES)
	{
		cout << "Invalid day number!\n";
		return -1;
	}

	int index = day_number - 1;

	cout << days[index] << " sales = " << sales[index] << endl;

	return index;
}
