# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Hafshoh Imroatun Naila</p>
<p align="center">2311110056</p>


## Dasar Teori

Tipe data adalah adalah sebuah pengklasifikasian data berdasarkan jenis data
tersebut. Tipe data dibutuhkan agar kompiler dapat mengetahui bagaimana sebuah
data akan digunakan. Terdapat 3 tipe data yang akan dipelajari, yaitu:
1) Tipe data primitif
   Adalah tipe data yang sudah ditentukan oleh sistem, perbedaannya terletak pada jumlah bit yang dialokasikan untuk setiap bit pada tipe data primitif tergantung pada sistem operasinya.
   Contoh tipe data primitif adalah:
   
   a) Int : tipe data yang digunakan untuk menyimpan bilangan bulat seperti 1, 2, 3, 4, 5 dsb
   
   b) Float : tipe data yang digunakan untuk menyimpan bilangan desimal seperti 2.1, 3.2, 4.7, dsb
   
   c) Char : tipe data yng digunakan untuk menyimpan data berupa sebuah huruf atau variabel seperti A, B, C, dsb
   
   d) Boolean : tipe data yang digunkan untuk menyimpan nilai Boolean yang hanya memiliki dua nilai yaitu true, false
   
3) Tipe data Abstrak
   Merupakan tipe data yang dibentuk oleh programer itu sendiri. Pada tipe data abstrak bisa berisi banyak tipe data, jadi nilainya bisa lebih dari satu dan beragam tipe data. Fitur Class adalah fitur Object Oriented Program(OOP) pada bahasa C++ yang mirip dengan fitur data structures Struct pada bahasa C. Keduanya berfungsi untuk membungkus tipe data di dalamnya sebagai anggota. Perbedaan antara Struct dan Class adalah pada akses defaultnya dimana Struct bersifat public dan Class bersifat private. 
   
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
```
#### Output:
![Screenshot (756)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/7fd4c00c-b530-48b3-aef4-42c42695408c)


Program ini mendefinisikan dua fungsi, penjumlahan dan perkalian. Fungsi-fungsi ini menerima dua argumen bertipe int (integer) dan mengembalikan hasilnya yang juga bertipe int. Dalam fungsi main, kita mendefinisikan dua variabel x dan y yang bertipe int, lalu kita memanggil fungsi tambah dan kali dengan x dan y sebagai argumen. Dalam program ini, diambil kesimpulan bahwa tipe data primitif seperti integer sangat dibutuhkan untuk menyimpan dan mengelola suatu data.


### 2.  Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya!

Class dan struct adalah dua fitur penting dalam pemrograman berorientasi objek (OOP) dalam C++. Keduanya digunakan untuk mendefinisikan tipe data baru yang dapat mencakup data dan fungsi.

Class adalah tipe data yang digunakan untuk mendefinisikan objek dengan menyatukan variabel dan fungsi dalam satu unit. Class biasanya digunakan untuk mendefinisikan objek yang lebih kompleks yang memerlukan metode dan properti. Dalam class, anggota data dan fungsi secara default bersifat private.

```C++
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
```

#### Output:
![Screenshot (756)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/df31930c-907c-435b-830e-a696bc13b494)


Struct mirip dengan class, tetapi secara tradisional digunakan untuk mengelompokkan variabel yang terkait erat. Dalam struct, anggota data dan fungsi secara default bersifat public.

```C++
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
```

Dari contoh kedua program class dan struct diatas, kita dapat mengambil kesimpulan bahwa class dan struct dalam C++ sangat penting untuk mendefinisikan tipe data baru yang dapat mencakup data dan fungsi, dan mereka memainkan peran penting dalam pemrograman berorientasi objek.

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map!

```C++
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
```
#### Output:
![Screenshot (758)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/2332ac2b-3833-4093-b6a4-c17ec6007324)


Program ini mendefinisikan sebuah map yang memetakan string ke int.
Perbedaan antara array dan map:

- *Array* adalah kumpulan elemen dengan tipe data yang sama yang diindeks dengan angka. Indeks array dimulai dari 0 dan berlanjut hingga n-1, di mana n adalah jumlah elemen dalam array. Array harus memiliki ukuran tetap yang ditentukan saat inisialisasi.

- *Map* adalah struktur data yang menyimpan pasangan kunci-nilai. Kunci dalam map bisa berupa tipe data apa pun, dan tidak harus berupa angka. Map juga tidak memiliki ukuran tetap.

## Kesimpulan
Tipe data adalah sebuah pengelompokan atau pengklasifikasian data berdasarkan jenis data tersebut. Tipe data adalah kategori yang mendefinisikan jenis nilai yang dapat disimpan dalam variabel atau digunakan dalam ekspresi. Setiap tipe data memiliki ukuran yang berbeda dan aturan operasional yang berbeda pula. Tipe data yang akan dipelajari, yaitu: Tipe data primitif, Tipe data abstrak, dan Tipe data koleksi.
