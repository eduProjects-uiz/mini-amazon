# ============================================================
#  Makefile  –  Amazon-like E-Commerce Store (C++17)
# ============================================================

CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -I include
TARGET   := store
SRC      := main.cpp \
            src/Product.cpp \
            src/KitchenEquipment.cpp \
            src/InformaticsEquipment.cpp \
            src/Clothes.cpp \
            src/Others.cpp \
            src/Cart.cpp \
            src/Store.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean
