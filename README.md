# Amazon-Like E-Commerce Store — C++ Project

## Project Structure

```
ecommerce/
├── main.cpp                      # Entry point
├── Makefile                      # Build automation
├── include/
│   ├── Product.h                 # Base product class
│   ├── KitchenEquipment.h        # Kitchen category
│   ├── InformaticsEquipment.h    # Tech/IT category
│   ├── Clothes.h                 # Clothing category
│   ├── Others.h                  # Miscellaneous category
│   ├── Cart.h                    # Shopping cart (panier)
│   └── Store.h                   # Store controller / UI
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

### With Make
```bash
make
./store
```

### Manual (g++)
```bash
g++ -std=c++17 -I include \
    src/Product.cpp src/KitchenEquipment.cpp \
    src/InformaticsEquipment.cpp src/Clothes.cpp \
    src/Others.cpp src/Cart.cpp src/Store.cpp \
    main.cpp -o store
./store
```

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

## Product Categories & IDs

| Range | Category |
|-------|----------|
| 101–108 | Kitchen Equipment |
| 201–209 | Informatics Equipment |
| 301–308 | Clothes |
| 401–408 | Others |

## Design Highlights
- **OOP hierarchy**: `Product` (base) → `KitchenEquipment`, `InformaticsEquipment`, `Clothes`, `Others`
- **`shared_ptr`** used in the cart to avoid ownership issues
- **Virtual `display()`** overridden per category with emoji prefix
- **Case-insensitive search** across name and description
- **Quantity management**: adding the same product increments its qty
- **Receipt** includes timestamp, line totals, tax, and grand total
