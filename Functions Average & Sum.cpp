#include <iostream>
using namespace std;

double average(double arr[], int size) { // This function is to calculate the average of the week.

	double sum(0), avg;

	for (int i = 0; i < size; ++i) { // We use a for loop to go through each array element and calculate the sum.

		sum += arr[i];
	}
	avg = sum / size;

	cout << "\nThe average of the sale is: " << avg << endl;

	return avg;
}

double sum(double arr[], int size) { // This function is to calculate the total sales of the week.
	double sum = 0;

	for (int i = 0; i < size; ++i) { //The same reason as above.
		sum += arr[i];
	}

	cout << "\nThe total of the sale for these days is: " << sum << endl;

	return sum;
}

int main() {// Main function is for testing the above functions.

	const int size(7);

	double sales[size]; 

	double avg, total;

	cout << "Enter the sales for 7 days: " << endl;

	for (int i = 0; i < size; ++i) {
		cout << "Day " << (i + 1) << ": ";
		cin >> sales[i];
	}

	avg = average(sales, size);

	total = sum(sales, size);

	return 0;

}