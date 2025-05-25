#include "palindrome_check.hpp"
#include <iostream>
#include <string>

int main() {
    std::string input;
    while (std::getline(std::cin, input)) {
        if (input.empty()) break;
        std::cout << input << (PalindromeCheck(input) ? " is" : " is not")
                  << " a palindrome" << std::endl;
    }
    return 0;
}
