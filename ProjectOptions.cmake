include(cmake/SystemLink.cmake)
include(cmake/LibFuzzer.cmake)
include(CMakeDependentOption)
include(CheckCXXCompilerFlag)


macro(cppAsIs_supports_sanitizers)
  if((CMAKE_CXX_COMPILER_ID MATCHES ".*Clang.*" OR CMAKE_CXX_COMPILER_ID MATCHES ".*GNU.*") AND NOT WIN32)
    set(SUPPORTS_UBSAN ON)
  else()
    set(SUPPORTS_UBSAN OFF)
  endif()

  if((CMAKE_CXX_COMPILER_ID MATCHES ".*Clang.*" OR CMAKE_CXX_COMPILER_ID MATCHES ".*GNU.*") AND WIN32)
    set(SUPPORTS_ASAN OFF)
  else()
    set(SUPPORTS_ASAN ON)
  endif()
endmacro()

macro(cppAsIs_setup_options)
  option(cppAsIs_ENABLE_HARDENING "Enable hardening" ON)
  option(cppAsIs_ENABLE_COVERAGE "Enable coverage reporting" OFF)
  cmake_dependent_option(
    cppAsIs_ENABLE_GLOBAL_HARDENING
    "Attempt to push hardening options to built dependencies"
    ON
    cppAsIs_ENABLE_HARDENING
    OFF)

  cppAsIs_supports_sanitizers()

  if(NOT PROJECT_IS_TOP_LEVEL OR cppAsIs_PACKAGING_MAINTAINER_MODE)
    option(cppAsIs_ENABLE_IPO "Enable IPO/LTO" OFF)
    option(cppAsIs_WARNINGS_AS_ERRORS "Treat Warnings As Errors" OFF)
    option(cppAsIs_ENABLE_USER_LINKER "Enable user-selected linker" OFF)
    option(cppAsIs_ENABLE_SANITIZER_ADDRESS "Enable address sanitizer" OFF)
    option(cppAsIs_ENABLE_SANITIZER_LEAK "Enable leak sanitizer" OFF)
    option(cppAsIs_ENABLE_SANITIZER_UNDEFINED "Enable undefined sanitizer" OFF)
    option(cppAsIs_ENABLE_SANITIZER_THREAD "Enable thread sanitizer" OFF)
    option(cppAsIs_ENABLE_SANITIZER_MEMORY "Enable memory sanitizer" OFF)
    option(cppAsIs_ENABLE_UNITY_BUILD "Enable unity builds" OFF)
    option(cppAsIs_ENABLE_CLANG_TIDY "Enable clang-tidy" OFF)
    option(cppAsIs_ENABLE_CPPCHECK "Enable cpp-check analysis" OFF)
    option(cppAsIs_ENABLE_PCH "Enable precompiled headers" OFF)
    option(cppAsIs_ENABLE_CACHE "Enable ccache" OFF)
  else()
    option(cppAsIs_ENABLE_IPO "Enable IPO/LTO" ON)
    option(cppAsIs_WARNINGS_AS_ERRORS "Treat Warnings As Errors" ON)
    option(cppAsIs_ENABLE_USER_LINKER "Enable user-selected linker" OFF)
    option(cppAsIs_ENABLE_SANITIZER_ADDRESS "Enable address sanitizer" ${SUPPORTS_ASAN})
    option(cppAsIs_ENABLE_SANITIZER_LEAK "Enable leak sanitizer" OFF)
    option(cppAsIs_ENABLE_SANITIZER_UNDEFINED "Enable undefined sanitizer" ${SUPPORTS_UBSAN})
    option(cppAsIs_ENABLE_SANITIZER_THREAD "Enable thread sanitizer" OFF)
    option(cppAsIs_ENABLE_SANITIZER_MEMORY "Enable memory sanitizer" OFF)
    option(cppAsIs_ENABLE_UNITY_BUILD "Enable unity builds" OFF)
    option(cppAsIs_ENABLE_CLANG_TIDY "Enable clang-tidy" ON)
    option(cppAsIs_ENABLE_CPPCHECK "Enable cpp-check analysis" ON)
    option(cppAsIs_ENABLE_PCH "Enable precompiled headers" OFF)
    option(cppAsIs_ENABLE_CACHE "Enable ccache" ON)
  endif()

  if(NOT PROJECT_IS_TOP_LEVEL)
    mark_as_advanced(
      cppAsIs_ENABLE_IPO
      cppAsIs_WARNINGS_AS_ERRORS
      cppAsIs_ENABLE_USER_LINKER
      cppAsIs_ENABLE_SANITIZER_ADDRESS
      cppAsIs_ENABLE_SANITIZER_LEAK
      cppAsIs_ENABLE_SANITIZER_UNDEFINED
      cppAsIs_ENABLE_SANITIZER_THREAD
      cppAsIs_ENABLE_SANITIZER_MEMORY
      cppAsIs_ENABLE_UNITY_BUILD
      cppAsIs_ENABLE_CLANG_TIDY
      cppAsIs_ENABLE_CPPCHECK
      cppAsIs_ENABLE_COVERAGE
      cppAsIs_ENABLE_PCH
      cppAsIs_ENABLE_CACHE)
  endif()

  cppAsIs_check_libfuzzer_support(LIBFUZZER_SUPPORTED)
  if(LIBFUZZER_SUPPORTED AND (cppAsIs_ENABLE_SANITIZER_ADDRESS OR cppAsIs_ENABLE_SANITIZER_THREAD OR cppAsIs_ENABLE_SANITIZER_UNDEFINED))
    set(DEFAULT_FUZZER ON)
  else()
    set(DEFAULT_FUZZER OFF)
  endif()

  option(cppAsIs_BUILD_FUZZ_TESTS "Enable fuzz testing executable" ${DEFAULT_FUZZER})

