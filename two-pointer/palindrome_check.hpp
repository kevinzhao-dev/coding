#pragma once
#include <string>
#include <cstdint>

inline bool PalindromeCheck(const std::string& str) {
    if (str.empty()) return true;
    uint32_t left = 0;
    uint32_t right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) return false;
        ++left;
        --right;
    }
    return true;
}
