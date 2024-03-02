# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\e914-Jorzul_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\e914-Jorzul_autogen.dir\\ParseCache.txt"
  "e914-Jorzul_autogen"
  )
endif()
