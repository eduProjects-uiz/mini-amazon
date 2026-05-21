// ============================================================
//  KitchenEquipment.cpp  –  Kitchen category implementation
// ============================================================
#include "KitchenEquipment.h"
#include <iostream>

KitchenEquipment::KitchenEquipment(int id, const std::string& name,
                                   double price, const std::string& description)
    : Product(id, name, price, description, "Kitchen Equipment") {}

void KitchenEquipment::display() const {
    std::cout << "  🍳 ";   // Frying Pan emoji
    Product::display();
}

std::vector<KitchenEquipment> KitchenEquipment::getCatalog() {
    return {
        {101, "Non-Stick Frying Pan",       29.99, "24 cm, PTFE-coated, induction compatible"},
        {102, "Stainless Steel Knife Set",   54.99, "6-piece professional chef knives with block"},
        {103, "Stand Mixer",                199.00, "5-Qt, 10 speeds, includes dough hook & whisk"},
        {104, "Digital Kitchen Scale",       14.99, "Max 5 kg, 1 g precision, tare function"},
        {105, "Espresso Machine",           149.99, "15-bar pump, milk frother, 1.5 L tank"},
        {106, "Air Fryer 5L",               89.99, "Rapid hot-air technology, dishwasher-safe basket"},
        {107, "Bamboo Cutting Board Set",   21.99, "3-piece set, juice grooves, eco-friendly"},
        {108, "Instant Pot 7-in-1",        109.99, "6-Qt multi-cooker: pressure, slow, rice, steam"},
    };
}
