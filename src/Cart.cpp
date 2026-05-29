// ============================================================
//  Cart.cpp  –  Shopping cart / panier implementation
// ============================================================
#include "Cart.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ctime>

// ---- addProduct ------------------------------------------------
void Cart::addProduct(std::shared_ptr<Product> product) {
    for (auto& item : items) {
        if (item.product->getId() == product->getId()) {
            item.quantity++;
            std::cout << "  -> Quantity updated: " << product->getName()
                      << " (x" << item.quantity << ")\n";
            return;
        }
    }
    items.push_back({product, 1});
    std::cout << "  -> Added to cart: " << product->getName() << "\n";
}

// ---- removeProduct ---------------------------------------------
bool Cart::removeProduct(int productId) {
    auto it = std::find_if(items.begin(), items.end(),
        [productId](const CartItem& ci) {
            return ci.product->getId() == productId;
        });

    if (it != items.end()) {
        std::cout << "  -> Removed from cart: " << it->product->getName() << "\n";
        items.erase(it);
        return true;
    }
    std::cout << "  -> Product ID " << productId << " not found in cart.\n";
    return false;
}

// ---- displayCart -----------------------------------------------
void Cart::displayCart() const {
    if (items.empty()) {
        std::cout << "  (Your cart is empty)\n";
        return;
    }
    std::cout << "\n  " << std::string(60, '-') << "\n";
    std::cout << "  CART CONTENTS\n";
    std::cout << "  " << std::string(60, '-') << "\n";
    double subtotal = 0;
    for (const auto& ci : items) {
        double lineTotal = ci.product->getPrice() * ci.quantity;
        subtotal += lineTotal;
        std::cout << "  [" << std::setw(3) << ci.product->getId() << "] "
                  << std::left << std::setw(28) << ci.product->getName()
                  << "  x" << ci.quantity
                  << "   $" << std::fixed << std::setprecision(2) << lineTotal << "\n";
    }
    std::cout << "  " << std::string(60, '-') << "\n";
    std::cout << "  Subtotal: $" << subtotal << "\n\n";
}

// ---- printBill (Updated with 20% TVA) --------------------------
void Cart::printBill(std::ostream& os) const {
    if (items.empty()) {
        os << "  Nothing to bill – your cart is empty.\n";
        return;
    }

    // Timestamp generation
    std::time_t now = std::time(nullptr);
    char timeBuf[32];
    std::strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d  %H:%M:%S", std::localtime(&now));

    const std::string LINE(56, '=');
    os << "\n  " << LINE << "\n";
    os << "              AMAZON-LIKE STORE – RECEIPT\n";
    os << "  " << LINE << "\n";
    os << "  Date : " << timeBuf << "\n";
    os << "  " << std::string(56, '-') << "\n";
    os << "  " << std::left << std::setw(28) << "Product"
       << std::setw(5)  << "Qty"
       << std::setw(10) << "Unit $"
       << "Total $\n";
    os << "  " << std::string(56, '-') << "\n";

    double subtotal = 0;
    for (const auto& ci : items) {
        double lineTotal = ci.product->getPrice() * ci.quantity;
        subtotal += lineTotal;
        os << "  " << std::left << std::setw(28) << ci.product->getName()
           << std::setw(5)  << ci.quantity
           << "$" << std::setw(9) << std::fixed << std::setprecision(2)
           << ci.product->getPrice()
           << "$" << lineTotal << "\n";
    }

    // --- TVA 20% Calculation ---
    const double TVA_RATE = 0.20;   // Changed from 0.08 to 0.20 (20%)
    double tvaAmount = subtotal * TVA_RATE;
    double total     = subtotal + tvaAmount;

    os << "  " << std::string(56, '-') << "\n";
    os << "  Subtotal  : $" << std::setw(10) << std::fixed << std::setprecision(2) << subtotal << "\n";
    os << "  TVA (20%) : $" << std::setw(10) << tvaAmount << "\n"; // Labeled explicitly as TVA
    os << "  " << std::string(56, '-') << "\n";
    os << "  TOTAL     : $" << std::setw(10) << total   << "\n";
    os << "  " << LINE << "\n";
    os << "       Thank you for shopping with us!\n";
    os << "  " << LINE << "\n\n";
}

// ---- isEmpty / clear -------------------------------------------
bool Cart::isEmpty() const { return items.empty(); }
void Cart::clear()          { items.clear(); }
