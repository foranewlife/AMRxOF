#ifndef CONFIG_HPP
#define CONFIG_HPP

// Configuration settings for the AMRxOF project
#include <string>
#include <vector>
#include <unordered_map>
#include <variant>
#include <iostream>
#include <rfl.hpp>

namespace Config
{
    using Age = rfl::Validator<unsigned int, rfl::Minimum<0>, rfl::Maximum<130>>;
    using TaskName = rfl::Literal<"SinglePoint">;
    using KedfName = rfl::Literal<"TF", "TFvW">;
    using ExcName = rfl::Literal<"LDA">;
    // using ElementName = rfl::Literal<"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne",
    //                                  "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca",
    //                                  "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
    //                                  "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr",
    //                                  "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
    //                                  "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
    //                                  "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
    //                                  "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg",
    //                                  "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
    //                                  "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
    //                                  "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
    //                                  "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og", "Uue", "Ubn",
    //                                  "Uut", "Uuq", "Uup", "Uus", "Uuo", "Uup", "Uus", "Uuo">;
    using ElementName = rfl::Literal<"H", "He">;

    struct Crystal
    {
        rfl::Rename<"file", std::string> crystal_file;
    };

    struct Kedf
    {
        rfl::Rename<"name", KedfName> kedf_name = KedfName::make<"TF">();
    };
    struct IonElec
    {
        rfl::Rename<"files", std::map<ElementName, std::string>> pseudo_files;
    };

    struct Exc
    {
        rfl::Rename<"name", ExcName> exchange_name = ExcName::make<"LDA">();
    };

    // struct IonIon
    // {
    //     rfl::Rename<"name", std::string> ion_name;
    // };

    // struct Atom
    // {
    //     rfl::Rename<"atom", std::string> atom_name;
    //     rfl::Rename<"atom_pos", std::vector<double>> atom_pos;
    // };

    struct Task
    {
        rfl::Rename<"name", TaskName> name = TaskName::make<"SinglePoint">();
        rfl::Rename<"output_charge", bool> output_charge = false;
    };

    struct Config
    {
        rfl::Rename<"task", Task> task;
        rfl::Rename<"crystal", Crystal> crystal;
        rfl::Rename<"E_KEDF", Kedf> kedf;
        rfl::Rename<"E_ion_elec", IonElec> ion_elec;
        rfl::Rename<"E_xc", Exc> exc;
    };
};

#endif // CONFIG_HPP