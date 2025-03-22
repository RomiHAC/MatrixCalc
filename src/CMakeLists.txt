file (GLOB_RECURSE MY_SOURCE_FILES CONFIGURE_DEPENDS LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_LIST_DIR} *.cpp)
target_sources (${CMAKE_PROJECT_NAME} PRIVATE ${MY_SOURCE_FILES} "../include/SquareMatrix.h" "SquareMartix.cpp" "../include/Help.h" "Help.cpp" "../include/Operation.h" "../include/Id.h" "Id.cpp" "../include/SubOperation.h" "SubOperation.cpp" "CompOperation.cpp")
