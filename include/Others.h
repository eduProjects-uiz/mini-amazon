#pragma once
#include "Product.h"
#include <vector>

// ============================================================
//  Others.h  –  Miscellaneous / General category
// ============================================================

class Others : public Product {
public:
    Others(int id, const std::string& name, double price,
           const std::string& description);

    void display() const override;

    static std::vector<Others> getCatalog();
};
