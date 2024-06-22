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