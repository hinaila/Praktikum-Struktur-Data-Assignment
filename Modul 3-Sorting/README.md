# <h1 align="center">Laporan Praktikum Modul Sorting</h1>
<p align="center">Hafshoh Imroatun Naila</p>
<p align="center">2311110056</p>

## Dasar Teori
Algoritma adalah kumpulan langkah sistematis untuk memperoleh hasil yang diinginkan. Sebelum sebuah algoritma dijalankan, biasanya ada suatu kondisi awal (initial state) yang harus dipenuhi. Kemudian, langkah-langkah ini diproses hingga mencapai suatu kondisi akhir[1].
Algoritma Sorting adalah algoritma untuk meletakkan kumpulan elemen data ke dalam urutan tertentu. Sorting didefinisikan sebagai pengurutan sejumlah data berdasarkan nilai kunci tertentu. Berdasarkan data terurutnya, algoritma sorting dibagi menjadi dua jenis, yaitu:

o  Ascending; pengurutan dari terkecil hingga terbesar. Contoh: a, b, c, d, e.
o  Descending; pengurutan dari nilai terbesar hingga terkecil. Contoh: e, d, c, b, a 

Dalam pertemuan kali ini, kita akan membahas tiga algoritma sorting, yaitu buble sort, selection sort, dan insertion sort.

### 1. BUBLE SORTING
Bubble  Sort adalah  jenis  sorting  yang digunakan untuk  mengurutkan  data dengan cara mengulang  proses, melakukan  perbandingan antara setiap elemen array dan melakukan penggantian posisi jika urutannya sudah benar. Perbandingan setiap elemen dari array ini berlanjut berjalan sampai kondisi yang ditentukan terpenuhi [2].



### 2. SELECTION SORTING
Algoritma selection sort adalah salah satu algoritma pengurutan sederhana yang beroperasi dengan cara memilih elemen terkecil dari daftar dan menukarnya dengan elemen pertama. Kemudian, ia akan  memilih  elemen  terkecil  dari  sisa  daftar  dan  menukarnya  dengan  elemen  kedua,  dan seterusnya, hingga seluruh daftar terurut [2].



### 3. INSERTION SORTING
Algoritma insertion sort disebut-sebut sebagai metode pertengahan. Artinya, metode ini memiliki kecepatan rata-rata antara metode primitif (bubble dan selection) dan modern (merge dan quick). Metode ini, didasarkan pada sebuah kunci yang diambil pada elemen ke-2  pada sebuah larik, lalu menyisipkan elemen tersebut jika kondisi percabangan terpenuhi. Metode penyisipan (insertion) bertujuan untuk menjadikan bagian sisi kiri larik terurutkan sampai dengan seluruh larik berhasil diurutkan [2]


## Guided

### 1. Mengurutkan secara ascending untuk data numerik bertipe double menggunakan Algoritma Bubble Sort

```C++

 #include <iostream>
using namespace std;

void bubble_sort(double arr[], int length){
    bool not_sorted = true;
    int j=0;
    double tmp;

    while (not_sorted){
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++){
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }//end of if
        }//end of for loop
    }//end of while loop
}//end of bubble_sort

void print_array(double a[], int length) {
    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    
    int length = 5;
    double a[] = {22.1, 15.3, 8.2, 33.21, 99,99};
    
    cout << "Urutan bilangan sebelum sorting: " << endl;
    print_array(a, length);
    
    bubble_sort(a, length);
    
    cout << "\nUrutan bilangan setelah sorting: " << endl;
    print_array(a, length);
}
```

### Penjelasan
Program di atas merupakan program untuk mengurutkan data numerik bertipe double dari kecil ke besar (ascending) menggunakan algoritma buble sorting.

Pertama, mengimpor library iostream dan membuat fungsi buble_sort untuk menerima 'arr' bertipe double serta panjang length sebagai argumennya. Variabel 'not_sorted' digunakan sebagai penanda apakah array masih perlu disortir atau tidak. Variabel 'j' digunakan untuk mengurangi jumlah perbandingan pada setiap iterasi loop. Dua loop digunakan: loop 'while' eksternal berjalan selama array belum sepenuhnya tersortir (not_sorted masih true), dan 'loop' for internal untuk membandingkan elemen-elemen berturut-turut. Jika elemen pada posisi i lebih besar dari elemen pada posisi i+1, mereka ditukar. Penanda 'not_sorted' diatur kembali ke true untuk melanjutkan pengurutan. 

