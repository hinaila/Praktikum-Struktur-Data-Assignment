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