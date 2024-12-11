#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

using namespace std;

// Struct for Product
struct Product {
    string Product_ID;      // Primary key (e.g., "20-071-020")
    string Product_Name;    // Name of the product
    int Product_Amount;     // Quantity of the product
    double Price;           // Price of the product
    string Type_of_Product; // Type of product (e.g., "eat", "syrup", "hard", "soft")
    int Shelf_Number;       // Shelf number for the product location

    // Constructor to initialize the product
    Product(string id, string name, int amount, double price, string type, int shelf)
        : Product_ID(id), Product_Name(name), Product_Amount(amount), Price(price), Type_of_Product(type), Shelf_Number(shelf) {}
};

#endif // PRODUCT_H
