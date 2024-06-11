# <h1 align="center">Laporan Praktikum Modul Graph & Tree</h1>
<p align="center">Hafshoh Imratun Naila</p>
<p align="center">2311110056</p>

## Dasar Teori
Grafik dan tree adalah dua struktur data mendasar yang digunakan dalam ilmu komputer untuk merepresentasikan hubungan antar objek. Meskipun keduanya memiliki kesamaan, keduanya juga memiliki perbedaan yang membuatnya cocok untuk aplikasi yang berbeda.
Graf atau graph adalah struktur data yang digunakan untuk merepresentasikan hubungan antara objek dalam bentuk node atau vertex dan sambungan antara node tersebut dalam bentuk sisi atau edge. Graf terdiri dari simpul dan busur yang secara matematis dinyatakan sebagai :

G = (V, E)
G = Graph
V = simpul
E = sisi

Graf digunakan untuk memodelkan berbagai sistem dunia nyata, seperti jaringan sosial , jaringan transportasi , dan jaringan komputer.
Jenis-jenis graph:
1) Graph berarah (directed graph): Urutan simpul mempunyai arti. Misal busur AB adalah e1 sedangkan busur BA adalah e8.
2) Graph tak berarah (undirected graph): Urutan simpul dalam sebuah busur tidak diperhatikan. Misal busur e1 dapat disebut busur AB atau BA.
3) Weight Graph : Graph yang mempunyai nilai pada tiap edgenya.

Tree adalah struktur data yang sangat umum dan kuat yang menyerupai nyata pohon. Struktur data pohon adalah struktur data hierarki yang terdiri dari node-node yang dihubungkan oleh tepian. Setiap node dapat memiliki beberapa node anak, tetapi hanya satu node induk. Node paling atas pada pohon disebut simpul akar. Binary tree atau pohon biner merupakan struktur data pohon akan tetapi setiap simpul dalam pohon diprasyaratkan memiliki simpul satu level di bawahnya (child) tidak lebih dari 2 simpul, artinya jumlah child yang diperbolehkan yakni 0, 1, dan 2. Membuat struktur data binary tree dalam suatu program (berbahasa C++) dapat menggunakan struct yang memiliki 2 buah pointer, seperti halnya double linked list.
1) Create
2) Clear
3) isEmpty
4) Insert
5) Find
6) Update
7) Retrive
8) Delete Sub
9) Characteristic
10) Traverse, terdiri dari 3 metode:Pre-Order (root - kiri - kanan), In-Order (kiri - root - kanan), Post-Order (kiri - kanan - root)
    
## Guided 

### 1. Graph

```C++
#include <iostream>
#include <iomanip>
using namespace std;

string simpul[7] = {"Ciamis",
                    "Bandung",
                    "Bekasi",
                    "Tasikmalaya",
                    "Cianjur",
                    "Purwokerto",
                    "Yogyakarta"};

int busur[7][7] = {
    {0,7,8,0,0,0,0},
    {0,0,5,0,9,15,0},
    {0,5,0,9,5,0,0},
    {0,0,0,2,4,0,8},
    {3,0,0,1,0,0,0},
    {0,0,7,0,0,9,4},
    {0,0,0,0,8,0,0}
};

void tampilGraph() {
    for (int baris = 0; baris < 7; baris++) {
        cout << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris][kolom] != 0)
                cout << " -> " << simpul[kolom] << "(" << busur[baris][kolom] << ")";
        }
        cout << endl;
    }
}

int main () {
    tampilGraph();
    return 0;
}
```

### Output
![Screenshot (1160)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/eb690e0e-e422-48e7-98ac-dc70cc5ffa67)


### 2. Tree

```C++
#include <iostream>
using namespace std;

// Definisii struktur pohon
struct pohon {
    pohon* kanan;
    char data;
    pohon* kiri;
};

//Deklarasi variabel global
pohon* simpul;
pohon* root;
pohon* saatIni;
pohon* helperA;
pohon* helperB;
pohon* alamat[256];

// Fungsi untuk inisialisasi root
void inisialisasi() {
    root = NULL;
}

// Fungsi untuk membuat simoul baru
void simpulBaru(char dataMasukkan) {
    simpul = new pohon;
    simpul->data = dataMasukkan;
    simpul->kanan = NULL;
    simpul->kiri = NULL;
}

// Fungsi untuk membuat simpul akar
void simpulAkar() {
    if (root == NULL) {
        char dataAnda;
        cout << "Silahkan masukkan data:" ;
        cin >> dataAnda;
        simpulBaru(dataAnda);
        root = simpul;
        cout << "Root terbentuk ..." << endl;
    } else {
        cout << "Root sudah ada..." << endl;
    }
}

//Fungsi untuk menambah simpul
void tambahSimpul() {
    if (root != NULL) {
        int i = 1, j = 1, penanda = 0;
        char dataUser;
        alamat[i] = root;

        while (penanda == 0 && j < 256) {
            cout << "Masukkan data kiri: ";
            cin >> dataUser;
            if (dataUser != '0') {
                simpulBaru(dataUser);
                saatIni = alamat[i];
                saatIni->kiri = simpul;
                j++;
                alamat[j] = simpul;
            } else {
                penanda = 1;
                j++;
                alamat[j] = NULL;
            }
            if (penanda == 0) {
                cout << "Masukkan data kanan: ";
                cin >> dataUser;
                if (dataUser != '0') {
                    simpulBaru(dataUser);
                    saatIni = alamat[i];
                    j++;
                    alamat[j] = simpul;
                } else {
                    penanda = 1;
                    j++;
                    alamat[j] = NULL;
                }
            }
            i++;
        }
    }
}

// Fungsi untuk membaca pohon
void bacaPohon() {
    if (root != NULL) {
        int i = 1, n = 1, pencacah = 0;
        cout << endl;
        while (alamat[i] != NULL) {
            saatIni = alamat[i];
            cout << saatIni->data << " ";
            pencacah++;
            if (pencacah == n) {
                cout << endl;
                pencacah = 0;
                n = n * 2;
            }
            i++;
        }
    }
}

//Fungsi utama
int main() {
    inisialisasi();
    simpulAkar();
    tambahSimpul();
    bacaPohon();
    return 0;
}
```
### Output
![Screenshot (1161)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/90d9aca2-66a6-4471-8250-5e39ba88b5d8)


