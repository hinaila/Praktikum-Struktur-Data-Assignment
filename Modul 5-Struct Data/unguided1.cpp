#include <iostream>
using namespace std;

struct Buah {
    string nama_buah;
    string warna_buah;
    string rasa;
    int berat_buah;
    float harga_buah;
};

int main(){

    //Membuat dan mengisi
    Buah buah1 ;
    buah1.nama_buah = "Rambutan";
    buah1.warna_buah = "Merah";
    buah1.rasa = "Manis";
    buah1.berat_buah = 500;
    buah1.harga_buah = 25000;

    //Menampilkan data
    cout << "Informasi Buah" << endl;
    cout << "Nama buah :" << buah1.nama_buah << endl;
    cout << "Warna buah :" << buah1.warna_buah << endl;
    cout << "Rasa :" << buah1.rasa << endl;
    cout << "Berat buah :" << buah1.berat_buah << endl;
    cout << "harga buah :" << buah1.harga_buah << endl;
}