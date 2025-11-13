#include <iostream>
using namespace std;

int search(string search_day); // Function prototybe.

// Searches for a day's name in the 'days' array.
// If found, returns the index of the day.
int search(string search_day) {
	for(int i= 0;i<SIZE;i++) {
		if(search_day==days[i]) {
			return i;
		}
	}
}

