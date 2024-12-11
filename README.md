# AlgoProject

# Inventory System - Documentation

## Project Overview

The **Inventory System** is a C++ Command-Line Interface (CLI) program that allows for the management of products in an inventory. It supports operations such as adding products, searching products by ID or type, deleting products, and sorting products by their amount. The system implements various algorithms to handle these operations efficiently.

---

## Features

1. **Add New Product**
   - Add a product to the inventory using either Linear Search or Hash Table to check for uniqueness.
   
2. **Retrieve Product by ID**
   - Retrieve a product based on its unique ID using either Binary Search or Breadth-First Search (BFS).
   
3. **Search Product by Type**
   - Search for products by their type using either Naive String Matching or Exhaustive Search.
   
4. **Delete Product by ID**
   - Delete a product from the inventory using either Array-based Deletion or AVL Tree for maintaining a balanced structure after deletion.
   
5. **Sort Products by Amount**
   - Sort the products by their amount using either Merge Sort or Counting Sort.

---

## Algorithms Used

### 1. **Add New Product**

#### a. **Linear Search for Unique Product_ID Validation**
   - **Explanation**: The Linear Search algorithm scans through each product in the inventory, comparing the `Product_ID` of each product with the new product's `Product_ID`. If a match is found, the product is not added.
   - **Time Complexity**: 
     - Best case: O(1) (if the first product ID is a match).
     - Worst case: O(n) (if the product ID is not found after scanning all products).
   
#### b. **Hash Table for Unique Product_ID Validation**
   - **Explanation**: The Hash Table stores `Product_ID`s in a table, ensuring constant time O(1) complexity for checking whether a product ID already exists in the inventory.
   - **Time Complexity**: 
     - Average case: O(1) for both searching and insertion.
     - Worst case: O(n) in case of hash collisions.
   
---

### 2. **Retrieve Product by ID**

#### a. **Binary Search on Sorted Product_IDs**
   - **Explanation**: Binary Search works by dividing the inventory into two halves and recursively checking the middle value against the desired `Product_ID`. The process repeats by narrowing down the search range.
   - **Time Complexity**: 
     - O(log n), as the inventory is divided in half at each step.
   
#### b. **Breadth-First Search (BFS)**
   - **Explanation**: BFS starts from the root and explores all neighboring nodes at the present depth before moving on to nodes at the next level. In the context of the inventory, this method explores all products to find a match.
   - **Time Complexity**: 
     - O(n), since BFS explores all the nodes in the inventory.
   
---

### 3. **Search Product by Type**

#### a. **Naive String Matching**
   - **Explanation**: The Naive String Matching algorithm searches for the target type (`Type_of_Product`) in each product's `Type_of_Product` by sequentially comparing each string.
   - **Time Complexity**: 
     - Best case: O(n) (if all products are of the same type).
     - Worst case: O(n * m), where n is the number of products and m is the length of the string being matched.
   
#### b. **Exhaustive Search**
   - **Explanation**: Exhaustive Search checks each product's `Type_of_Product` against the target type, similar to Naive String Matching, but it may employ more efficient comparisons.
   - **Time Complexity**: 
     - O(n), as it searches through every product.

---

### 4. **Delete Product by ID**

#### a. **Array-based Deletion**
   - **Explanation**: In this method, once a product is found, it is removed from the array and all subsequent products are shifted to fill the gap.
   - **Time Complexity**: 
     - Worst case: O(n), as it may require shifting all products in the array after deletion.
   
#### b. **AVL Tree for Maintaining Balanced Structure**
   - **Explanation**: The AVL Tree ensures that the tree remains balanced after a product is deleted, maintaining O(log n) time complexity for both insertion and deletion.
   - **Time Complexity**: 
     - O(log n), as AVL trees are balanced and provide logarithmic time for deletion.
   
---

### 5. **Sort Products by Amount**

#### a. **Merge Sort**
   - **Explanation**: Merge Sort divides the inventory into smaller subarrays, sorts them, and then merges the sorted subarrays into one final sorted array. This algorithm is a stable, divide-and-conquer approach.
   - **Time Complexity**: 
     - O(n log n), as the array is recursively divided and merged.
   
#### b. **Counting Sort**
   - **Explanation**: Counting Sort counts the number of occurrences of each unique value (in this case, the `Product_Amount`) and uses this count to place products in their correct sorted position.
   - **Time Complexity**: 
     - O(n + k), where n is the number of products and k is the range of the `Product_Amount` values.
   
---

## Comparison of Algorithms

| Operation                          | Algorithm 1                 | Time Complexity 1 | Algorithm 2                | Time Complexity 2 |
|-------------------------------------|-----------------------------|-------------------|----------------------------|-------------------|
| **Add New Product**                 | Linear Search               | O(n)              | Hash Table                 | O(1) (avg)        |
| **Retrieve Product by ID**          | Binary Search               | O(log n)          | BFS                        | O(n)              |
| **Search Product by Type**          | Naive String Matching       | O(n * m)          | Exhaustive Search          | O(n)              |
| **Delete Product by ID**            | Array-based Deletion        | O(n)              | AVL Tree                   | O(log n)          |
| **Sort Products by Amount**         | Merge Sort                  | O(n log n)        | Counting Sort              | O(n + k)          |

---

## Conclusion

The **Inventory System** is designed to demonstrate the use of different algorithms for common inventory operations. It provides a variety of ways to perform tasks such as adding, searching, deleting, and sorting products, and allows users to choose the most suitable algorithm for each operation.

By comparing the time complexities of each algorithm, you can make informed decisions about performance optimization, depending on the size of the inventory and the frequency of each operation.
