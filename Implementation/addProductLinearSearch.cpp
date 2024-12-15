#include "inventory.h"

using namespace std;

// Constructor to initialize the inventory
Inventory::Inventory() {
    // Initialize the inventory with an empty vector and hash table
    inventory = {};
    productTable = {};
    sortedProductIDs = {};
}

// Add new product using Linear Search to check for uniqueness of Product_ID
void Inventory::addProductLinearSearch(const Product& newProduct) {
    // Check if the Product_ID already exists using Linear Search
    for (const auto& product : inventory) {
        if (product.Product_ID == newProduct.Product_ID) {
            cout << "Error: Product with ID " << newProduct.Product_ID << " already exists!" << endl;
            return; // Exit the function if the product ID is not unique
        }
    }

    // If the Product_ID is unique, add the new product to the inventory
    inventory.push_back(newProduct);
    sortedProductIDs.push_back(newProduct.Product_ID);

    cout << "Product with ID " << newProduct.Product_ID << " added successfully!" << endl;
}
