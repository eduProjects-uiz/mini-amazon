// ============================================================
//  InformaticsEquipment.cpp  –  Tech / Computing category
// ============================================================
#include "InformaticsEquipment.h"
#include <iostream>

InformaticsEquipment::InformaticsEquipment(int id, const std::string& name,
                                           double price, const std::string& description)
    : Product(id, name, price, description, "Informatics Equipment") {}

void InformaticsEquipment::display() const {
    std::cout << "  💻 ";   // Laptop emoji
    Product::display();
}

std::vector<InformaticsEquipment> InformaticsEquipment::getCatalog() {
    return {
        {201, "Mechanical Keyboard",         79.99, "TKL, Cherry MX Red switches, RGB backlit"},
        {202, "27\" 4K Monitor",            329.99, "IPS panel, 144 Hz, HDR400, USB-C hub"},
        {203, "Wireless Mouse",              39.99, "Ergonomic, 2.4 GHz, 2000 DPI, silent clicks"},
        {204, "USB-C Hub 7-in-1",            34.99, "HDMI 4K, 3x USB-A, SD/MicroSD, 100W PD"},
        {205, "Laptop Stand + Cooling Pad",  27.99, "Aluminium, adjustable, dual 120 mm fans"},
        {206, "1 TB External SSD",           89.99, "USB 3.2 Gen2, 1050 MB/s read, rugged case"},
        {207, "Noise-Cancelling Headset",   119.99, "ANC, 30 h battery, foldable, mic boom"},
        {208, "Webcam Full HD 1080p",        49.99, "60 fps, autofocus, built-in stereo mic"},
        {209, "Smart Wi-Fi Router",          99.99, "Wi-Fi 6, dual-band, mesh compatible, 4 LAN"},
    };
}
