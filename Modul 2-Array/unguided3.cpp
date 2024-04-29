#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int panjang_array;
    cout << "Masukkan panjang array: ";
    cin >> panjang_array;

    // Meminta pengguna untuk memasukkan elemen array
    vector<int> array(panjang_array);
    cout << "Masukkan " << panjang_array << " angka untuk array: ";
    for (int i = 0; i < panjang_array; ++i) {
        cin >> array[i];
    }

    int pilihan;
    do {
        // Menampilkan menu
        cout << "\nMenu:\n";
        cout << "1. Cari nilai maksimum\n";
        cout << "2. Cari nilai minimum\n";
        cout << "3. Cari nilai rata-rata\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                int maksimum = *max_element(array.begin(), array.end());
                cout << "Nilai maksimum dalam array: " << maksimum << endl;
                break;
            }
            case 2: {
                int minimum = *min_element(array.begin(), array.end());
                cout << "Nilai minimum dalam array: " << minimum << endl;
                break;
            }
            case 3: {
                int total = 0;
                for (int i = 0; i < panjang_array; ++i) {
                    total += array[i];
                }
                double rata_rata = static_cast<double>(total) / panjang_array;
                cout << "Nilai rata-rata dari array: " << rata_rata << endl;
                break;
            }
            case 4: {
                cout << "Terima kasih telah menggunakan program ini!\n";
                break;
            }
            default: {
                cout << "Pilihan tidak valid. Silakan pilih 1-4.\n";
                break;
            }
        }
    } while (pilihan != 4);

    return 0;
}
