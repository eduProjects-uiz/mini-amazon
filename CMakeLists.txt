cmake_minimum_required(VERSION 3.15)
project(ecommerce VERSION 1.0 LANGUAGES CXX)

# Force C++17 standard compliance
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add strict compiler warnings (matching your g++ flags)
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra)
endif()

# Define the source files
set(SOURCE_FILES
    main.cpp
    src/Product.cpp
    src/KitchenEquipment.cpp
    src/InformaticsEquipment.cpp
    src/Clothes.cpp
    src/Others.cpp
    src/Cart.cpp
    src/Store.cpp
)

# Define the executable target
add_executable(store ${SOURCE_FILES})

# Link the header folder ('include') to our executable target
target_include_directories(store PRIVATE include)
