set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
file(GLOB HEADER_FILES ${PROJECT_SOURCE_DIR}/include/Model/*.h)
file(GLOB CPP_FILES *.cpp)
add_library(ModelData ${HEADER_FILES} ${CPP_FILES})
