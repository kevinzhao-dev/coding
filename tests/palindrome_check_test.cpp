#include "test_framework.h"
#include "two-pointer/palindrome_check.hpp"

TEST_CASE(test_empty) {
    if (!PalindromeCheck("")) throw std::runtime_error("empty string should be palindrome");
}

TEST_CASE(test_basic_true) {
    if (!PalindromeCheck("level")) throw std::runtime_error("level should be palindrome");
}

TEST_CASE(test_basic_false) {
    if (PalindromeCheck("hello")) throw std::runtime_error("hello is not palindrome");
}
