# <h1 align="center">Laporan Praktikum Modul Rekursif & Hash Table</h1>
<p align="center">Hafshoh Imroatun Naila</p>
<p align="center">2311110056</p>

## Dasar Teori
### Rekursif

Secara  algoritmik:  Suatu  cara  untuk  mendesain  solusi dari  masalah  dengan  cara  divide-and-conquer  atau decrease-andconquer  (Mengurangi  masalah  ke  versi  yang lebih sederhana dari masalah yang sama).
Secara semantic: Teknik pemrograman dimana fungsi dapat memanggil dirinya sendiri. 
Fungsi rekursif adalah fungsi yang mengacu pada dirinya sendiri dengan proses pengulangan item-item dengan cara yang mirip.

Jenis-jenis rekursif :
1. Rekursif langsung adalah jenis rekursi di mana suatu fungsi memanggil dirinya sendiri secara langsung dalam blok kodenya sendiri.
2. Rekursif tidak langsung adalah suatu fungsi memanggil fungsi lain yang kemudian memanggil kembali fungsi pertama. Rekursif berakhir ketika kasus dasar terpenuhi, dan pada saat itulah proses berhenti.

Kelebihan fungsi rekursif :
1. Mudah dimengerti
2. Efektif dalam menangani masalah yang dapat diuraikan yang menjadi sub tugas serupa.
3. Solusi rekursif dapat memberikan kode yang lebih elegan dan lebih kompak dibandigkan dengan pendekatan iteratif.

Kekurangan fungsi rekursif :
1. Masalah efisiensi ruang karena setiap panggilan rekursif menambah overhead pada call stack.
2. Kurang efisien waktu
3. Kesulitan dalam pemahaman konsep yang dapat memunculkan potensi bug dan kompleksitas pemecahan masalah.

## Hash Table
Hash Table adalah struktur data yang mengorganisir data ke dalam pasangan kunci-nilai Hash table adalah sebuah cara menyimpan suatu data pada memori ke dalam baris-baris dan kolom-kolom sehingga membentuk tabel yang dapat diakses dengan cepat. 
Operasi hash table yaitu:

<pre>
- Insertion : Memasukkan data baru ke dalam hash table dengan memanggil fungsi hash untuk menentukan posisi bucket yang tepat, dan kemudian menambahkan data ke bucket tersebut.
- Deletion : Menghapus data dari hash table dengan mencari data menggunakan fungsi hash, dan kemudian menghapusnya dari bucket yang sesuai.
- Searching : Mencari data dalam hash table dengan memasukkan input kunci ke fungsi hash untuk menentukan posisi bucket, dan kemudian mencari data di dalam bucket yang sesuai.
- Update : Memperbarui data dalam hash table dengan mencari data menggunakan fungsi hash, dan kemudian memperbarui data yang ditemukan.
- Traversal : Melalui seluruh hash table untuk memproses semua data yang ada dalam tabel.
</pre>


## Guided
### 1. Rekursif Langsung (Direct Recursion)
```C++
#include <iostream>
using namespace std;

// Code ini berfungsi untuk melakukan hitung mundur dari angka yang diinputkan

void countdown(int n) {
    if (n == 0) {
        return;
    }
    cout << n << " ";
    countdown(n - 1);
}

int main() {
    cout << "Rekursif Langsung: ";
    countdown(5); // 5 merupakan input nya
    cout << endl;
    return 0;
}
```

### Output
![Screenshot (1082)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/87c0c193-d544-47a4-8683-f896508fd040)


### 2. Rekursif Tidak Langsung (Indirect Recursion)
```C++
#include <iostream>
using namespace std;

void functionB(int n);

void functionA(int n) {
    if (n > 0) {
        cout << n << " ";
        functionB(n - 1); // Panggilan rekursif tidak langsung
    }
}

void functionB(int n) {
    if (n > 0) {
        cout << n << " ";
        functionA(n / 2); // Panggilan rekursif tidak langsung
    }
}

int main() {
    int num = 5;
    cout << "Rekursif Tidak Langsung: ";
    functionA(num);
    return 0;
}
```
### Output
![Screenshot (1083)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/0b8e6c98-78fe-40ea-9fea-e1474e53c79d)


