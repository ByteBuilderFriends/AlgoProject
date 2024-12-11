#include <iostream>
#include "inventory.h"

using namespace std;

int main() {
    Inventory inv;

    // Add some products to the inventory
    Product p1 = {"20-071-020", "Apple Juice", 100, 5.99, "drink", 1};
    Product p2 = {"20-071-021", "Banana Syrup", 50, 3.49, "syrup", 2};
    Product p3 = {"20-071-022", "Carrot Juice", 30, 4.99, "drink", 3};
    Product p4 = {"20-071-023", "Hard Drive", 10, 79.99, "hard", 4};
    Product p5 = {"20-071-024", "Soft Drink", 120, 2.99, "drink", 5};

    // Add products using the methods
    inv.addProduct(p1);
    inv.addProduct(p2);
    inv.addProduct(p3);
    inv.addProduct(p4);
    inv.addProduct(p5);

    // Test Linear Search to add a new product
    cout << "Adding Product: 20-071-025\n";
    Product p6 = {"20-071-025", "Orange Juice", 60, 5.49, "drink", 6};
    inv.addNewProductLinearSearch(p6);

    // Test Hash Table for adding a new product
    cout << "Adding Product: 20-071-026\n";
    Product p7 = {"20-071-026", "Grapes Syrup", 40, 4.49, "syrup", 7};
    inv.addNewProductHashTable(p7);

    // Search products by type using Naive String Matching
    cout << "\nSearching for 'drink' products using Naive String Matching:\n";
    vector<Product> drinkProductsNaive = inv.searchByTypeNaive("drink");
    for (const auto& product : drinkProductsNaive) {
        cout << product.Product_Name << " - " << product.Type_of_Product << endl;
    }

    // Search products by type using Exhaustive Search
    cout << "\nSearching for 'syrup' products using Exhaustive Search:\n";
    vector<Product> syrupProductsExhaustive = inv.searchByTypeExhaustive("syrup");
    for (const auto& product : syrupProductsExhaustive) {
        cout << product.Product_Name << " - " << product.Type_of_Product << endl;
    }

    // Example of retrieving a product by ID (Linear Search)
    string searchID = "20-071-022";
    cout << "\nSearching for product by ID: " << searchID << "\n";
    Product* searchedProduct = inv.searchByID(searchID);
    if (searchedProduct) {
        cout << "Product found: " << searchedProduct->Product_Name << " - " << searchedProduct->Product_ID << endl;
    } else {
        cout << "Product not found\n";
    }

    // Example of deleting a product by ID
    cout << "\nDeleting product by ID: " << searchID << "\n";
    inv.deleteProductByID(searchID);
    searchedProduct = inv.searchByID(searchID);
    if (!searchedProduct) {
        cout << "Product successfully deleted\n";
    } else {
        cout << "Failed to delete the product\n";
    }

    return 0;
}
