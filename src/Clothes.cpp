// ============================================================
//  Clothes.cpp  –  Clothing & Fashion category
// ============================================================
#include "Clothes.h"
#include <iostream>

Clothes::Clothes(int id, const std::string& name, double price,
                 const std::string& description)
    : Product(id, name, price, description, "Clothes") {}

void Clothes::display() const {
    std::cout << "  👕 ";   // T-shirt emoji
    Product::display();
}

std::vector<Clothes> Clothes::getCatalog() {
    return {
        {301, "Classic White T-Shirt",       12.99, "100% cotton, crew neck, unisex, sizes XS-3XL"},
        {302, "Slim-Fit Denim Jeans",        49.99, "Stretch denim, mid-rise, available in 5 colors"},
        {303, "Hoodie Fleece",               34.99, "80% cotton, kangaroo pocket, sizes XS-2XL"},
        {304, "Waterproof Rain Jacket",      79.99, "Taped seams, packable, reflective trim"},
        {305, "Running Sneakers",            69.99, "Lightweight mesh upper, cushioned sole, US 6-13"},
        {306, "Wool Blend Overcoat",        129.99, "Double-breasted, herringbone, sizes XS-XL"},
        {307, "Sports Leggings",             27.99, "High-waist, 4-way stretch, UPF 50+"},
        {308, "Casual Linen Shirt",          31.99, "Relaxed fit, breathable, button-down collar"},
    };
}
