# <h1 align="center">Laporan Praktikum Modul Array</h1>
<p align="center">Hafshoh Imroatun Naila</p>
<p align="center">2311110056</p>


## Dasar Teori

Array adalah struktur data yang paling dasar. Berikut ini, ada beberapa jenis array yang akan dipelajari :
1) Array Satu Dimensi
   Adalah tipe variabel yang terdiri dari kumpulan data dengan tipe yang sama yang disusun dalam satu baris atau satu dimensi.
   Contoh tipe array satu dimensi adalah bilangan bulat {1, 2, 3, 4, 5} memiliki 5 elemen dan 4 indeks (indeks dimulai dari 0)
   
2) Array Dua Dimensi
   adalah variable yang terdiri dari kumpulan array satu dimensi dengan tipe yang sama yang disusun dalam baris dan kolom. Dalam array dua dimensi, setiap elemen memiliki dua indeks, yaitu indeks baris dan indeks kolom.
   
3) Array Multidimensi
   memiliki kesamaan dengan array satu dimensi dan dua dimensi, namun memiliki kapasitas memori yang lebih besar. Biasa digunakan untuk array yang memiliki lebih dari dua indeks, seperti array 3 dimensi, array 4 dimensi, array 5 dimensi, dan seterusnya.

4) Array Empat Dimensi
   Meskipun array bisa memiliki hingga 32 dimensi, sangat jarang ada yang lebih dari tiga dimensi.
5) Array Lima Dimensi

## Guided 

### 1. Program Input Array Tiga Dimensi

```C++
#include <iostream>
using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
    // Deklarasi array
    int arr[2][3][3];
    // Input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z <<
"] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
    // Output Array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z <<
"] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // Tampilan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```

### 2. Program Mencari Nilai Maksimal Pada Array

```C++
#include <iostream>
using namespace std;

int main()
{
    int maks, a, i = 1, lokasi;
    cout << "Masukkan panjang array: ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }
    maks = array[0];
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << "berada di Array ke " << lokasi << endl ;
}
```
![Screenshot (777)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/53c24750-0a6d-42ab-8276-a0b0e4282987)


## Unguided 

### 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!
![image](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/06aa6dc4-85f9-42ae-a282-437ed62f40a8)



```C++
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Meminta pengguna untuk memasukkan panjang array
    int panjang_array;
    cout << "Masukkan panjang array: ";
    cin >> panjang_array;

    // Meminta pengguna untuk memasukkan elemen array
    cout << "Masukkan " << panjang_array << " angka untuk array: ";
    vector<int> array(panjang_array);
    for (int i = 0; i < panjang_array; ++i) {
        cin >> array[i];
    }

    // Memisahkan nomor genap dan ganjil
    vector<int> genap, ganjil;
    for (int i = 0; i < panjang_array; ++i) {
        if (array[i] % 2 == 0) {
            genap.push_back(array[i]);
        } else {
            ganjil.push_back(array[i]);
        }
    }

    // Menampilkan hasil
    cout << "Data array :";
    for (int i = 0; i < panjang_array; ++i) {
        cout << " " << array[i];
    }
    cout << endl;

    cout << "Nomor genap :";
    for (int i = 0; i < genap.size(); ++i) {
        cout << " " << genap[i];
    }
    cout << endl;

    cout << "Nomor ganjil :";
    for (int i = 0; i < ganjil.size(); ++i) {
        cout << " " << ganjil[i];
    }
    cout << endl;

    return 0;
}
```


#### Output:
![Screenshot (779)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/857e4c7b-785e-43cc-a051-1be8a844c0bd)


Program ini meminta pengguna untuk input 10 angka seperti pada soal, kemudian program mengklasifikasikan angka-angka tersebut menjadi angka genap dan ganjil.

### 2.  Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

```C++
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int panjang, lebar, tinggi;

    // Meminta pengguna untuk memasukkan panjang, lebar, dan tinggi array tiga dimensi
    cout << "Masukkan panjang array tiga dimensi: ";
    cin >> panjang;
    cout << "Masukkan lebar array tiga dimensi: ";
    cin >> lebar;
    cout << "Masukkan tinggi array tiga dimensi: ";
    cin >> tinggi;

    // Membuat array tiga dimensi berdasarkan panjang, lebar, dan tinggi yang dimasukkan pengguna
    vector<vector<vector<int>>> array3D(panjang, vector<vector<int>>(lebar, vector<int>(tinggi)));

    // Meminta pengguna untuk memasukkan elemen-elemen array tiga dimensi
    cout << "Masukkan elemen array tiga dimensi:" << endl;
    for (int i = 0; i < panjang; ++i) {
        for (int j = 0; j < lebar; ++j) {
            for (int k = 0; k < tinggi; ++k) {
                cout << "Array[" << i << "][" << j << "][" << k << "]: ";
                cin >> array3D[i][j][k];
            }
        }
    }

    // Menampilkan elemen-elemen array tiga dimensi
    cout << "Array tiga dimensi yang dimasukkan:" << endl;
    for (int i = 0; i < panjang; ++i) {
        for (int j = 0; j < lebar; ++j) {
            for (int k = 0; k < tinggi; ++k) {
                cout << "Array[" << i << "][" << j << "][" << k << "]: " << array3D[i][j][k] << endl;
            }
        }
    }

    return 0;
}
```

#### Output:
![Screenshot (780)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/4c92445f-46ee-4d53-b075-6726dba18b94)


Program ini meminta pengguna untuk memasukkan ukuran array tiga dimensi dan elemen-elemennya menggunakan panjang, lebar, dan tinggi. Lalu mencetak elemen-elemen tersebut.

### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!

```C++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int panjang_array;
    cout << "Masukkan panjang array: ";
    cin >> panjang_array;

    // Meminta pengguna untuk memasukkan elemen array
    vector<int> array(panjang_array);
    cout << "Masukkan " << panjang_array << " angka untuk array: ";
    for (int i = 0; i < panjang_array; ++i) {
        cin >> array[i];
    }

    int pilihan;
    do {
        // Menampilkan menu
        cout << "\nMenu:\n";
        cout << "1. Cari nilai maksimum\n";
        cout << "2. Cari nilai minimum\n";
        cout << "3. Cari nilai rata-rata\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                int maksimum = *max_element(array.begin(), array.end());
                cout << "Nilai maksimum dalam array: " << maksimum << endl;
                break;
            }
            case 2: {
                int minimum = *min_element(array.begin(), array.end());
                cout << "Nilai minimum dalam array: " << minimum << endl;
                break;
            }
            case 3: {
                int total = 0;
                for (int i = 0; i < panjang_array; ++i) {
                    total += array[i];
                }
                double rata_rata = static_cast<double>(total) / panjang_array;
                cout << "Nilai rata-rata dari array: " << rata_rata << endl;
                break;
            }
            case 4: {
                cout << "Terima kasih telah menggunakan program ini!\n";
                break;
            }
            default: {
                cout << "Pilihan tidak valid. Silakan pilih 1-4.\n";
                break;
            }
        }
    } while (pilihan != 4);

    return 0;
}
```

![Screenshot (781)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/8d1cc711-3ffe-47a8-bc89-b3862012d4d9)



## Kesimpulan
Array adalah struktur data yang paling dasar. Beberapa jenis array yang akan dipelajari, yaitu: array 1 dimensi, array 2 dimensi, array multidimensi, array 4 dimensi, dan array 5 dimensi.  Meskipun array bisa memiliki hingga 32 dimensi, sangat jarang ada yang lebih dari tiga dimensi.
