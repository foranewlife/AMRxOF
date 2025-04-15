export module Config;

#include <string>
#include <vector>
#include <unordered_map>
#include <variant>
#include <iostream>
#include <rfl.hpp>

export namespace Config
{
  using Age = rfl::Validator<unsigned int, rfl::Minimum<0>, rfl::Maximum<130>>;
  using KedfName = rfl::Literal<"TF", "TFvW">;

  struct Config
  {
    rfl::Rename<"KEDF", Kedf> kedf;
    rfl::Rename<"CRYSTALL", Crystal> crystal;
  };

  struct Kedf
  {
    rfl::Rename<"name", KedfName> kedf_name;
  };
  struct Crystal
  {
    rfl::Rename<"name", std::string> crystal_name;
    rfl::Rename<"lattice", std::vector<double>> lattice;
    rfl::Rename<"atom", std::vector<std::string>> atom;
    rfl::Rename<"atom_pos", std::vector<std::vector<double>>> atom_pos;
  };

};