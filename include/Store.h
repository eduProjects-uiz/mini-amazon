#pragma once
#include "Product.h"
#include "Cart.h"
#include <vector>
#include <memory>
#include <string>

// ============================================================
//  Store.h  –  Central catalog manager and UI controller
// ============================================================

class Store {
private:
    std::vector<std::shared_ptr<Product>> catalog;
    Cart cart;

    // Internal helper methods
    void loadCatalog();
    std::shared_ptr<Product> findById(int id) const;
    void showMainMenu() const;

public:
    Store();

    // Core UI Actions
    void displayAll() const;
    void displayByCategory(); // Kept non-const so it can manage cart items
    void searchByName() const;
    void viewCart() const;
    void checkout();          // Handles both screen printing & file registration
    
    // Main execution loop
    void run();
};
