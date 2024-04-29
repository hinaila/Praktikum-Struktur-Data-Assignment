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
