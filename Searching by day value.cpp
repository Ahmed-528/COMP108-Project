#include <iostream>
using namespace std;

void SearchByValue(double sales[], int size) { //This function searches for a sales value in the sales array

	double value;

	cout << "which sales value do you want to search for? ";
	cin >> value;

	bool found = false;		//A boolean variable to keep track if the value was found or not

	for (int i = 0; i < size; ++i) {		//We use the loop to search through the sales array unitl it matches the value
		if (sales[i] == value) {
			cout << "\nValue " << value << " found on day " << (i + 1) << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "\nValue " << value << " was NOT found in any day.\n";
	}
}

int main() {	//This main only for testing the SearchByValue function

	const int size(7);
	double sales[size];

	cout << "Enter the sales for 7 days: " << endl;

	for (int i = 0; i < size; ++i) {
		cout << "Day " << (i + 1) << ": ";
		cin >> sales[i];
	}

	SearchByValue(sales, size);

	return 0;
}