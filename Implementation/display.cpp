#include <iostream>
#include "Inventory.h"
using namespace std;

void Inventory::display() {
    if (productList.empty()) {
        cout << "No products in inventory." << endl;
        return;
    }

    // Header for the product list
    cout << "Product_ID\tProduct_Name\tProduct_Amount\tPrice\tType_of_Product\tShelf_Number" << endl;
    
    // Loop through each product and display the details
    for (const auto& product : productList) {
        cout << product.productID << "\t" 
             << product.productName << "\t"
             << product.productAmount << "\t"
             << product.price << "\t"
             << product.typeOfProduct << "\t"
             << product.shelfNumber << endl;
    }
}
