# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/lagranj_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/lagranj_autogen.dir/ParseCache.txt"
  "lagranj_autogen"
  )
endif()
