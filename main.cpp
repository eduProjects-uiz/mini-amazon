// ============================================================
//  main.cpp  –  Entry point for the Amazon-like e-commerce app
//
//  Build:
//    g++ -std=c++17 -I include \
//        src/Product.cpp src/KitchenEquipment.cpp \
//        src/InformaticsEquipment.cpp src/Clothes.cpp \
//        src/Others.cpp src/Cart.cpp src/Store.cpp \
//        main.cpp -o store
//
//  Run:  ./store
// ============================================================

#include "Store.h"

int main() {
    Store store;
    store.run();
    return 0;
}
