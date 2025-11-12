# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/dtf_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/dtf_autogen.dir/ParseCache.txt"
  "dtf_autogen"
  )
endif()
