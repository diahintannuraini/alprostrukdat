#include <iostream>
using namespace std;

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int panjang_data = sizeof(data) / sizeof(data[0]); // Menghitung panjang larik data
    int angka_yang_dicari = 4;
    int count = 0; // Variabel untuk menghitung jumlah kemunculan angka 4

    // Algoritma Sequential Search
    for (int i = 0; i < panjang_data; ++i) {
        if (data[i] == angka_yang_dicari) {
            count++; // Meningkatkan jumlah kemunculan angka 4 setiap kali ditemukan
        }
    }

    cout << "Jumlah kemunculan angka 4 dalam data adalah: " << count << endl;

    return 0;
}