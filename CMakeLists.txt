cmake_minimum_required(VERSION 4.0)
# Include CPM.cmake for package management
include(cmake/CPM.cmake)

project(AMRxOF
  VERSION 0.1
  LANGUAGES CXX
)

# Enable C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add the Finufft package using CPM
CPMAddPackage("gh:flatironinstitute/finufft@2.3.1")

CPMAddPackage("gh:ToruNiina/toml11@4.4.0")

# Add the AMReX library using CPM
CPMAddPackage(
  NAME             AMReX
  GIT_REPOSITORY   https://github.com/AMReX-Codes/amrex.git
  GIT_TAG          25.04
  GIT_SHALLOW      Yes
  GIT_PROGRESS     Yes
  EXCLUDE_FROM_ALL Yes
  SYSTEM
)

# CPMAddPackage(
#   NAME Boost
#   VERSION 1.86.0 # Versions less than 1.85.0 may need patches for installation targets.
#   URL https://github.com/boostorg/boost/releases/download/boost-1.86.0/boost-1.86.0-cmake.tar.xz
#   URL_HASH SHA256=2c5ec5edcdff47ff55e27ed9560b0a0b94b07bd07ed9928b476150e16b0efc57
#   OPTIONS "BOOST_ENABLE_CMAKE ON" "BOOST_SKIP_INSTALL_RULES ON" # Set `OFF` for installation
#           "BUILD_SHARED_LIBS OFF" "BOOST_INCLUDE_LIBRARIES preprocessor\\\;asio" # Note the escapes!
# )

# Add tomlplusplus using CPM
CPMAddPackage(
    NAME tomlplusplus
    GIT_REPOSITORY https://github.com/marzer/tomlplusplus.git
    GIT_TAG v3.3.0
    OPTIONS "TOMLPLUSPLUS_BUILD_TESTS OFF" "TOMLPLUSPLUS_BUILD_EXAMPLES OFF"
)

# CPMAddPackage(
#   NAME magic_enum
#   GIT_REPOSITORY https://github.com/Neargye/magic_enum.git
#   GIT_TAG v0.9.7
# )

# CPMAddPackage(
#   NAME refl-cpp
#   GIT_REPOSITORY https://github.com/veselink1/refl-cpp.git
#   GIT_TAG v0.12.4
# )

# Add boost-ext/reflect using CPM
# CPMAddPackage(
#   NAME boost-ext-reflect
#   GIT_REPOSITORY https://github.com/boost-ext/reflect
#   GIT_SHALLOW ON  # Download the branch without its history
#   GIT_TAG        v1.1.1
# )


set(REFLECTCPP_TOML ON) # Optional

CPMAddPackage(
  NAME reflect-cpp
  GIT_REPOSITORY git@github.com:getml/reflect-cpp.git
  GIT_SHALLOW ON  # Download the branch without its history
  GIT_TAG       v0.18.0
)


# if(EXISTS ${CMAKE_SOURCE_DIR}/thirdparty/reflect-cpp)
#   add_subdirectory(thirdparty/reflect-cpp) # Add this project as a subdirectory
# else()
#   message(FATAL_ERROR "Directory 'thirdparty/reflect-cpp' does not exist.")
# endif()

# set(REFLECTCPP_AVRO ON) # Optional
# set(REFLECTCPP_BSON ON) # Optional
# set(REFLECTCPP_CBOR ON) # Optional
# set(REFLECTCPP_FLEXBUFFERS ON) # Optional
# set(REFLECTCPP_MSGPACK ON) # Optional

# set(REFLECTCPP_UBJSON ON) # Optional
# set(REFLECTCPP_XML ON) # Optional
# set(REFLECTCPP_YAML ON) # Optional



# Add include and src directories
include_directories(${CMAKE_BINARY_DIR}/_deps/tomlplusplus-src/include)
include_directories(${CMAKE_BINARY_DIR}/_deps/magic_enum-src/include)
include_directories(${CMAKE_BINARY_DIR}/_deps/refl-cpp-src/include)
include_directories(${CMAKE_BINARY_DIR}/_deps/boost-ext-reflect-src/include)
include_directories(${CMAKE_BINARY_DIR}/_deps/toml11-src/include)
include_directories(${CMAKE_BINARY_DIR}/_deps/reflect-cpp-src/include)


add_executable(amrxof src/main.cpp)
target_link_libraries(amrxof PRIVATE AMReX::amrex reflectcpp toml11::toml11)

