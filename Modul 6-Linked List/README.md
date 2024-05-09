# <h1 align="center">Laporan Praktikum Modul Linked List</h1>
<p align="center">Hafshoh Imroatun Naila</p>
<p align="center">2311110056</p>

## Dasar Teori

Linked list dikenal juga dengan sebutan senarai berantai adalah stuktur data yang terdiri dari urutan record data dimana setiap record memiliki field yang menyimpan alamat/referensi dari record selanjutnya (dalam urutan). Masing-masing komponen sering disebut dengan simpul atau node atau verteks. Setiap simpul pada dasarnya dibagi atas  dua bagian pertama disebut bagian isi atau informasi atau data yang berisi nilai yang disimpan oleh simpul. Bagian kedua disebut bagian pointer yang berisi alamat dari node berikutnya atau sebelumnya. 
Linked list dibagi menjadi 2 yaitu :

1) Single Linked List
   Merupakan suatu bentuk struktur data yang berisi kumpulan data, biasanya disebut node yang tersusun secara sambung menyambung, sekuensial, dinamis, dan terbatas. Setiap elemen dalam linked list dihubungkan ke elemen lain melalui pointer (alamat elemen). Masing-masing komponen sering disebut dengan simpul atau node atau verteks. Setiap simpul pada dasarnya dibagi atas  dua bagian pertama disebut bagian isi atau informasi atau data yang berisi nilai yang disimpan oleh simpul. Bagian kedua disebut bagian pointer yang berisi alamat dari node berikutnya atau sebelumnya.  Dengan struktur seperti ini, linked list dibentuk dengan cara menunjuk pointer next suatu elemen ke elemen yang mengikutinya. Pointer next pada elemen terakhir merupakan NULL, yang menunjukkan akhir dari suatu list. Elemen pada awal suatu list disebut 'head' dan elemen terakhir dari suatu list disebut 'tail'.


2) Double Linked List
   Merupakan struktur data Linked List yang mirip dengan Single Linked List, namun dengan tambahan satu pointer tambahan pada setiap simpul yaitu pointer prev yang menunjuk ke simpul sebelumnya. Setiap simpul pada Double Linked List memiliki tiga elemen penting, yaitu elemen data (biasanya berupa nilai), pointer next yang menunjuk ke simpul berikutnya, dan pointer prev yang menunjuk ke simpul sebelumnya. Double Linked List memerlukan memori yang lebih besar. Keuntungan dari Double Linked List adalah memungkinkan untuk melakukan operasi penghapusan dan penambahan pada simpul dimana saja dengan efisien, sehingga sangat berguna dalam implementasi beberapa algoritma yang membutuhkan operasi tersebut. Selain itu, Double Linked List juga memungkinkan kita untuk melakukan traversal pada list baik dari depan 'head' maupun dari belakang 'tail' dengan mudah. 


## Guided 

### 1. Single Linked List

```C++
#include <iostream>
using namespace std;

///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node{
    //komponen/member
    int data;
    Node *next;
};
    Node *head;
    Node *tail;
//Inisialisasi Node
void init(){
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty(){
    if (head == NULL)
    return true;
    else
    return false;
}
//Tambah Depan
void insertDepan(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
        baru->next = head;
        head = baru;
    }
}
//Tambah Belakang
void insertBelakang(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
    tail->next = baru;
    tail = baru;
    }
}
//Hitung Jumlah List
int hitungList(){
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while( hitung != NULL ){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
//Tambah Tengah
void insertTengah(int data, int posisi){
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
            bantu = head;
            int nomor = 1;
        while( nomor < posisi - 1 ){
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
//Hapus Depan
void hapusDepan() {
    Node *hapus;
    if (isEmpty() == false){
        if (head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Belakang
void hapusBelakang() {
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false){
        if (head != tail){
            hapus = tail;
            bantu = head;
            while (bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Tengah
void hapusTengah(int posisi){
    Node *hapus, *bantu, *bantu2;
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        int nomor = 1;
        bantu = head;
        while( nomor <= posisi ){
            if( nomor == posisi-1 ){
                bantu2 = bantu;
            }
            if( nomor == posisi ){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
    delete hapus;
    }
}
//Ubah Depan
void ubahDepan(int data){
    if (isEmpty() == false){
        head->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Tengah
void ubahTengah(int data, int posisi){
    Node *bantu;
    if (isEmpty() == false){
        if( posisi < 1 || posisi > hitungList() ){
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if( posisi == 1){
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else{
            bantu = head;
            int nomor = 1;
            while (nomor < posisi){
                bantu = bantu->next;nomor++;
            }
            bantu->data = data;
        }
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Belakang
void ubahBelakang(int data){
    if (isEmpty() == false){
        tail->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Hapus List
void clearList(){
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
//Tampilkan List
void tampil(){
    Node *bantu;
    bantu = head;
    if (isEmpty() == false){
        while (bantu != NULL){
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
int main(){
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7,2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();

    insertTengah(7,1);
    tampil();
    return 0;
}
```


