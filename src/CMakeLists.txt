cmake_minimum_required(VERSION 3.0)
project(network-sniffer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)



file(GLOB ALL_SOURCES
    "*.cpp")
file(GLOB ALL_HEADERS
    "*.h")


include_directories(../basestruct) # 搜索头文件位置
include_directories(../3rdpart/)
# include_directories(kafka)
link_directories(${PROJECT_BINARY_DIR}) # 搜索库位置
#:TODO 此处需要修改引入第三方项目方式 待修改
message(STATUS "1111111111111"  ${PROJECT_BINARY_DIR})
link_directories(${PROJECT_BINARY_DIR}/../3rdpart/PublisherCode/lib)

add_executable(${PROJECT_NAME} ${ALL_SOURCES} ${ALL_HEADERS})

set(LINK_LISTS basestruct
               publicCode
               pcap
               net
               gthread-2.0
               nids
               )
#target_link_libraries(${PROJECT_NAME}  basestruct)
#target_link_libraries(${PROJECT_NAME}  publicCode)
#target_link_libraries(${PROJECT_NAME}  pcap)
#target_link_libraries(${PROJECT_NAME}  net)
#target_link_libraries(${PROJECT_NAME}  pthread)
#target_link_libraries(${PROJECT_NAME}  nids)
#target_link_libraries(${PROJECT_NAME}  gthread-2.0)

target_link_libraries(${PROJECT_NAME}  ${LINK_LISTS})
set(CMAKE_INSTALL_PREFIX "/usr" CACHE PATH "Install path prefix" FORCE)
# Install files
install(TARGETS ${PROJECT_NAME} DESTINATION bin/)


