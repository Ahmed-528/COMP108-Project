#include <iostream>
using namespace std;

void exit()
{
    char choice;
    while (true)
    {
        cout << "\nYou have unsaved changes!" << endl;
        cout << "Enter 'y' to exit with saving. Enter 'n' to exit without saving.\n";
        cin >> choice;

        if (choice == 'y' || choice == 'Y')
        {
            saveData();
            cout << "Exiting program." << endl;
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
