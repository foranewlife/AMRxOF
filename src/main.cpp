#include <AMReX.H>
#include <AMReX_Print.H>
#include <fstream>
#include <iostream>
#include <string>
#include <rfl.hpp>
#include <rfl/toml.hpp>
#include "config.hpp"

int main(int argc, char *argv[])
{
    // 禁用 AMReX 的 ParmParse 自动解析
    amrex::Initialize(argc, argv);
    auto kedf = Config::Kedf{.kedf_name = Config::KedfName::make<"TF">()};
    auto pesudo_files = std::map<Config::ElementName, std::string>();
    pesudo_files.insert(std::make_pair("H", "H.pbe-rrkjus.UPF"));
    auto ion_elec = Config::IonElec{.pseudo_files = std::move(pesudo_files)};
    auto exc = Config::Exc{.exchange_name = Config::ExcName::make<"LDA">()};
    auto crystal = Config::Crystal{.crystal_file = "crystal.cif"};
    auto task = Config::Task{.name = Config::TaskName::make<"SinglePoint">()};
    auto config = Config::Config{
        .task = task,
        .crystal = crystal,
        .kedf = kedf,
        .ion_elec = ion_elec,
        .exc = exc};
    // 将配置写入文件
    std::ofstream config_file("config.toml");
    rfl::toml::write(config, config_file);

    amrex::Finalize();
}
