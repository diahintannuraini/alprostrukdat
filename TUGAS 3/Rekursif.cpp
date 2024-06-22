#include <iostream>

using namespace std;

int faktorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * faktorial(n - 1);
}

int main() {
    int n;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> n;

    if (n < 0) {
        cout << "Input tidak valid. Masukkan bilangan bulat positif." << endl;
        return 1;
    }

    int hasil = faktorial(n);
    cout << "Faktorial dari " << n << " adalah: " << hasil << endl;

    return 0;
}
