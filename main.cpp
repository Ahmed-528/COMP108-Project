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
#include <fstream>
using namespace std;

const int MAX_SALES = 7;

struct DailySales
{
    string dayName;
    double sales;
    string currency;
};

DailySales salesDataSAR[MAX_SALES];
DailySales salesDataUSD[MAX_SALES];
DailySales ascendingSalesData[MAX_SALES];
DailySales descendingSalesData[MAX_SALES];

void setupDataSAR()
{
    for (int i = 0; i < MAX_SALES; i++)
    {
        salesDataSAR[i].dayName = "Day " + to_string(i + 1);
        salesDataSAR[i].sales = 0.0;
        salesDataSAR[i].currency = "SAR";
    }
}

void setupDataUSD()
{
    for (int i = 0; i < MAX_SALES; i++)
    {
        salesDataUSD[i].dayName = "Day " + to_string(i + 1);
        salesDataUSD[i].sales = 0.0;
        salesDataUSD[i].currency = "$";
    }
}

void menuSAR()
{
    cout << "\033[94m";
    cout << "===================================" << endl;
    cout << "\t Sales Tracker Menu" << endl;
    cout << "===================================" << endl;
    cout << "1. Enter daily sales data\n";
    cout << "2. Display all sales\n";
    cout << "3. Calculate total sales\n";
    cout << "4. Calculate average sales\n";
    cout << "5. Show maximum or minimum sales day\n";
    cout << "6. Search data (By Day / By sales)\n";
    cout << "7. Sort sales\n";
    cout << "8. Update day sales\n";
    cout << "9. Save data to file\n";
    cout << "10. Convert sales to USD\n";
    cout << "11. Generate Full Report (Summary)\n";
    cout << "12. Reset all sales\n";
    cout << "13. Help\n";
    cout << "14. Exit program\n\n";
    cout << "\033[0m";
}

void menuUSD()
{
    cout << "\033[94m";
    cout << "===================================" << endl;
    cout << "\t Sales Tracker Menu" << endl;
    cout << "===================================" << endl;
    cout << "1. Enter daily sales data\n";
    cout << "2. Display all sales\n";
    cout << "3. Calculate total sales\n";
    cout << "4. Calculate average sales\n";
    cout << "5. Show maximum or minimum sales day\n";
    cout << "6. Search data (By Day / By sales)\n";
    cout << "7. Sort sales\n";
    cout << "8. Update day sales\n";
    cout << "9. Save data to file\n";
    cout << "10. Convert sales to SAR\n";
    cout << "11. Generate Full Report (Summary)\n";
    cout << "12. Reset all sales\n";
    cout << "13. Help\n";
    cout << "14. Exit program\n\n";
    cout << "\033[0m";
}

