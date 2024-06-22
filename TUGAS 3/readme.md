 ## a.	Priority Queue
 ### Pengertian:
 Jenis queue yang mengatur elemen berdasarkan nilai prioritasnya disebut queue prioritas. Dalam baris prioritas, setiap elemen memiliki nilai prioritas tertentu. Elemen dengan nilai prioritas lebih tinggi biasanya diambil sebelum elemen dengan nilai prioritas lebih rendah. Nilai prioritas setiap elemen yang ditambahkan ke antrian menentukan posisinya. Misalnya, jika Anda menambahkan elemen dengan nilai prioritas tinggi ke antrian prioritas, elemen tersebut dapat ditempatkan di dekat bagian depan antrian, sementara elemen dengan nilai prioritas rendah dapat ditempatkan di dekat bagian belakang. Daftar prioritas juga dapat memiliki aturan untuk menempatkan elemen-elemennya; misalnya, mereka dapat memprioritaskan yang maksimum atau minimum. Proses relaksasi juga akan berbeda untuk setiap situasi yang ingin dipecahkan, dan metode inisialisasi jarak juga akan berbeda.[1] Container priority_queue tidak memiliki iterator dan dibangun berdasarkan vector. Hanya item yang memiliki prioritas paling tinggi yang dapat dihapus dalam konten ini. Operator untuk tipe data elemen harus sudah didefinisikan. Jika x < y memberikan true, berarti elemen y memiliki prioritas yang lebih besar daripada elemen x. Fungsi member sebanding dengan stack[2]


 ```C++
 #include <iostream>
#include <vector>

using namespace std;

vector<int> H;
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
        swap(H[parent(i)], H[i]);
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
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    if (heapSize < H.size()) {
        H[heapSize] = p;
    } else {
        H.push_back(p);
    }
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

void buildHeap(const vector<int>& input) {
    H = input;
    heapSize = input.size() - 1;
    for (int i = (heapSize / 2); i >= 0; --i) {
        shiftDown(i);
    }
}

int main() {
    int n, value;
    cout << "Enter the number of elements to insert into the heap: ";
    cin >> n;

    vector<int> input(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }

    buildHeap(input);

    cout << "Priority Queue after building the heap: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    cout << "Node with maximum priority: " << extractMax() << "\n";

    cout << "Priority Queue after extracting maximum: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    int index, newPriority;
    cout << "Enter the index and new priority to change: ";
    cin >> index >> newPriority;
    changePriority(index, newPriority);

    cout << "Priority queue after priority change: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    cout << "Enter the index to remove: ";
    cin >> index;
    remove(index);

    cout << "Priority queue after removing the element: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    return 0;
}
 ```
 ### Penjelasan Alur Program:
 Program ini mengimplementasikan antrian prioritas menggunakan heap biner. Program meminta pengguna untuk memasukkan jumlah elemen dan elemen-elemen, lalu membangun heap menggunakan fungsi buildHeap. Kemudian, program menghapus elemen prioritas tertinggi menggunakan extractMax, mengubah prioritas node menggunakan changePriority, dan menghapus node menggunakan remove. Program mencetak antrian prioritas setelah setiap operasi untuk menunjukkan perubahan yang terjadi. Dengan demikian, program menunjukkan perilaku heap di bawah skenario yang berbeda.
 ### Sumber Jurnal:
 [1] Naufal, M. F. (2021). Penerapan Algoritme Greedy dalam Menghitung Bandwith pada Jaringan Telepon.
 [2] Santoso, L. E. (2004). STANDARD TEMPLATE LIBRARY C++ UNTUK MENGAJARKAN STRUKTUR DATA. Jurnal FASILKOM Vol, 2(2).

 ## b.	Hash Table
 ### Pengertian:
 Hash table adalah struktur data yang mengorganisir data ke dalam pasangan nilai kunci. Hash table  terdiri dari dua komponen utama yaitu array (atau vektor) dan fungsi hash. Hashing merupakan teknik yang digunakan untuk mengubah rentang nilai kunci menjadi rentang indeks array. Array menyimpan data dalam slot yang disebut bucket, yang masing-masing dapat menampung satu atau beberapa item data. Fungsi hash digunakan untuk menghasilkan nilai unik dari setiap item data, yang digunakan seb Hash table memungkinkan pencarian data dalam waktu yang konstan (O(1)) dalam situasi terbaik.Sistem hash table menggunakan fungsi hash untuk mengambil input kunci dan memetakkannya ke nilai indeks array. Kemudian, fungsi hash menghasilkan posisi indeks array, dan ketika data perlu dicari, input kunci dijadikan parameter untuk fungsi hash, dan posisi indeks array yang dihasilkan dipakai untuk mencari data. Dalam situasi di mana dua atau lebih data memiliki nilai hash yang sama, hash table menyimpan data tersebut dalam slot yang sama. Teknik yang disebut chaining adalah cara untuk melakukan ini dalam kasus di mana hash collision terjadi.[1]
 ### Penggunaan Hash Table:
 Hash table digunakan karena menawarkan efisiensi waktu operasi yang lebih tinggi untuk tujuan pengarsipan dan pencarian data. Bidang jaringan komputer mengembangkannya menjadi hybrid open hash table, yang kemudian digunakan untuk memproses jaringan komputer.[2]
 ### Kelebihan dan Kekurangan Hash Table:
 Mempersingkat Waktu Operasi, Akses Instan, Penyimpanan yang Cukup Besar untuk Data, Penyelesaian Kecelakaan, adapun Kekurangan Hash Table: Pertemuan, Batasan Ukuran, Limitasi Khusus[3]

 ```C++
 #include <iostream>
using namespace std;

const int MAX_SIZE = 10;

int hash_func(int key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable {
private:
    Node** table;
public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }

    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Menambahkan data baru
    void insert(int key, int value) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node* node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Mencari data berdasarkan NIM
    int get(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Menghapus data berdasarkan NIM
    void remove(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Mencari data berdasarkan rentang nilai (80-90)
    void search_by_value_range(int min_value, int max_value) {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                if (current->value >= min_value && current->value <= max_value) {
                    cout << "NIM: " << current->key << ", Nilai: " << current->value << endl;
                }
                current = current->next;
            }
        }
    }

    // Traversal untuk menampilkan semua data
    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                cout << "NIM: " << current->key << ", Nilai: " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    HashTable ht;
    int choice, nim, nilai;
    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah data mahasiswa\n";
        cout << "2. Hapus data mahasiswa\n";
        cout << "3. Cari data berdasarkan NIM\n";
        cout << "4. Cari data berdasarkan rentang nilai (80-90)\n";
        cout << "5. Tampilkan semua data\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan NIM: ";
                cin >> nim;
                cout << "Masukkan Nilai: ";
                cin >> nilai;
                ht.insert(nim, nilai);
                break;
            case 2:
                cout << "Masukkan NIM yang akan dihapus: ";
                cin >> nim;
                ht.remove(nim);
                break;
            case 3:
                cout << "Masukkan NIM yang akan dicari: ";
                cin >> nim;
                nilai = ht.get(nim);
                if (nilai != -1) {
                    cout << "Nilai mahasiswa dengan NIM " << nim << " adalah: " << nilai << endl;
                } else {
                    cout << "Data tidak ditemukan." << endl;
                }
                break;
            case 4:
                cout << "Mahasiswa dengan nilai antara 80 dan 90:\n";
                ht.search_by_value_range(80, 90);
                break;
            case 5:
                cout << "Data semua mahasiswa:\n";
                ht.traverse();
                break;
            case 6:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (choice != 6);

    return 0;
}
``` 
## Penjelasan alur program:
Program ini mengimplementasikan tabel hash untuk mengelola data mahasiswa. Program ini memiliki fungsi utama seperti menginsert data, mencari data berdasarkan NIM, menghapus data, mencari data berdasarkan rentang nilai, dan menampilkan semua data. Program ini juga memiliki menu interaktif yang memungkinkan pengguna memilih operasi yang ingin dilakukan. Program ini berjalan dengan cara meminta pengguna memilih menu, lalu melakukan operasi yang dipilih. Dengan demikian, program ini dapat membantu mengelola dan mencari data mahasiswa dengan lebih efektif dan efisien.
### Sumber Jurnal:
[1] Karumanchi, N. (2016). Data Structures and algorithms made easy: Concepts, problems, Interview Questions. CareerMonk Publications.
[2] Prestiliano, J. (2007). Aplikasi Tabel Hash dalam Pengarsipan dan Pencarian Data.
[3] Fasilkom UI - IKI20100 Hash Table by Ruli Manurung & Ade Azurat


