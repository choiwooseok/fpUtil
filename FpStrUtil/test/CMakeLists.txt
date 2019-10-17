cmake_minimum_required(VERSION 2.6)

project(FPSTRUNITTESTS)

ENABLE_TESTING()

################################
# UNIT TESTS
################################
SET(FPSTRUNITTESTS_SRC
    UtilTest.cpp
)
ADD_EXECUTABLE(utilTest ${FPSTRUNITTESTS_SRC})
TARGET_LINK_LIBRARIES(utilTest
    gtest
    gtest_main
)

INSTALL(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../build/inc/ 
    FILES_MATCHING PATTERN "*.h*"
)
