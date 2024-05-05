# <h1 align="center">Laporan Praktikum Modul Struct dan Implementasi</h1>
<p align="center">Hafshoh Imroatun Naila</p>
<p align="center">2311110056</p>

## Dasar Teori
Struct adalah tipe data bentukan yang berisi kumpulan variabel yang ada dalam satu nama yang sama dan terdapat kaitannya satu sama lain. Berbeda dengan array yang hanya berupa kumpulan variabel bertipe data sama, struct bisa memiliki variabel-variabel yang bertipe data sama atau berbeda, struct juga bisa menyimpan variabel yang bertipe data array atau struct itu sendiri [1]. Variabel-variabel yang menjadi anggota struct ini dapat disebut dengan elemen struct. Penggunaan struct dapat memudahkan pemetaan entitas dari sebuah kehidupan yang nyata maupun suatu model dengan penyimpanan dan handling dalam C++ [2].

## Guided 

### 1. Buatlah sebuah struktur dengan nama buku yang berisi judul_buku, pengarang, penerbit, tebal_halaman, harga_buku. Isi dengan nilai kemudian tampilkan.

```C++
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
```
Kode di atas digunakan untuk menngimplementasikan bagaimana struct dapat digunakan untuk menyimpan dan mengisi data dari sebuah buku, kemudian menampilkan informasi buku tersebut berupa judul buku, pengarang, penerbit, tebal halaman, dan harga buku. 

![Screenshot (759)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/63519f24-44ce-46ae-9bc8-3918e3a9b30d)


### 2. Buatlah sebuah struktur dengan skema seperti dibawah, isi dengan nilai kemudian jalankan.

![Screenshot (760)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/8527bdc8-7af9-4451-9d2e-6d22bd459198)

```C++
#include <iostream>
using namespace std;

struct Hewan {
    string nama_hewan;
    string jenis_kelamin;
    string cara_berkembangbiak;
    string alat_pernafasan;
    string tempat_hidup;
    string apakah_karnivora;
}; Hewan info_hewan;

struct Hewan_Darat{
    int jumlah_kaki;
    string apakah_menyusui;
    string suara;
    Hewan info_hewan;
}; Hewan_Darat hewan1;

struct Hewan_Laut{
    string bentuk_sirip;
    string bentuk_pertahanan_diri;
    Hewan info_hewan;
}; Hewan_Laut hewan2;

int main() {
    // Membuat dan mengisi Hewan
    hewan1.info_hewan.nama_hewan = "Singa" ;
    hewan1.info_hewan.jenis_kelamin = "Jantan";
    hewan1.info_hewan.cara_berkembangbiak = "Melahirkan";
    hewan1.info_hewan.alat_pernafasan = "Paru-paru";
    hewan1.info_hewan.tempat_hidup = "Darat";
    hewan1.info_hewan.apakah_karnivora = " Ya";
    hewan1.apakah_menyusui = "Ya";
    hewan1.suara = " arggg";

    hewan2.info_hewan.nama_hewan = "Hiu" ;
    hewan2.info_hewan.jenis_kelamin = "Jantan";
    hewan2.info_hewan.cara_berkembangbiak = "Melahirkan";
    hewan2.info_hewan.alat_pernafasan = "Insang";
    hewan2.info_hewan.tempat_hidup = "Laut";
    hewan2.info_hewan.apakah_karnivora = " Ya";
    hewan2.bentuk_sirip = "Membulat";
    hewan2.bentuk_pertahanan_diri = " Menyerang ";

// Menampilkan informasi Hewan
    cout << " Nama Hewan: " <<hewan1.info_hewan.nama_hewan << endl;
    cout << " Jenis Kelamin: " <<hewan1.info_hewan.jenis_kelamin << endl;
    cout << " Cara Berkembangbiak: " <<hewan1.info_hewan.cara_berkembangbiak<< endl;
    cout << " Alat Pernafasan: " <<hewan1.info_hewan.alat_pernafasan << endl;
    cout << " Tempat Hidup: " <<hewan1.info_hewan.tempat_hidup << endl;
    cout << " Apakah Karnivora: " <<hewan1.info_hewan.apakah_karnivora << endl;
    cout << " Apakah Menyusui " <<hewan1.apakah_menyusui << endl;
    cout << " Suara: " <<hewan1.suara << endl;

    cout << "\n Nama Hewan: " <<hewan2.info_hewan.nama_hewan << endl;
    cout << " Jenis Kelamin: " <<hewan2.info_hewan.jenis_kelamin << endl;
    cout << " Cara Berkembangbiak: " <<hewan2.info_hewan.cara_berkembangbiak<< endl;
    cout << " Alat Pernafasan: " <<hewan2.info_hewan.alat_pernafasan << endl;
    cout << " Tempat Hidup: " <<hewan2.info_hewan.tempat_hidup << endl;
    cout << " Apakah Karnivora: " <<hewan2.info_hewan.apakah_karnivora << endl;
    cout << " Bentuk Sirip " <<hewan2.bentuk_sirip << endl;
    cout << " Bentuk Pertahanan Diri: " <<hewan2.bentuk_pertahanan_diri << endl;

return 0;
}
```
Kode di atas digunakan untuk mengorganisir data-data yang terkait ke dalam satu unit. Dalam kode program di atas mendefinisikan struktur data untuk hewan darat dan hewan laut, kemudian mengisi data dua jenis hewan tersebut dan menampilkan informasinya. 

