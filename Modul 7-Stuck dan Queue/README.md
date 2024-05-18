# <h1 align="center">Laporan Praktikum Modul Stack & Queue</h1>
<p align="center">Hafshoh Imroatun Naila</p>
<p align="center">2311110056</p>

## Dasar Teori

# A. Stack
Stack adalah struktur data yang mengakses data secara LIFO (yang terakhir datang, yang awal diproses). Kelas di Java yang dapat mengimplementasikan stack adalah Stack. Stack merupakan turunan dari Vector, sehingga seluruh operasi dari vector dapat digunakan di Stack.
Operasi pada stack memiliki fungsi dasar, beberapa diantaranya yaitu Push (memasukkan) : Menambahkan elemen ke dalam tumpukan pada posisi paling atas atau ujung, dan Pop (mengeluarkan) : Menghapus elemen dari posisi paling atas atau ujung tumpukan.


# B. Queue
Queue adalah struktur data yang mengakses data secara FIFO (yang awal datang, yang awal diproses). Kelas di Java yang dapat mengimplementasikan queue adalah LinkedList dan PriorityQueue. Queue mirip dengan konsep antrian pada kehidupan sehari-hari, dimana konsumen yang datang lebih dulu akan dilayani terlebih dahulu. Struktur data queue terdiri dari dua pointer yaitu front dan rear. Front/head adalah pointer ke elemen pertama dalam queue dan rear/tail/back adalah pointer ke elemen terakhir dalam queue.
Operasi pada queue memiliki fungsi dasar, beberapa diantaranya yaitu enqueue() : menambahkan data ke dalam queue dan dequeue() : mengeluarkan data dari queue.


Perbedaan antara stack dan queue terdapat pada aturan penambahan dan penghapusan elemen. Pada stack, operasi penambahan dan penghapusan elemen dilakukan di satu ujung. Elemen yang terakhir diinputkan akan berada paling atas sehingga pada operasi penghapusan, elemen teratas tersebut akan dihapus paling awal, sifat demikian dikenal dengan LIFO. Sedangkan pada Queue, operasi tersebut dilakukan ditempat berbeda (melalui salah satu ujung) karena perubahan data selalu mengacu pada Head, maka hanya ada 1 jenis insert maupun delete, sifat demikian dikenal dengan FIFO (First-In First-Out).


## Guided 

### Stack

```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";
    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;
    peekArrayBuku(2);
    popArrayBuku();
    cout << "Banyaknya data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cout << endl;
    cetakArrayBuku();
    cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();

    return 0;
}
```

## Output
![Screenshot (919)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/9186e6bb-883f-4cf7-97dc-76cbae91f640)


### Queue

```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda depan antrian
int back = 0; // Penanda belakang antrian
string queueTeller[5]; // Array untuk menyimpan antrian

bool isFull() { // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue) {
        return true; // =1
    } else {
        return false;
    }
}

bool isEmpty() { // Antrian kosong atau tidak
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { // Menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { // Jika antrian kosong
            queueTeller[0] = data;
            front++;
            back++;
        } else { // Jika antrian ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { // Mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { // Menghitung jumlah antrian
    return back;
}

void clearQueue() { // Menghapus semua antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { // Melihat isi antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```

## Output
![Screenshot (920)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/deedaa8a-da43-48ae-b433-7bcc5171ad45)


## Unguided 

### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkadalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.
![Screenshot (927)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/be65aba0-11dc-460b-98d8-d09d79c44c88)


