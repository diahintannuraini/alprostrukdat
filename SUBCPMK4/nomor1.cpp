#include <iostream>
using namespace std;

struct buku {
    string judul_buku[5];
    string pengarang[5];
    string penerbit[5];
    int tebal_halaman[5];
    double harga_buku[5];
};

int main() {
    buku contoh_buku;

    // Mengisi array dengan data
    for (int i = 0; i < 5; ++i) {
        contoh_buku.judul_buku[i] = "Judul Buku Contoh " + to_string(i+1);
        contoh_buku.pengarang[i] = "Pengarang Contoh " + to_string(i+1);
        contoh_buku.penerbit[i] = "Penerbit Contoh " + to_string(i+1);
        contoh_buku.tebal_halaman[i] = 300 + i*10;
        contoh_buku.harga_buku[i] = 150000.0 + i*5000;
    }

    // Menampilkan isi array
    cout << "Data Buku:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Buku " << i+1 << ":" << endl;
        cout << "Judul Buku: " << contoh_buku.judul_buku[i] << endl;
        cout << "Pengarang: " << contoh_buku.pengarang[i] << endl;
        cout << "Penerbit: " << contoh_buku.penerbit[i] << endl;
        cout << "Tebal Halaman: " << contoh_buku.tebal_halaman[i] << endl;
        cout << "Harga Buku: Rp" << contoh_buku.harga_buku[i] << endl;
        cout << endl;
    }

    return 0;
}