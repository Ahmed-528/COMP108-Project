#include <iostream>
using namespace std;

const int MAX_SALES = 7;
double sales[MAX_SALES];
string days[MAX_SALES] = {"Day 1", "Day 2", "Day 3", "Day 4", "Day 5", "Day 6", "Day 7"};

void menu()
{
    cout << "\033[94m";
    cout << "===================================" << endl;
    cout << "\t Sales Tracker Menu" << endl;
    cout << "===================================" << endl;
    cout << "1. Enter daily sales data\n";
    cout << "2. Display all sales\n";
    cout << "3. Calculate total sales\n";
    cout << "4. Calculate average sales\n";
    cout << "5. Show highest sales day\n";
    cout << "6. Show lowest sales day\n";
    cout << "7. Search for a day\n";
    cout << "8. Sort sales\n";
    cout << "9. Save data to file\n";
    cout << "10. help\n";
    cout << "11. Exit program\n\n";
    cout << "\033[0m";
}

void inputSales()
{

    for (int i = 0; i < MAX_SALES; i++)
    {
        cout << "\033[33mEnter sale amount for day " << (i + 1) << ": \033[0m";
        cin >> sales[i];
    }

    cout << "\nSales data stored in the array successfully.\n\n\n";
}

int find_max_sales(double sales[]) {
	int max= 0; // Assume the first day has the highest sales.
	
	for(int i=1; i< MAX_SALES ;i++) {
		if(sales[i]>sales[max]) {
			max= i; //  Save the index of the highest sales day.
		}
	}
	  return max; // Return the index of the highest day.
}

int search(string search_day)
{
    for (int i = 0; i < MAX_SALES; i++)
    {
        if (search_day == days[i])
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int choice;
    do
    {
        menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nYou chose to enter sales data.\n\n";
            inputSales();
            break;
        case 2:
            cout << "\nYou chose to display sales.\n\n";
            break;
        case 3:
            cout << "\nYou chose to calculate total sales.\n\n";
            break;
        case 4:
            cout << "\nYou chose to calculate average sales.\n\n";
            break;
        case 5:
            cout << "\nYou chose to show the highest sales day.\n\n";
            break;
        case 6:
            cout << "\nYou chose to show the lowest sales day.\n\n";
            break;
        case 7:
            cout << "\nYou chose to searsh for a day.\n\n";
            
            break;
        case 8:
            cout << "\nYou chose to sort sales.\n\n";
            break;
        case 9:
            cout << "\nYou chose to save data to file.\n\n";
            break;
        case 10:

            break;
        case 11:

            cout << "\nExiting program... Goodbye\n\n";
            break;
        default:
            cout << "\nInvalid choice, please try again.\n\n";
            break;
        }
    } while (choice != 11);

    return 0;
}
