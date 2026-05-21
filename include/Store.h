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

    // Helper methods
    void loadCatalog();
    std::shared_ptr<Product> findById(int id) const;
    void showMainMenu() const;

public:
    Store();

    // Core UI Actions
    void displayAll() const;
    
    // REMOVED 'const' here because it now modifies the cart state
    void displayByCategory(); 
    
    void searchByName() const;
    void viewCart() const;
    void checkout();
    
    // Main execution loop
    void run();
};
