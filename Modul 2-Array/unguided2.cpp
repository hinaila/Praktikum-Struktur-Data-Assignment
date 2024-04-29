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
