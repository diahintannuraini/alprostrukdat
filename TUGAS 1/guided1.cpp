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