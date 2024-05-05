# Praktikum-Struktur-Data-Assignment
# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Hafshoh Imroatun Naila</p>

## Dasar Teori

Tipe data adalah sebuah pengelompokan atau pengklasifikasian data berdasarkan jenis data tersebut. Tipe data yang akan dipelajari, yaitu:
1) Tipe data primitif
   Adalah tipe data yang sudah ditentukan oleh sistem, perbedaannya terletak pada jumlah bit yang dialokasikan untuk setiap bit pada tipe data primitif tergantung pada sistem operasinya.
   Contoh tipe data primitif adalah:
   
   a) Int : 1, 2, 3, 4, dsb
   
   b) Float : 2.1, 3.4, 4.3, dsb
   
   c) Char : A, B, C, dsb
   
   d) Boolean : true, false
   
3) Tipe data Abstrak
   Merupakan tipe data yang dibentuk oleh programer itu sendiri. Pada tipe data abstrak bisa berisi banyak tipe data, jadi nilainya bisa lebih dari satu dan beragam tipe data.
   
4) Tipe data Koleksi 
   Adalah tipe data yang digunakan untuk mengelompokkan dan menyimpan beberapa nilai atau objek secara bersamaan. Tipe data ini dapat menyimpan, mengelola, dan mengakses sejumlah besar data dengan cara yang terstruktur.
   Beberapa tipe data koleksi yang umum digunakan:
   
   a) Array : struktur data statis yang menyimpan elemen-elemen dengan tipe data yang sama.
   
   b) Vector : Standard Template Library (STL) jika di dalam C/C++ memiliki bentuk std::vector.
   
   c) Map : mirip dengan array namun dengan index yang memungkinkan, dapat berupa tipe data selain integer.

## Guided 

### 1. Tipe Data Primitif

```C++
#include <iostream>
using namespace std;
// main program
int main()
{
    char op;
    float num1, num2;
    cout<<"Masukkan Operator: ";
    cin>>op;
    cout<<"\nMasukkan Bilangan ke-1 dan ke-2: ";
    cin>>num1>>num2;

    switch(op)
    {
    case '+':
        cout<< num1+num2;
        break;
    case '-':
        cout<< num1-num2;
    case '*':
        cout<< num1*num2;
    case '/':
        cout<< num1/num2;
    default:
        cout<< "Error! operator is not correct";
    }
return 0;
}
```

### 2. Tipe Data Abstrak

```C++
#include <stdio.h>
#include <string.h>

//Struct
struct Mahasiswa
{
    char name[50];
    char address[100];
    int age;
};
int main()
{
// menggunakan struct
struct Mahasiswa mhs1, mhs2;
//mengisi nilai ke struct
strcpy(mhs1.name, "Dian");
strcpy(mhs1.address, "Mataram");
mhs1.age = 22;
strcpy(mhs2.name, "Bambang");
strcpy(mhs2.address, "Surabaya");
mhs2.age = 23;

// mencetak isi struct
printf("## Mahasiswa 1 ##\n");
printf("Nama: %s\n", mhs1.name);
printf("Alamat: %s\n", mhs1.address);
printf("Umur: %d\n", mhs1.age);
printf("\n");
printf("## Mahasiswa 2 ##\n");
printf("Nama: %s\n", mhs2.name);
printf("Alamat: %s\n", mhs2.address);
printf("Umur: %d\n", mhs2.age);
return 0;
}
```

### 3. Tipe Data Koleksi

```C++
#include <iostream>
#include <array>
using namespace std;

int main() {
    // Deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    // Mencetak array dengan tab
    cout << "Isi array pertama : " << nilai[0] << endl;
    cout << "Isi array kedua   : " << nilai[1] << endl;
    cout << "Isi array ketiga  : " << nilai[2] << endl;
    cout << "Isi array keempat : " << nilai[3] << endl;
    cout << "Isi array kelima  : " << nilai[4] << endl;

    return 0;
}
```

## Unguided 

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
#include<iostream>
using namespace std;

// Fungsi untuk menambahkan dua bilangan
int tambah(int a, int b) {
    return a + b;
}

// Fungsi untuk mengalikan dua bilangan
int kali(int a, int b) {
    return a * b;
}

