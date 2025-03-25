include_directories(commands)

file(GLOB_RECURSE FILENAMES *.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(LV-MAGIC LV-MAGIC.cpp ${FILENAMES})
target_link_libraries(LV-MAGIC alice)
