# <h1 align="center">Tugas Struktur Data</h1>
<p align="center">Diah Intan Nuraini</p>

## CPMK 2
### 1. Terdapat tiga algoritma sorting yang umum digunakan yakni, Bubble Sort, Selection Sort, dan Merge Sort. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma!:

a. Bubble Sort:

Alur:

1. Lakukan perulangan melewati seluruh elemen array.
2. Bandingkan elemen saat ini dengan elemen berikutnya.
3. Jika elemen saat ini lebih besar dari elemen berikutnya, tukar tempatnya.
4. Ulangi langkah 1 dan 2 sampai tidak ada lagi pertukaran yang terjadi.

Runtime:

1. Best case: O(n) - Terjadi ketika array sudah terurut, sehingga tidak ada pertukaran yang dilakukan.
2. Worst case: O(n^2) - Terjadi ketika array terurut secara terbalik, sehingga diperlukan n kali perulangan untuk mengurutkannya.

b. Selection Sort

Alur:

1. Temukan elemen terkecil dalam array.
2. Tukar elemen terkecil dengan elemen pertama.
3. Ulangi langkah 1 dan 2 untuk elemen selanjutnya, hingga seluruh elemen terurut.

Runtime:

1. Best case: O(n) - Terjadi ketika array sudah terurut, sehingga tidak perlu mencari elemen terkecil lagi.
2. Worst case: O(n^2) - Terjadi ketika array terurut secara acak, sehingga diperlukan n kali perulangan untuk menemukan elemen terkecil.

c. Merge Sort:

Alur:

1. Bagi array menjadi dua bagian yang sama besar.
2. Lakukan rekursi untuk mengurutkan kedua bagian secara terpisah.
3. Gabungkan kedua bagian yang telah terurut menjadi satu array yang terurut.

Runtime:

1. Best case: O(n log n) - Terjadi ketika array terbagi secara merata pada setiap pembagian.
2. Worst case: O(n log n) - Terjadi ketika array selalu terbagi tidak merata pada setiap pembagian.

### 2. Buatlah fungsi dari salah satu algoritma sorting pada soal nomor 1, dan berikan penjelasan pada program tersebut:
```C++
#include<iostream>
using namespace std;
void bubbleSort(string arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                string temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
} }
} }
void printArray(string arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
const int jumlah205 = 10;
string nama[jumlah205] = {"intan", "shafa", "renna", "donna",
"destina", "raisha", "hajra", "alin", "nino", "dani"};
cout << "Nama-nama warga sebelum diurutkan: " << endl; printArray(nama, jumlah205);
bubbleSort(nama, jumlah205);
cout << "Nama-nama warga setelah diurutkan: " << endl; printArray(nama, jumlah205);
return 0; 
}
```
### Interpretasi:
Program ini mengurutkan daftar nama secara alfabet menggunakan bubble sort. Pertama, program mencetak nama-nama warga dalam urutan asli yaitu "intan", "shafa", "renna", "donna", "destina", "raisha", "hajra", "alin", "nino", dan "dani". Kemudian, fungsi bubbleSort mengurutkan nama-nama ini dengan cara membandingkan dan menukar pasangan nama yang berdekatan jika diperlukan. Setelah selesai, program mencetak nama-nama yang sudah diurutkan: "alin", "dani", "destina", "donna", "hajra", "intan", "nino", "raisha", "renna", dan "shafa". 

### 3.Tulislah sebuah fungsi untuk mensorting dan mengecek dua buah array of strings, sehingga menghasilkan “anagram” dan “tidak anagram”:
```C++
#include <iostream>
#include <algorithm>
#include <string>

std::string isAnagram(const std::string& str1, const std::string& str2) {
    if (str1.length() != str2.length()) {
        return "tidak anagram";
    }

    std::string sortedStr1 = str1;
    std::string sortedStr2 = str2;

    std::sort(sortedStr1.begin(), sortedStr1.end());
    std::sort(sortedStr2.begin(), sortedStr2.end());

    if (sortedStr1 == sortedStr2) {
        return "anagram";
    } else {
        return "tidak anagram";
    }
}

int main() {
    std::string string1 = "bahu";
    std::string string2 = "buah";
    std::cout << "Input: string1 = " << string1 << " string2 = " << string2 << std::endl;
    std::cout << "Output: " << isAnagram(string1, string2) << std::endl;

    string1 = "hello";
    string2 = "world";
    std::cout << "Input: string1 = " << string1 << " string2 = " << string2 << std::endl;
    std::cout << "Output: " << isAnagram(string1, string2) << std::endl;

   
    return 0;
}
```


