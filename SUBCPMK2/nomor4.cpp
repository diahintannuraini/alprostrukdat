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
