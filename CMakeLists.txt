cmake_minimum_required(VERSION 3.0)
project(network-sniffer)

option(DOTEST "option for test" OFF)
# 是否开启单元测试编译
set(DOTEST ON)

#compile flags
if (CMAKE_BUILD_TYPE MATCHES Debug)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -Wextra")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra")
  # Enable Qt builtin debug mode
  add_definitions("-DQT_MESSAGELOGCONTEXT")
else()
  # -Wl, -O2 Enable linker optimizations
  # -Wl, --gc-sections Remove unused code resulting from -fdsta-sections and
  # -ffunction-sections
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O2 -Wl,--gc-sections")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2 -Wl,--gc-sections")
endif()

# 检查内存泄漏代码
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -fsanitize=address -O2")
#set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fsanitize=address -O2")
#set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -g -fsanitize=address -O2")
#set(CMAKE_C_FLAGS_MINSIZEREL "${CMAKE_C_FLAGS_MINSIZEREL} -g -fsanitize=address -O2")
#set(CMAKE_C_FLAGS_RELWITHDEBINFO "${CMAKE_C_FLAGS_RELWITHDEBINFO} -g -fsanitize=address -O2")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fsanitize=address -O2")
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address -O2")
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -g -fsanitize=address -O2")
#set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} -g -fsanitize=address -O2")
#set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO}  -g -fsanitize=address -O2")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fstack-protector-all -z relro -z now -z noexecstack -pie")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fstack-protector-all -z relro -z now -z noexecstack -pie")


#设置库文件路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
#设置可执行程序路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_subdirectory(basestruct)
add_subdirectory(3rdpart)
add_subdirectory(src)

# 开启单元测试
if(DOTEST)
    # 添加gocv覆盖率文件的输出
    # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fprofile-arcs -ftest-coverage")
    # 设置测试模块
    # set(QT Core Gui Widgets Network DBus Sql LinguistTools Svg Multimedia Test)
    # find_package(Qt5 COMPONENTS ${QT} REQUIRED)
    # 添加子模块test
    add_subdirectory(tests)
endif()