## c.	Rekursif
### Pengertian:
Rekursif merupakan salah satu proses pengulangan fungsi atau prosedur yang memanggil dirinya sendiri.Fungsi rekursif dapat memanggil dirinya sendiri berulang kali. Ada kondisi yang harus menghentikan proses yang berulang. Jika tidak, proses tidak akan pernah berhenti sampai memori yang digunakan habis.[1] Rekursi adalah ketika sebuah fungsi dapat memecah masalah menjadi submasalah yang lebih kecil dan kemudian memanggil dirinya sendiri untuk menyelesaikan submasalah tersebut.[2]
### Kelebihan dan kekurangan rekursif:
Fungsi rekursif membuat kode lebih singkat dan lebih mudah dipahami, tetapi dapat menyebabkan stack overflow jika proses pemanggilan berulang dirinya sendiri. Akibatnya, fungsi iteratif dapat menggunakan memori dengan lebih efisien dalam beberapa situasi.[3]
```C++
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
```
### Penjelasan alur program:
Program ini menghitung faktorial dari sebuah bilangan bulat positif. Program ini meminta pengguna memasukkan bilangan, lalu menghitung faktorial menggunakan fungsi rekursif. Jika bilangan tidak valid, program akan menampilkan pesan error. Hasil faktorial kemudian ditampilkan ke layar. Program ini membantu dalam menghitung faktorial dengan cara yang efektif dan efisien.
### Sumber Jurnal:
[1] Karumanchi, N. (2016). Data Structures and algorithms made easy: Concepts, problems, Interview Questions. CareerMonk Publications.
[2] Purbasari, W., Iqbal, T., Inayah, I., Munawir, M., Sutjiningtyas, S., Hikmawati, E., ... & Basri, H. (2024). ALGORITMA PEMROGRAMAN
[3] Jurnal Sains dan Teknologi Widya.

