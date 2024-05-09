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
