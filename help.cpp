#include <iostream>
using namespace std;

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
    cout<<"8. Sort sales - Arrange sales data in order (ascending/descending)\n";
    cout<<"9. Save data to file - Store your sales data in a file\n";
    cout<<"10. Help - Show this help information\n";
    cout<<"11. Exit program - Close the program\n\n";
    
    cout<<"Simply choose a number from the menu to perform that action.\n";
    cout<<"After each action, the menu will appear again until you choose to exit.\n";
    cout<<"===================================\n\n";
}

