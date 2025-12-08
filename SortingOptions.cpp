#include <iostream>
using namespace std;

void SortingOptions(){

int numberChoice;

  cout<<"Enter 1 for ascending sort or 2 for descending sort: \n";
  cin>>numberChoice;

  if(numberChoice == 1){
    AscendingSort();
  }
  else if(numberChoice == 2){
    DescendingSort();
  }
  else
    cout<<"The entered value is not acceptable.\n";

  
}
