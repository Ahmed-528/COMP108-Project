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
#include <string>
using namespace std;

const int MAX_SALES = 7;

struct DailySales
{
    string dayName;
    double sales;
};

DailySales salesData[MAX_SALES];
DailySales ascendingSalesData[MAX_SALES];
DailySales descendingSalesData[MAX_SALES];

void setupData()
{
    for (int i = 0; i < MAX_SALES; i++)
    {
        salesData[i].dayName = "Day " + to_string(i + 1);
        salesData[i].sales = 0.0;
    }
}

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
    cout << "10. Reset all sales\n";
    cout << "11. Help\n";
    cout << "12. Exit program\n\n";
    cout << "\033[0m";
}

void inputSales() 
{

    for (int i = 0; i < MAX_SALES; i++)
    {
        cout << "\033[33mEnter sale amount for " << salesData[i].dayName << ": \033[0m";
        cin >> salesData[i].sales;
    }

    cout << "\nSales data stored in the array successfully.\n\n\n";
}

void displayArray() 
{
    int i;
    for (i = 0; i < MAX_SALES; i++)
    {
        cout << salesData[i].dayName << "\t|   " << salesData[i].sales << "\n";
    }
}

double sum( int count ) 
{
    double sum = 0;

    for (int i = 0; i < MAX_SALES; ++i)
    {
        sum += salesData[i].sales;
    }

    cout << "\033[33m\nThe total of the sales for these days is: \033[0m" << sum << "\n\n\n";

    return sum;
}

void average(double &avg) 
{

    double sum = 0;

    for (int i = 0; i < MAX_SALES; ++i)
    {
        sum += salesData[i].sales;
    }
    avg = sum / MAX_SALES;

    cout << "\n\033[33mThe average of the sales is:\033[0m " << avg << "\n\n\n";
}

int find_max_sales() 
{
    int maxIndex = 0;

    for (int i = 1; i < MAX_SALES; i++)
    {
        if (salesData[i].sales > salesData[maxIndex].sales)
        {
            maxIndex = i;
        }
    }

    cout << "\033[32mHighest sales is on " << salesData[maxIndex].dayName << " with amount: " << salesData[maxIndex].sales << "\033[32m\n\n\n";

    return maxIndex;
}

int find_lowest_sales() 
{
    int lowestIndex = 0;

    for (int i = 1; i < MAX_SALES; i++)
    {
        if (salesData[i].sales < salesData[lowestIndex].sales)
        {
            lowestIndex = i;
        }
    }

    cout << "\033[31mLowest sales is on " << salesData[lowestIndex].dayName << " with amount: " << salesData[lowestIndex].sales << "\033[32m\n\n\n";

    return lowestIndex;
}

int search_day() 
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

    cout << "\n"
         << salesData[index].dayName << " sales = " << salesData[index].sales << "\n\n";

    return index;
}

void ascendingSort() 
{
    for(int i=0 ; i<MAX_SALES ; i++)
    {
         ascendingSalesData[i] = salesData[i];
    }

    for (int i = 0; i < MAX_SALES - 1; ++i)
    {
        for (int j = 0; j < MAX_SALES - i - 1; ++j)
        {
            if ( ascendingSalesData[j].sales >  ascendingSalesData[j + 1].sales)
            {
                DailySales temp =  ascendingSalesData[j];
                 ascendingSalesData[j] =  ascendingSalesData[j + 1];
                 ascendingSalesData[j + 1] = temp;
            }
        }
    }

    

    cout << "Sorted sales (ascending):\n";
    for (int i = 0; i < MAX_SALES; ++i)
    {
        cout <<  ascendingSalesData[i].dayName << "\t|   " <<  ascendingSalesData[i].sales << "\n";
    }
    cout << "\n";
}

void descendingSort()
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
            if (sortsales[j] < sortsales[j+1])
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

     cout << "Sorted sales (Descending):\n";
    for (int i = 0; i < MAX_SALES; ++i) {
        cout << sortDays[i] << "\t|   " << sortsales[i] << "\n";
    }
    cout << "\n";

}

void SortingOptions()
{

int numberChoice;

  cout<<"Enter 1 for ascending sort or 2 for descending sort: \n";
  cin>>numberChoice;

  if(numberChoice == 1){
    ascendingSort();
  }
  else if(numberChoice == 2){
    descendingSort();
  }
  else
    cout<<"The entered value is not acceptable.\n";
 
}

void showHelp()
{
    cout << "\n===================================" << endl;
    cout << "\t    HELP SECTION" << endl;
    cout << "===================================" << endl;
    cout << "This program helps you track and manage daily sales data.\n\n";

    cout << "MENU OPTIONS EXPLAINED:\n";
    cout << "1. Enter daily sales data - Add new sales figures for different days\n";
    cout << "2. Display all sales - Show all the sales data you have entered\n";
    cout << "3. Calculate total sales - Add up all sales to get the sum\n";
    cout << "4. Calculate average sales - Find the average of all sales\n";
    cout << "5. Show highest sales day - Find the day with the most sales\n";
    cout << "6. Show lowest sales day - Find the day with the least sales\n";
    cout << "7. Search for a sales value - Look for a specific sales amount\n";
    cout << "8. Sales sorting - Arrange sales data in ascending order when 1 is selected and in descending order when 2 is selected\n";
    cout << "9. Save data to file - Store your sales data in a file\n";
    cout << "10. Help - Show this help information\n";
    cout << "11. Exit program - Close the program\n\n";

    cout << "Simply choose a number from the menu to perform that action.\n";
    cout << "After each action, the menu will appear again until you choose to exit.\n";
    cout << "===================================\n\n";
}

void resetAllSales(DailySales *salesPtr)
{
    for (int i = 0; i < MAX_SALES; i++)
    {
        salesPtr[i].sales = 0.0;
    }
    cout << "All sales Data has been successfully reset to zero.\n\n";
}

int updateDaySales()
{
   int day_number;
   cout << "Enter the number of the day to update (1 - "<<MAX_SALES<<"): "; 
   cin >> day_number;
   
    if (day_number < 1 || day_number > MAX_SALES)
    {
        cout << "\nInvalid day number!\n\n";
        return -1;
    }

    int index = day_number - 1;

    cout << "The old sales for "<< salesData[index].dayName<< " is: "<< salesData[index].sales<<endl;
    cout << "Enter the NEW sales: ";
    cin >> salesData[index].sales;
    
    return 1;


}

int main()
{
    int choice;
    double avg, total;

    setupData();

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
            cout << "\n\n";
            break;
        case 3:
            cout << "\nYou chose to calculate total sales.\n\n";
            total = sum(MAX_SALES);
            break;
        case 4:
            cout << "\nYou chose to calculate average sales.\n\n";
            average(avg);
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
            SortingOptions();
            break;
        case 9:
            cout << "\nYou chose to save data to file.\n\n";
            break;
        case 10:
            cout << "\nYou chose to reset all sales.\n";
            resetAllSales(salesData);
            break;
        case 11:
            showHelp();
            break;
        case 12:
            
            cout << "\nExiting program... Goodbye\n\n";
            break;
        default:
            cout << "\nInvalid choice, please try again.\n\n";
            break;
        }
    } while (choice != 12);

    return 0;
}
