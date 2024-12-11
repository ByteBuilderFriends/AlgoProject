#include "inventory.h"

using namespace std;

// Add new product using Hash Table to check for uniqueness of Product_ID
void Inventory::addProductHashTable(const Product& newProduct) {
    // Check if the Product_ID already exists using the Hash Table
    if (productTable.find(newProduct.Product_ID) != productTable.end()) {
        cout << "Error: Product with ID " << newProduct.Product_ID << " already exists!" << endl;
        return; // Exit the function if the product ID is not unique
    }

    // If the Product_ID is unique, add the new product to the hash table
    productTable[newProduct.Product_ID] = newProduct;

    cout << "Product with ID " << newProduct.Product_ID << " added successfully!" << endl;
}
