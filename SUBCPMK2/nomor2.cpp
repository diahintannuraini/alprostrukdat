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