Membuat fungsi 'print_array" untuk menerima array 'a' dan panjangnya 'length'. Kemudian diatur dan dipanggil pada fungsi 'main'.

### 2. Mengurutkan karakter secara descending (dari terbesar hingga terkecil) menggunakan Algoritma Insertion Sort

```C++
#include <iostream>
using namespace std;

void insertion_sort(char arr[], int length) {
    int i, j;
    char tmp;
    for (i = 1; i < length; i++) {
        j = i;
        while (j > 0 && arr[j - 1] < arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }//end of while loop
    } //end of for loop
}

void print_array(char a[], int length) {
    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}
int main() {
    int length = 6;
    char a[length] = {'c', 'f', 'a', 'z', 'd', 'p'};
    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, length);
    insertion_sort(a, length);
    cout << "\nUrutan karakter setelah sorting: " << endl;
    print_array(a, length);
}
```

### Penjelasan
Program di atas merupakan program untuk mengurutkan karakter secara descending (terbesar hingga terkecil) menggunakan algoritma insertion sorting.

Pertama, mengimpor library iostream dan lanjut membuat fungsi insertion_sort untuk menerima 'arr' bertipe char dan panjang 'length'. Pada setiap iterasi 'i' dipindahkan ke posisi yang sesuai dalam subarray yang sudah terurut sebelumnya. Perubahan akan terjadi di perulangan 'while' dimana karakter akan diurutkan secara descending. Jika elemen sebelumnya ('arr[j-1]') lebih kecil dari elemen saat ini ('arr[j]'), maka elemen tersebut ditukar. 

Kemudian membuat fungsi 'print_array' untuk menerima array 'a' dan panjangnya 'length'. Serta fungsi 'main' untuk mengatur dan memanggil fungsi-fungsi sebelumnya. 

## Tugas 

### 1. Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerima lembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort! (Score: 30)

```C++
#include <iostream>

void selectionSort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[max_index]) {
                max_index = j;
            }
        }
        // Tukar elemen terbesar dengan elemen ke-i
        float temp = arr[i];
        arr[i] = arr[max_index];
        arr[max_index] = temp;
    }
}

int main() {
    float IPS[] = {3.8, 2.9, 3.3, 4.0, 2.4};
    int n = sizeof(IPS) / sizeof(IPS[0]);

    std::cout << "IPS sebelum diurutkan: ";
    for (int i = 0; i < n; i++) {
        std::cout << IPS[i] << " ";
    }
    std::cout << std::endl;

    selectionSort(IPS, n);

    std::cout << "IPS setelah diurutkan dari yang terbesar ke terkecil: ";
    for (int i = 0; i < n; i++) {
        std::cout << IPS[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```


#### Output:
https://1drv.ms/i/c/1007d1edc4cc5662/ESoh9CcPhiVIkRG-S-saG3sBiG8sBt-pJRBSIqP3MlRGCA?e=xXFRbN

### Penjelasan
Program di atas merupakan program untuk mengurutkan Indeks Prestasi Semester mahasiwa kelas S1 IF 2016 G dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort. 

Program dimulai dengan mendefinisikan fungsi 'selection_sort_descending' yang mengandung parameter 'arr' yang akan diurutkan dan integer 'n' sebagai jumlah elemen dalam array. Di dalam fungsi tersebut, terdapat dua perulangan: 'for' loop pertama digunakan untuk iterasi melalui setiap elemen array, kecuali elemen terakhir. 'for' loop kedua digunakan untuk mencari nilai maksimum di dalam array, dimulai dari indeks setelah elemen saat ini hingga elemen terakhir. Jika nilai elemen yang sedang dicek lebih besar dari nilai elemen maksimum yang sudah ditentukan sebelumnya (arr[current_item] > arr[current_max]), maka nilai current_max diupdate dengan indeks elemen tersebut. Jika nilai maksimum tidak berada pada posisi elemen saat ini (current_max != i), maka nilai elemen pada posisi current_max dan i ditukar.

Terakhir, mendefinisikan fungsi 'main' yang di dalamnya terdapat sebuah array dengan 5 elemen float diinisialisasikan. Kemudian memanggil fungsi 'selection_sort_descending' untuk mengurutkan IPS mahasiswa secara descending.

### 2. Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo, dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan nama-nama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan menggunakan algoritma Bubble Sort! (Score: 30)

