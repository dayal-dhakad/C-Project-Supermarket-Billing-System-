#include<iostream>
using namespace std;
 
 
int main(){
 

  int choice;
    cout << "\n\n---------------------------------------------------------------------------------------------------------------------------------------\n\n\n";
    cout << "\t\t\t\t\t\t ________________________________________________\n";
    cout << "\t\t\t\t\t\t|                                                |\n";
    cout << "\t\t\t\t\t\t|              ADMINISTRATOR MENU                |\n";
    cout << "\t\t\t\t\t\t|________________________________________________|\n\n";
    cout << "\t\t\t\t\t\t1. Add Product\n";
    cout << "\t\t\t\t\t\t2. Edit Product\n";
    cout << "\t\t\t\t\t\t3. Remove Product\n";
    cout << "\t\t\t\t\t\t4. List Products\n";
    cout << "\t\t\t\t\t\t5. Back to Main Menu\n";
    cout << "\t\t\t\t\t\tEnter your choice (1-5): ";
    cin >> choice;

    switch (choice) {
        case 1:
    //        addProduct();
     //       administratorMenu();
            break;
        case 2:
      //      editProduct();
       //     administratorMenu();
            break;
        case 3:
     //       removeProduct();
       //     administratorMenu();
            break;
        case 4:
       //     listProducts();
      //      administratorMenu();
            break;
        case 5:
       //     menu();
            break;
        default:
            cout << "\nInvalid choice. Please try again.\n";
       //     administratorMenu();
    }
  
  
return 0;
}