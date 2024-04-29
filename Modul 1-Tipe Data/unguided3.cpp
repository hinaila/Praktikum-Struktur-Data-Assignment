#include <iostream>
#include <map>

int main() {
    // Membuat objek map yang berisi pasangan kunci-nilai (key-value)
    std::map<std::string, int> umur;

    // Menambahkan elemen ke dalam map
    umur["Budi"] = 25;
    umur["Ani"] = 20;
    umur["Cindy"] = 30;

    // Mengakses nilai berdasarkan kunci
    std::cout << "Umur Budi: " << umur["Budi"] << std::endl;
    std::cout << "Umur Ani: " << umur["Ani"] << std::endl;
    std::cout << "Umur Cindy: " << umur["Cindy"] << std::endl;

    return 0;
}