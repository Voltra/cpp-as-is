add_library(cppAsIs_cppAsIs INTERFACE cppAsIs.hpp)


add_library(cppAsIs::cppAsIs ALIAS cppAsIs_cppAsIs)

target_link_libraries(
        cppAsIs_cppAsIs
        INTERFACE cppAsIs::cppAsIs_options
        cppAsIs::cppAsIs_warnings)


#target_include_directories(cppAsIs_cppAsIs INTERFACE "${CMAKE_BINARY_DIR}/configured_files/include")