#include <AMReX.H>
#include <AMReX_Print.H>
#include <fstream>
#include <iostream>
#include <string>
#include <rfl.hpp>
#include "config.hpp"

namespace test_readme_example {

    using Age = rfl::Validator<unsigned int, rfl::Minimum<0>, rfl::Maximum<130>>;
    
    struct Person {
      rfl::Rename<"firstName", std::string> first_name;
      rfl::Rename<"lastName", std::string> last_name = "Simpson";
      std::string town = "Springfield";
      rfl::Timestamp<"%Y-%m-%d"> birthday;
      Age age;
      rfl::Email email;
      std::vector<Person> child;
    };
};


int main(int argc, char* argv[])
{
    // 禁用 AMReX 的 ParmParse 自动解析
    amrex::Initialize(argc, argv);

    // 示例：创建一个 Person 对象
    const auto bart = test_readme_example::Person{
        .first_name = "Bart",
        .birthday = "1987-04-19",
        .age = 10,
        .email = "bart@simpson.com"};

        try {
            std::ofstream toml_file("output.toml");
            if (!toml_file) {
                throw std::ios_base::failure("Failed to open file");
            }
            rfl::toml::write(bart, toml_file);
            toml_file.close();
        } catch (const std::exception& e) {
            std::cerr << "Error writing to TOML file: " << e.what() << std::endl;
        }

    // amrex::Print() << "Person details:\n";
    // amrex::Print() << "First Name: " << bart.first_name << "\n";
    // amrex::Print() << "Last Name: " << bart.last_name << "\n";
    // amrex::Print() << "Town: " << bart.town << "\n";
    // amrex::Print() << "Age: " << bart.age << "\n";
    // amrex::Print() << "Email: " << bart.email << "\n";

    amrex::Finalize();
}

