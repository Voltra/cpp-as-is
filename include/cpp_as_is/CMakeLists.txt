add_library(cpp_as_is_cpp_as_is INTERFACE cpp_as_is.hpp is/is.hpp is/traits.hpp is/impl/variant.hpp is/impl/impl.hpp is/impl/any.hpp is/impl/optional.hpp is/impl/future.hpp is/impl/expected.hpp is/concepts.hpp is/impl/pointer.hpp is/impl/shared_ptr.hpp is/impl/unique_ptr.hpp utils.hpp as/as.hpp as/traits.hpp as/concepts.hpp is/impl/identity.hpp as/impl/impl.hpp as/impl/pointer.hpp as/impl/any.hpp as/impl/variant.hpp)


add_library(cpp_as_is::cpp_as_is ALIAS cpp_as_is_cpp_as_is)

target_link_libraries(
        cpp_as_is_cpp_as_is
        INTERFACE cpp_as_is::cpp_as_is_options
        cpp_as_is::cpp_as_is_warnings)


#target_include_directories(cpp_as_is_cpp_as_is INTERFACE "${CMAKE_BINARY_DIR}/configured_files/include")
target_include_directories(cpp_as_is_cpp_as_is INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:/include>
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
        )