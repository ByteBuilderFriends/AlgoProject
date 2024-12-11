#include "inventory.h"

using namespace std;

// Helper function for Naive String Matching algorithm
vector<Product*> Inventory::naiveStringMatching(const string& productType) {
    vector<Product*> result;

    // Iterate through the inventory and find products matching the type
    for (auto& product : inventory) {
        if (product.Type_of_Product == productType) {
            result.push_back(&product);  // Add the matching product to the result
        }
    }

    return result;
}

// Helper function for Exhaustive Search algorithm
vector<Product*> Inventory::exhaustiveSearch(const string& productType) {
    vector<Product*> result;

    // Iterate through the inventory and find products matching the type
    for (auto& product : inventory) {
        if (product.Type_of_Product == productType) {
            result.push_back(&product);  // Add the matching product to the result
        }
    }

    return result;
}

// Method to search products by type using Naive String Matching
vector<Product*> Inventory::searchProductByTypeNaive(const string& productType) {
    return naiveStringMatching(productType);
}

// Method to search products by type using Exhaustive Search
vector<Product*> Inventory::searchProductByTypeExhaustive(const string& productType) {
    return exhaustiveSearch(productType);
}