endmacro()

macro(cppAsIs_global_options)
  if(cppAsIs_ENABLE_IPO)
    include(cmake/InterproceduralOptimization.cmake)
    cppAsIs_enable_ipo()
  endif()

  cppAsIs_supports_sanitizers()

  if(cppAsIs_ENABLE_HARDENING AND cppAsIs_ENABLE_GLOBAL_HARDENING)
    include(cmake/Hardening.cmake)
    if(NOT SUPPORTS_UBSAN 
       OR cppAsIs_ENABLE_SANITIZER_UNDEFINED
       OR cppAsIs_ENABLE_SANITIZER_ADDRESS
       OR cppAsIs_ENABLE_SANITIZER_THREAD
       OR cppAsIs_ENABLE_SANITIZER_LEAK)
      set(ENABLE_UBSAN_MINIMAL_RUNTIME FALSE)
    else()
      set(ENABLE_UBSAN_MINIMAL_RUNTIME TRUE)
    endif()
    message("${cppAsIs_ENABLE_HARDENING} ${ENABLE_UBSAN_MINIMAL_RUNTIME} ${cppAsIs_ENABLE_SANITIZER_UNDEFINED}")
    cppAsIs_enable_hardening(cppAsIs_options ON ${ENABLE_UBSAN_MINIMAL_RUNTIME})
  endif()
endmacro()

macro(cppAsIs_local_options)
  if(PROJECT_IS_TOP_LEVEL)
    include(cmake/StandardProjectSettings.cmake)
  endif()

  add_library(cppAsIs_warnings INTERFACE)
  add_library(cppAsIs_options INTERFACE)

  include(cmake/CompilerWarnings.cmake)
  cppAsIs_set_project_warnings(
    cppAsIs_warnings
    ${cppAsIs_WARNINGS_AS_ERRORS}
    ""
    ""
    ""
    "")

  if(cppAsIs_ENABLE_USER_LINKER)
    include(cmake/Linker.cmake)
    configure_linker(cppAsIs_options)
  endif()

  include(cmake/Sanitizers.cmake)
  cppAsIs_enable_sanitizers(
    cppAsIs_options
    ${cppAsIs_ENABLE_SANITIZER_ADDRESS}
    ${cppAsIs_ENABLE_SANITIZER_LEAK}
    ${cppAsIs_ENABLE_SANITIZER_UNDEFINED}
    ${cppAsIs_ENABLE_SANITIZER_THREAD}
    ${cppAsIs_ENABLE_SANITIZER_MEMORY})

  set_target_properties(cppAsIs_options PROPERTIES UNITY_BUILD ${cppAsIs_ENABLE_UNITY_BUILD})

  if(cppAsIs_ENABLE_PCH)
    target_precompile_headers(
      cppAsIs_options
      INTERFACE
      <vector>
      <string>
      <utility>)
  endif()

  if(cppAsIs_ENABLE_CACHE)
    include(cmake/Cache.cmake)
    cppAsIs_enable_cache()
  endif()

  include(cmake/StaticAnalyzers.cmake)
  if(cppAsIs_ENABLE_CLANG_TIDY)
    cppAsIs_enable_clang_tidy(cppAsIs_options ${cppAsIs_WARNINGS_AS_ERRORS})
  endif()

  if(cppAsIs_ENABLE_CPPCHECK)
    cppAsIs_enable_cppcheck(${cppAsIs_WARNINGS_AS_ERRORS} "" # override cppcheck options
    )
  endif()

  if(cppAsIs_ENABLE_COVERAGE)
    include(cmake/Tests.cmake)
    cppAsIs_enable_coverage(cppAsIs_options)
  endif()

  if(cppAsIs_WARNINGS_AS_ERRORS)
    check_cxx_compiler_flag("-Wl,--fatal-warnings" LINKER_FATAL_WARNINGS)
    if(LINKER_FATAL_WARNINGS)
      # This is not working consistently, so disabling for now
      # target_link_options(cppAsIs_options INTERFACE -Wl,--fatal-warnings)
    endif()
  endif()

  if(cppAsIs_ENABLE_HARDENING AND NOT cppAsIs_ENABLE_GLOBAL_HARDENING)
    include(cmake/Hardening.cmake)
    if(NOT SUPPORTS_UBSAN 
       OR cppAsIs_ENABLE_SANITIZER_UNDEFINED
       OR cppAsIs_ENABLE_SANITIZER_ADDRESS
       OR cppAsIs_ENABLE_SANITIZER_THREAD
       OR cppAsIs_ENABLE_SANITIZER_LEAK)
      set(ENABLE_UBSAN_MINIMAL_RUNTIME FALSE)
    else()
      set(ENABLE_UBSAN_MINIMAL_RUNTIME TRUE)
    endif()
    cppAsIs_enable_hardening(cppAsIs_options OFF ${ENABLE_UBSAN_MINIMAL_RUNTIME})
  endif()

endmacro()
