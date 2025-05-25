#include "../two-pointer/palindrome_check.hpp"
#include "test_framework.h"

TEST_CASE(StandardPalindromes) {
    REQUIRE(PalindromeCheck("level"));
    REQUIRE(PalindromeCheck("naan"));
    REQUIRE(PalindromeCheck("nan"));
}

TEST_CASE(NonPalindromes) {
    REQUIRE(!PalindromeCheck("apple"));
    REQUIRE(!PalindromeCheck("hello"));
}

TEST_CASE(EdgeCases) {
    REQUIRE(PalindromeCheck(""));
    REQUIRE(PalindromeCheck("a"));
    REQUIRE(!PalindromeCheck("A man a plan a canal Panama"));
}
