#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Market {
private:
    int pcode;
    string pname;
    float price;
    float discount;

public:
    bool check(int m);
    void addProduct();
};

bool Market::check(int m) {
    ifstream inFile("products.txt");
    if (!inFile) {
        cout << "Unable to open products file." << endl;
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

void Market::addProduct() {
    cout << "ADD NEW PRODUCT" << endl;
    cout << "Enter Product Code: ";
    cin >> pcode;

    if (!check(pcode)) {
        ofstream outFile("products.txt", ios::app);
        if (!outFile) {
            cout << "Unable to add product." << endl;
            return;
        }

        cout << "Enter Product Name: ";
        cin >> pname;
        cout << "Enter Product Price: ";
        cin >> price;
        cout << "Enter Product Discount: ";
        cin >> discount;

        outFile << pcode << " " << pname << " " << price << " " << discount << endl;

        outFile.close();

        cout << "Product added successfully." << endl;
    }
    else {
        cout << "Enter a different product code." << endl;
        addProduct(); // Recursive call to allow entering a different product code
    }
}

int main() {
    Market p;
    p.addProduct();
    return 0;
}
