#include <iostream>
#include <rfl.hpp>
#include <string>
#include <vector>
#include <fstream>
#include <rfl/toml.hpp>
#include "config.hpp"

void writeToToml(const test_readme_example::Person& person, const std::string& filePath) {
    // 使用 reflect-cpp 的 toml 序列化功能
    auto serialized = rfl::toml::write(person);

    // 将序列化的内容写入文件
    std::ofstream outFile(filePath);
    if (!outFile) {
        throw std::ios_base::failure("Failed to open file: " + filePath);
    }
    outFile << serialized;
    outFile.close();
}

