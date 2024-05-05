# <h1 align="center">Laporan Praktikum Modul Algoritma Searching</h1>
<p align="center">Hafshoh Imroatun Naila</p>
<p align="center">2311110056</p>

## Dasar Teori
Pencarian (Searching) yaitu proses menemukan suatu nilai tertentu pada kumpulan data. Hasil pencarian adalah salah satu dari tiga keadaan ini:  data  ditemukan,  data  ditemukan  lebih  dari  satu,  atau  data  tidak ditemukan. Algoritma Searching merupakan algoritma yang digunakan untuk mencari lokasi dari sebuah data yang diberikan pada kumpulan data yang ada (database). Setelah  proses  pencarian dilaksanakan, akan diperoleh salah satu dari dua kemungkinan, yaitu data yang dicari ditemukan (successfull) atau tidak ditemukan (unsuccessfull)[1].

### a. Sequential Search
`Sequential Search` adalah sebuah teknik pencarian yang membandingkan setiap elemen data dengan data yang dicari. Metode ini biasanya digunakan untuk data berpola acaka atau belum terurut. Pencarian dilakukan dengan membandingkan sebuah elemen data yang dicari dengan elemen pertama sampai dengan terakhir, dimana data dalam array dibaca satu per satu, jika data yang dicari ditemukan maka pencarian akan dihentikan[2].

Meskipun sederhana, tapi `sequential search` memiliki kinerja yang kurang efisien terutama untuk kumpulan data yang banyak. Hal ini dikarenakan `sequential search` memiliki kompleksitas waktu O(n) dimana n adalah jumlah elemen dalam kumpulan data. Oleh karena itu meskipun cocok untuk kumpulan data kecil dan tidak terurut namun sangat tidak efisien jika digunakan untuk data yang besar.

### 2. Binary Search
`Binary search` adalah algoritma pencarian untuk data yang  terurut. Pencarian dilakukan dengan cara menebak apakah data yang dicari berada ditengah-tengah data, kemudian membandingkan data yang dicari dengan data yang ada ditengah. Jika data yang ditengah sama dengan data yang dicari, maka data ditemukan. Tapi, jika data yang ditengah lebih besar dari data yang dicari, maka dapat dipastikan bahwa data yang  dicari berada disebelah kiri data tengah dan data disebelah kanan  data  tengah  dapat  diabai. Begitu juga sebaliknya[1]. `Binary search` pada metode ini data tidak perlu diurutkan terlebih dahulu karena elemen dalam array akan dicari satu persatu baik dari depan maupun belakang. Algoritma ini hanya bisa digunakan pada data yang elemenya sudah terurut baik secara ascending maupun descending.

## Guided 

### 1. Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data. 

```C++
#include <iostream>
using namespace std;

int main(){
 int n = 10;
 int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
 int cari = 10;
 bool ketemu = false;
 int i;
 // algoritma Sequential Search
 for (i = 0; i < n; i++){
    if(data[i] == cari){
        ketemu = true;
        break;
    }
 }
    cout << "\t Program Sequential Search Sederhana\n" << endl;
    cout << " data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}"<< endl;
 if (ketemu){
    cout << "\n angka "<< cari << " ditemukan pada indeks ke-" << i << endl;
 } else {
    cout << cari << " tidak dapat ditemukan pada data." << endl;
 }
 return 0;
}
```
#### Output :
![Guided 1]![Screenshot (764)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/87bc5478-316a-4b1e-bb69-b9fb82d57312)


Program diatas merupakan implementasi dari sequential search. Variabel `n` menunjukkan jumlah elemen dalam array dan bertipe data integer. `data[n]` adalah array yang memiliki panjang 10 elemen integer yang akan dicari nanti. `cari` adalah variabel yang menyimpan data nilai yang ingin dicari di dalam array. `ketemu` merupakan variabel boolean untuk menandai apakah nilai yang dicari sudah ditemukan atau belum.

Pertama, program akan menggunakan loop `for` unruk melakukan sequential search melalui array `data`. Lalu program akan memeriksa pada setiap iterasi apakah elemen array ke-i sama dengan nilai `cari`. Jika iya maka `ketemu` menjadi `true` dan program akan menyimpan indeks elemen yang ditemukan dalam variabel `i`. Setelah itu program akan mencetak judul "Program Sequential Search Sederhana" dan daftar data yang akan dicari. Jika nilai `cari` ditemukan di dalam array maka program akan mencetak pesan bahwa 'nilai tersebut ditemukan beserta indeksnya'. Jika tidak, maka program akan mencetak pesan 'nilai tersebut tidak dapat ditemukan pada data'. 