### 3. Hash Table
```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;
class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
         int hash_val = 0;
         for (char c : key) {
            hash_val += c;
        }
    return hash_val % TABLE_SIZE; // 4 bisa aja 204,12004, 6 bisa aja
266, 300;
    }
    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);

        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
    int hash_val = hashFunc(name);

        for (auto it = table[hash_val].begin(); it !=
table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                 table[hash_val].erase(it);
                 return;
            }
        }
    }
string searchByName(string name) {
int hash_val = hashFunc(name);
for (auto node : table[hash_val]) {
    if (node->name == name) {
        return node->phone_number;
    }
}
return "";
}
void print() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << i << ": ";
            for (auto pair : table[i]) {
            if(pair != nullptr){
                cout << "[" << pair->name << ", " <<
pair->phone_number << "]";
                }           
            }
            cout << endl;
        }
    }
};

int main() {
HashMap employee_map;

employee_map.insert("Mistah", "1234");
employee_map.insert("Pastah", "5678");
employee_map.insert("Ghana", "91011");

cout << "Nomer Hp Mistah : " <<employee_map.searchByName("Mistah") <<
endl;
cout << "Phone Hp Pastah : " <<employee_map.searchByName("Pastah") <<
endl;
cout << "Phone Hp Ghana : " <<employee_map.searchByName("Ghana") <<
endl;

employee_map.remove("Mistah");

cout << "Nomer Hp Mistah setelah dihapus : "
<<employee_map.searchByName("Mistah") << endl << endl;\

cout << "Hash Table : " << endl;
employee_map.print();

return 0;
}
```

### Output
![Screenshot (1084)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/a3a61a7d-788a-48ba-b79c-3ee61b8027f0)


## Unguided
### 1. Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!
```C++
#include <iostream>
using namespace std;

int faktorial(int n) {
    if (n == 1)
        return 1;
    else
        return n * faktorial(n - 1);
}

int main() {
    int bilangan;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> bilangan;

    if (bilangan < 0) {
        cout << "Masukkan bilangan bulat positif!" << endl;
    } else {
        int hasil = faktorial(bilangan);
        cout << "Faktorial dari " << bilangan << " adalah: " << hasil << endl;
    }

    return 0;
}
```
#### Output:
![Screenshot (1085)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/02df8ea4-921f-4f9b-a285-1b7a3204e7ab)

Program diatas merupakan program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif. Kode ini menggunakan fungsi hitungFactorial yang menerima inputan angka dan menghitung faktorialnya secara rekursif. Fungsi ini memanggil dirinya sendiri dengan mengurangi nilai input sebanyak satu setiap kali hingga mencapai angka 1.

<pre>
a. Jika n sama dengan 0, maka fungsi akan mengembalikan nilai 1. Karena faktorial dari 0 adalah 1 (0! = 1).
b. Jika n tidak sama dengan 0, maka fungsi akan melakukan operasi rekursif dengan rumus n! = n * (n-1)!. Artinya, fungsi factorial akan memanggil dirinya sendiri dengan argumen (n-1) dan mengalikan hasilnya dengan n.
</pre>


### 2. Buatlah versi program Rekursif Tidak Langsung (Indirect Recursion) dari soal nomor 1 di atas!
```C++
#include <iostream>

using namespace std;

// Deklarasi fungsi
int fungsiA(int n);
int fungsiB(int n);

// Fungsi A memanggil Fungsi B
int fungsiA(int n) {
    // Basis kasus: jika n adalah 0 atau 1, faktorialnya adalah 1
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * fungsiB(n - 1);
    }
}

// Fungsi B memanggil Fungsi A
int fungsiB(int n) {
    return fungsiA(n);
}

int main() {
    int bilangan;

    // Meminta input dari pengguna
    cout << "Masukkan bilangan bulat positif: ";
    cin >> bilangan;

    // Memastikan input adalah bilangan bulat positif
    if (bilangan < 0) {
        cout << "Input tidak valid. Masukkan bilangan bulat positif." << endl;
    } else {
        // Menghitung faktorial menggunakan fungsi rekursif tidak langsung
        int hasil = fungsiA(bilangan);
        cout << "Faktorial dari " << bilangan << " adalah: " << hasil << endl;
    }

    return 0;
}
```

