# lib name
set(LIB_NAME "anfis-lib")

# configure library structure
set(LIB_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(LIB_SRC_PATH "${LIB_MODULE_PATH}/source")
set(LIB_INCLUDE_PATH "${LIB_MODULE_PATH}/include")

# bring sources/headers into scope
add_subdirectory(${LIB_SRC_PATH})
add_subdirectory(${LIB_INCLUDE_PATH})

# define library
add_library(${LIB_NAME} STATIC ${sources} ${headers})

# Adding include path as library property
# makes target_link_library bring aformentioned path into target scope
target_include_directories(${LIB_NAME} PUBLIC ${LIB_INCLUDE_PATH})