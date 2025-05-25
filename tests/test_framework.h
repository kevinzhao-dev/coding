#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using TestFunc = void(*)();

inline std::vector<std::pair<std::string, TestFunc>>& GetRegistry() {
    static std::vector<std::pair<std::string, TestFunc>> registry;
    return registry;
}

struct Register {
    Register(const std::string& name, TestFunc func) {
        GetRegistry().push_back({name, func});
    }
};

#define TEST_CASE(name) \
    void name(); \
    static Register reg_##name(#name, &name); \
    void name()

#define REQUIRE(cond) \
    do { \
        if (!(cond)) throw std::runtime_error("Requirement failed: " #cond); \
    } while (0)