![Screenshot (783)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/a0d4c9f0-7e5e-421b-a86b-8788a49f29e4)


### 2. Double Linked List

```C++
#include <iostream>
using namespace std;

class Node {
    public:int data;
    Node* prev;
    Node* next;
};
class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } 
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } 
        else {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```


![Screenshot (784)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/525006c7-b2dd-4fc9-a8d0-cc062c97ec2a)

![Screenshot (785)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/022efb43-0f46-4223-acb0-85bb941778ad)


## Unguided 

### 1. Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:

a. Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda.
![Screenshot (787)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/e79dabf0-718c-4868-b024-fdb698a31189)

b. Hapus data Akechi

c. Tambahkan data berikut diantara John dan Jane : Futaba 18

d. Tambahkan data berikut diawal : Igor 20

e. Ubah data Michael menjadi : Reyn 18

f. Tampilkan seluruh data

```C++
#include <iostream>
#include <string>
using namespace std;

// Struktur node untuk menyimpan data mahasiswa
struct Node {
    string nama;
    int usia;
    Node* next;
};

// Class untuk mengelola linked list
class LinkedList {
private:
    Node* head;

public:
    // Konstruktor
    LinkedList() {
        head = nullptr;
    }

    // Fungsi untuk menambahkan data di depan linked list
    void tambahDepan(string nama, int usia) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = head;
        head = newNode;
    }

    // Fungsi untuk menambahkan data di belakang linked list
    void tambahBelakang(string nama, int usia) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Fungsi untuk menambahkan data di tengah linked list
    void tambahTengah(string nama, int usia, string namaSebelumnya) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->nama == namaSebelumnya) {
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
        cout << "Data " << namaSebelumnya << " tidak ditemukan" << endl;
    }

    // Fungsi untuk menghapus data dari linked list
    void hapus(string nama) {
        Node* temp = head;
        Node* prev = nullptr;
        while (temp != nullptr && temp->nama != nama) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Data tidak ditemukan" << endl;
            return;
        }
        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
    }

    // Fungsi untuk mengubah data dalam linked list
    void ubah(string nama, int usiaBaru) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->nama == nama) {
                temp->usia = usiaBaru;
                return;
            }
            temp = temp->next;
        }
        cout << "Data tidak ditemukan" << endl;
    }

    // Fungsi untuk menampilkan seluruh data dalam linked list
    void tampilkan() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->nama << "\t" << temp->usia << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;
    // Menambahkan data sesuai dengan urutan yang diminta
    list.tambahDepan("John", 19);
    list.tambahBelakang("Jane", 20);
    list.tambahBelakang("Michael", 18);
    list.tambahBelakang("Yusuke", 19);
    list.tambahBelakang("Akechi", 20);
    list.tambahBelakang("Hoshino", 18);
    list.tambahBelakang("Karin", 18);

    // Menjalankan operasi yang diminta
    list.hapus("Akechi");
    list.tambahTengah("Futaba", 18, "John");
    list.tambahDepan("Igor", 20);
    list.ubah("Michael", 18);

    // Menampilkan seluruh data
    cout << "Data Mahasiswa:" << endl;
    list.tampilkan();

    return 0;
}
```


#### Output:
![Screenshot (788)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/e8a1159a-cd1d-4f88-8b14-876306317cd1)


### 2. Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.
![Screenshot (789)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/12bf330e-2e66-4d55-a1a8-be17d9bba30c)


Case:
1. Tambahkan produk Azarine dengan harga 65.000 diantara 
Somethinc dan Skintific
2. Hapus produk wardah
3. Update produk Hanasui menjadi Cleora dengan harga 55.000
4. Tampilkan menu seperti dibawah ini

Toko Skincare Purwokerto
1. Tambah Data
2. Hapus Data
3. Update Data
4. Tambah Data Urutan Tertentu
5. Hapus Data Urutan Tertentu
6. Hapus Seluruh Data
7. Tampilkan Data
8. Exit
Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah 
ini :
![Screenshot (790)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/b85ca566-a6e0-4d7a-9db5-99b8094b6ee8)


