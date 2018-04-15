if (WIN32)
    cmake_minimum_required(VERSION 3.10)
    project(topicosI)

    set(CMAKE_CXX_STANDARD 11)
    #set(SOURCE_FILES main.cpp)

    add_executable(topicosI main.cpp Comment.cpp Comment.h File.cpp File.h Command.cpp Command.h Element.cpp Element.h
            Constants.h Object.cpp Object.h)
endif (WIN32)

if (UNIX)
    cmake_minimum_required(VERSION 3.10)
    project(topicosI)
    set(CMAKE_CXX_STANDARD 11)
    add_executable(topicosI main.cpp Comment.cpp Comment.h File.cpp File.h Command.cpp Command.h Element.cpp Element.h
            Constants.h)
endif(UNIX)