#### Output
![Screenshot (1086)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/1afffd83-b180-475c-815d-3bff823f181b)

Program diatas merupakan program yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif menggunakan Rekursif Tidak Langsung (Indirect Recursion). Kode ini menggunakan fungsi hitungFactorial yang menerima inputan angka dan menghitung faktorialnya secara rekursif. Fungsi ini memanggil dirinya sendiri dengan mengurangi nilai input sebanyak satu setiap kali hingga mencapai angka 1.


### 3. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan : a. Setiap mahasiswa memiliki NIM dan nilai. b. Program memiliki tampilan pilihan menu berisi poin C. c. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).
```C++
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int TABLE_SIZE = 11;

// Struktur untuk menyimpan data mahasiswa
struct Mahasiswa {
    string nim;
    string nama;
    double nilai;
    Mahasiswa(string nim, string nama, double nilai) : nim(nim), nama(nama), nilai(nilai) {}
};

class HashMap {
private:
    vector<Mahasiswa*> table[TABLE_SIZE];

    // Fungsi hash untuk menghasilkan indeks dari sebuah NIM
    int hashFunc(string nim) {
        int hash_val = 0;
        for (size_t i = 0; i < nim.length(); ++i) {
            hash_val += nim[i];
        }
        return hash_val % TABLE_SIZE;
    }

public:
    // menambahkan data mahasiswa baru
    void insertData(string nim, string nama, double nilai) {
        int index = hashFunc(nim);
        table[index].push_back(new Mahasiswa(nim, nama, nilai));
    }

    // menghapus data mahasiswa berdasarkan NIM
    void removeData(string nim) {
        int index = hashFunc(nim);
        for (size_t i = 0; i < table[index].size(); ++i) {
            if (table[index][i]->nim == nim) {
                delete table[index][i];
                table[index].erase(table[index].begin() + i);
                return;
            }
        }
        cout << "Mahasiswa dengan NIM '" << nim << "' tidak ditemukan." << endl;
    }

    // mencari data mahasiswa berdasarkan NIM
    void searchByNIM(string nim) {
        int index = hashFunc(nim);
        for (size_t i = 0; i < table[index].size(); ++i) {
            if (table[index][i]->nim == nim) {
                cout << "Mahasiswa dengan NIM '" << nim << "' ditemukan. Nama: " << table[index][i]->nama << ", Nilai: " << table[index][i]->nilai << endl;
                return;
            }
        }
        cout << "Mahasiswa dengan NIM '" << nim << "' tidak ditemukan." << endl;
    }

    // mencari data mahasiswa berdasarkan rentang nilai
    void searchByRange(double minNilai, double maxNilai) {
        bool found = false;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            for (size_t j = 0; j < table[i].size(); ++j) {
                if (table[i][j]->nilai >= minNilai && table[i][j]->nilai <= maxNilai) {
                    found = true;
                    cout << "NIM: " << table[i][j]->nim << ", Nama: " << table[i][j]->nama << ", Nilai: " << table[i][j]->nilai << endl;
                }
            }
        }
        if (!found) {
            cout << "Mahasiswa dengan nilai antara " << minNilai << " dan " << maxNilai << " tidak ditemukan." << endl;
        }
    }

    // Destructor untuk membersihkan memori
    ~HashMap() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            for (size_t j = 0; j < table[i].size(); ++j) {
                delete table[i][j];
            }
        }
    }
};
// main programm
int main() {
    HashMap mahasiswa_map;
    int choice;
    string nim, nama;
    double nilai;

    do {
        cout << "Program Untuk Menyimpan Data Mahasiswa Menggunakan Hash Table" << endl;
        cout << "===============================================================" << endl; 
        cout << "\nMenu:\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Hapus Data Mahasiswa\n";
        cout << "3. Cari Mahasiswa Berdasarkan NIM\n";
        cout << "4. Cari Mahasiswa Berdasarkan Rentang Nilai (80 - 90)\n";
        cout << "5. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1: // input data mahasiswa
                cout << "Masukkan NIM Mahasiswa: ";
                cin >> nim;
                cout << "Masukkan Nama Mahasiswa: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan Nilai Mahasiswa: ";
                cin >> nilai;
                mahasiswa_map.insertData(nim, nama, nilai);
                break;
            case 2: // menghapus data mahasiswa
                cout << "Masukkan NIM Mahasiswa yang akan dihapus: "; // menggunakan NIM
                cin >> nim;
                mahasiswa_map.removeData(nim);
                break;
            case 3: // mencari data mahasiswa menggunakan NIM
                cout << "Masukkan NIM Mahasiswa yang ingin dicari: ";
                cin >> nim;
                mahasiswa_map.searchByNIM(nim);
                break;
            case 4: // mencaru data mahasiswa dengan rentang nilai 80-90
                mahasiswa_map.searchByRange(80.0, 90.0);
                break;
            case 5: // keluar dari menu
                cout << "Terimakasih!\n";
                break;
            default: // error message jika input angka yang salah
                cout << "Pilihan tidak valid. Masukkan pilihan yang benar.\n";
                break;
        }
    } while (choice != 5);
    
    return 0;
} 
```
#### Output
![Screenshot (1087)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/454c1058-9293-49db-9527-ea5f460ae3f6)
![Screenshot (1088)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/d92f9157-db2e-45db-b5f9-d18040483eea)
![Screenshot (1089)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/dd30327c-3ef0-4cc3-a096-7ed8843b45ff)
![Screenshot (1090)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/0e5d15be-2aa6-42e6-8b9a-d839c67574c3)

