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