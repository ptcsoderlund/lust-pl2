file(GLOB_RECURSE PL_SOURCES CONFIGURE_DEPENDS src/*.c)
add_executable(pl2 ${PL_SOURCES})

target_include_directories(pl2 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