double getValidSale()
{
    double value;

    while (!(cin >> value) || value <= 0)
    {
        if (cin.fail())
        {
            cout << "Invalid! Enter a value : ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    return value;
}

void inputSalesSAR()
{
    for (int i = 0; i < MAX_SALES; i++)
    {
        cout << "\033[33mEnter sale amount for " << salesDataSAR[i].dayName << ": \033[0m";
        salesDataSAR[i].sales = getValidSale();
    }

    cout << "\nSales data stored in the array successfully.\n\n\n";
}

void inputSalesUSD()
{
    for (int i = 0; i < MAX_SALES; i++)
    {
        cout << "\033[33mEnter sale amount for " << salesDataUSD[i].dayName << ": \033[0m";
        salesDataUSD[i].sales = getValidSale();
    }

    cout << "\nSales data stored in the array successfully.\n\n\n";
}

void displayArraySAR()
{
    int i;
    for (i = 0; i < MAX_SALES; i++)
    {
        cout << salesDataSAR[i].dayName << "\t|   " << salesDataSAR[i].sales << " " << salesDataSAR[i].currency << "\n";
    }
}

void displayArrayUSD()
{
    int i;
    for (i = 0; i < MAX_SALES; i++)
    {
        cout << salesDataUSD[i].dayName << "\t|   " << salesDataUSD[i].sales << " " << salesDataUSD[i].currency << "\n";
    }
}

double sumSAR(int count)
{
    double sum = 0;

    for (int i = 0; i < MAX_SALES; ++i)
    {
        sum += salesDataSAR[i].sales;
    }

    cout << "\033[33m\nThe total of the sales for these days is: \033[0m" << sum << " " << salesDataSAR[0].currency << "\n\n\n";

    return sum;
}

double sumUSD(int count)
{
    double sum = 0;

    for (int i = 0; i < MAX_SALES; ++i)
    {
        sum += salesDataUSD[i].sales;
    }

    cout << "\033[33m\nThe total of the sales for these days is: \033[0m" << sum << " " << salesDataUSD[0].currency << "\n\n\n";

    return sum;
}

void averageSAR(double &avg)
{

    double sum = 0;

    for (int i = 0; i < MAX_SALES; ++i)
    {
        sum += salesDataSAR[i].sales;
    }
    avg = sum / MAX_SALES;

    cout << "\n\033[33mThe average of the sales is:\033[0m " << avg << " " << salesDataSAR[0].currency << "\n\n\n";
}

void averageUSD(double &avg)
{

    double sum = 0;

    for (int i = 0; i < MAX_SALES; ++i)
    {
        sum += salesDataUSD[i].sales;
    }
    avg = sum / MAX_SALES;

    cout << "\n\033[33mThe average of the sales is:\033[0m " << avg << " " << salesDataUSD[0].currency << "\n\n\n";
}

int findMaxSalesSAR()
{
    int maxIndex = 0;

    for (int i = 1; i < MAX_SALES; i++)
    {
        if (salesDataSAR[i].sales > salesDataSAR[maxIndex].sales)
        {
            maxIndex = i;
        }
    }

    cout << "\033[32mHighest sales is on " << salesDataSAR[maxIndex].dayName << " with amount: " << salesDataSAR[maxIndex].sales << " " << salesDataSAR[maxIndex].currency << "\033[32m\n\n\n";

    return maxIndex;
}

int findMaxSalesUSD()
{
    int maxIndex = 0;

    for (int i = 1; i < MAX_SALES; i++)
    {
        if (salesDataUSD[i].sales > salesDataUSD[maxIndex].sales)
        {
            maxIndex = i;
        }
    }

    cout << "\033[32mHighest sales is on " << salesDataUSD[maxIndex].dayName << " with amount: " << salesDataUSD[maxIndex].sales << " " << salesDataUSD[maxIndex].currency << "\033[32m\n\n\n";

    return maxIndex;
}

int findLowestSalesSAR()
{
    int lowestIndex = 0;

    for (int i = 1; i < MAX_SALES; i++)
    {
        if (salesDataSAR[i].sales < salesDataSAR[lowestIndex].sales)
        {
            lowestIndex = i;
        }
    }

    cout << "\033[31mLowest sales is on " << salesDataSAR[lowestIndex].dayName << " with amount: " << salesDataSAR[lowestIndex].sales << " " << salesDataSAR[lowestIndex].currency << "\033[32m\n\n\n";

    return lowestIndex;
}

int findLowestSalesUSD()
{
    int lowestIndex = 0;

    for (int i = 1; i < MAX_SALES; i++)
    {
        if (salesDataUSD[i].sales < salesDataUSD[lowestIndex].sales)
        {
            lowestIndex = i;
        }
    }

    cout << "\033[31mLowest sales is on " << salesDataUSD[lowestIndex].dayName << " with amount: " << salesDataUSD[lowestIndex].sales << " " << salesDataUSD[lowestIndex].currency << "\033[32m\n\n\n";

    return lowestIndex;
}

void findOptionsSAR()
{
    int numberChoice;
    cout << "Enter 1 for Highest sales Day or 2 for Lowest Sales Day: ";
    while (true)
    {
        cin >> numberChoice;
        cout << "\n";
        if (numberChoice == 1)
        {
            findMaxSalesSAR();
            cout << endl;
            break;
        }
        else if (numberChoice == 2)
        {
            findLowestSalesSAR();
            cout << endl;
            break;
        }
        else
        {
            cout << "Invalid selection. Please choose 1 or 2 and try again.\n";
        }
    }
}

void findOptionsUSD()
{
    int numberChoice;
    cout << "Enter 1 for Highest sales Day or 2 for Lowest Sales Day: ";
    while (true)
    {
        cin >> numberChoice;
        cout << "\n";
        if (numberChoice == 1)
        {
            findMaxSalesUSD();
            cout << endl;
            break;
        }
        else if (numberChoice == 2)
        {
            findLowestSalesUSD();
            cout << endl;
            break;
        }
        else
        {
            cout << "Invalid selection. Please choose 1 or 2 and try again.\n";
        }
    }
}

int searchByDaySAR()
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
         << salesDataSAR[index].dayName << " sales = " << salesDataSAR[index].sales << " " << salesDataSAR[index].currency << "\n\n";

    return index;
}

int searchByDayUSD()
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
         << salesDataUSD[index].dayName << " sales = " << salesDataUSD[index].sales << " " << salesDataUSD[index].currency << "\n\n";

    return index;
}

