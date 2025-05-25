#include "test_framework.h"
#include "two-pointer/smaller_prefix.hpp"
#include <vector>

TEST_CASE(smaller_prefix_stub) {
    std::vector<int> arr = {1,2,3};
    if (!SmallerPrefix(arr)) throw std::runtime_error("stub should return true");
}
