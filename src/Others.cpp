// ============================================================
//  Others.cpp  –  Miscellaneous / General category
// ============================================================
#include "Others.h"
#include <iostream>

// Correct implementation of Others constructor matching base signature
Others::Others(int id, const std::string& name, double price,
               const std::string& description)
    : Product(id, name, price, description, "Others") {}

void Others::display() const {
    std::cout << "  🛒 ";   // Shopping cart emoji
    Product::display();
}

std::vector<Others> Others::getCatalog() {
    return {
        {401, "Yoga Mat",                    19.99, "6 mm thick, non-slip, carry strap included"},
        {402, "Scented Candle Set",          14.99, "3-pack, 40 h burn each, vanilla/cedar/citrus"},
        {403, "Stainless Water Bottle",      22.99, "750 ml, double-wall insulated, leak-proof lid"},
        {404, "Leather Wallet",              24.99, "Bifold, RFID blocking, 8 card slots"},
        {405, "Bluetooth Speaker",           44.99, "360 sound, IPX7, 12 h playback, USB-C charge"},
        {406, "Desk Organiser Set",          18.99, "Bamboo, 5 compartments, pen holder included"},
        {407, "Reusable Grocery Bag 3-Pack", 11.99, "Heavy-duty, 30 L each, machine washable"},
        {408, "Puzzle 1000 Pieces",          16.99, "Landscape art, 50x70 cm assembled, family fun"},
    };
}
