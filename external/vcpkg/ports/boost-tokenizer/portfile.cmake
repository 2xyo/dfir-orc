# Automatically generated by boost-vcpkg-helpers/generate-ports.ps1

include(vcpkg_common_functions)

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO boostorg/tokenizer
    REF boost-1.70.0
    SHA512 f1c48f599d9b0e8722d4b78a2def4760a48602838e03bc5a5e964ce4f78b7ffafad12ddd272fee1f576da06b231781e2fb95898ca7d1f09e68f9bbddcf4ee954
    HEAD_REF master
)

include(${CURRENT_INSTALLED_DIR}/share/boost-vcpkg-helpers/boost-modular-headers.cmake)
boost_modular_headers(SOURCE_PATH ${SOURCE_PATH})