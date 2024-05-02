#include <iostream>
#include <string>

using namespace std;

// Definisi struct dengan anggota berjenis array
struct DataMahasiswa {
    string nama[3];
    int umur[3];
    float ipk[3];
};

int main() {
    // Deklarasi variabel struct yang berjenis array
    DataMahasiswa mahasiswa;

    // Mengisi data ke dalam array
    for (int i = 0; i < 3; ++i) {
        cout << "Masukkan nama mahasiswa ke-" << i+1 << ": ";
        getline(cin, mahasiswa.nama[i]);
        cout << "Masukkan umur mahasiswa ke-" << i+1 << ": ";
        cin >> mahasiswa.umur[i];
        cout << "Masukkan IPK mahasiswa ke-" << i+1 << ": ";
        cin >> mahasiswa.ipk[i];
        cin.ignore(); // Membersihkan buffer keyboard
    }

    // Menampilkan data
    cout << "\nData Mahasiswa:\n";
    for (int i = 0; i < 3; ++i) {
        cout << "Mahasiswa ke-" << i+1 << ":\n";
        cout << "Nama: " << mahasiswa.nama[i] << endl;
        cout << "Umur: " << mahasiswa.umur[i] << endl;
        cout << "IPK: " << mahasiswa.ipk[i] << endl << endl;
    }

    return 0;
}
