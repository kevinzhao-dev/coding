#pragma once
#include <vector>
#include <functional>
#include <iostream>
#include <exception>

struct Test {
    const char* name;
    std::function<void()> func;
};

inline std::vector<Test>& get_tests() {
    static std::vector<Test> tests;
    return tests;
}

#define TEST_CASE(name) \
    void name(); \
    struct name##_registrar { \
        name##_registrar() { get_tests().push_back({#name, name}); } \
    } name##_registrar_instance; \
    void name()

inline int run_all_tests() {
    int failed = 0;
    for (const auto& t : get_tests()) {
        try {
            t.func();
            std::cout << t.name << ": OK" << std::endl;
        } catch (const std::exception& e) {
            ++failed;
            std::cout << t.name << ": FAILED - " << e.what() << std::endl;
        } catch (...) {
            ++failed;
            std::cout << t.name << ": FAILED - unknown exception" << std::endl;
        }
    }
    std::cout << (get_tests().size() - failed) << "/" << get_tests().size()
              << " tests passed" << std::endl;
    return failed;
}