```C++
#include <iostream>
#include <string>

void bubbleSort(std::string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Tukar elemen jika urutan tidak benar
                std::string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    std::string names[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};
    int n = sizeof(names) / sizeof(names[0]);

    std::cout << "Nama-nama sebelum diurutkan: ";
    for (int i = 0; i < n; i++) {
        std::cout << names[i] << " ";
    }
    std::cout << std::endl;

    bubbleSort(names, n);

    std::cout << "Nama-nama setelah diurutkan secara alfabet: ";
    for (int i = 0; i < n; i++) {
        std::cout << names[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

#### Output:
https://1drv.ms/i/c/1007d1edc4cc5662/EWNyTgwgKOdHuqwMrGmlEbYBA3vyQzD2FPYs7NnkD4zv3g?e=JUcukv


### Penjelasan
Program diatas merupakan program yang dirancang untuk mengurutkan nama-nama 10 warga sesuai alfabet menggunakan algoritma buble sort.

Program dimulai dengan memanggil library iostream untuk I/O dan library 'string' untuk menggunakan tipe data srting. Selanjutnya, membuat fungsi 'buble_sort' yang mengandung parameter array 'arr' bertipe string dan 'length' bertipe integer. Dalam blok program while, program membandingkan elemen saat ini 'arr[i]' dengan elemen berikutnya 'arr[i + 1]', Jika elemen saat ini lebih besar dari elemen berikutnya maka tukar. 

Lanjut membuat fungsi 'print_array' yang mengandung parameter 'a' untuk menyimpan array dan 'length' untuk panjang array yang nantinya digunakan untuk menampilkan array.

Terakhir, membuat fungsi 'main' untuk memanggil fungsi-fungsi sebelumnya termasuk mengurutkan nama-nama warga sesuai alfabet dengan algoritma buble sort.

### 3. Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending)! (Score: 40)

```C++
#include <iostream>
#include <algorithm>

int main() {
    int n;
    std::cout << "Masukkan jumlah karakter (n): ";
    std::cin >> n;

    char characters[n];
    
    std::cout << "Masukkan " << n << " karakter: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> characters[i];
    }

    // Sorting menaik
    std::sort(characters, characters + n);
    
    // Menampilkan hasil sorting menaik
    std::cout << "Hasil sorting menaik: ";
    for (int i = 0; i < n; ++i) {
        std::cout << characters[i] << " ";
    }
    std::cout << std::endl;

    // Sorting menurun
    std::sort(characters, characters + n, std::greater<char>());
    
    // Menampilkan hasil sorting menurun
    std::cout << "Hasil sorting menurun: ";
    for (int i = 0; i < n; ++i) {
        std::cout << characters[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

#### Output:
https://1drv.ms/i/c/1007d1edc4cc5662/EbHcvDby6hpHmmiTClthWxMB0KKLCcAwHbUowz5yA3SsqA?e=EiHfzW

### Penjelasan
Program diatas merupakan program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending) dengan menggunakan aloritma insertion sort.

Program dimulai dengan memanggil library iostream untuk I/O. Selanjutnya, membuat dua fungsi, yaitu fungsi 'insertion_sort_ascending' untuk mengurutkan array secara ascending (kecil ke besar) dan fungsi 'insertion_sort_descending' untuk mengurutkan array secara descending (besar ke kecil) dengan masing-masing memiliki parameter 'arr' bertipe data char dan 'length' bertipe data integer. 

Kemudian, membuat fungsi 'print_array' untuk menampilkan isi array 'a' dengan panjang 'length'. Dan terakhir, membuat fungsi utama 'main' untuk meminta user memasukkan jumlah karakter, memasukkan karakter-karakter tersebut, memanggil fungsi-fungsi sebelumnya untuk mengurutkan secara ascending maupun descending.

## Kesimpulan
Ada beberapa tipe algoritma sorting yaitu insertion sort yang merupakan algoritma sorting yang bekerja dengan cara membandingkan dan mengurutkan dua data pertama pada array, kemudian membandingkan data para array berikutnya apakah sudah berada di tempat semestinya. Lalu ada selection sort yang bekerja dengan cara mencari nilai tertinggi / terendah di dalam array kemudian menempatkan nilai tersebut di tempat semestinya. Terakhir ada bubble sort yang merupakan metode pengurutan algoritma dengan cara melakukan penukaran data secara terus menerus sampai bisa dipastikan dalam suatu iterasi tertentu tidak ada lagi perubahan/penukaran.

Pada unguided 3 ini kita belajar bagaimana implementasi dari algoritma sorting untuk mengurutkan nilai array secara ascending menggunakan algoritma Selection Sort, mengurutkan nama sesuai abjad menggunakan algoritma bubble sort, dan mengurutkan karakter secara ascending lalu descending menggunakan fungsi inputan.
