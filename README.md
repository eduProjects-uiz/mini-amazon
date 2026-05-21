# Amazon-Like E-Commerce Store — C++ Project

## Project Structure

```
ecommerce/
├── CMakeLists.txt
├── main.cpp                      
├── Makefile                      
├── include/
│   ├── Product.h                 
│   ├── KitchenEquipment.h        
│   ├── InformaticsEquipment.h    
│   ├── Clothes.h                 
│   ├── Others.h                  
│   ├── Cart.h                    
│   └── Store.h                   
└── src/
    ├── Product.cpp
    ├── KitchenEquipment.cpp
    ├── InformaticsEquipment.cpp
    ├── Clothes.cpp
    ├── Others.cpp
    ├── Cart.cpp
    └── Store.cpp
```

## Build & Run

mkdir build
cd build
cmake ..
make

## Features

| Option | Feature |
|--------|---------|
| 1 | Display all products across all categories |
| 2 | Browse products by category |
| 3 | Search products by name or keyword |
| 4 | Add a product to the cart (panier) |
| 5 | Remove a product from the cart |
| 6 | View current cart contents with subtotal |
| 7 | Checkout: print itemised bill with 8% tax |
| 0 | Exit |



- **Virtual `display()`** overridden per category with emoji prefix
- **Case-insensitive search** across name and description
- **Quantity management**: adding the same product increments its qty
- **Receipt** includes timestamp, line totals, tax, and grand total
