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
    void listProducts();
 
};


/*-------------------------LIST PRODUCTS-------------------------*/
void Market:: listProducts(){
     
   cout << "\n\n---------------------------------------------------------------------------------------------------------------------------------------\n\n\n";
    cout << "\t\t\t\t\t\t ________________________________________________\n";
    cout << "\t\t\t\t\t\t|                                                |\n";
    cout << "\t\t\t\t\t\t|               LIST OF PRODUCTS                 |\n";
    cout << "\t\t\t\t\t\t|________________________________________________|\n\n";

    ifstream inFile("products.txt");

    if (!inFile) {
        cerr << "Error: Unable to open the file.\n";
        return;
    }

    cout << "\t\t\t\t\t\tProduct Code\tProduct Name\tProduct Price\tProduct Discount (%)\n";
    cout << "\t\t\t\t\t\t--------------------------------------------------------------\n";

    while (inFile >> pcode >> pname >> price >> discount) {
        cout << "\t\t\t\t\t\t" << pcode << "\t\t" << pname << "\t\t" << price << "\t\t" << discount << endl;
    }

    inFile.close();
}




 
int main(){
 Market p;
 p.listProducts();
  
  
return 0;
}