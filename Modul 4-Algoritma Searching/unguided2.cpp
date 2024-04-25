#include <iostream>
#include <string>
#include <cctype> // Untuk menggunakan fungsi isalpha dan tolower
using namespace std;

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    int jumlah_vokal = 0;
    for (char karakter : kalimat) {
        // Ubah karakter menjadi huruf kecil untuk konsistensi
        karakter = tolower(karakter);
        // Periksa apakah karakter adalah huruf vokal
        if (karakter == 'a' || karakter == 'e' || karakter == 'i' || karakter == 'o' || karakter == 'u') {
            jumlah_vokal++;
        }
    }

    cout << "Jumlah huruf vokal dalam kalimat tersebut adalah: " << jumlah_vokal << endl;

    return 0;
}