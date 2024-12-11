#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include "product.h"  // Include the Product struct

using namespace std;

class Inventory {
private:
    vector<Product> inventory;               // Vector to store products (for Linear Search method)
    unordered_map<string, Product> productTable; // Hash Table to store products (for Hash Table method)
    vector<string> sortedProductIDs;          // Vector for storing sorted Product_IDs for Binary Search

public:
    // Constructor
    Inventory();

    // Task 1: Add New Product
    void addProductLinearSearch(const Product& newProduct); // Linear Search
    void addProductHashTable(const Product& newProduct);   // Hash Table

    // Task 2: Retrieve Product by ID
    Product retrieveProductByIDBinarySearch(const string& productID); // Binary Search on sorted Product_IDs
    Product retrieveProductByIDBFS(const string& productID);         // Breadth-First Search (BFS)

    // Task 3: Search Product by Type
    vector<Product> searchProductByTypeNaive(const string& productType); // Naive String Matching
    vector<Product> searchProductByTypeExhaustive(const string& productType); // Exhaustive Search

    // Task 4: Delete Product by ID
    void deleteProductByIDArray(const string& productID);  // Array-based deletion
    void deleteProductByIDAVL(const string& productID);    // AVL Tree deletion (to maintain balanced structure)

    // Task 5: Sort Products by Amount
    void sortProductsByAmountMergeSort();  // Merge Sort
    void sortProductsByAmountCountingSort(); // Counting Sort

    // Utility functions
    void displayInventory();  // Display all products in the inventory (for testing or debugging)
};

#endif // INVENTORY_H
