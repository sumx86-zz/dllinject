cmake_minimum_required(VERSION 3.10)

# set the project name
project(dllinject VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_definitions(-DDEBUG=1) # comment this line if you dont want the DEBUG option enabled

#add_definitions(-DDLLINJECT_CREATE_REMOTE_THREAD=1) # comment this line if you want to use NtCreateThreadEx
add_definitions(-DDLLINJECT_NT_CREATE_THREAD_EX=1)  # comment this line if you want to use CreateRemoteThread

# add the executable
add_executable(${PROJECT_NAME} src/main.cpp src/injector.cpp src/pe_parser.cpp src/injector.h src/pe_parser.h )
