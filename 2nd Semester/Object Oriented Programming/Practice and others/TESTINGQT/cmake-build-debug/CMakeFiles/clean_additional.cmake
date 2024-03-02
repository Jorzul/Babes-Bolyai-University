# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TESTINGQT_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TESTINGQT_autogen.dir\\ParseCache.txt"
  "TESTINGQT_autogen"
  )
endif()
