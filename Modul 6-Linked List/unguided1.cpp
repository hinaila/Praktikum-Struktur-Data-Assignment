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
