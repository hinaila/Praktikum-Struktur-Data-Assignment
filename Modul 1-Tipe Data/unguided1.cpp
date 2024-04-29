#include <iostream>

// Fungsi untuk menjumlahkan dua bilangan bulat
int tambah(int a, int b) {
    return a + b;
}

// Fungsi untuk mengalikan dua bilangan riil
float kali(float a, float b) {
    return a * b;
}

int main() {
    // Memanggil fungsi tambah
    int hasil_tambah = tambah(5, 3);
    std::cout << "Hasil penjumlahan: " << hasil_tambah << std::endl;

    // Memanggil fungsi kali
    float hasil_kali = kali(2.5, 4.0);
    std::cout << "Hasil perkalian: " << hasil_kali << std::endl;

    return 0;
}
