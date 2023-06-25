#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;
 
class Market{
    private:
    int pcode;
    string pname;
    float price;
    float discount;

    public:

    void editProduct();
  
};
/*-------------------------EDIT PRODUCT-------------------------*/


void Market::editProduct() {
    int code;
    cout << "\n\n---------------------------------------------------------------------------------------------------------------------------------------\n\n\n";
    cout << "\t\t\t\t\t\t ________________________________________________\n";
    cout << "\t\t\t\t\t\t|                                                |\n";
    cout << "\t\t\t\t\t\t|               EDIT PRODUCT MENU                |\n";
    cout << "\t\t\t\t\t\t|________________________________________________|\n\n";
    cout << "\t\t\t\t\t\tEnter Product Code to edit: ";
    cin >> code;

    ifstream inFile("products.txt");
    ofstream outFile("temp.txt");

    if (!inFile) {
        cout << "Error: Unable to open the file.\n";
        return;
    }

    bool found = false;
    while (inFile >> pcode >> pname >> price >> discount) {
        if (pcode == code) {
            found = true;
            cout << "\t\t\t\t\t\tEnter New Product Name: ";
            cin>>pname;
            cout << "\t\t\t\t\t\tEnter New Product Price: ";
            cin >> price;
            cout << "\t\t\t\t\t\tEnter New Product Discount (%): ";
            cin >> discount;
        }
        outFile << pcode << " " << pname << " " << price << " " << discount << endl;
    }

    inFile.close();
    outFile.close();

    if (found) {
        remove("products.txt");
        rename("temp.txt", "products.txt");
        cout << "\nProduct updated successfully!\n";
    } else {
        cout << "\nProduct not found!\n";
    }
}


int main(){
 Market p;
 p.editProduct();
  
  
return 0;
}