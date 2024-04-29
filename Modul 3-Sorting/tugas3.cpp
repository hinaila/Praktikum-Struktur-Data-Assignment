#include <iostream>
#include <algorithm>

int main() {
    int n;
    std::cout << "Masukkan jumlah karakter (n): ";
    std::cin >> n;

    char characters[n];
    
    std::cout << "Masukkan " << n << " karakter: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> characters[i];
    }

    // Sorting menaik
    std::sort(characters, characters + n);
    
    // Menampilkan hasil sorting menaik
    std::cout << "Hasil sorting menaik: ";
    for (int i = 0; i < n; ++i) {
        std::cout << characters[i] << " ";
    }
    std::cout << std::endl;

    // Sorting menurun
    std::sort(characters, characters + n, std::greater<char>());
    
    // Menampilkan hasil sorting menurun
    std::cout << "Hasil sorting menurun: ";
    for (int i = 0; i < n; ++i) {
        std::cout << characters[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
