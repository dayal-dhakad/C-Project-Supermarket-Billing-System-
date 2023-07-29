#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//admin email: dayal@email.com //
//admin password: dayal@123

using namespace std;

class Market
{
private:
    int pcode;
    string pname;
    float price;
    float discount;

public:
    void menu();
    void administratorMenu();
    void buyerMenu();
    bool check(int m);
    void addProduct();
    void editProduct();
    void removeProduct();
    void listProducts();
    void generateReceipt();
};

/*-------------------------MAIN MENU-------------------------*///
void Market::menu()
{
m:
    int choice;
    string email;
    string password;
    // cout << "\n\n---------------------------------------------------------------------------------------------------------------------------------------\n\n\n";
    cout << "\t\t\t\t\t\t ____________________________________\n";
    cout << "\t\t\t\t\t\t|                                    |\n";
    cout << "\t\t\t\t\t\t|        SUPERMARKET MAIN MENU       |\n";
    // cout << "\t\t\t\t\t\t|                              | \n";
    cout << "\t\t\t\t\t\t|____________________________________|\n\n";
    cout << "\t\t\t\t\t\t        ______________________\n";
    cout << "\t\t\t\t\t\t       |                      | \n";
    cout << "\t\t\t\t\t\t       |   1) Buyer           | \n";
    cout << "\t\t\t\t\t\t       |                      | \n";
    cout << "\t\t\t\t\t\t       |   2) Administrator   | \n";
    cout << "\t\t\t\t\t\t       |                      | \n";
    cout << "\t\t\t\t\t\t       |   3) Exit            | \n";
    cout << "\t\t\t\t\t\t       |______________________| \n";
    cout << "\n\t\t\t\t\t\t\t Please Select!  ";
    cin >> choice;

    system("cls");
    switch (choice)
    {
    case 2:

        cout << endl;
        cout << "\t\t\t\t\t\t\t _______________________" << endl;
        cout << "\t\t\t\t\t\t\t|                       |" << endl;
        cout << "\t\t\t\t\t\t\t|      Please Login     |\n";
        cout << "\t\t\t\t\t\t\t|_______________________|" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t Enter Email : ";
        cin >> email;
        cout << "\n\t\t\t\t\t\t\t Password    : ";
        cin >> password;

        if (email == "dayal@email.com" && password == "dayal@123")
        {
            system("cls");
            administratorMenu();
        }
        else
        {
            cout << "Invalid email/password";
        }
        break;

    case 1:
        buyerMenu();

    case 3:
        exit(0);
    default:
        cout << "Please select from the given options";
        break;
    }

    goto m;
}

/*-------------------------ADMIN MENU-------------------------*/
void Market::administratorMenu()
{

    int choice;
    cout << "\t\t\t\t\t\t ____________________________________\n";
    cout << "\t\t\t\t\t\t|                                    |\n";
    cout << "\t\t\t\t\t\t|         ADMINISTRATOR MENU         |\n";
    cout << "\t\t\t\t\t\t|____________________________________|\n";
    cout << "\t\t\t\t\t\t      ___________________________\n";
    cout << "\t\t\t\t\t\t     |                           |\n";
    cout << "\t\t\t\t\t\t     |    1. Add Product         |\n";
    cout << "\t\t\t\t\t\t     |                           |\n";
    cout << "\t\t\t\t\t\t     |    2. Edit Product        |\n";
    cout << "\t\t\t\t\t\t     |                           |\n";
    cout << "\t\t\t\t\t\t     |    3. Remove Product      |\n";
    cout << "\t\t\t\t\t\t     |                           |\n";
    cout << "\t\t\t\t\t\t     |    4. List Products       |\n";
    cout << "\t\t\t\t\t\t     |                           |\n";
    cout << "\t\t\t\t\t\t     |    5. Back to Main Menu   |\n";
    cout << "\t\t\t\t\t\t     |___________________________|\n\n";

    cout << "\t\t\t\t\t\t     Enter your choice (1-5): ";
    cin >> choice;
    system("cls");
    switch (choice)
    {
    case 1:
        addProduct();
        administratorMenu();
        break;
    case 2:
        editProduct();
        administratorMenu();
        break;
    case 3:
        removeProduct();
        administratorMenu();
        break;
    case 4:
        listProducts();
        administratorMenu();
        break;
    case 5:
        menu();
        break;
    default:
        cout << "\t\t\t\t\t\t \n    Invalid choice. Please try again.\n";
        administratorMenu();
    }
}