int main() {
    int x = 5;
    int y = 10;

    cout << "Hasil penjumlahan x dan y adalah: " << tambah(x, y) << endl;
    cout << "Hasil perkalian x dan y adalah: " << kali(x, y) << endl;

    return 0;
}
```
#### Output:
![Screenshot 2024-03-20 085913](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/7d23e55a-7911-4ac0-be7b-39aec8721b58)

Program ini mendefinisikan dua fungsi, tambah dan kali, yang masing-masing melakukan penjumlahan dan perkalian dua bilangan. Fungsi-fungsi ini menerima dua argumen bertipe int (integer) dan mengembalikan hasilnya yang juga bertipe int. Di dalam fungsi main, kita mendefinisikan dua variabel x dan y yang bertipe int, lalu kita memanggil fungsi tambah dan kali dengan x dan y sebagai argumen.

Dari program ini, dapat diambil kesimpulan bahwa tipe data primitif seperti int sangat penting dalam pemrograman karena dapat digunakan untuk menyimpan dan memanipulasi data. 

### 2.  Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya!

```C++
#include<iostream>
using namespace std;

// Mendefinisikan struct
struct Mahasiswa {
    string nama;
    int umur;
    double ipk;
};

// Mendefinisikan class
class Mobil {
private:
    string merk;
    int tahun;
public:
    Mobil(string m, int t) {
        merk = m;
        tahun = t;
    }
    void tampilkan() {
        cout << "Merk mobil : " << merk << ", Tahun: " << tahun << endl;
    }
};

int main() {
    // Membuat objek dari struct
    Mahasiswa mhs1;
    mhs1.nama = "Budi";
    mhs1.umur = 20;
    mhs1.ipk = 3.5;
    cout << "Nama: " << mhs1.nama << ", Umur: " << mhs1.umur << ", IPK: " << mhs1.ipk << endl;

    // Membuat objek dari class
    Mobil mobil1("Toyota", 2010);
    mobil1.tampilkan();

    return 0;
}
```
#### Output:
![Screenshot 2024-03-20 090021](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/e0b89c4a-ab3e-4bf9-90e8-5edce35db24f)

Class dan struct adalah dua fitur penting dalam pemrograman berorientasi objek (OOP) dalam C++. Keduanya digunakan untuk mendefinisikan tipe data baru yang dapat mencakup data dan fungsi.

Class adalah tipe data yang digunakan untuk mendefinisikan objek dengan menyatukan variabel dan fungsi dalam satu unit. Class biasanya digunakan untuk mendefinisikan objek yang lebih kompleks yang memerlukan metode dan properti. Dalam class, anggota data dan fungsi secara default bersifat private.

Struct mirip dengan class, tetapi secara tradisional digunakan untuk mengelompokkan variabel yang terkait erat. Dalam struct, anggota data dan fungsi secara default bersifat public.
Dari program ini, kita dapat mengambil kesimpulan bahwa class dan struct dalam C++ sangat penting untuk mendefinisikan tipe data baru yang dapat mencakup data dan fungsi, dan mereka memainkan peran penting dalam pemrograman berorientasi objek.

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map!

```C++
#include<iostream>
#include<map>
using namespace std;

int main() {
    // Membuat map baru
    map<string, int> umur;

    // Menambahkan pasangan kunci-nilai ke dalam map
    umur["Ali"] = 20;
    umur["Budi"] = 25;
    umur["Citra"] = 22;

    // Mengakses nilai dalam map menggunakan kunci
    cout << "Umur Ali: " << umur["Ali"] << endl;
    cout << "Umur Budi: " << umur["Budi"] << endl;
    cout << "Umur Citra: " << umur["Citra"] << endl;

    return 0;
}
```
#### Output:
![Screenshot 2024-03-20 090102](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/935ed45e-06de-442e-b17d-8ddf840b1ae9)

Program ini mendefinisikan sebuah map yang memetakan string ke int.
Perbedaan antara array dan map:

- *Array* adalah kumpulan elemen dengan tipe data yang sama yang diindeks dengan angka. Indeks array dimulai dari 0 dan berlanjut hingga n-1, di mana n adalah jumlah elemen dalam array. Array harus memiliki ukuran tetap yang ditentukan saat inisialisasi.

- *Map* adalah struktur data yang menyimpan pasangan kunci-nilai. Kunci dalam map bisa berupa tipe data apa pun, dan tidak harus berupa angka. Map juga tidak memiliki ukuran tetap.

## Kesimpulan
Tipe data adalah sebuah pengelompokan atau pengklasifikasian data berdasarkan jenis data tersebut. Tipe data yang akan dipelajari, yaitu: Tipe data primitif, Tipe data abstrak, dan Tipe data koleksi

## Referensi
Karumanchi, N. (2016). Data Structures and algorithms made easy: Concepts, problems, Interview Questions. CareerMonk Publications.

TylerMSFT. (n.d.). Collections (C++/CX). diakses dari https://learn.microsoft.com/en-us/cpp/cppcx/collections-c-cx?view=msvc-170
