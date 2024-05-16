#include <iostream>
#include <vector>
#include <string>

int findString(const std::vector<std::string>& arr, const std::string& target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Jika mid adalah string kosong, cari elemen non-kosong terdekat
        int midLeft = mid;
        int midRight = mid;

        while (midLeft >= left && arr[midLeft] == "") {
            midLeft--;
        }
        while (midRight <= right && arr[midRight] == "") {
            midRight++;
        }

        // Pilih elemen non-kosong terdekat
        if (midLeft >= left && arr[midLeft] != "") {
            mid = midLeft;
        } else if (midRight <= right && arr[midRight] != "") {
            mid = midRight;
        } else {
            return -1; // tidak ditemukan
        }

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = midRight + 1;
        } else {
            right = midLeft - 1;
        }
    }

    return -1; // tidak ditemukan
}

int main() {
    std::vector<std::string> arr = {"Adi", "", "", "", "bermain", "", "bola", "", "", "sedang"};
    std::string target = "bola";

    int result = findString(arr, target);

    if (result != -1) {
        std::cout << "Indeks dari '" << target << "' adalah " << result << std::endl;
    } else {
        std::cout << "Kata '" << target << "' tidak ditemukan dalam array." << std::endl;
    }

    return 0;
}