![Screenshot (761)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/5ede78a3-a912-4093-aeb4-812e313a7cbc)

## Unguided 

### 1. Modifikasi tugas guided pertama, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan.
```C++
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
```
#### Output:
![Screenshot (762)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/94549501-ef1a-4ad6-a706-03c3618c2db0)


Kode di atas digunakan untuk mendefinisikan sebuah struktur bernama buah1 yang berisi array untuk menyimpan informasi tentang buah favorit. Masing-masing lima elemen menampung data dari buah.


### 2. Apa yang terjadi jika deklarasi variabel struct yang dibuat pada tugas guided I, berjenis Array. Bagaimana cara mengisi data dan menampilkannya?

```C++
#include <iostream>
#include <string>

using namespace std;

// Definisi struct dengan anggota berjenis array
struct DataMahasiswa {
    string nama[3];
    int umur[3];
    float ipk[3];
};

int main() {
    // Deklarasi variabel struct yang berjenis array
    DataMahasiswa mahasiswa;

    // Mengisi data ke dalam array
    for (int i = 0; i < 3; ++i) {
        cout << "Masukkan nama mahasiswa ke-" << i+1 << ": ";
        getline(cin, mahasiswa.nama[i]);
        cout << "Masukkan umur mahasiswa ke-" << i+1 << ": ";
        cin >> mahasiswa.umur[i];
        cout << "Masukkan IPK mahasiswa ke-" << i+1 << ": ";
        cin >> mahasiswa.ipk[i];
        cin.ignore(); // Membersihkan buffer keyboard
    }

    // Menampilkan data
    cout << "\nData Mahasiswa:\n";
    for (int i = 0; i < 3; ++i) {
        cout << "Mahasiswa ke-" << i+1 << ":\n";
        cout << "Nama: " << mahasiswa.nama[i] << endl;
        cout << "Umur: " << mahasiswa.umur[i] << endl;
        cout << "IPK: " << mahasiswa.ipk[i] << endl << endl;
    }

    return 0;
}
```

![Screenshot (763)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/6b52b804-9c91-4daa-8595-c7b8938701e1)

Jika deklarasi variabel struct yang dibuat berjenis array, berarti akan memiliki kumpulan mahasiswa, bukan hanya satu. Setiap elemen dalam array akan mewakili satu mahasiswa dengan atribut yang ditentukan. Setiap struct mahasiswa diisi dengan informasi yang relevan, kemudian semua informasi tersebut ditampilkan dengan menggunakan loop for. Untuk itu, dapat dilakukan dengan mendeklarasikan struct dengan nama mahasiswa yang memiliki beberapa field seperti nama mahasiswa, umur, IPK. 


## Kesimpulan
Struct merupakan tipe data bentukan yang memungkinkan kita untuk mengelompokkan variabel-variabel yang berkaitan satu sama lain menjadi satu kesatuan.
Struct mempunyai beberapa manfaat, yaitu memudahkan dan membantu pengorganisasian data yang terkait, sehingga lebih mudah dikelola dan dipahami, meningkatkan efisiensi kode atau mengurangi redundansi kode dan membuat kode lebih ringkas, lalu meningkatkan keterbacaan kode atau membuat kode lebih mudah dibaca dan dimengerti karena data yang terkait dikelompokkan bersama.