### Penjelasan
Program diatas merupakan program implementasi hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Fungsi insert, remove, dan searchByNilai digunakan untuk menambahkan data baru mahasiswa, menghapus data mahasiswa, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai.


## Kesimpulan
Fungsi rekursif adalah fungsi yang mengacu pada dirinya sendiri dengan proses pengulangan item-item dengan cara yang mirip.

Jenis-jenis rekursif :
1. Rekursif langsung adalah jenis rekursi di mana suatu fungsi memanggil dirinya sendiri secara langsung dalam blok kodenya sendiri.
2. Rekursif tidak langsung adalah suatu fungsi memanggil fungsi lain yang kemudian memanggil kembali fungsi pertama. Rekursif berakhir ketika kasus dasar terpenuhi, dan pada saat itulah proses berhenti.

Hash Table adalah struktur data yang mengorganisir data ke dalam pasangan kunci-nilai Hash table adalah sebuah cara menyimpan suatu data pada memori ke dalam baris-baris dan kolom-kolom sehingga membentuk tabel yang dapat diakses dengan cepat.

Rekursif dan Hash Table adalah konsep penting dalam pemrograman yang digunakan untuk menyelesaikan masalah secara efisien dan efektif. Rekursif berguna untuk memecah masalah menjadi bagian-bagian yang lebih sederhana, rekursif merupakan salah satu proses pengulangan fungsi yang memanggil dirinya sendiri dan pemanggilannya dapat terjadi berulang kali. Sementara hash table memungkinkan penyimpanan dan pengaksesan data dengan cepat. Hash table biasanya terdiri dari dua komponen utama yaitu array (atau vektor) dan fungsi hash.


## Referensi
S. Herlambang, 2008, Implementasi Fungsi Rekursif Dalam Algoritma dan Perbandingannya dengan Fungsi Iteratif.
