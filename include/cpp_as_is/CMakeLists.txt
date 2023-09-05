add_library(cpp_as_is_cpp_as_is INTERFACE cpp_as_is.hpp)


add_library(cpp_as_is::cpp_as_is ALIAS cpp_as_is_cpp_as_is)

target_link_libraries(
        cpp_as_is_cpp_as_is
        INTERFACE cpp_as_is::cpp_as_is_options
        cpp_as_is::cpp_as_is_warnings)


#target_include_directories(cpp_as_is_cpp_as_is INTERFACE "${CMAKE_BINARY_DIR}/configured_files/include")