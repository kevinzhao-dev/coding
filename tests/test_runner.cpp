#include "test_framework.h"

int main() {
    auto& tests = GetRegistry();
    int passed = 0;
    for (auto& t : tests) {
        try {
            t.second();
            std::cout << t.first << ": PASS\n";
            ++passed;
        } catch (const std::exception& e) {
            std::cout << t.first << ": FAIL - " << e.what() << "\n";
        }
    }
    std::cout << passed << "/" << tests.size() << " tests passed\n";
    return passed == static_cast<int>(tests.size()) ? 0 : 1;
}