### 2. Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search 

```C++
#include <iostream>
#include <iomanip>

using namespace std;

int bil_data[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort() {
    int temp, min, i, j;
    for(i = 0; i < 7; i++) {
        min = i;
        for(j = i + 1; j < 7; j++) {
            if(bil_data[j] < bil_data[min]) {
                min = j;
            }
        }
        temp = bil_data[i];
        bil_data[i] = bil_data[min];
        bil_data[min] = temp;
    }
}

void binary_search() {
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = 6;
    while (b_flag == 0 && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if(bil_data[tengah] == cari) {
            b_flag = 1;
            break;
        } else if(bil_data[tengah] < cari) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }
    if(b_flag == 1) {
        cout << "\n Data ditemukan pada index ke-" << tengah << endl;
    } else {
        cout << "\n Data tidak ditemukan\n";
    }
}

int main() {
    cout << "\t BINARY SEARCH\n";
    cout << "\n Data : ";
    // tampilkan data awal
    for(int x = 0; x < 7; x++) {
        cout << setw(3) << bil_data[x];
    }
    cout << endl;
    cout << "\n Masukkan data yang ingin Anda cari : ";
    cin >> cari;
    cout << "\n Data diurutkan : ";
    // urutkan data dengan selection sort
    selection_sort();
    // tampilkan data setelah diurutkan
    for(int x = 0; x < 7; x++) {
        cout << setw(3) << bil_data[x];
    }
    cout << endl;
    binary_search();
    return 0;
}
```

#### Output :
![Guided 2]![Screenshot (766)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/cfea9bed-6920-40b4-8bb8-0b16bf5149f7)

Kode diatas merupakan sebuah program untuk mencari letak data dalam suatu array menggunakan binary search.

Program akan mendeklarasikan array `bil_data` yang berisi angka-angka yang belum diurutkan bertipe data integer. Variabel `cari` memuat angka inputan yang ingin diketahui posisinya bertipe data integer. Variabel `awal`, `akhir`, `tengah`, `b_flag` juga bertipe data integer. 

Pertama program akan menampilkan data yang yang belum diurutkan, lalu user akan diminta untuk memasukkan nilai yang ingin dicari posisinya. Lalu program akan mengurutkan data terlebih dahulu secara ascending menggunakan algoritma `selection sort` dan menampilkan hasilnya. Lalu melalui fungsi `binary_search` program akan mencari nilai yang disimpan dalam variabel `cari` di dalam array `bil_data` yang sudah diurutkan. Algoritma binary search ini bekerja dengan membagi dua array, lalu di cek apakah nilai yang dicari lebih kecil / lebih besar dari nilai tengah. Jika nilai yang dicari berada di `nilai tengah` maka program akan selesai dan menampilkan hasil pencariannya. Jika tidak, maka pencarian akan dilanjutkan ke setengah bagian yang sesuai berdasarkan nilai yang dicari, jika `cari` < `nilai tengah` maka program akan mencari ke sebelah kiri `nilai tengah`, jika `cari` > `nilai tengah` maka program akan mencari ke sebelah kanan `nilai tengah`. Proses ini berulang sampai nilai yang dicari ditemukan.



## Unguided 

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search! 

```C++
#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(string arr, char x) {
    int low = 0;
    int high = arr.length() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] < x) {
            low = mid + 1;
        } else if (arr[mid] > x) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);
    transform(kalimat.begin(), kalimat.end(), kalimat.begin(), ::tolower); // Ubah menjadi huruf kecil untuk memudahkan pencarian
    sort(kalimat.begin(), kalimat.end()); // Urutkan kalimat

    char huruf;
    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> huruf;
    huruf = tolower(huruf); // Ubah menjadi huruf kecil untuk konsistensi

    int posisi = binarySearch(kalimat, huruf);

    if (posisi != -1) {
        cout << "Huruf '" << huruf << "' ditemukan pada indeks ke-" << posisi << endl;
    } else {
        cout << "Huruf '" << huruf << "' tidak ditemukan dalam kalimat" << endl;
    }

    return 0;
}
```
#### Output:
![Unguided 1]![Screenshot (768)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/ddc01d29-e1c5-44b6-8008-8095e9781ce3)