### 4. Tulislah sebuah fungsi program dengan asumsi sebagai berikut: Terdapat dua buah sorted array A dan B yang memiliki tipe data sama, dimana array A memiliki indeks yang cukup untuk menampung array B. Gabungkan array B kedalam array A, kemudian urutkan array tersebut!
```C++
#include <iostream>
#include <vector>

void mergeSortedArrays(std::vector<int>& A, const std::vector<int>& B, int lenA, int lenB) {
    
    int indexA = lenA - 1;
    int indexB = lenB - 1;
    int indexMerged = lenA + lenB - 1;

    
    while (indexB >= 0) {
        if (indexA >= 0 && A[indexA] > B[indexB]) {
            A[indexMerged] = A[indexA];
            indexA--;
        } else {
            A[indexMerged] = B[indexB];
            indexB--;
        }
        indexMerged--;
    }
}

int main() {
    
    std::vector<int> A = {1, 3, 5, 7, 0, 0, 0, 0};  
    std::vector<int> B = {2, 4, 6, 8};
    int lenA = 4;  
    int lenB = 4;  

    mergeSortedArrays(A, B, lenA, lenB);

    
    for (int num : A) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```


## CPMK 3
### 1. Terdapat dua algoritma searching yang umum digunakan yakni, Binary Search dan Linear Search. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma!

A. Linear Search (Pencarian Linear)

Alur:

1. Memulai dari elemen pertama dalam array.
2. Membandingkan elemen saat ini dengan elemen yang dicari.
3. Jika elemen saat ini sama dengan elemen yang dicari, kembalikan indeksnya.
4. Jika elemen saat ini tidak sama dengan elemen yang dicari, lanjutkan ke elemen berikutnya.
5. Ulangi langkah 2-4 sampai elemen yang dicari ditemukan atau seluruh array telah dijelajahi.
6. Jika elemen yang dicari tidak ditemukan di seluruh array, kembalikan nilai yang menunjukkan bahwa elemen tidak ditemukan.

Runtime:

1. Best case: O(1) - Terjadi ketika elemen yang dicari ditemukan pada indeks pertama array.
2. Worst case: O(n) - Terjadi ketika elemen yang dicari tidak ditemukan di dalam array, dan seluruh array perlu dijelajahi.

B. Binary Search (Pencarian Biner)

Alur:
1. Memeriksa elemen tengah array.
2. Membandingkan elemen tengah dengan elemen yang dicari.
3. Jika elemen tengah sama dengan elemen yang dicari, kembalikan indeksnya.
4. Jika elemen tengah lebih kecil dari elemen yang dicari, cari di subarray sebelah kanan elemen tengah.
5. Jika elemen tengah lebih besar dari elemen yang dicari, cari di subarray sebelah kiri elemen tengah.
6. Ulangi langkah 1-5 hingga elemen yang dicari ditemukan atau subarray menjadi kosong.
7. Jika elemen yang dicari tidak ditemukan di seluruh array, kembalikan nilai yang menunjukkan bahwa elemen tidak ditemukan.

Runtime:

1. Best case: O(1) - Terjadi ketika elemen yang dicari ditemukan pada elemen tengah array.

2. Worst case: O(log n) - Terjadi ketika elemen yang dicari tidak ditemukan di dalam array, dan seluruh array perlu dibagi dua secara berulang sampai subarray menjadi kosong.



### 2.	Buatlah fungsi dari salah satu algoritma searching pada soal nomor 1, dan berikan penjelasan pada program tersebut 
```C++
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
```
### Interpretasi:
Program ini menghitung berapa kali angka 4 muncul dalam sebuah array. Array yang digunakan berisi 10 angka yaitu {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}. Program ini menggunakan loop untuk memeriksa setiap elemen dalam array, dan setiap kali menemukan angka 4, variabel penghitung atau count akan bertambah satu. Setelah memeriksa seluruh array, program mencetak jumlah kemunculan angka 4, yang dalam hal ini adalah 4 kali. 
### 3.	Tulislah sebuah fungsi program dengan kondisi sebagai berikut: Terdapat sebuah sorted array of strings yang mana terdapat string kosong diantaranya, carilah lokasi/indeks dari kata yang dicari!





## CPMK 4
### 1.	Berikan penjelasan dari struct dan buatlah sebuah contoh program dari struct! 
penjelasan:
Struct adalah statement yang berguna untuk mengkelompokkan sejumlah data dengan tipe yang berlainan. Data Structures merupakan kumpulan dari data element yang digabung menjadi satu bagian dengan satu nama. Tiap elemen dikenal sebagai anggota struktur. Tiap anggota boleh berbeda tipe data dan berbeda panjang data.
Merupakan tipe data bentukan yang terdiri dari beberapa tipe data standar
maupun tipe data bentukan lainnya yang telah didefinisikan sebelumnya.
Sebagaimana telah disinggung sebelumnya, keyword yang digunakan untuk
membuat/mendeklarasikan sebuah struktur yakni struct.

