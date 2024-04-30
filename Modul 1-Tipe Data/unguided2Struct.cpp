#include <iostream>

// Definisi struct
struct Mahasiswa {
    // Variabel anggota (data)
    std::string nama;
    int usia;
};

int main() {
    // Membuat objek dari struct Mahasiswa
    Mahasiswa mhs1;

    // Mengatur nilai variabel anggota
    mhs1.nama = "Budi";
    mhs1.usia = 20;

    // Menampilkan informasi menggunakan objek struct
    std::cout << "Nama: " << mhs1.nama << std::endl;
    std::cout << "Usia: " << mhs1.usia << std::endl;

    return 0;
}

Struct merupakan perintah yang dapat digunakan untuk membuat struktur dari suatu record.
Pada program diatas, sebuah record yang merepresentasikan tentang mahasiswa memiliki atribut berupa nama yang bertipe string, usia yang bertipe integer.
