int main() {
    InventorySystem inventory;
    int choice;

    do {
        cout << "1. Add New Product\n";
        cout << "2. Display Products\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            inventory.addNewProduct();
            break;
        case 2:
            inventory.displayProducts();
            break;
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
