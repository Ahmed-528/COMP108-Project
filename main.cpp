/**************************************** 
_________________________________________
| name                   |     id       |
|________________________|______________|
| Ahmed Al Mohammed Ali  |  2260002495  |
|________________________|______________|
| Abdullah Almakki       |  2250001700  |
|________________________|______________|
| Ali Alsalman           |  2260002527  |
|________________________|______________|
| Hassan Al Hamoud       |  2260002413  |
|________________________|______________|
| HASSAN Al Abdullatif   |  2260002440  |
|________________________|______________|
| Hussain Al Ghazwi      |  2260002427  |
|________________________|______________|                       
****************************************/

#include <iostream>
using namespace std;

const int MAX_SALES = 7;
double sales[MAX_SALES];
double sortsales[MAX_SALES];
string days[MAX_SALES] = {"Day 1", "Day 2", "Day 3", "Day 4", "Day 5", "Day 6", "Day 7"};
string sortDays[MAX_SALES];

void menu() //This function displays the menu.
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
    cout << "10. Help\n";
    cout << "11. Exit program\n\n";
    cout << "\033[0m";
}

void inputSales() //This function requires the user to add values.
{

    for (int i = 0; i < MAX_SALES; i++)
    {
        cout << "\033[33mEnter sale amount for day " << (i + 1) << ": \033[0m";
        cin >> sales[i];
    }

    cout << "\nSales data stored in the array successfully.\n\n\n";
}

void displayArray() //This function displays the input values.
{
    int i;
    for (i = 0; i < MAX_SALES; i++)
    {
        cout << days[i] << "\t|   " << sales[i] << "\n";
    }
}

double sum() //This function is to calculate the total sales of the week.
{ 
    double sum = 0;

    for (int i = 0; i < MAX_SALES; ++i)
    { // We use a for loop to go through each array element and calculate the sum.
        sum += sales[i];
    }

    cout << "\033[33m\nThe total of the sales for these days is: \033[0m" << sum << "\n\n\n";

    return sum;
}

double average() //This function is to calculate the average of the week.
{ 

    double sum(0), avg;

    for (int i = 0; i < MAX_SALES; ++i)
    { // We use a for loop to go through each array element and calculate the sum.

        sum += sales[i];
    }
    avg = sum / MAX_SALES;

    cout << "\n\033[33mThe average of the sales is:\033[0m " << avg << "\n\n\n";

    return avg;
}

int find_max_sales() //This function finds the highest sales day.
{
    int max = 0; 

    for (int i = 1; i < MAX_SALES; i++)
    {
        if (sales[i] > sales[max])
        {
            max = i; 
        }
    }

    cout << "\033[32mHighest sales is on Day " << (max + 1) << " with amount: " << sales[max] << "\033[32m\n\n\n";

    return max; 
}

int find_lowest_sales() //This function finds the lowest sales day.
{
    int lowest = 0; 

    for (int i = 1; i < MAX_SALES; i++)
    {
        if (sales[i] < sales[lowest])
        {
            lowest = i; 
        }
    }

    cout << "\033[31mLowest sales is on Day " << (lowest + 1) << " with amount: " << sales[lowest] << "\033[32m\n\n\n";

    return lowest; 
}

int search_day() //This function finds the day that the user is searching for.
{
	int day_number;
	cout << "Enter day number (1 - 7): ";
	cin >> day_number;
	if (day_number < 1 || day_number > MAX_SALES)
	{
		cout << "\nInvalid day number!\n\n";
		return -1;
	}

	int index = day_number - 1;

	cout <<"\n"<< days[index] << " sales = " << sales[index] << "\n\n";

	return index;
}

void sortArray() //This function sorts sales in ascending order.
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

void showHelp()
{
    cout<<"\n==================================="<<endl;
    cout<<"\t    HELP SECTION"<<endl;
    cout<<"==================================="<<endl;
    cout<<"This program helps you track and manage daily sales data.\n\n";
    
    cout<<"MENU OPTIONS EXPLAINED:\n";
    cout<<"1. Enter daily sales data - Add new sales figures for different days\n";
    cout<<"2. Display all sales - Show all the sales data you have entered\n";
    cout<<"3. Calculate total sales - Add up all sales to get the sum\n";
    cout<<"4. Calculate average sales - Find the average of all sales\n";
    cout<<"5. Show highest sales day - Find the day with the most sales\n";
    cout<<"6. Show lowest sales day - Find the day with the least sales\n";
    cout<<"7. Search for a sales value - Look for a specific sales amount\n";
    cout<<"8. Sort sales - Arrange sales data in order ascending\n";
    cout<<"9. Save data to file - Store your sales data in a file\n";
    cout<<"10. Help - Show this help information\n";
    cout<<"11. Exit program - Close the program\n\n";
    
    cout<<"Simply choose a number from the menu to perform that action.\n";
    cout<<"After each action, the menu will appear again until you choose to exit.\n";
    cout<<"===================================\n\n";
}

int main()
{
    int choice;
    double avg, total;
    
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
            displayArray();
            cout<<"\n\n";
            break;
        case 3:
            cout << "\nYou chose to calculate total sales.\n\n";
            total = sum();
            break;
        case 4:
            cout << "\nYou chose to calculate average sales.\n\n";
            avg = average();
            break;
        case 5:
            cout << "\nYou chose to show the highest sales day.\n\n";
            find_max_sales();
            break;
        case 6:
            cout << "\nYou chose to show the lowest sales day.\n\n";
            find_lowest_sales();
            break;
        case 7:
            cout << "\nYou chose to search for a day.\n\n";
            search_day();
            break;
        case 8:
            cout << "\nYou chose to sort sales.\n\n";
            sortArray();
            break;
        case 9:
            cout << "\nYou chose to save data to file.\n\n";
            break;
        case 10:
            showHelp();
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
