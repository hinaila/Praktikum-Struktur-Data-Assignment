#include <iostream>

// Definisi class
class Mahasiswa {
public:
    // Variabel anggota (data)
    std::string nama;
    int usia;

    // Metode untuk menampilkan data mahasiswa
    void displayInfo() {
        std::cout << "Nama: " << nama << std::endl;
        std::cout << "Usia: " << usia << std::endl;
    }
};

int main() {
    // Membuat objek dari class Mahasiswa
    Mahasiswa mhs1;

    // Mengatur nilai variabel anggota
    mhs1.nama = "Budi";
    mhs1.usia = 20;

    // Memanggil metode untuk menampilkan informasi
    mhs1.displayInfo();

    return 0;
}

Class adalah cetak biru atau blueprint dari object. Class digunakan hanya untuk membuat kerangka dasar. Yang akan kita pakai nanti adalah hasil cetakan dari class, yakni object. Kata class kunci mendeklarasikan jenis kelas atau menentukan objek dari jenis kelas.
Dalam program diatas, fungsi class digunakan untuk mencetak biru sebuah kata benda seperti 'nama' dan 'usia' dari Mahasiswa.
