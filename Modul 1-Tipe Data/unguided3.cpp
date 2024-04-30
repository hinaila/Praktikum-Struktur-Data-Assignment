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

Fungsi array_map() mengirimkan setiap nilai array ke fungsi buatan pengguna, dan mengembalikan array dengan nilai baru, yang diberikan oleh fungsi buatan pengguna.
Seperti pada program tersebut, kita dapat bebas memasukkan array apa saja ke fungsi dengan mempertimbangkan tipe data tersebut. 
