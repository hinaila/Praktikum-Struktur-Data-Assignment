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
