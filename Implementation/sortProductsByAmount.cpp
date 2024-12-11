#include "inventory.h"
#include <algorithm>
#include <iostream>

using namespace std;

// Helper function for Merge Sort algorithm
void merge(vector<Product>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    merge(arr, left, mid);      // Sort the left half
    merge(arr, mid + 1, right); // Sort the right half

    // Merge the two sorted halves
    vector<Product> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i].Product_Amount <= arr[j].Product_Amount) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    // Copy remaining elements from left half
    while (i <= mid) {
        temp.push_back(arr[i++]);
    }

    // Copy remaining elements from right half
    while (j <= right) {
        temp.push_back(arr[j++]);
    }

    // Copy the sorted array back to the original array
    for (int i = left; i <= right; ++i) {
        arr[i] = temp[i - left];
    }
}

// Merge Sort wrapper for sorting products by amount
void Inventory::mergeSortByAmount() {
    merge(inventory, 0, inventory.size() - 1);
    cout << "Products sorted by amount using Merge Sort!" << endl;
}

// Helper function for Counting Sort algorithm
void countingSort(vector<Product>& arr) {
    // Find the maximum product amount to know the range for counting sort
    int maxAmount = 0;
    for (const auto& product : arr) {
        maxAmount = max(maxAmount, product.Product_Amount);
    }

    // Initialize count array to store frequency of product amounts
    vector<int> count(maxAmount + 1, 0);

    // Count the frequency of each product amount
    for (const auto& product : arr) {
        count[product.Product_Amount]++;
    }

    // Reconstruct the sorted array based on the frequency count
    int index = 0;
    for (int i = 0; i <= maxAmount; ++i) {
        while (count[i]--) {
            arr[index].Product_Amount = i;
            index++;
        }
    }
}

// Counting Sort wrapper for sorting products by amount
void Inventory::countingSortByAmount() {
    countingSort(inventory);
    cout << "Products sorted by amount using Counting Sort!" << endl;
}
