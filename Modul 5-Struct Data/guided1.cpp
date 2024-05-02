#include <iostream>
using namespace std;

struct Buku {
    string judul_buku;
    string pengarang;
    string penerbit;
    int tebal_buku;
    float harga_buku;
};

int main(){

    //Membuat dan mengisi
    Buku buku1;
    buku1.judul_buku = "Algoritma dan Struktur Data";
    buku1.pengarang = "Yunus Prademon";
    buku1.penerbit = "Gramedia Pustaka Utama";
    buku1.tebal_buku = 500;
    buku1.harga_buku = 250000;

    //Menampilkan data
    cout << "Informasi Buku" << endl;
    cout << "Judul Buku :" << buku1.judul_buku << endl;
    cout << "Pengarang :" << buku1.pengarang << endl;
    cout << "Penerbit :" << buku1.penerbit << endl;
    cout << "Tebal Buku :" << buku1.tebal_buku << endl;
    cout << "Harga Buku :" << buku1.harga_buku << endl;
} 