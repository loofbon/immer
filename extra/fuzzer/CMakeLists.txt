
add_custom_target(fuzzers
  COMMENT "Build all fuzzers.")

file(GLOB_RECURSE immer_fuzzers "*.cpp")
foreach(_file IN LISTS immer_fuzzers)
  immer_target_name_for(_target _output "${_file}")
  add_executable(${_target} EXCLUDE_FROM_ALL "${_file}")
  set_target_properties(${_target} PROPERTIES OUTPUT_NAME ${_output})
  target_compile_options(${_target} PUBLIC
    "-fsanitize-coverage=trace-pc-guard -fsanitize=address")
    target_link_libraries(${_target} PUBLIC Fuzzer)
  add_dependencies(fuzzers ${_target})
endforeach()
