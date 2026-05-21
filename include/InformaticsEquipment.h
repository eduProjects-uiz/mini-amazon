#pragma once
#include "Product.h"
#include <vector>

// ============================================================
//  InformaticsEquipment.h  –  Tech / Computing category
// ============================================================

class InformaticsEquipment : public Product {
public:
    InformaticsEquipment(int id, const std::string& name, double price,
                         const std::string& description);

    void display() const override;

    static std::vector<InformaticsEquipment> getCatalog();
};
