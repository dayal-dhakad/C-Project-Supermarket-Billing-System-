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
    void removeProduct();

};



/*-------------------------REMOVE PRODUCT-------------------------*/
void Market:: removeProduct(){
    int code;
    cout << "\n\n---------------------------------------------------------------------------------------------------------------------------------------\n\n\n";
    cout << "\t\t\t\t\t\t ________________________________________________\n";
    cout << "\t\t\t\t\t\t|                                                |\n";
    cout << "\t\t\t\t\t\t|             REMOVE PRODUCT MENU               |\n";
    cout << "\t\t\t\t\t\t|________________________________________________|\n\n";
    cout << "\t\t\t\t\t\tEnter Product Code to remove: ";
    cin >> code;

    ifstream inFile("products.txt");
    ofstream outFile("temp.txt");

    if (!inFile) {
        cout << "Error: Unable to open the file.\n";
        return;
    }

    bool found = false;
    while (inFile >> pcode >> pname >> price >> discount) {
        if (pcode != code) {
            outFile << pcode << " " << pname << " " << price << " " << discount << endl;
        } else {
            found = true;
        }
    }

    inFile.close();
    outFile.close();

    if (found) {
        remove("products.txt");
        rename("temp.txt", "products.txt");
        cout << "\nProduct removed successfully!\n";
    } else {
        cout << "\nProduct not found!\n";
    }
}
 
int main(){
 
   Market p;
   p.removeProduct();
  
return 0;
}