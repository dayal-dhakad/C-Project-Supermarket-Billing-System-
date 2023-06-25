#include<iostream>
using namespace std;
 
 
int main(){
 
     int choice;
    cout << "\n\n---------------------------------------------------------------------------------------------------------------------------------------\n\n\n";
    cout << "\t\t\t\t\t\t ________________________________________________\n";
    cout << "\t\t\t\t\t\t|                                                |\n";
    cout << "\t\t\t\t\t\t|                  BUYER MENU                    |\n";
    cout << "\t\t\t\t\t\t|________________________________________________|\n\n";
    cout << "\t\t\t\t\t\t1. List Products\n";
    cout << "\t\t\t\t\t\t2. Generate Receipt\n";
    cout << "\t\t\t\t\t\t3. Back to Main Menu\n";
    cout << "\t\t\t\t\t\tEnter your choice (1-3): ";
    cin >> choice;

    switch (choice) {
        case 1:
      //      listProducts();
      //      buyerMenu();
            break;
        case 2:
      //      generateReceipt();
      //      buyerMenu();
            break;
        case 3:
      //      menu();
            break;
        default:
            cout << "\nInvalid choice. Please try again.\n";
      //      buyerMenu();
    }
  
  
return 0;
}