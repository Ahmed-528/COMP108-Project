#include <iostream>
using namespace std;

void sortArray(int arr[], int n)
{
    int temp, i, j;
    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }   
}
