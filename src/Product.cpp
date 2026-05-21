// ============================================================
//  Product.cpp  –  Base class implementation
// ============================================================
#include "Product.h"
#include <iostream>
#include <iomanip>

Product::Product(int id, const std::string& name, double price,
                 const std::string& description, const std::string& category)
    : id(id), name(name), price(price),
      description(description), category(category) {}

int         Product::getId()          const { return id; }
std::string Product::getName()        const { return name; }
double      Product::getPrice()       const { return price; }
std::string Product::getDescription() const { return description; }
std::string Product::getCategory()    const { return category; }

void Product::display() const {
    std::cout << "  [" << std::setw(3) << id << "] "
              << std::left << std::setw(30) << name
              << "  $" << std::fixed << std::setprecision(2) << price
              << "\n       Category   : " << category
              << "\n       Description: " << description << "\n";
}