Program dimulai dengan user memasukkan kalimat menggunakan fungsi `getline()`. Lalu user diminta untuk memasukkan huruf yang ingin dicari di dalam kalimat. Setelah itu melalui fungsi `search_Letter()` akan dicari posisi indeks dari huruf yang dimasukkan pengguna dalam kalimat. Fungsi ini akan melakukan literasi pada setiap karakter dalam `kalimat`. Jika karakter dalam kalimat sama dengan huruf yang dicari, maka posisi indeks karakter tersebut akan ditambahkan ke dalam vektor indeks.

Setelah itu program akan menampilkan posisi indeks huruf dalam kalimat. Tetatpi, jika huruf tidak ditemukan maka akan dicetak "Huruf tidak ditemukan dalam kalimat"


### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat! 

```C++
#include <iostream>
#include <string>
#include <cctype> // Untuk menggunakan fungsi isalpha dan tolower
using namespace std;

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    int jumlah_vokal = 0;
    for (char karakter : kalimat) {
        // Ubah karakter menjadi huruf kecil untuk konsistensi
        karakter = tolower(karakter);
        // Periksa apakah karakter adalah huruf vokal
        if (karakter == 'a' || karakter == 'e' || karakter == 'i' || karakter == 'o' || karakter == 'u') {
            jumlah_vokal++;
        }
    }

    cout << "Jumlah huruf vokal dalam kalimat tersebut adalah: " << jumlah_vokal << endl;

    return 0;
}
```
#### Output:
![Unguided 2]![Screenshot (769)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/7f975eeb-2463-4cf3-865b-2b829633d5b6)

### Interpretasi :
Kode diatas merupukan program untuk mencari dan menghitung huruf vokal dalam suatu kalimat yang dimasukkan oleh user. Jika karakter tersebut adalah huruf vokal maka fungsi akan mengembalikan `true`, jika tidak maka `false`.



### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search! 

```C++
#include <iostream>
using namespace std;

int sequentialSearch(int arr[], int size, int target) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            count++;
        }
    }
    return count;
}

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int size = sizeof(data) / sizeof(data[0]);
    int target = 4;

    int count = sequentialSearch(data, size, target);

    cout << "Banyaknya angka " << target << " dalam data adalah: " << count << endl;

    return 0;
}
```
#### Output:
![Unguided 3]![Screenshot (770)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/9367e588-1975-4ded-82c0-fac1c1edd8b8)

### Interpretasi :
Kode diatas merupakan program untuk menghitung frekuensi angka 4 dalam array. Pertama program akan mendeklarasikan array `data ` yang berisi 10 elemen bertipe integer. Lalu variabel `cari` yang merupakan elemen yang ingin dicari didalam array. Variabel `ketemu` yang bertipe boolean akan menjadi `true` jika elemen yang dicari ditemukan dan akan dihitung jumlah kemunculannya dan `false` jika tidak. Setelah selesai iterasi, program akan mencetak array, nilai yang dicari beserta indeksnya, dan jumlah kemunculan nilai tersebut.


## Kesimpulan
Pada praktikum kali ini, algoritma searching adalah proses untuk menemukan atau mencari nilai tertentu dalam suatu struktur data. Ada dua jenis algoritma pencarian yang umum digunakan:
1. Sequential Search

    Sequential search adalah algoritma pencarian yang paling sederhana. Algoritma ini bekerja dengan cara memeriksa setiap elemen dalam struktur data secara berurutan hingga menemukan elemen yang dicari atau hingga mencapai akhir struktur data. Algoritma ini sederhana dan mudah dipahami, selain itu tidak memerlukan struktur data yang terurut. Namun, algoritma ini lambat untuk struktur data yang besar dan tidak efisien untuk pencarian data yang sering dilakukan.

2. Binary Search

    Binary search adalah algoritma pencarian yang lebih efisien daripada sequential search. Algoritma ini hanya dapat digunakan pada struktur data yang terurut dan bekerja dengan cara membagi struktur data menjadi dua bagian secara berulang hingga menemukan elemen yang dicari. Algoritma ini cepat untuk struktur data yang besar dan efisien untuk pencarian data yang sering dilakukan. Namun, algoritma ini memerlukan struktur data yang terurut dan lebih kompleks daripada sequential search.