/*-------------------------BUYER MENU-------------------------*/
void Market::buyerMenu()
{

    int choice;
    cout << "\n\n\n";
    cout << "\t\t\t\t\t\t ____________________________________\n";
    cout << "\t\t\t\t\t\t|                                    |\n";
    cout << "\t\t\t\t\t\t|              BUYER MENU            |\n";
    cout << "\t\t\t\t\t\t|____________________________________|\n";
    cout << "\t\t\t\t\t\t      ___________________________\n";
    cout << "\t\t\t\t\t\t     |                           |\n";
    cout << "\t\t\t\t\t\t     |   1. Buy Products         |\n";
    cout << "\t\t\t\t\t\t     |                           |\n";
    cout << "\t\t\t\t\t\t     |   2. list Products        |\n";
    cout << "\t\t\t\t\t\t     |                           |\n";
    cout << "\t\t\t\t\t\t     |   3. Back to Main Menu    |\n";
    cout << "\t\t\t\t\t\t     |___________________________|\n\n";
    cout << "\t\t\t\t\t\t        Enter your choice (1-3): ";
    cin >> choice;
    system("cls");
    switch (choice)
    {
    case 2:
        listProducts();
        buyerMenu();
        break;
    case 1:
        generateReceipt();
        buyerMenu();
        break;
    case 3:
        menu();
        break;
    default:
        cout << "\nInvalid choice. Please try again.\n";
        buyerMenu();
    }
}

/*-------------------------CHECK ITEM---------------------------*/

bool Market::check(int m)
{
    ifstream inFile("products.txt");
    if (!inFile)
    {
        cout << "Unable to open products file." << endl;
        return false;
    }

    int code;
    string name;
    float productPrice, productDiscount;

    while (inFile >> code >> name >> productPrice >> productDiscount)
    {
        if (m == code)
        {
            inFile.close();
            return true;
        }
    }
    inFile.close();
    return false;
}

/*-------------------------ADD PRODUCT-------------------------*/
void Market::addProduct()
{
    cout << "\t\t\t\t\t ADD NEW PRODUCT" << endl
         << endl;
    cout << "\t\t\t\t Enter Product Code: ";
    cin >> pcode;

    if (!check(pcode))
    {
        ofstream outFile("products.txt", ios::app);
        if (!outFile)
        {
            cout << "Unable to add product." << endl;
            return;
        }

        cout << "\t\t\t\t Enter Product Name: ";
        cin >> pname;
        cout << "\t\t\t\t Enter Product Price: ";
        cin >> price;
        cout << "\t\t\t\t Enter Product Discount: ";
        cin >> discount;

        outFile << pcode << " " << pname << " " << price << " " << discount << endl;

        outFile.close();
        system("cls");
        cout << "\t\t\t\t Product added successfully." << endl;
    }
    else
    {
        cout << "\t\t\t\t Enter a different product code." << endl
             << endl
             << endl;
        addProduct(); // Recursive call to allow entering a different product code
    }
}

/*-------------------------EDIT PRODUCT-------------------------*/
void Market::editProduct()
{
    int code;
    cout << "\t\t\t\t\t\t ________________________________________________\n";
    cout << "\t\t\t\t\t\t|                                                |\n";
    cout << "\t\t\t\t\t\t|               EDIT PRODUCT MENU                |\n";
    cout << "\t\t\t\t\t\t|________________________________________________|\n\n";
    cout << "\t\t\t\t\t\tEnter Product Code to edit: ";
    cin >> code;

    ifstream inFile("products.txt");
    ofstream outFile("temp.txt");

    if (!inFile)
    {
        cout << "Error: Unable to open the file.\n";
        return;
    }

    bool found = false;
    while (inFile >> pcode >> pname >> price >> discount)
    {
        if (pcode == code)
        {
            found = true;
            cout << "\t\t\t\t\t\tEnter New Product Name: ";
            cin >> pname;
            cout << "\t\t\t\t\t\tEnter New Product Price: ";
            cin >> price;
            cout << "\t\t\t\t\t\tEnter New Product Discount (%): ";
            cin >> discount;
        }
        outFile << pcode << " " << pname << " " << price << " " << discount << endl;
    }

    inFile.close();
    outFile.close();

    if (found)
    {
        remove("products.txt");
        rename("temp.txt", "products.txt");
        system("cls");
        cout << "\n \t\t\t\t\t\t Product updated successfully!\n\n\n";
    }
    else
    {
        cout << "\nProduct not found!\n";
    }
}

/*-------------------------REMOVE PRODUCT-------------------------*/
void Market::removeProduct()
{
    int code;
    cout << "\t\t\t\t\t\t ________________________________________________\n";
    cout << "\t\t\t\t\t\t|                                                |\n";
    cout << "\t\t\t\t\t\t|             REMOVE PRODUCT MENU               |\n";
    cout << "\t\t\t\t\t\t|________________________________________________|\n\n";
    cout << "\t\t\t\t\t\tEnter Product Code to remove: ";
    cin >> code;

    ifstream inFile("products.txt");
    ofstream outFile("temp.txt");

    if (!inFile)
    {
        cout << "Error: Unable to open the file.\n";
        return;
    }

    bool found = false;
    while (inFile >> pcode >> pname >> price >> discount)
    {
        if (pcode != code)
        {
            outFile << pcode << " " << pname << " " << price << " " << discount << endl;
        }
        else
        {
            found = true;
        }
    }

    inFile.close();
    outFile.close();

    if (found)
    {
        remove("products.txt");
        rename("temp.txt", "products.txt");
        cout << "\n\t\t\t\t\t\t Product removed successfully!\n\n\n";
    }
    else
    {
        cout << "\t\t\t\t\t\t Product not found!\n\n\n";
    }
}

