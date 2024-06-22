# <h1 align="center">Tugas Struktur Data</h1>
<p align="center">Diah Intan Nuraini</p>

### 1. Sederhanakan program di bawah ini!
```C++
#include <iostream>
using namespace std;

bool cekDuplikat(int arr[]){
    int panjangArr = 4;
    for(int i=0; i<panjangArr; i++){
        for(int j=i+1; j<panjangArr; j++){
            if(arr[i]==arr[j]){
                return true;
            }
        }
    }
    return false;
}

int main(void)
{
    int arrA[] = {2, 1, 3, 1};
    cout << cekDuplikat(arrA);

    return 0;
}
```

### Jawaban
```C++
#include <iostream>
using namespace std;

bool cekDuplikat(int arr[], int panjangArr) {
    for(int i=0; i<panjangArr; i++){
        for(int j=i+1; j<panjangArr; j++){
            if(arr[i]==arr[j]){
                return true;
            }
        }
    }
    return false;
}

int main(void)
{
    int arrA[] = {2, 1, 3, 1};
    int panjangArr = sizeof(arrA)/sizeof(arrA[0]);
    cout << cekDuplikat(arrA, panjangArr);

    return 0;
}
```
### Interpretasi:
Kodingan ini merupakan contoh program C++ yang digunakan untuk memeriksa apakah terdapat elemen duplikat dalam sebuah array. Fungsi cekDuplikat adalah untuk membandingkan setiap elemen dalam array dengan elemen lainnya untuk menemukan duplikat. Jika ditemukan elemen duplikat, maka fungsi ini langsung kembali dengan nilai true. Jika tidak ditemukan duplikat, fungsi ini kembali dengan nilai false. Pada fungsi utama, array arrA dengan elemen {2, 1, 3, 1} didefinisikan. Panjang array ini dihitung menggunakan sizeof(arrA)/sizeof(arrA). Lalu, fungsi cekDuplikat dipanggil dengan array dan panjang array sebagai parameter, dan hasilnya dicetak ke layar.Output dari program ini adalah 1, yang menunjukkan bahwa terdapat elemen duplikat dalam array arrA, yaitu elemen 1 yang muncul dua kali.

### Screen Shoot Output:
![Output tugas 1](https://github.com/diahintannuraini/alprostrukdat/assets/162097079/81f60c76-3b1c-4348-a630-a5ff85105f5a)
