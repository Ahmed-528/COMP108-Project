#include <iostream>
using namespace std;

void menu()
{
    cout<<"==================================="<<endl;
    cout<<"\t Sales Tracket Menu"<<endl;
    cout<<"==================================="<<endl;
    cout<<"1. Enter daily sales data\n";
    cout<<"2. Display all sales\n";
    cout<<"3. Calculate total sales\n";
    cout<<"4. Calculate average sales\n";
    cout<<"5. Show highest sales day\n"; 
    cout<<"6. Show lowest sales day\n";
    cout<<"7. Searsh for a sales value\n";
    cout<<"8. Sort sales\n";
    cout<<"9. Save data to file\n";
    cout<<"10. help\n";
    cout<<"11. Exit program\n\n"; 
}

int main()
{
    int choice;
    do
    {
        menu();
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"\nYou chose to enter sales data.\n\n";
                break;
            case 2:
                cout<<"\nYou chose to display sales.\n\n";
                break;
            case 3:
                cout<<"\nYou chose to calculate total sales.\n\n";
                break;
            case 4:
                cout<<"\nYou chose to calculate average sales.\n\n";
                break;
            case 5:
                cout<<"\nYou chose to show the highest sales day.\n\n";
                break;
            case 6:
                cout<<"\nYou chose to show the lowest sales day.\n\n";
                break;
            case 7:
                cout<<"\nYou chose to searsh for a sales value.\n\n";
                break;
            case 8:
                cout<<"\nYou chose to sort sales.\n\n";
                break;
            case 9:
                cout<<"\nYou chose to save data to file.\n\n";
                break;
            case 10:
                
                break;
            case 11:
            
                cout<<"\nExiting program... Goodbye\n\n";
                break;
            default:
                cout<<"\nInvalid choice, please try again.\n\n";
                break;
        }
    }
    while(choice != 10);
    
    
    return 0;
}