```C++
#include <iostream>
#include <stack>
#include <cctype> // Untuk menggunakan isalnum()

using namespace std;

// Fungsi untuk menghapus karakter non-alphanumeric dari sebuah string
string removeNonAlphaNumeric(string str) {
    string result = "";
    for (char c : str) {
        if (isalnum(c)) {
            result += tolower(c); // Mengubah ke huruf kecil untuk memperlakukan huruf kapital dan huruf kecil sebagai sama
        }
    }
    return result;
}

// Fungsi untuk menentukan apakah sebuah string adalah palindrom atau tidak
bool isPalindrome(string str) {
    stack<char> charStack;
    int len = str.length();

    // Memasukkan karakter ke dalam stack
    for (int i = 0; i < len; ++i) {
        charStack.push(str[i]);
    }

    // Membandingkan karakter pada string dengan karakter pada stack
    for (int i = 0; i < len; ++i) {
        if (str[i] != charStack.top()) {
            return false; // Tidak palindrom
        }
        charStack.pop();
    }
    return true; // Palindrom
}

int main() {
    string sentence;
    cout << "Masukkan kalimat: ";
    getline(cin, sentence);

    // Menghapus karakter non-alphanumeric dan mengubah huruf menjadi lowercase
    string cleanSentence = removeNonAlphaNumeric(sentence);

    // Memeriksa apakah kalimat adalah palindrom
    if (isPalindrome(cleanSentence)) {
        cout << "Kalimat tersebut adalah palindrom.\n";
    } else {
        cout << "Kalimat tersebut bukan palindrom.\n";
    }

    return 0;
}
```
#### Output:
![Screenshot (921)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/5e48cbc9-1970-4c13-81d9-5265b864c45c)

Cara kerja program ini adalah sebagai berikut:
1. Membaca kalimat yang dimasukkan oleh user.
2. Kemudian, program ini memasukkan setiap karakter dari kalimat tersebut ke dalam stack.
3. Membandingkan setiap karakter dari kalimat tersebut dengan karakter teratas dari stack.
4. Jika karakter tidak sama dengan karakter teratas dari stack, maka program ini akan mengembalikan false, yang berarti kalimat tersebut bukan palindrom.
5. Jika semua karakter dari kalimat tersebut sama dengan karakter teratas dari stack, maka program akan mengembalikan true, yang berarti kalimat tersebut adalah palindrom.

### 2.   Ubah guided queue diatas agar menjadi program inputan user dan program menu.

```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 4; // Maksimal antrian
int front = 0; // Penanda depan antrian
int back = 0; // Penanda belakang antrian
string queueTeller[5]; // Array untuk menyimpan antrian

bool isFull() { // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue) {
        return true; // =1
    } else {
        return false;
    }
}

bool isEmpty() { // Antrian kosong atau tidak
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { // Menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { // Jika antrian kosong
            queueTeller[0] = data;
            front++;
            back++;
        } else { // Jika antrian ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { // Mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { // Menghitung jumlah antrian
    return back;
}

void clearQueue() { // Menghapus semua antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { // Melihat isi antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    int pilihan;
    string data;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah antrian\n";
        cout << "2. Kurangi antrian\n";
        cout << "3. Lihat antrian\n";
        cout << "4. Hapus semua antrian\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama: ";
                cin >> data;
                enqueueAntrian(data);
                break;
            case 2:
                dequeueAntrian();
                break;
            case 3:
                viewQueue();
                break;
            case 4:
                clearQueue();
                break;
            case 5:
                cout << "Terima kasih telah menggunakan program ini.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 5);

    return 0;
}
```

#### Output:
![Screenshot (922)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/62bba7b2-dfd3-4349-9ad8-77a0e65aa04d)

![Screenshot (923)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/a2b07978-7e12-4214-9e3c-0245133b225b)

![Screenshot (924)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/be77e0e5-238c-4bed-bfdd-21bbce9f0266)

![Screenshot (925)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/f5055255-cd17-42a4-8c22-493cf0c4075f)

![Screenshot (926)](https://github.com/hinaila/Praktikum-Struktur-Data-Assignment/assets/161398108/64f204e1-2f16-4855-95f1-be41dc347b02)


## Kesimpulan
Stack adalah struktur data sederhana yang digunakan untuk menyimpan data (mirip dengan Linked Lists). Metode dalam Stack disebut Last in First out (LIFO). Sedangkan Queue adalah struktur data yang digunakan untuk menyimpan data dengan metode FIFO (First-In First-Out). Queue mirip dengan konsep antrian pada kehidupan sehari-hari.

## Referensi
Sihombing, J. (2020). Penerapan  Stack  dan  Queue  pada  Array dan  Linked  List dalam  Java. Program Studi Manajemen Informatika DIV  Politeknik Piksi Ganesha.
