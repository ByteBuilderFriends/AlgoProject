#include "inventory.h"
#include <queue>
#include <algorithm>

using namespace std;

// Helper function to perform Binary Search on sorted Product_IDs
Product* Inventory::binarySearchByID(const string& productID) {
    int left = 0;
    int right = sortedProductIDs.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sortedProductIDs[mid] == productID) {
            // Find and return the corresponding product
            return &productTable[sortedProductIDs[mid]];
        }
        if (sortedProductIDs[mid] < productID) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return nullptr;  // Product not found
}

// Helper function to perform Breadth-First Search (BFS) on the inventory vector
Product* Inventory::breadthFirstSearchByID(const string& productID) {
    if (inventory.empty()) {
        return nullptr;
    }

    queue<Product*> productQueue;
    // Enqueue all products in the inventory
    for (auto& product : inventory) {
        productQueue.push(&product);
    }

    // Perform BFS
    while (!productQueue.empty()) {
        Product* currentProduct = productQueue.front();
        productQueue.pop();

        if (currentProduct->Product_ID == productID) {
            return currentProduct;  // Product found
        }
    }

    return nullptr;  // Product not found
}

// Method to retrieve product by ID using Binary Search
Product* Inventory::retrieveProductByIDBinarySearch(const string& productID) {
    return binarySearchByID(productID);
}

// Method to retrieve product by ID using Breadth-First Search
Product* Inventory::retrieveProductByIDBFS(const string& productID) {
    return breadthFirstSearchByID(productID);
}
