# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles/coretime_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/coretime_autogen.dir/ParseCache.txt"
  "coretime_autogen"
  )
endif()
