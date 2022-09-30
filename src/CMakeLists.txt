set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB ALL_SOURCES
    "*.cpp")
file(GLOB ALL_HEADERS
    "*.h")

add_executable(${PROJECT_NAME} ${ALL_SOURCES} ${ALL_HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC ../basestruct) # 搜索头文件位置
target_include_directories(${PROJECT_NAME} PUBLIC ../3rdpart/publicCode/src)
# include_directories(kafka)
target_link_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR}/lib) # 搜索库位置
#:TODO 此处需要修改引入第三方项目方式 待修改
target_link_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR}/3rdpart/publicCode/lib)
message(STATUS "PROJECT_BINARY_DIR" ${PROJECT_BINARY_DIR})


set(LINK_LISTS basestruct
               publicCode
               pcap
               net
               gthread-2.0
               nids
               )

target_link_libraries(${PROJECT_NAME}  ${LINK_LISTS})
set(CMAKE_INSTALL_PREFIX "/usr" CACHE PATH "Install path prefix" FORCE)
# Install files
install(TARGETS ${PROJECT_NAME} DESTINATION bin/)