void SearchByValueSAR()
{ // This function searches for a sales value in the sales array

    double value;

    cout << "which sales value do you want to search for? ";
    cin >> value;

    bool found = false; // A boolean variable to keep track if the value was found or not

    for (int i = 0; i < MAX_SALES; ++i)
    { // We use the loop to search through the sales array unitl it matches the value
        if (salesDataSAR[i].sales == value)
        {
            cout << "\nValue " << value << " " << salesDataSAR[i].currency << " found on " << salesDataSAR[i].dayName << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "\nValue " << value << " was NOT found in any day.\n\n";
    }
    cout << endl;
}

void SearchByValueUSD()
{ // This function searches for a sales value in the sales array

    double value;

    cout << "which sales value do you want to search for? ";
    cin >> value;

    bool found = false; // A boolean variable to keep track if the value was found or not

    for (int i = 0; i < MAX_SALES; ++i)
    { // We use the loop to search through the sales array unitl it matches the value
        if (salesDataUSD[i].sales == value)
        {
            cout << "\nValue " << value << " " << salesDataUSD[i].currency << " found on " << salesDataUSD[i].dayName << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "\nValue " << value << " was NOT found in any day.\n\n";
    }
    cout << endl;
}

void searchOptionsSAR()
{
    int numberChoice;
    cout << "Enter 1 for Search By Day or 2 for Search By sales: \n";
    while (true)
    {
        cin >> numberChoice;
        cout << "\n";
        if (numberChoice == 1)
        {
            searchByDaySAR();
            break;
        }
        else if (numberChoice == 2)
        {
            SearchByValueSAR();
            break;
        }
        else
            cout << "The entered value is not acceptable.\n";
    }
}

void searchOptionsUSD()
{
    int numberChoice;
    cout << "Enter 1 for Search By Day or 2 for Search By sales: \n";
    while (true)
    {
        cin >> numberChoice;
        cout << "\n";
        if (numberChoice == 1)
        {
            searchByDayUSD();
            break;
        }
        else if (numberChoice == 2)
        {
            SearchByValueUSD();
            break;
        }
        else
            cout << "The entered value is not acceptable.\n";
    }
}

void ascendingSortSAR()
{
    for (int i = 0; i < MAX_SALES; i++)
    {
        ascendingSalesData[i] = salesDataSAR[i];
    }

    for (int i = 0; i < MAX_SALES - 1; ++i)
    {
        for (int j = 0; j < MAX_SALES - i - 1; ++j)
        {
            if (ascendingSalesData[j].sales > ascendingSalesData[j + 1].sales)
            {
                DailySales temp = ascendingSalesData[j];
                ascendingSalesData[j] = ascendingSalesData[j + 1];
                ascendingSalesData[j + 1] = temp;
            }
        }
    }

    cout << "Sorted sales (ascending):\n";
    for (int i = 0; i < MAX_SALES; ++i)
    {
        cout << ascendingSalesData[i].dayName << "\t|   " << ascendingSalesData[i].sales << " " << salesDataSAR[i].currency << "\n";
    }
    cout << "\n";
}

void ascendingSortUSD()
{
    for (int i = 0; i < MAX_SALES; i++)
    {
        ascendingSalesData[i] = salesDataUSD[i];
    }

    for (int i = 0; i < MAX_SALES - 1; ++i)
    {
        for (int j = 0; j < MAX_SALES - i - 1; ++j)
        {
            if (ascendingSalesData[j].sales > ascendingSalesData[j + 1].sales)
            {
                DailySales temp = ascendingSalesData[j];
                ascendingSalesData[j] = ascendingSalesData[j + 1];
                ascendingSalesData[j + 1] = temp;
            }
        }
    }

    cout << "Sorted sales (ascending):\n";
    for (int i = 0; i < MAX_SALES; ++i)
    {
        cout << ascendingSalesData[i].dayName << "\t|   " << ascendingSalesData[i].sales << " " << salesDataUSD[i].currency << "\n";
    }
    cout << "\n";
}

void descendingSortSAR()
{
    for (int i = 0; i < MAX_SALES; ++i)
    {
        descendingSalesData[i] = salesDataSAR[i];
    }

    for (int i = 0; i < MAX_SALES - 1; ++i)
    {
        for (int j = 0; j < MAX_SALES - i - 1; ++j)
        {
            if (descendingSalesData[j].sales < descendingSalesData[j + 1].sales)
            {
                DailySales temp = descendingSalesData[j];
                descendingSalesData[j] = descendingSalesData[j + 1];
                descendingSalesData[j + 1] = temp;
            }
        }
    }

    cout << "Sorted sales (Descending):\n";
    for (int i = 0; i < MAX_SALES; ++i)
    {
        cout << descendingSalesData[i].dayName << "\t|   " << descendingSalesData[i].sales << " " << salesDataSAR[i].currency << "\n";
    }
    cout << "\n";
}

void descendingSortUSD()
{
    for (int i = 0; i < MAX_SALES; ++i)
    {
        descendingSalesData[i] = salesDataUSD[i];
    }

    for (int i = 0; i < MAX_SALES - 1; ++i)
    {
        for (int j = 0; j < MAX_SALES - i - 1; ++j)
        {
            if (descendingSalesData[j].sales < descendingSalesData[j + 1].sales)
            {
                DailySales temp = descendingSalesData[j];
                descendingSalesData[j] = descendingSalesData[j + 1];
                descendingSalesData[j + 1] = temp;
            }
        }
    }

    cout << "Sorted sales (Descending):\n";
    for (int i = 0; i < MAX_SALES; ++i)
    {
        cout << descendingSalesData[i].dayName << "\t|   " << descendingSalesData[i].sales << " " << salesDataUSD[i].currency << "\n";
    }
    cout << "\n";
}

void SortingOptionsSAR()
{
    int numberChoice;
    cout << "Enter 1 for ascending sort or 2 for descending sort: \n";
    while (true)
    {
        cin >> numberChoice;
        cout << "\n";
        if (numberChoice == 1)
        {
            ascendingSortSAR();
            break;
        }
        else if (numberChoice == 2)
        {
            descendingSortSAR();
            break;
        }
        else
            cout << "The entered value is not acceptable.\n";
    }
}

void SortingOptionsUSD()
{
    int numberChoice;
    cout << "Enter 1 for ascending sort or 2 for descending sort: \n";
    while (true)
    {
        cin >> numberChoice;
        cout << "\n";
        if (numberChoice == 1)
        {
            ascendingSortUSD();
            break;
        }
        else if (numberChoice == 2)
        {
            descendingSortUSD();
            break;
        }
        else
            cout << "The entered value is not acceptable.\n";
    }
}

void helpSAR()
{
    cout << "\n===================================" << endl;
    cout << "     Help - Sales Tracker (SAR)    " << endl;
    cout << "===================================" << endl;
    cout << "1. Enter daily sales data\n";
    cout << "2. Display all sales records\n";
    cout << "3. Calculate total sales amount\n";
    cout << "4. Calculate average daily sales\n";
    cout << "5. Find day with highest/lowest sales\n";
    cout << "6. Search by day or by sales amount\n";
    cout << "7. Sort sales in order\n";
    cout << "8. Update sales for a specific day\n";
    cout << "9. Save all data to a file\n";
    cout << "10. Convert sales from SAR to USD\n";
    cout << "11. Generate comprehensive sales report\n";
    cout << "12. Reset/clear all sales data\n";
    cout << "13. Show this help page\n";
    cout << "14. Exit the program\n";
    cout << "===================================\n\n";
}

void helpUSD()
{
    cout << "\n===================================" << endl;
    cout << "     Help - Sales Tracker (USD)    " << endl;
    cout << "===================================" << endl;
    cout << "1. Enter daily sales data\n";
    cout << "2. Display all sales records\n";
    cout << "3. Calculate total sales amount\n";
    cout << "4. Calculate average daily sales\n";
    cout << "5. Find day with highest/lowest sales\n";
    cout << "6. Search by day or by sales amount\n";
    cout << "7. Sort sales in order\n";
    cout << "8. Update sales for a specific day\n";
    cout << "9. Save all data to a file\n";
    cout << "10. Convert sales from USD to SAR\n";
    cout << "11. Generate comprehensive sales report\n";
    cout << "12. Reset/clear all sales data\n";
    cout << "13. Show this help page\n";
    cout << "14. Exit the program\n";
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

int updateDaySalesSAR()
{
    int day_number;
    cout << "Enter the number of the day to update (1 - " << MAX_SALES << "): ";
    cin >> day_number;

    if (day_number < 1 || day_number > MAX_SALES)
    {
        cout << "\nInvalid day number!\n\n";
        return -1;
    }

    int index = day_number - 1;

    cout << "The old sales for " << salesDataSAR[index].dayName << " is: " << salesDataSAR[index].sales << " " << salesDataSAR[index].currency << endl;
    cout << "Enter the NEW sales: ";
    cin >> salesDataSAR[index].sales;
    return 1;
}

int updateDaySalesUSD()
{
    int day_number;
    cout << "Enter the number of the day to update (1 - " << MAX_SALES << "): ";
    cin >> day_number;

    if (day_number < 1 || day_number > MAX_SALES)
    {
        cout << "\nInvalid day number!\n\n";
        return -1;
    }

    int index = day_number - 1;

    cout << "The old sales for " << salesDataUSD[index].dayName << " is: " << salesDataUSD[index].sales << " " << salesDataUSD[index].currency << endl;
    cout << "Enter the NEW sales: ";
    cin >> salesDataUSD[index].sales;
    return 1;
}

void convertSARtoUSD()
{
    for (int i = 0; i < MAX_SALES; i++)
    {
        salesDataUSD[i].dayName = "Day " + to_string(i + 1);
        salesDataUSD[i].sales = salesDataSAR[i].sales / 3.75;
        salesDataUSD[i].currency = "$";
    }
    cout << "Convert sales to USD\n";

    for (int i = 0; i < MAX_SALES; i++)
    {
        cout << salesDataUSD[i].dayName << "\t|   " << salesDataUSD[i].sales << " " << salesDataUSD[i].currency << "\n";
    }
}

void convertUSDtoSAR()
{
    for (int i = 0; i < MAX_SALES; i++)
    {
        salesDataSAR[i].dayName = "Day " + to_string(i + 1);
        salesDataSAR[i].sales = salesDataUSD[i].sales * 3.75;
        salesDataSAR[i].currency = "SAR";
    }
    cout << "Convert sales to SAR\n";
    for (int i = 0; i < MAX_SALES; i++)
    {
        cout << salesDataSAR[i].dayName << "\t|   " << salesDataSAR[i].sales << " " << salesDataSAR[i].currency << "\n";
    }
}

void saveSalesSAR()
{
    int maxIndex = 0, lowestIndex = 0;
    double avg, sum = 0;
    ofstream file("sales.txt");

    if (!file)
    {
        cout << "Error opening file!\n";
        return;
    }

    file << "Sales Data\n";
    file << "===========\n";

    for (int i = 0; i < MAX_SALES; i++)
    {
        file << salesDataSAR[i].dayName << "\t|   " << salesDataSAR[i].sales << " " << salesDataSAR[i].currency << "\n";
    }

    for (int i = 0; i < MAX_SALES; ++i)
    {
        sum += salesDataSAR[i].sales;
    }

    file << "\nThe total of the sales for these days is: " << sum << " " << salesDataSAR[0].currency << "\n";

    avg = sum / MAX_SALES;
    file << "\nThe average of the sales is: " << avg << " " << salesDataSAR[0].currency << "\n";

    for (int i = 1; i < MAX_SALES; i++)
    {
        if (salesDataSAR[i].sales > salesDataSAR[maxIndex].sales)
        {
            maxIndex = i;
        }
    }

    file << "\nHighest sales is on " << salesDataSAR[maxIndex].dayName << " with amount: " << salesDataSAR[maxIndex].sales << " " << salesDataSAR[maxIndex].currency << "\n";

    for (int i = 1; i < MAX_SALES; i++)
    {
        if (salesDataSAR[i].sales < salesDataSAR[lowestIndex].sales)
        {
            lowestIndex = i;
        }
    }

    file << "\nLowest sales is on " << salesDataSAR[lowestIndex].dayName << " with amount: " << salesDataSAR[lowestIndex].sales << " " << salesDataSAR[lowestIndex].currency << "\n";

    file << endl;
    for (int i = 0; i < MAX_SALES; i++)
    {
        ascendingSalesData[i] = salesDataSAR[i];
    }

    for (int i = 0; i < MAX_SALES - 1; ++i)
    {
        for (int j = 0; j < MAX_SALES - i - 1; ++j)
        {
            if (ascendingSalesData[j].sales > ascendingSalesData[j + 1].sales)
            {
                DailySales temp = ascendingSalesData[j];
                ascendingSalesData[j] = ascendingSalesData[j + 1];
                ascendingSalesData[j + 1] = temp;
            }
        }
    }

    file << "Sorted sales (ascending):\n";
    for (int i = 0; i < MAX_SALES; ++i)
    {
        file << ascendingSalesData[i].dayName << "\t|   " << ascendingSalesData[i].sales << " " << salesDataSAR[i].currency << "\n";
    }
    file << "\n";
    file << endl;
    for (int i = 0; i < MAX_SALES; ++i)
    {
        descendingSalesData[i] = salesDataSAR[i];
    }

    for (int i = 0; i < MAX_SALES - 1; ++i)
    {
        for (int j = 0; j < MAX_SALES - i - 1; ++j)
        {
            if (descendingSalesData[j].sales < descendingSalesData[j + 1].sales)
            {
                DailySales temp = descendingSalesData[j];
                descendingSalesData[j] = descendingSalesData[j + 1];
                descendingSalesData[j + 1] = temp;
            }
        }
    }

    file << "Sorted sales (Descending):\n";
    for (int i = 0; i < MAX_SALES; ++i)
    {
        file << descendingSalesData[i].dayName << "\t|   " << descendingSalesData[i].sales << " " << salesDataSAR[i].currency << "\n";
    }
    file << "\n";
    file << endl;

    for (int i = 0; i < MAX_SALES; i++)
    {
        salesDataUSD[i].dayName = "Day " + to_string(i + 1);
        salesDataUSD[i].sales = salesDataSAR[i].sales / 3.75;
        salesDataUSD[i].currency = "$";
    }

    file << "SAR to USD Conversin\n";
    for (int i = 0; i < MAX_SALES; i++)
    {
        file << salesDataUSD[i].dayName << "\t|   " << salesDataUSD[i].sales << " " << salesDataUSD[i].currency << "\n";
    }

    file.close();
    cout << "Data saved successfully to sales.txt\n\n";
}

void saveSalesUSD()
{
    int maxIndex = 0, lowestIndex = 0;
    double avg, sum = 0;
    ;
    ofstream file("sales.txt");

    if (!file)
    {
        cout << "Error opening file!\n";
        return;
    }

    file << "Sales Data\n";
    file << "===========\n";

    for (int i = 0; i < MAX_SALES; i++)
    {
        file << salesDataUSD[i].dayName << "\t|   " << salesDataUSD[i].sales << " " << salesDataUSD[i].currency << "\n";
    }

    for (int i = 0; i < MAX_SALES; ++i)
    {
        sum += salesDataUSD[i].sales;
    }

    file << "\nThe total of the sales for these days is: " << sum << " " << salesDataUSD[0].currency << "\n";

    avg = sum / MAX_SALES;
    file << "\nThe average of the sales is: " << avg << " " << salesDataUSD[0].currency << "\n";

    for (int i = 1; i < MAX_SALES; i++)
    {
        if (salesDataUSD[i].sales > salesDataUSD[maxIndex].sales)
        {
            maxIndex = i;
        }
    }

    file << "\nHighest sales is on " << salesDataUSD[maxIndex].dayName << " with amount: " << salesDataUSD[maxIndex].sales << " " << salesDataUSD[maxIndex].currency << "\n";

    for (int i = 1; i < MAX_SALES; i++)
    {
        if (salesDataUSD[i].sales < salesDataUSD[lowestIndex].sales)
        {
            lowestIndex = i;
        }
    }

    file << "\nLowest sales is on " << salesDataUSD[lowestIndex].dayName << " with amount: " << salesDataUSD[lowestIndex].sales << " " << salesDataUSD[lowestIndex].currency << "\n";

    file << endl;
    for (int i = 0; i < MAX_SALES; i++)
    {
        ascendingSalesData[i] = salesDataUSD[i];
    }

    for (int i = 0; i < MAX_SALES - 1; ++i)
    {
        for (int j = 0; j < MAX_SALES - i - 1; ++j)
        {
            if (ascendingSalesData[j].sales > ascendingSalesData[j + 1].sales)
            {
                DailySales temp = ascendingSalesData[j];
                ascendingSalesData[j] = ascendingSalesData[j + 1];
                ascendingSalesData[j + 1] = temp;
            }
        }
    }

    file << "Sorted sales (ascending):\n";
    for (int i = 0; i < MAX_SALES; ++i)
    {
        file << ascendingSalesData[i].dayName << "\t|   " << ascendingSalesData[i].sales << " " << salesDataUSD[i].currency << "\n";
    }
    file << "\n";
    file << endl;
    for (int i = 0; i < MAX_SALES; ++i)
    {
        descendingSalesData[i] = salesDataUSD[i];
    }

    for (int i = 0; i < MAX_SALES - 1; ++i)
    {
        for (int j = 0; j < MAX_SALES - i - 1; ++j)
        {
            if (descendingSalesData[j].sales < descendingSalesData[j + 1].sales)
            {
                DailySales temp = descendingSalesData[j];
                descendingSalesData[j] = descendingSalesData[j + 1];
                descendingSalesData[j + 1] = temp;
            }
        }
    }

    file << "Sorted sales (Descending):\n";
    for (int i = 0; i < MAX_SALES; ++i)
    {
        file << descendingSalesData[i].dayName << "\t|   " << descendingSalesData[i].sales << " " << salesDataUSD[i].currency << "\n";
    }
    file << "\n";
    file << endl;

    for (int i = 0; i < MAX_SALES; i++)
    {
        salesDataSAR[i].dayName = "Day " + to_string(i + 1);
        salesDataSAR[i].sales = salesDataUSD[i].sales * 3.75;
        salesDataSAR[i].currency = "SAR";
    }

    file << "USD to SAR Conversin\n";
    for (int i = 0; i < MAX_SALES; i++)
    {
        file << salesDataSAR[i].dayName << "\t|   " << salesDataSAR[i].sales << " " << salesDataSAR[i].currency << "\n";
    }

    file.close();
    cout << "Data saved successfully to sales.txt\n\n";
}

void SummarySAR() 
{
    double avg;
    cout << "Sales Data\n";
    cout << "===========\n";
	displayArraySAR();
	sumSAR(MAX_SALES);
	averageSAR(avg);
	findMaxSalesSAR();
	findLowestSalesSAR();
	ascendingSortSAR();
	descendingSortSAR();
	convertSARtoUSD();
}

void SummaryUSD() 
{
    double avg;
    cout << "Sales Data\n";
    cout << "===========\n";
	displayArrayUSD();
	sumUSD(MAX_SALES);
	averageUSD(avg);
	findMaxSalesUSD();
	findLowestSalesUSD();
	ascendingSortUSD();
	descendingSortUSD();
	convertUSDtoSAR();
}

void exitSAR()
{
    char choice;
    while (true)
    {
        cout << "\nYou have unsaved changes!" << endl;
        cout << "Enter 'y' to exit with saving. Enter 'n' to exit without saving.\n";
        cin >> choice;

        if (choice == 'y' || choice == 'Y')
        {
            saveSalesSAR();
            cout << "\nExiting program... Goodbye\n\n";
            break;
        }
        else if (choice == 'n' || choice == 'N')
        {
            cout << "Exiting without saving." << endl;
            break;
        }
        else
        {
            cout << "Invalid input. Please enter 'y' or 'n'." << endl;
        }
    }
}

void exitUSD()
{
    char choice;
    while (true)
    {
        cout << "\nYou have unsaved changes!" << endl;
        cout << "Enter 'y' to exit with saving. Enter 'n' to exit without saving.\n";
        cin >> choice;

        if (choice == 'y' || choice == 'Y')
        {
            saveSalesUSD();
            cout << "\nExiting program... Goodbye\n\n";
            break;
        }
        else if (choice == 'n' || choice == 'N')
        {
            cout << "Exiting without saving." << endl;
            break;
        }
        else
        {
            cout << "Invalid input. Please enter 'y' or 'n'." << endl;
        }
    }
}

int mainSAR()
{
    int choice;
    double avg, total;

    setupDataSAR();

    do
    {
        menuSAR();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nYou chose to enter sales data.\n\n";
            inputSalesSAR();
            break;
        case 2:
            cout << "\nYou chose to display sales.\n\n";
            displayArraySAR();
            cout << "\n\n";
            break;
        case 3:
            cout << "\nYou chose to calculate total sales.\n\n";
            total = sumSAR(MAX_SALES);
            break;
        case 4:
            cout << "\nYou chose to calculate average sales.\n\n";
            averageSAR(avg);
            break;
        case 5:
            cout << "\nYou chose to show maximum or minimum sales day.\n\n";
            findOptionsSAR();
            break;
        case 6:
            cout << "\nYou chose to Search data.\n\n";
            searchOptionsSAR();
            break;
        case 7:
            cout << "\nYou chose to sort sales.\n\n";
            SortingOptionsSAR();
            break;
        case 8:
            cout << "\nYou chose to update day sales\n\n";
            updateDaySalesSAR();
            break;
        case 9:
            cout << "\nYou chose to save data to file.\n\n";
            saveSalesSAR();
            break;
        case 10:
            cout << "\nYou chose to convert sales to USD.\n\n";
            convertSARtoUSD();
            break;
        case 11:
            cout << "\nYou chose to show summary.\n\n";
            SummarySAR();
            break;
        case 12:
            cout << "\nYou chose to reset all sales.\n";
            resetAllSales(salesDataSAR);
            break;
        case 13:
            helpSAR();
            break;
        case 14:
            exitSAR();
            break;
        default:
            cout << "\nInvalid choice, please try again.\n\n";
            break;
        }
    } while (choice != 14);

    return 0;
}

int mainUSD()
{
    int choice;
    double avg, total;

    setupDataUSD();

    do
    {
        menuUSD();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nYou chose to enter sales data.\n\n";
            inputSalesUSD();
            break;
        case 2:
            cout << "\nYou chose to display sales.\n\n";
            displayArrayUSD();
            cout << "\n\n";
            break;
        case 3:
            cout << "\nYou chose to calculate total sales.\n\n";
            total = sumUSD(MAX_SALES);
            break;
        case 4:
            cout << "\nYou chose to calculate average sales.\n\n";
            averageUSD(avg);
            break;
        case 5:
            cout << "\nYou chose to show maximum or minimum sales day.\n\n";
            findOptionsUSD();
            break;
        case 6:
            cout << "\nYou chose to Search data.\n\n";
            searchOptionsUSD();
            break;
        case 7:
            cout << "\nYou chose to sort sales.\n\n";
            SortingOptionsUSD();
            break;
        case 8:
            cout << "\nYou chose to update day sales\n\n";
            updateDaySalesUSD();
            break;
        case 9:
            cout << "\nYou chose to save data to file.\n\n";
            saveSalesUSD();
            break;
        case 10:
            cout << "\nYou chose to convert sales to SAR.\n\n";
            convertUSDtoSAR();
            break;
        case 11:
            cout << "\nYou chose to show summary.\n\n";
            SummaryUSD();
            break;
        case 12:
            cout << "\nYou chose to reset all sales.\n";
            resetAllSales(salesDataUSD);
            break;
        case 13:
            helpUSD();
            break;
        case 14:
            exitUSD();
            break;
        default:
            cout << "\nInvalid choice, please try again.\n\n";
            break;
        }
    } while (choice != 14);

    return 0;
}

int main()
{
    char currency;

    cout << "--- Welcome to Sales Tracker System ---\n\n";
    cout << "Enter 'R' for Saudi Riyal (SAR) or 'D' for US Dollar (USD): ";

    while (true)
    {
        cin >> currency;
        if (currency == 'R' || currency == 'r')
        {
            mainSAR();
            break;
        }
        else if (currency == 'D' || currency == 'd')
        {
            mainUSD();
            break;
        }
        else
        {
            cout << "Invalid selection. Please choose R or D and try again.\n";
        }
    }

    return 0;
}