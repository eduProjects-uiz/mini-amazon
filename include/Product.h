#pragma once
#include <string>

// ============================================================
//  Product.h  –  Base class for all products in the store
// ============================================================

class Product {
protected:
    int         id;
    std::string name;
    double      price;
    std::string description;
    std::string category;

public:
    Product(int id, const std::string& name, double price,
            const std::string& description, const std::string& category);
    virtual ~Product() = default;

    // Getters
    int         getId()          const;
    std::string getName()        const;
    double      getPrice()       const;
    std::string getDescription() const;
    std::string getCategory()    const;

    // Display
    virtual void display() const;
};