## Unguided 

### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.

```C++
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    int numNodes;
    cout << "Silakan masukan jumlah simpul: ";
    cin >> numNodes;

    vector<string> nodes(numNodes);
    vector<vector<int>> distanceMatrix(numNodes, vector<int>(numNodes));

    // Masukkan nama nodes
    for (int i = 0; i < numNodes; ++i) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> nodes[i];
    }

    // Masukkan jarak antar node
    for (int i = 0; i < numNodes; ++i) {
        for (int j = 0; j < numNodes; ++j) {
            if (i == j) {
                distanceMatrix[i][j] = 0;
            } else {
                cout << "Silakan masukkan bobot antar simpul " << nodes[i] << "-->" << nodes[j] << ": ";
                cin >> distanceMatrix[i][j];
            }
        }
    }

    // Print jarak matriks
    cout << "\n      "; 
    for (const auto& node : nodes) {
        cout << setw(6) << node; 
    }
    cout << endl;

    for (int i = 0; i < numNodes; ++i) {
        cout << setw(6) << nodes[i]; 
        for (int j = 0; j < numNodes; ++j) {
            cout << setw(6) << distanceMatrix[i][j]; 
        }
        cout << endl;
    }

    return 0;
}
```

#### Output:
![Screenshot (1162)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/9ed83fef-0909-46b2-a540-f8d0bec33f84)

### 2.   Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan tampilkan pada pre-order, inorder, dan post order!

```C++
#include <iostream>
using namespace std;

// Definisi struktur pohon
struct pohon {
    pohon* kiri;
    pohon* kanan;
    char data;
};

// Membuat simpul baru
pohon* buatSimpul(char data) {
    pohon* baru = new pohon();
    baru->data = data;
    baru->kiri = baru->kanan = NULL;
    return baru;
}

// Menambahkan simpul ke pohon
pohon* tambahSimpul(pohon* root, char data) {
    if (root == NULL) {
        return buatSimpul(data);
    } else {
        char arah;
        cout << "Tambahkan " << data << " ke kiri (l) atau kanan (r) dari " << root->data << "? (l/r): ";
        cin >> arah;
        if (arah == 'l') {
            root->kiri = tambahSimpul(root->kiri, data);
        } else {
            root->kanan = tambahSimpul(root->kanan, data);
        }
    }
    return root;
}

// Fungsi untuk traversal pre-order
void preOrder(pohon* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

// Fungsi untuk traversal in-order
void inOrder(pohon* root) {
    if (root != NULL) {
        inOrder(root->kiri);
        cout << root->data << " ";
        inOrder(root->kanan);
    }
}

// Fungsi untuk traversal post-order
void postOrder(pohon* root) {
    if (root != NULL) {
        postOrder(root->kiri);
        postOrder(root->kanan);
        cout << root->data << " ";
    }
}

// Fungsi utama
int main() {
    pohon* root = NULL;
    int pilihan;
    char data;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Tambahkan Simpul\n";
        cout << "2. Tampilkan Pre-order\n";
        cout << "3. Tampilkan In-order\n";
        cout << "4. Tampilkan Post-order\n";
        cout << "5. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan karakter yang diinginkan: ";
                cin >> data;
                if (root == NULL) {
                    root = buatSimpul(data);
                } else {
                    tambahSimpul(root, data);
                }
                break;
            case 2:
                cout << "Pre-order: ";
                preOrder(root);
                cout << endl;
                break;
            case 3:
                cout << "In-order: ";
                inOrder(root);
                cout << endl;
                break;
            case 4:
                cout << "Post-order: ";
                postOrder(root);
                cout << endl;
                break;
            case 5:
                return 0;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    }
    return 0;
}
```
#### Output:
![Screenshot (1163)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/c6e5e276-cb18-47e5-8a9a-d997664d1b52)
![Screenshot (1164)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/6b97fda2-bd36-479b-b7e6-e5ed71aa3176)


## Kesimpulan
Graf atau graph adalah struktur data yang digunakan untuk merepresentasikan hubungan antara objek dalam bentuk node dan sambungan antara node tersebut dalam bentuk sisi. Tree atau Pohon adalah struktur data yang sangat umum dan kuat yang menyerupai nyata pohon. 

## Referensi
Sjukani, M. 2007. Struktur Data (Algoritma & Struktur Data 2) dengan C, C++. Jakarta : Penerbit Mitra Wacana Media.
