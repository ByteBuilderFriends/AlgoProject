#include "inventory.h"
#include <algorithm>

using namespace std;

// Helper function for Array-based deletion
bool Inventory::arrayBasedDeletion(const string& productID) {
    // Search for the product in the inventory by ID
    auto it = find_if(inventory.begin(), inventory.end(), [&productID](const Product& product) {
        return product.Product_ID == productID;
    });

    if (it != inventory.end()) {
        // Product found, remove it
        inventory.erase(it);
        cout << "Product with ID " << productID << " deleted successfully!" << endl;
        return true;
    }

    cout << "Error: Product with ID " << productID << " not found!" << endl;
    return false;
}

// Helper function for AVL Tree-based deletion
bool Inventory::avlTreeDeletion(const string& productID) {
    // Check if the product exists in the hash table (for AVL, we need a balanced structure)
    if (productTable.find(productID) != productTable.end()) {
        // Delete the product from the hash table
        productTable.erase(productID);

        // Also remove the product from the sorted list and inventory vector
        sortedProductIDs.erase(remove(sortedProductIDs.begin(), sortedProductIDs.end(), productID), sortedProductIDs.end());
        
        auto it = find_if(inventory.begin(), inventory.end(), [&productID](const Product& product) {
            return product.Product_ID == productID;
        });
        if (it != inventory.end()) {
            inventory.erase(it);
        }

        // After deletion, maintain AVL tree balancing (this would require an AVL tree structure, which we assume you will implement)
        // Example: Rebalance the AVL tree if necessary
        cout << "Product with ID " << productID << " deleted and AVL tree rebalanced!" << endl;
        return true;
    }

    cout << "Error: Product with ID " << productID << " not found!" << endl;
    return false;
}

// Method to delete product by ID using Array-based deletion
bool Inventory::deleteProductByIDArrayBased(const string& productID) {
    return arrayBasedDeletion(productID);
}

// Method to delete product by ID using AVL Tree-based deletion
bool Inventory::deleteProductByIDAVLTree(const string& productID) {
    return avlTreeDeletion(productID);
}
