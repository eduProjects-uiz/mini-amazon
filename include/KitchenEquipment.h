#pragma once
#include "Product.h"
#include <vector>

// ============================================================
//  KitchenEquipment.h  –  Kitchen category products
// ============================================================

class KitchenEquipment : public Product {
public:
    KitchenEquipment(int id, const std::string& name, double price,
                     const std::string& description);

    void display() const override;

    // Factory: returns all pre-loaded kitchen products
    static std::vector<KitchenEquipment> getCatalog();
};
