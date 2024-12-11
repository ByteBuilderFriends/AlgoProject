struct Product {
    string Product_ID;
    string Product_Name;
    int Product_Amount;
    double Price;
    string Type_of_Product;
    int Shelf_Number;
    // Add other suitable fields here if needed
};

class InventorySystem {
private:
    vector<Product> products; // Store all products
    unordered_set<string> productIDHashTable; // Hash table for quick lookup

public:
    // Function to check if Product_ID is unique using linear search
    bool isUniqueLinear(const string& productID) {
        for (const auto& product : products) {
            if (product.Product_ID == productID) {
                return false; // Product_ID already exists
            }
        }
        return true;
    }

    // Function to check uniqueness using hash table
    bool isUniqueHashTable(const string& productID) {
        return productIDHashTable.find(productID) == productIDHashTable.end();
    }

    // Function to add a new product
    void addNewProduct() {
        Product newProduct;

        cout << "Enter Product ID: ";
        cin >> newProduct.Product_ID;

        // Validate uniqueness
        if (!isUniqueLinear(newProduct.Product_ID)) {
            cout << "Error: Product ID already exists.\n";
            return;
        }

        // Store the Product_ID in the hash table for future quick checks
        productIDHashTable.insert(newProduct.Product_ID);

        cout << "Enter Product Name: ";
        cin.ignore();
        getline(cin, newProduct.Product_Name);

        cout << "Enter Product Amount: ";
        cin >> newProduct.Product_Amount;

        cout << "Enter Product Price: ";
        cin >> newProduct.Price;

        cout << "Enter Type of Product: ";
        cin.ignore();
        getline(cin, newProduct.Type_of_Product);

        cout << "Enter Shelf Number: ";
        cin >> newProduct.Shelf_Number;

        // Add the product to the inventory
        products.push_back(newProduct);

        cout << "Product added successfully!\n";
    }

    // Debug function to display all products
    void displayProducts() {
        for (const auto& product : products) {
            cout << "Product ID: " << product.Product_ID << "\n"
                 << "Product Name: " << product.Product_Name << "\n"
                 << "Amount: " << product.Product_Amount << "\n"
                 << "Price: " << product.Price << "\n"
                 << "Type: " << product.Type_of_Product << "\n"
                 << "Shelf Number: " << product.Shelf_Number << "\n"
                 << "-------------------------\n";
        }
    }
};
