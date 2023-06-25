#include<iostream>
using namespace std;
 
 
int main(){
 

 m:
    int choice;
    string email;
    string password;
    cout<<"\n\n---------------------------------------------------------------------------------------------------------------------------------------\n\n\n";
    cout << "\t\t\t\t\t\t ______________________________\n";
    cout << "\t\t\t\t\t\t|                              |\n";
    cout << "\t\t\t\t\t\t|    SUPERMARKET MAIN MENU     |\n";
 // cout << "\t\t\t\t\t\t|                              | \n";
    cout << "\t\t\t\t\t\t|______________________________|\n\n";
    cout << "\t\t\t\t\t\t     ______________________\n";
    cout << "\t\t\t\t\t\t    |                      | \n";
    cout << "\t\t\t\t\t\t    |   1) Administrator   | \n";
    cout << "\t\t\t\t\t\t    |                      | \n";
    cout << "\t\t\t\t\t\t    |   2) Buyer           | \n";
    cout << "\t\t\t\t\t\t    |                      | \n";
    cout << "\t\t\t\t\t\t    |   3) Exit            | \n";
    cout << "\t\t\t\t\t\t    |______________________| \n";
    cout << "\n\t\t\t\t\t\t\t Please Select!  ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        
        cout<<"---------------------------------------------------------------------------------------------------------------------------------------";
        cout<<endl;
        cout<<"\t\t\t\t\t\t\t ______________"<<endl;
        
        cout << "\t\t\t\t\t\t\t| Please Login |\n";
        cout<<"\t\t\t\t\t\t\t|______________|"<<endl<<endl;
        cout << "\t\t\t\t\t\t\t Enter Email  \n     \t\t\t\t                         ";
        cin >> email;
        cout << "\n\t\t\t\t\t\t\t Password     \n     \t\t\t\t                         ";
        cin >> password;
        cout<<"\n\n---------------------------------------------------------------------------------------------------------------------------------------";


        if (email == "dayal@gmail.com" && password == "dayal@123")
        {
     //       administrator();
        }
        else
        {
            cout << "Invalid email/password";
        }
        break;
        
    case 2:
     //   buyer();

    case 3:

        exit(0);

    default:
        cout << "Please select from the given options";
        break;
    }
    goto m;
  



  
return 0;
}