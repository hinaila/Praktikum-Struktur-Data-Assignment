#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(string arr, char x) {
    int low = 0;
    int high = arr.length() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] < x) {
            low = mid + 1;
        } else if (arr[mid] > x) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);
    transform(kalimat.begin(), kalimat.end(), kalimat.begin(), ::tolower); // Ubah menjadi huruf kecil untuk memudahkan pencarian
    sort(kalimat.begin(), kalimat.end()); // Urutkan kalimat

    char huruf;
    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> huruf;
    huruf = tolower(huruf); // Ubah menjadi huruf kecil untuk konsistensi

    int posisi = binarySearch(kalimat, huruf);

    if (posisi != -1) {
        cout << "Huruf '" << huruf << "' ditemukan pada indeks ke-" << posisi << endl;
    } else {
        cout << "Huruf '" << huruf << "' tidak ditemukan dalam kalimat" << endl;
    }

    return 0;
}