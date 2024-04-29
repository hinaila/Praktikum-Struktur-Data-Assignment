#include <iostream>

void selectionSort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[max_index]) {
                max_index = j;
            }
        }
        // Tukar elemen terbesar dengan elemen ke-i
        float temp = arr[i];
        arr[i] = arr[max_index];
        arr[max_index] = temp;
    }
}

int main() {
    float IPS[] = {3.8, 2.9, 3.3, 4.0, 2.4};
    int n = sizeof(IPS) / sizeof(IPS[0]);

    std::cout << "IPS sebelum diurutkan: ";
    for (int i = 0; i < n; i++) {
        std::cout << IPS[i] << " ";
    }
    std::cout << std::endl;

    selectionSort(IPS, n);

    std::cout << "IPS setelah diurutkan dari yang terbesar ke terkecil: ";
    for (int i = 0; i < n; i++) {
        std::cout << IPS[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
