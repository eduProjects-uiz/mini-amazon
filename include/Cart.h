#pragma once
#include "Product.h"
#include <vector>
#include <memory>
#include <iostream>

// ============================================================
//  Cart.h  –  Shopping cart / panier management
// ============================================================

struct CartItem {
    std::shared_ptr<Product> product;
    int quantity;
};

class Cart {
private:
    std::vector<CartItem> items;

public:
    // Add a product (increments quantity if already present)
    void addProduct(std::shared_ptr<Product> product);

    // Remove a product by ID (completely)
    bool removeProduct(int productId);

    // Display all items in the cart
    void displayCart() const;

    // Print the final bill (Defaults to std::cout, can take an ofstream)
    void printBill(std::ostream& os = std::cout) const;

    // Check if the cart is empty
    bool isEmpty() const;

    // Clear the entire cart
    void clear();
};
