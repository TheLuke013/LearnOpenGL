cmake_minimum_required (VERSION 3.8)

set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)

project ("LearnOpenGL")

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_definitions(-DGLEW_STATIC)

add_executable (${CMAKE_PROJECT_NAME})

set(RES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/res")

add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${RES_DIR}
    $<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>/res
)

set_property(TARGET "${CMAKE_PROJECT_NAME}" PROPERTY CXX_STANDARD 17)

target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${SOURCE_FILES})

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE 
    "ThirdParty/glfw/include"
    "ThirdParty/glew/include"
    "ThirdParty/stb")

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty/glfw/lib/glfw3.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty/glew/lib/glew32s.lib
    opengl32.lib
)
