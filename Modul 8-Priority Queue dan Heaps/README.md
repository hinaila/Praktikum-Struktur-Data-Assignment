# <h1 align="center">Laporan Praktikum Modul Priority Queue & Heaps</h1>
<p align="center">Hafshoh Imroatun Naila</p>
<p align="center">2311110056</p>

## Dasar Teori

Priority Queue adalah jenis queue yang mengatur elemen berdasarkan nilai prioritas tambahan. Elemen dengan prioritas lebih tinggi didahulukan saat dikeluarkan dari antrian dibanding elemen dengan prioritas lebih rendah. Jika dua elemen memiliki prioritas yang sama, mereka dikeluarkan berdasarkan urutan masuknya ke dalam antrian (first-in-first-out).

Heap dalam struktur data adalah struktur berbasis pohon biner (binary tree) dengan aturan tertentu. Heap memiliki beberapa ciri khas yang membedakannya dari pohon binary biasa, yaitu:
1) Complete Binary Tree.
   Heap harus berbentuk complete binary tree, di mana setiap levelnya terisi penuh kecuali level paling bawah. Level paling bawah pun harus terisi dari kiri ke kanan.
2) Order Property
   Heap dibagi menjadi 2 jenis yaitu max heap dan min heap:
   1) Max-heap
      Elemen pada node parent selalu lebih besar atau sama dengan elemen pada node anaknya (anak kiri dan kanan). Elemen dengan prioritas tertinggi ada di root (akar) pohon.
   2) Min-heap
      Elemen pada node parent selalu lebih kecil atau sama dengan elemen pada node anaknya. Elemen dengan prioritas tertinggi (nilai minimum) ada di root (akar) pohon.

Heap adalah salah satu cara untuk mengimplementasikan antrian prioritas. Struktur pohon binary dari heap memungkinkan operasi seperti enqueue dan dequeue dilakukan dalam waktu logaritmik (log N), dimana N adalah jumlah elemen dalam antrian. Ini jauh lebih efisien daripada implementasi antrian prioritas menggunakan struktur data lain seperti array linear, yang membutuhkan waktu linear (N) untuk operasi tersebut.


## Guided 

```C++
#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";
    
    std::cout << "Node with maximum priority : " << extractMax() << "\n";
    
    std::cout << "Priority queue after extracting maximum : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";
    
    changePriority(2, 49);
    std::cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    remove(3);
    std::cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    return 0;
}
```

#### Output
![Screenshot (984)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/270dd5ac-a739-4c54-8bad-dc47a4d79f25)


## Unguided 

### 1. Modifikasi guided diatas yang mana heap dikonstruksi secara manual berdasarkan user.

```C++
#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    insert(70);
    insert(45);
    insert(13);
    insert(42);
    insert(31);
    insert(16);
    insert(36);
    insert(14);
    insert(7);

    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";
    
    std::cout << "Node with maximum priority : " << extractMax() << "\n";
    
    std::cout << "Priority queue after extracting maximum : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";
    
    changePriority(2, 49);
    std::cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    remove(3);
    std::cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    return 0;
}
```

#### Output:
![Screenshot (995)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/151a6e26-9101-4e5b-bb98-b603f6cc9587)



## Kesimpulan
Priority Queue atau Heaps adalah jenis queue yang mengatur elemen berdasarkan nilai prioritas. Elemen dengan nilai prioritas lebih tinggi umumnya akan diambil sebelum elemen dengan nilai prioritas lebih rendah. Dalam priority queue, setiap elemen memiliki nilai prioritas yang terkait dengannya.  Jika dua elemen memiliki prioritas yang sama, mereka dikeluarkan berdasarkan urutan masuknya ke dalam antrian (first-in-first-out).
Heap dalam struktur data adalah struktur berbasis pohon biner (binary tree) dengan aturan tertentu dengan kelebihan dalam hal kecepatan operasi yang hanya membutuhkan waktu O(log N), sedangkan mencari elemen minimum/maksimum hanya membutuhkan waktu konstan O(1).

## Referensi
F, L, Tobing, dkk., 2022, Implementasi Algoritma Heapsort dalam Pembelajaran Algoritma Sorting, Jurnal Widya Volume 3 Nomor 2
