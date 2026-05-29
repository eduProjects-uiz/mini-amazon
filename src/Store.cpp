// ============================================================
//  Store.cpp  –  Central catalog manager and UI controller
// ============================================================
#include "Store.h"
#include "KitchenEquipment.h"
#include "InformaticsEquipment.h"
#include "Clothes.h"
#include "Others.h"

#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <limits>
#include <fstream> 

// ---- Constructor -----------------------------------------------
Store::Store() { loadCatalog(); }

// ---- loadCatalog -----------------------------------------------
void Store::loadCatalog() {
    // Kitchen
    for (auto& p : KitchenEquipment::getCatalog())
        catalog.push_back(std::make_shared<KitchenEquipment>(p));

    // Informatics
    for (auto& p : InformaticsEquipment::getCatalog())
        catalog.push_back(std::make_shared<InformaticsEquipment>(p));

    // Clothes
    for (auto& p : Clothes::getCatalog())
        catalog.push_back(std::make_shared<Clothes>(p));

    // Others
    for (auto& p : Others::getCatalog())
        catalog.push_back(std::make_shared<Others>(p));
}

// ---- findById --------------------------------------------------
std::shared_ptr<Product> Store::findById(int id) const {
    for (const auto& p : catalog)
        if (p->getId() == id) return p;
    return nullptr;
}

// ---- showMainMenu ----------------------------------------------
void Store::showMainMenu() const {
    std::cout << "\n  ========================================\n";
    std::cout << "         🛒  AMAZON-LIKE STORE  🛒\n";
    std::cout << "  ========================================\n";
    std::cout << "   1. Display ALL products\n";
    std::cout << "   2. Browse Category & Manage Cart (Add/Remove)\n";
    std::cout << "   3. Search product by name\n";
    std::cout << "   4. View final panier (Cart)\n";
    std::cout << "   5. Checkout & Register Bill\n";
    std::cout << "   0. Exit\n";
    std::cout << "  ----------------------------------------\n";
    std::cout << "   Your choice: ";
}

// ---- displayAll ------------------------------------------------
void Store::displayAll() const {
    std::cout << "\n  === ALL PRODUCTS (" << catalog.size() << ") ===\n\n";
    for (const auto& p : catalog) {
        p->display();
        std::cout << "\n";
    }
}

// ---- displayByCategory (Merged Management) ---------------------
void Store::displayByCategory() {
    const std::vector<std::string> categories = {
        "Kitchen Equipment",
        "Informatics Equipment",
        "Clothes",
        "Others"
    };

    std::cout << "\n  Select category:\n";
    for (int i = 0; i < (int)categories.size(); ++i)
        std::cout << "   " << (i + 1) << ". " << categories[i] << "\n";
    std::cout << "  Your choice: ";

    int choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (choice < 1 || choice > (int)categories.size()) {
        std::cout << "  Invalid choice.\n";
        return;
    }

    const std::string& cat = categories[choice - 1];

    int action = -1;
    while (action != 0) {
        std::cout << "\n  === " << cat << " ===\n\n";
        bool found = false;
        for (const auto& p : catalog) {
            if (p->getCategory() == cat) {
                p->display();
                std::cout << "\n";
                found = true;
            }
        }
        if (!found) { 
            std::cout << "  No products in this category.\n"; 
            return; 
        }

        cart.displayCart();

        std::cout << "  ----------------------------------------\n";
        std::cout << "   1. Add a product to cart\n";
        std::cout << "   2. Remove a product from cart\n";
        std::cout << "   0. Back to main menu\n";
        std::cout << "  Your choice: ";
        std::cin >> action;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (action == 1) {
            std::cout << "  Enter product ID to add: ";
            int id; std::cin >> id;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            auto product = findById(id);
            
            if (product) {
                std::cout << "  [Stock Info] Verifying inventory allocation for ID " << id << "...\n";
                cart.addProduct(product);
                std::cout << "  -> Added successfully to your panier.\n";
            } else {
                std::cout << "  Product ID " << id << " not found.\n";
            }

        } else if (action == 2) {
            std::cout << "  Enter product ID to remove: ";
            int id; std::cin >> id;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cart.removeProduct(id);
        }
    }
}

// ---- searchByName ----------------------------------------------
void Store::searchByName() const {
    std::cout << "\n  Enter search term: ";
    std::string term;
    std::getline(std::cin, term);

    auto toLower = [](std::string s) {
        std::transform(s.begin(), s.end(), s.begin(),
                       [](unsigned char c){ return std::tolower(c); });
        return s;
    };
    std::string lTerm = toLower(term);

    std::cout << "\n  === Search results for \"" << term << "\" ===\n\n";
    bool found = false;
    for (const auto& p : catalog) {
        if (toLower(p->getName()).find(lTerm) != std::string::npos ||
            toLower(p->getDescription()).find(lTerm) != std::string::npos) {
            p->display();
            std::cout << "\n";
            found = true;
        }
    }
    if (!found) std::cout << "  No products matched \"" << term << "\".\n";
}

// ---- viewCart --------------------------------------------------
void Store::viewCart() const {
    std::cout << "\n  === YOUR PANIER (CURRENT CART) ===\n";
    cart.displayCart();
}

// ---- checkout --------------------------------------------------


#include <fstream> // Make sure this is at the top of src/Store.cpp

void Store::checkout() {
    if (cart.isEmpty()) {
        std::cout << "  Your cart is empty – nothing to checkout.\n";
        return;
    }
    
    std::cout << "\n  === FINAL PANIER REVIEW ===\n";
    cart.displayCart();
    
    std::cout << "  Confirm purchase and save/register bill? (y/n): ";
    char confirm;
    std::cin >> confirm;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (confirm == 'y' || confirm == 'Y') {
        // Step A: Print the receipt on the console screen
        std::cout << "\n  --- Printing Receipt ---\n";
        cart.printBill(std::cout); 
        
        // Step B: Open the file stream and write the SAME itemized receipt to the file
        std::ofstream billFile("registered_bill.txt");
        if (billFile.is_open()) {
            cart.printBill(billFile); // Writes products, subtotal, 20% TVA, and Total directly into the file
            billFile.close();
            std::cout << "  [File System] Complete itemized bill successfully registered to 'registered_bill.txt'!\n";
        } else {
            std::cout << "  [Error] Failed to write registered_bill.txt file structure.\n";
        }

        // Clear the cart after a successful order
        cart.clear();
        std::cout << "  Order placed! Your cart has been cleared.\n";
    } else {
        std::cout << "  Checkout cancelled.\n";
    }
}

// ---- run -------------------------------------------------------
void Store::run() {
    int choice = -1;
    while (choice != 0) {
        showMainMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: displayAll();        break;
            case 2: displayByCategory(); break; 
            case 3: searchByName();      break;
            case 4: viewCart();          break;
            case 5: checkout();          break;
            case 0:
                std::cout << "\n  Goodbye! See you next time. 👋\n\n";
                break;
            default:
                std::cout << "  Invalid option. Please try again.\n";
        }
    }
}
