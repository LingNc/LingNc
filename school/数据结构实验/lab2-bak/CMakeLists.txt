# CMake最低版本要求
cmake_minimum_required(VERSION 3.12)

# 项目名称和版本
project(HuffmanCoding VERSION 1.0.0 LANGUAGES C)

# 设置C标准
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 编译器特定设置
if(MSVC)
    # Visual Studio编译器设置
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /W3")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /Od /Zi")
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /O2")

    # 对于MSVC，我们需要一些额外的定义
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)
else()
    # GCC/Clang编译器设置
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g")
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O2")

    # 检查是否支持gnu99扩展
    include(CheckCCompilerFlag)
    check_c_compiler_flag("-std=gnu99" COMPILER_SUPPORTS_GNU99)
    if(COMPILER_SUPPORTS_GNU99)
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu99")
    else()
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
        message(WARNING "编译器不支持gnu99扩展，回退到c99标准")
    endif()
endif()

# 包含目录
include_directories(include)

# 定义源文件
set(LIBRARY_SOURCES
    src/exception.c
    src/hdfile.c
    src/heap.c
    src/huffcode.c
    src/huffman.c
    src/interface.c
    src/pair.c
    src/sqlist.c
    src/tools.c
)

# 定义头文件
set(LIBRARY_HEADERS
    include/any.h
    include/exception.h
    include/hdfile.h
    include/heap.h
    include/huffcode.h
    include/huffman.h
    include/interface.h
    include/pair.h
    include/sqlist.h
    include/tools.h
)

# 创建静态库
add_library(huffman_lib STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})

# 为库设置包含目录
target_include_directories(huffman_lib PUBLIC include)

# 主程序
add_executable(huffman_main main.c)
target_link_libraries(huffman_main huffman_lib)

# 数学库链接（在Unix系统上）
if(UNIX)
    target_link_libraries(huffman_main m)
endif()

# 设置输出目录
set_target_properties(huffman_main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

set_target_properties(huffman_lib PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

# 测试程序已移除，仅保留主程序构建

# 安装规则
install(TARGETS huffman_main huffman_lib
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

install(FILES ${LIBRARY_HEADERS}
    DESTINATION include
)

# 创建测试数据目录的复制规则
file(GLOB TEST_DATA_FILES "testdata/*")
foreach(TEST_FILE ${TEST_DATA_FILES})
    configure_file(${TEST_FILE} ${CMAKE_BINARY_DIR}/testdata/ COPYONLY)
endforeach()

# 包配置（可选，用于让其他项目引用此库）
# 如果需要可以取消注释以下部分
# include(CMakePackageConfigHelpers)
# write_basic_package_version_file(
#     HuffmanCodingConfigVersion.cmake
#     VERSION ${PROJECT_VERSION}
#     COMPATIBILITY AnyNewerVersion
# )

# 打印配置信息
message(STATUS "=== 哈夫曼编码项目配置 ===")
message(STATUS "项目名称: ${PROJECT_NAME}")
message(STATUS "项目版本: ${PROJECT_VERSION}")
message(STATUS "C编译器: ${CMAKE_C_COMPILER}")
message(STATUS "C标准: C${CMAKE_C_STANDARD}")
message(STATUS "构建类型: ${CMAKE_BUILD_TYPE}")
message(STATUS "主程序: huffman_main")

if(WIN32)
    message(STATUS "平台: Windows")
    message(STATUS "注意: 在Windows上，请确保使用UTF-8编码的控制台")
elseif(UNIX)
    message(STATUS "平台: Unix/Linux")
endif()

message(STATUS "========================")

# 添加自定义目标用于清理
add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/bin
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/lib
    COMMENT "清理所有生成的文件"
)