contoh:
```C++
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

    for (int i = 0; i < 5; ++i) {
        contoh_buku.judul_buku[i] = "Judul Buku Contoh " + to_string(i+1);
        contoh_buku.pengarang[i] = "Pengarang Contoh " + to_string(i+1);
        contoh_buku.penerbit[i] = "Penerbit Contoh " + to_string(i+1);
        contoh_buku.tebal_halaman[i] = 300 + i*10;
        contoh_buku.harga_buku[i] = 150000.0 + i*5000;
    }

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
```
## CPMK 5
### 1.	Buatlah sebuah fungsi program untuk menghilangkan duplikasi data pada unsorted linked list (single atau double atau circular)
```C++
#include <iostream>
#include <unordered_set>

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

void removeDuplicates(Node* head) {
    if (head == nullptr) return;

    std::unordered_set<int> seen;
    Node* curr = head;
    Node* prev = nullptr;

    while (curr != nullptr) {
        if (seen.find(curr->data) != seen.end()) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            seen.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
}

void displayList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(20);
    head->next->next->next->next = new Node(40);

    std::cout << "Linked list sebelum menghapus duplikasi: ";
    displayList(head);

    removeDuplicates(head);

    std::cout << "Linked list setelah menghapus duplikasi: ";
    displayList(head);

    Node* curr = head;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}
```

### 2.	Buatlah sebuah algoritma dan fungsi program untuk menghapus node di tengah single linked list!
```C++
#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void addNode(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void deleteMiddleNode(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        std::cout << "Linked list tidak memiliki node di tengah." << std::endl;
        return;
    }

    Node* slowPtr = head;
    Node* fastPtr = head;
    Node* prev = nullptr;

    while (fastPtr != nullptr && fastPtr->next != nullptr) {
        fastPtr = fastPtr->next->next;
        prev = slowPtr;
        slowPtr = slowPtr->next;
    }

    prev->next = slowPtr->next;
    delete slowPtr;
}

void printLinkedList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    Node* head = nullptr;

    addNode(head, 6);
    addNode(head, 5);
    addNode(head, 4);
    addNode(head, 3);
    addNode(head, 2);
    addNode(head, 1);

    std::cout << "Linked list sebelum penghapusan: ";
    printLinkedList(head);

    deleteMiddleNode(head);

    std::cout << "Linked list setelah penghapusan: ";
    printLinkedList(head);

    return 0;
}

```

### 3.	Buatlah sebuah program untuk mengecek apakah linked list adalah sebuah palindrom!
```C++
#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void addNode(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void printLinkedList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return true; 
    }

    Node* slowPtr = head;
    Node* fastPtr = head;
    while (fastPtr->next != nullptr && fastPtr->next->next != nullptr) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    Node* secondHalf = reverseLinkedList(slowPtr->next);
    
    Node* firstHalf = head;
    while (secondHalf != nullptr) {
        if (firstHalf->data != secondHalf->data) {
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true; 
}

int main() {
    Node* head = nullptr;

    addNode(head, 1);
    addNode(head, 2);
    addNode(head, 3);
    addNode(head, 2);
    addNode(head, 1);

    std::cout << "Linked list: ";
    printLinkedList(head);

    if (isPalindrome(head)) {
        std::cout << "Linked list adalah palindrom." << std::endl;
    } else {
        std::cout << "Linked list bukan palindrom." << std::endl;
    }

    return 0;
}

```

