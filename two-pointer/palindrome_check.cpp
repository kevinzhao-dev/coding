#include "palindrome_check.hpp"
#include <cstdint>

// level, naan
bool PalindromeCheck(const std::string& str) {
  if (str.empty()) return true;

  uint32_t left = 0, right = str.length() - 1;

  while (left < right) {
    if (str[left] != str[right])
      return false;
    left++;
    right--;
  }

  return true;
}


