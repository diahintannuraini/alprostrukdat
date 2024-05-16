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