## CPMK 6
### 1.	Tulislah sebuah program dari operasi stack seperti pop, push, isEmpty, isFull, dll(min 5)! 
```C++
#include <iostream>

class Stack {
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int x) {
        if (isFull()) {
            std::cout << "Stack overflow. Cannot push " << x << std::endl;
            return;
        }
        arr[++top] = x;
        std::cout << "Pushed " << x << " to stack." << std::endl;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack underflow. Cannot pop." << std::endl;
            return -1;
        }
        std::cout << "Popped " << arr[top] << " from stack." << std::endl;
        return arr[top--];
    }

    int peek() {
        if (!isEmpty()) {
            return arr[top];
        } else {
            std::cout << "Stack is empty." << std::endl;
            return -1;
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    int size() {
        return top + 1;
    }
};

int main() {
    Stack stack(5);

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6); 

    std::cout << "Top element is " << stack.peek() << std::endl;

    std::cout << "Stack size is " << stack.size() << std::endl;

    stack.pop();
    stack.pop();

    std::cout << "Top element is " << stack.peek() << std::endl;

    std::cout << "Stack is " << (stack.isEmpty() ? "empty" : "not empty") << std::endl;

    return 0;
}
```
### 2.	Tulislah sebuah program untuk mensortir sebuah stack, sehingga item dengan nilai terkecil menjadi top pada stack tersebut! Diperbolehkan menggunakan tambahan temporary stack, namun tidak diperbolehkan untuk menyalin dari struktur data yang lain seperti array.  Program stack yang dibuat dapat menggunakan operasi stack seperti push, pop, peek, dan isEmpty
```C++
#include <iostream>
#include <stack>

void sortStack(std::stack<int> &mainStack) {
    std::stack<int> tempStack;

    while (!mainStack.empty()) {
        int temp = mainStack.top();
        mainStack.pop();

        while (!tempStack.empty() && tempStack.top() > temp) {
            mainStack.push(tempStack.top());
            tempStack.pop();
        }
        tempStack.push(temp);
    }

    while (!tempStack.empty()) {
        mainStack.push(tempStack.top());
        tempStack.pop();
    }
}

void printStack(std::stack<int> s) {
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::stack<int> s;
    s.push(34);
    s.push(3);
    s.push(31);
    s.push(98);
    s.push(92);
    s.push(23);

    std::cout << "Original Stack:" << std::endl;
    printStack(s);

    sortStack(s);

    std::cout << "Sorted Stack:" << std::endl;
    printStack(s);

    return 0;
}
```
## CPMK 7
### nomor 1
```C++
#include <iostream>

class Queue {
private:
    int *arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    Queue(int size) {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int item) {
        if (isFull()) {
            std::cout << "Queue overflow. Cannot enqueue " << item << std::endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        count++;
        std::cout << "Enqueued " << item << " to queue." << std::endl;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue underflow. Cannot dequeue." << std::endl;
            return -1;
        }
        int item = arr[front];
        front = (front + 1) % capacity;
        count--;
        std::cout << "Dequeued " << item << " from queue." << std::endl;
        return item;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }

    int size() {
        return count;
    }
};

int main() {
    Queue queue(5);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6); 

    std::cout << "Front element is " << queue.peek() << std::endl;

    std::cout << "Queue size is " << queue.size() << std::endl;

    queue.dequeue();
    queue.dequeue();

    std::cout << "Front element is " << queue.peek() << std::endl;

    std::cout << "Queue is " << (queue.isEmpty() ? "empty" : "not empty") << std::endl;

    return 0;
}
```
### nomor 2
```C++
#include <iostream>
#include <queue>
#include <string>

class Animal {
public:
    std::string type;
    int order;

    Animal(std::string t, int o) : type(t), order(o) {}
};

class AnimalShelter {
private:
    std::queue<Animal> dogs;
    std::queue<Animal> cats;
    int order;

public:
    AnimalShelter() : order(0) {}

    void enqueue(std::string type) {
        Animal animal(type, order++);
        if (type == "dog") {
            dogs.push(animal);
            std::cout << "Enqueued dog with order " << animal.order << std::endl;
        } else if (type == "cat") {
            cats.push(animal);
            std::cout << "Enqueued cat with order " << animal.order << std::endl;
        } else {
            std::cout << "Invalid animal type!" << std::endl;
        }
    }

    Animal dequeueAny() {
        if (dogs.empty() && cats.empty()) {
            std::cout << "No animals available for adoption." << std::endl;
            return Animal("none", -1);
        }

        if (dogs.empty()) {
            return dequeueCat();
        }

        if (cats.empty()) {
            return dequeueDog();
        }

        Animal dog = dogs.front();
        Animal cat = cats.front();

        if (dog.order < cat.order) {
            return dequeueDog();
        } else {
            return dequeueCat();
        }
    }

    Animal dequeueDog() {
        if (dogs.empty()) {
            std::cout << "No dogs available for adoption." << std::endl;
            return Animal("none", -1);
        }

        Animal dog = dogs.front();
        dogs.pop();
        std::cout << "Dequeued dog with order " << dog.order << std::endl;
        return dog;
    }

    Animal dequeueCat() {
        if (cats.empty()) {
            std::cout << "No cats available for adoption." << std::endl;
            return Animal("none", -1);
        }

        Animal cat = cats.front();
        cats.pop();
        std::cout << "Dequeued cat with order " << cat.order << std::endl;
        return cat;
    }
};

int main() {
    AnimalShelter shelter;

    shelter.enqueue("dog");
    shelter.enqueue("cat");
    shelter.enqueue("dog");
    shelter.enqueue("cat");

    shelter.dequeueAny();
    shelter.dequeueDog();
    shelter.dequeueCat();
    shelter.dequeueAny();

    return 0;
}
```
