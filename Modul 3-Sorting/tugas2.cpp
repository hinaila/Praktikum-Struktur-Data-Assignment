#include <iostream>
#include <string>

void bubbleSort(std::string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Tukar elemen jika urutan tidak benar
                std::string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    std::string names[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};
    int n = sizeof(names) / sizeof(names[0]);

    std::cout << "Nama-nama sebelum diurutkan: ";
    for (int i = 0; i < n; i++) {
        std::cout << names[i] << " ";
    }
    std::cout << std::endl;

    bubbleSort(names, n);

    std::cout << "Nama-nama setelah diurutkan secara alfabet: ";
    for (int i = 0; i < n; i++) {
        std::cout << names[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