/*-------------------------LIST PRODUCTS-------------------------*/
void Market::listProducts()
{
    cout << "\t\t\t\t\t ___________________________________________________________________\n";
    cout << "\t\t\t\t\t|                                                                   |\n";
    cout << "\t\t\t\t\t|                           LIST OF PRODUCTS                        |\n";
    cout << "\t\t\t\t\t|___________________________________________________________________|\n\n";

    ifstream inFile("products.txt");

    if (!inFile)
    {
        cerr << "Error: Unable to open the file.\n";
        return;
    }

    cout << "\t\t\t\t\tProduct Code\tProduct Name\tProduct Price\tProduct Discount (%)\n";
    cout << "\t\t\t\t\t--------------------------------------------------------------------\n";

    while (inFile >> pcode >> pname >> price >> discount)
    {
        cout << "\t\t\t\t\t  " << pcode << "\t\t" << pname << "\t\t " << price << "\t\t  " << discount << endl;
    }
    cout << "\t\t\t\t\t--------------------------------------------------------------------\n";
    inFile.close();
}

/*-------------------------GENERATE RECEIPT-------------------------*/

void Market::generateReceipt()
{
    vector<int> products;
    vector<int> productquantity;
    int quantity;
    float a, b;
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
    f:
        cout << "\n\n\t\t\t\t\t\t Product code (0 to exit) : ";
        cin >> pcode;

        for (int i = 0; i < products.size(); i++)
        {
            if (pcode == products[i])
            {
                cout << "\t\t\t\t\t\t You've already added this product" << endl;
                goto m;
            }
        }
        if (check(pcode))
        {
            products.push_back(pcode);
            cout << "\t\t\t\t\t\t Product Quantity         : ";
        q:
            cin >> quantity;
            if (quantity <= 0)
            {
                cerr << "\t\t\t\t\t\t Invalid Quantity" << endl;
                cout << "\t\t\t\t\t\t Re-enter quantity        : ";
                goto q;
            }
            else
            {
                productquantity.push_back(quantity);
            }
        }
        else if (pcode == 0)
        {
            break;
        }

        else
        {
            cout << "\t\t\t\t\t\t  Wrong Product code" << endl;
            goto x;
        }

    } while (pcode != 0);

    //--------------To check whether it is working fine-----------
    //    for (int i = 0; i < products.size(); i++)
    //    {
    //      cout<<products[i]<<" ";
    //    }

    //-------------------------------FINAL BILL------------------------------------
    char ch;
    cout << "\n\n \t\t\t\t\t\t Do you want to Exit (Y/N)?\n";
    cout << " \t\t\t\t\t\t 'Y' or an 'N' : ";
    cin >> ch;
    if (ch == 'n' || ch == 'N')
    {
        goto f;
    }

    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout << "\t\t  _________________________________________________________________________________________________" << endl;
    cout << "\t\t |                                                                  |                              |" << endl;
    cout << "\t\t |        DHAKAD SUPER MART                                         |   DATE       : " << __DATE__ << "   |" << endl;
    cout << "\t\t |        INDORE, 452001                                            |   TIME       : " << __TIME__ << "      |" << endl;
    cout << "\t\t |__________________________________________________________________|______________________________|" << endl
         << endl;

    cout << "\t\t Pcode"
         << "\t\t"
         << "Pname"
         << "\t\t"
         << "Price"
         << "\t\t"
         << "Qty"
         << "\t\t"
         << "Discount(%)"
         << "\t\t"
         << "Amount" << endl;

    for (int i = 0; i < products.size(); i++)
    {

        ifstream checkFile("products.txt");
        while (checkFile >> pcode >> pname >> price >> discount)
        {

            if (products[i] == pcode)
            {
                a = price * (discount / 100);
                b = productquantity[i] * a;
                amount = ((price * productquantity[i]) - b);
                total += amount;
                cout << "\t\t  " << pcode << "\t\t" << pname << "\t\t" << price << "\t\t" << productquantity[i] << "\t\t" << discount << "\t\t\t" << amount << endl;
            }
        }
    }
    cout << "\t\t _________________________________________________________________________________________________" << endl;
    cout << "\t\t" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t GRAND TOTAL = " << total << endl;
    cout << "\t\t _________________________________________________________________________________________________" << endl
         << endl
         << endl
         << endl;

    int exit;
    cout << "\n\n\t\t\t\t\t\t\t Back to main menu(Enter 0) : ";
    cin >> exit;
    system("cls");
}

int main()
{
    Market super;
    super.menu();

    return 0;
}
