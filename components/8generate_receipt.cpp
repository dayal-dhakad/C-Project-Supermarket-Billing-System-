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

    void generateReceipt();
    void listProducts();
    bool check(int m);
};



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


bool Market::check(int m) {
    ifstream inFile("products.txt");
    if (!inFile) {
    //    cout << "Unable to open products file." << endl;
        return false;
    }

    int code;
    string name;
    float productPrice, productDiscount;

    while (inFile >> code >> name >> productPrice >> productDiscount) {
        if (m == code) {
            inFile.close();
            return true;
        }
    }

    inFile.close();
    return false;
}
/*-------------------------GENERATE RECEIPT-------------------------*/
void Market:: generateReceipt(){
    vector<int> products;
    vector<int> productquantity;
    int quantity;
    float a , b;
    float total = 0;
    float amount = 0;


    listProducts();

        products.clear();
        productquantity.clear();

//----------------------ADDING PRODUCTS IN CART--------------------------
    do
    {
        x:
        m:
            cout << "Enter Product pcode (enter 0 to exit)" << endl;
            cin >> pcode;

        for (int i = 0; i < products.size(); i++)
        {
            if (pcode == products[i])
            {
                cout << "You've already added this product" << endl;
                goto m;
            }
        }
        if (check(pcode))
        {
            products.push_back(pcode);
            cout<<"Enter Quantity"<<endl;
            cin>>quantity;
            productquantity.push_back(quantity);
            
        }
        else if (pcode==0)
        {
            break;
           
        }
        
        else{
            cout<<"Wrong Product code"<<endl;
            goto x;
        }
        


    } while (pcode!=0);


//--------------To check whether it is working fine-----------
//    for (int i = 0; i < products.size(); i++)  
//    {
//      cout<<products[i]<<" ";
//    }
 


//-------------------------------FINAL BILL------------------------------------


 cout << "****************************** SUPER MART *******************************" << endl;
    
    cout<<"Pcode"<<"\t"<<"Pname"<<"\t"<<"Price"<<"\t"<<"Qty"<<"\t"<<"Discount(%)"<<"\t"<<"Amount"<<endl;

   
    
    for (int i = 0; i < products.size(); i++)
    {
         
         ifstream checkFile("products.txt");
        while (checkFile >> pcode >> pname >> price>>discount)
        {
  
            if (products[i]==pcode)
            {
                  a= price*(discount/100);
                  b= productquantity[i] * a;
                  amount = ((price * productquantity[i]) -b) ;
                  total+=amount;
                cout<<pcode<<"\t"<<pname<<"\t"<<price<<"\t"<<productquantity[i]<<"\t"<<discount<<"\t\t"<<amount<<endl;
            }
        }
    }
  
    
    cout<<"\n\n\n TOTAL = "<<total<<endl;
  

}


 
int main(){
 Market p;
 p.generateReceipt();
  
  
return 0;
}