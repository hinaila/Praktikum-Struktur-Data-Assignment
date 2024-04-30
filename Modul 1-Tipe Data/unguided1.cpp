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

Tipe data primitif seperti int digunakan untuk menyimpan nilai bilangan bulat. Penggunaan tipe data primitif dalam program C++ memungkinkan kita untuk melakukan operasi matematika dan pemrosesan data dasar dengan mudah.  Dalam program di atas, kita menggunakan tipe data primitif int untuk merepresentasikan operasi penjumlahan dan perkalian. Dengan menggunakan tipe data primitif yang sesuai, kita dapat mengoptimalkan penggunaan memori dan meningkatkan performa program.