```C++
#include <iostream>
#include <string>

using namespace std;

// Deklarasi class Node
class Node {
public:
    string nama_produk;
    double harga;
    Node* prev;
    Node* next;

    Node(string nama, double hrg) {
        nama_produk = nama;
        harga = hrg;
        prev = nullptr;
        next = nullptr;
    }
};

// Deklarasi class GuidedDoubleLinkedList
class GuidedDoubleLinkedList {
private:
    Node* head;
    Node* tail;

public:
    GuidedDoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Method untuk menambah data di tengah
    void tambah_data_di_tengah(string nama_produk, double harga, int posisi) {
        Node* current = head;
        Node* new_node = new Node(nama_produk, harga);
        int count = 1;

        while (current != nullptr && count != posisi) {
            current = current->next;
            count++;
        }

        if (current == nullptr) {
            cout << "Posisi tidak valid" << endl;
            return;
        }

        new_node->next = current->next;
        new_node->prev = current;
        if (current->next != nullptr) {
            current->next->prev = new_node;
        } else {
            tail = new_node;
        }
        current->next = new_node;
    }

    // Method untuk menghapus data
    void hapus_data(string nama_produk) {
        Node* current = head;

        while (current != nullptr) {
            if (current->nama_produk == nama_produk) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }

                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }

                delete current;
                return;
            }
            current = current->next;
        }

        cout << "Data tidak ditemukan" << endl;
    }

    // Method untuk update data
    void update_data(string nama_produk, double harga_baru) {
        Node* current = head;

        while (current != nullptr) {
            if (current->nama_produk == nama_produk) {
                current->harga = harga_baru;
                return;
            }
            current = current->next;
        }

        cout << "Data tidak ditemukan" << endl;
    }

    // Method untuk menampilkan data
    void tampilkan_data() {
        Node* current = head;

        cout << "Nama Produk\tHarga" << endl;
        while (current != nullptr) {
            cout << current->nama_produk << "\t\t" << current->harga << endl;
            current = current->next;
        }
    }

    // Method untuk menambah data di akhir
    void tambah_data_di_akhir(string nama_produk, double harga) {
        Node* new_node = new Node(nama_produk, harga);

        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }
};

int main() {
    GuidedDoubleLinkedList skincare_list;

    // Inisialisasi data awal
    skincare_list.tambah_data_di_akhir("Originote", 60000);
    skincare_list.tambah_data_di_akhir("Somethinc", 150000);
    skincare_list.tambah_data_di_akhir("Skintific", 100000);
    skincare_list.tambah_data_di_akhir("Wardah", 50000);
    skincare_list.tambah_data_di_akhir("Hanasui", 30000);

    // Operasi sesuai dengan case
    skincare_list.tambah_data_di_tengah("Azarine", 65000, 3);
    skincare_list.hapus_data("Wardah");
    skincare_list.update_data("Hanasui", 55000);

    // Tampilkan data akhir
    cout << "Toko Skincare Purwokerto" << endl;
    cout << "1. Tambah Data" << endl;
    cout << "2. Hapus Data" << endl;
    cout << "3. Update Data" << endl;
    cout << "4. Tambah Data Urutan Tertentu" << endl;
    cout << "5. Hapus Data Urutan Tertentu" << endl;
    cout << "6. Hapus Seluruh Data" << endl;
    cout << "7. Tampilkan Data" << endl;
    cout << "8. Exit" << endl;
    cout << endl;
    skincare_list.tampilkan_data();

    return 0;
}
```


#### Output:
![Screenshot (792)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/e85f0815-7cbd-4085-8fc5-432d5c3aa09e)



## Kesimpulan
Linked list adalah strukur data linier berbentuk rantai simpul di mana setiap simpul menyimpan 2 item, yaitu nilai data dan pointer ke simpul elemen berikutnya. Berbeda dengan array, elemen linked list tidak ditempatkan dalam alamat memori yang berdekatan melainkan elemen ditautkan menggunakan pointer.Linked list dikenal juga dengan sebutan senarai berantai adalah stuktur data yang terdiri dari urutan record data dimana setiap record memiliki field yang menyimpan alamat/referensi dari record selanjutnya (dalam urutan). Linked List terbagi menjadi 2 yaitu Single Linked List dan Double Linked List, setiap jenis Linked List tersebut memiliki kelebihan dan kekurangannya masing-masing.