## d.	Graph & Tree
### Pengertian:
Graf, juga dikenal sebagai graf, adalah struktur data yang menunjukkan hubungan antara objek dalam bentuk node atau vertex serta sambungan antara node tersebut dalam bentuk sisi atau tepi.Tree atau Pohon: Dalam ilmu komputer, pohon atau pohon adalah struktur data yang sangat umum dan kuat yang mirip dengan pohon nyata. Ini terdiri dari satu set node yang tertaut yang terurut dalam grafik yang terhubung; setiap node memiliki setidaknya satu simpul induk dan nol atau lebih simpul anak dalam urutan tertentu. Data hirarki seperti pohon keluarga, skema pertandingan, dan struktur organisasi disimpan dalam struktur data pohon.[1]
### Jenis-jenis binary tree :
Complete Binary Tree Suatu binary tree T disebut lengkap atau lengkap jika setiap levelnya memiliki anak dua buah, kecuali level paling akhir. Namun, pada titik terakhirnya, setiap daun atau cabang muncul terurut dari sebelah kiri.
Extended Binary Tree Sebuah binary tree disebut sebagai extended binary tree jika tiap simpul N memiliki 0 atau 2 anak. Dalam diagram node, simpul dengan dua anak disebut simpul internal (internal node), dan simpul dengan zero anak disebut simpul eksternal (external node).[2]
```C++
#include <iostream>
using namespace std;

void tampilGraph(string *simpul, int **busur, int intan_2311110046)
{
    cout << endl;
    for (int i = 0; i < intan_2311110046; i++)
    {
        cout << "\t" << simpul[i];
    }
    cout << endl;
    for (int i = 0; i < intan_2311110046; i++)
    {
        cout << simpul[i] << "\t";
        for (int j = 0; j < intan_2311110046; j++)
        {
            cout << busur[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int intan_2311110046;
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> intan_2311110046;
    cin.ignore();
    cout << "Silahkan masukkan nama simpul" << endl;

    string *simpul = new string[intan_2311110046];
    for (int i = 0; i < intan_2311110046; i++)
    {
        cout << "Simpul " << i + 1 << " : ";
        getline(cin, simpul[i]);
    }

    int **busur = new int *[intan_2311110046];
    for (int i = 0; i < intan_2311110046; i++)
    {
        busur[i] = new int[intan_2311110046];
    }

    cout << "Silakan masukkan bobot antar simpul" << endl;
    for (int i = 0; i < intan_2311110046; i++)
    {
        for (int j = 0; j < intan_2311110046; j++)
        {
            cout << simpul[i] << "-->" << simpul[j] << " = ";
            cin >> busur[i][j];
        }
    }

    tampilGraph(simpul, busur, intan_2311110046);

    for (int i = 0; i < intan_2311110046; i++)
    {
        delete[] busur[i];
    }
    delete[] busur;
    delete[] simpul;

    return 0;
}
```
### Penjelasan Alur program:
Program ini mengimplementasikan fungsi untuk menampilkan grafik menggunakan struktur data simpul dan busur. Program ini meminta pengguna untuk memasukkan jumlah simpul, nama-nama simpul, dan bobot antar simpul. Kemudian, program menampilkan grafik menggunakan fungsi tampilGraph dan menghapus alokasi memori yang digunakan. Dengan demikian, program ini membantu dalam mengelola dan menampilkan grafik dengan cara yang efektif dan efisien.
### Sumber Jurnal:
[1] Karumanchi, N. (2011). Data Structures and Algorithms Made Easy: 700 Data Structure and Algorithmic Puzzles. CreateSpace.
[2] Arianti, M. Y., Fitriani, N., Khairani, D., & Adinda, S. T. (2021). Rapor, Nilai, Dev C++ ANALISIS NILAI AKHIR RAPOR DENGAN PROGRAM C++ SMK ISLAMIYAH SEI KAMAH II 2021. PKM-P, 5(2), 164-167.