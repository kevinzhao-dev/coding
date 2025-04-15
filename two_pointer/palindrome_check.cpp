#include <iostream>
#include <string>

// level, naan
bool PalindromeCheck(const std::string str) {

  uint32_t left = 0, right = str.length() - 1;

  while (left < right) {
    if (str[left] != str[right])
      return false;
    left++;
    right--;
  }

  return true;
}

int main() {
  // Test standard palindromes
  std::cout << "--- Testing standard palindromes ---\n";
  std::cout << "\"level\": "
            << (PalindromeCheck("level") ? "Palindrome ✓"
                                         : "Not a palindrome ✗")
            << std::endl;
  std::cout << "\"naan\": "
            << (PalindromeCheck("naan") ? "Palindrome ✓" : "Not a palindrome ✗")
            << std::endl;
  std::cout << "\"nan\": "
            << (PalindromeCheck("nan") ? "Palindrome ✓" : "Not a palindrome ✗")
            << std::endl;

  // Test non-palindromes
  std::cout << "\n--- Testing non-palindromes ---\n";
  std::cout << "\"apple\": "
            << (PalindromeCheck("apple") ? "Palindrome ✗"
                                         : "Not a palindrome ✓")
            << std::endl;
  std::cout << "\"hello\": "
            << (PalindromeCheck("hello") ? "Palindrome ✗"
                                         : "Not a palindrome ✓")
            << std::endl;

  // Test edge cases
  std::cout << "\n--- Testing edge cases ---\n";
  std::cout << "Empty string: "
            << (PalindromeCheck("") ? "Palindrome ✓" : "Not a palindrome ✗")
            << std::endl;
  std::cout << "Single char \"a\": "
            << (PalindromeCheck("a") ? "Palindrome ✓" : "Not a palindrome ✗")
            << std::endl;
  std::cout << "\"A man a plan a canal Panama\": "
            << (PalindromeCheck("A man a plan a canal Panama")
                    ? "Palindrome ✗"
                    : "Not a palindrome ✓")
            << std::endl;

  return 0;
}
