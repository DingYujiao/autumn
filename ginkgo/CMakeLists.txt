## 银杏是秋天的主题之一
message(STATUS "build ginkgo start!")

# 查找当前目录下的所有源文件
aux_source_directory(. DIR_SRCS)

#添加共有头文件
include_directories(../include)

add_library(ginkgo  ${DIR_SRCS})

message(STATUS "build ginkgo end!")