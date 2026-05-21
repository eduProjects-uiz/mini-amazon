#pragma once
#include "Product.h"
#include <vector>

// ============================================================
//  Clothes.h  –  Clothing & Fashion category
// ============================================================

class Clothes : public Product {
public:
    Clothes(int id, const std::string& name, double price,
            const std::string& description);

    void display() const override;

    static std::vector<Clothes> getCatalog();
};
