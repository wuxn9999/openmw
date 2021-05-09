if (OPENMW_USE_SYSTEM_GOOGLETEST)
    find_package(GTest 1.10 REQUIRED)
    find_package(GMock 1.10 REQUIRED)

    include_directories(SYSTEM ${GTEST_INCLUDE_DIRS})
    include_directories(SYSTEM ${GMOCK_INCLUDE_DIRS})
else()
    cmake_minimum_required(VERSION 3.11)

    include(FetchContent)

    set(SAVED_CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

    string(REPLACE "-Wundef" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

    set(gtest_force_shared_crt ON)

    FetchContent_Declare(googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.10.0.zip
        URL_HASH MD5=82358affdd7ab94854c8ee73a180fc53
        SOURCE_DIR fetched/googletest
    )

    FetchContent_MakeAvailableExcludeFromAll(googletest)

    set(CMAKE_CXX_FLAGS "${SAVED_CMAKE_CXX_FLAGS}")
    set(GMOCK_LIBRARIES gmock)
endif()

file(GLOB UNITTEST_SRC_FILES
    ../openmw/mwworld/store.cpp
    ../openmw/mwworld/esmstore.cpp
    mwworld/test_store.cpp

    mwdialogue/test_keywordsearch.cpp

    esm/test_fixed_string.cpp
    esm/variant.cpp

    misc/test_stringops.cpp
    misc/test_endianness.cpp

    nifloader/testbulletnifloader.cpp

    detournavigator/navigator.cpp
    detournavigator/settingsutils.cpp
    detournavigator/recastmeshbuilder.cpp
    detournavigator/gettilespositions.cpp
    detournavigator/recastmeshobject.cpp
    detournavigator/navmeshtilescache.cpp
    detournavigator/tilecachedrecastmeshmanager.cpp

    settings/parser.cpp

    shader/parsedefines.cpp
    shader/parsefors.cpp
    shader/shadermanager.cpp
)

source_group(apps\\openmw_test_suite FILES openmw_test_suite.cpp ${UNITTEST_SRC_FILES})

openmw_add_executable(openmw_test_suite openmw_test_suite.cpp ${UNITTEST_SRC_FILES})

target_link_libraries(openmw_test_suite ${GMOCK_LIBRARIES} components)
# Fix for not visible pthreads functions for linker with glibc 2.15
if (UNIX AND NOT APPLE)
    target_link_libraries(openmw_test_suite ${CMAKE_THREAD_LIBS_INIT})
endif()

if (BUILD_WITH_CODE_COVERAGE)
    add_definitions(--coverage)
    target_link_libraries(openmw_test_suite gcov)
endif()
