cmake_minimum_required(VERSION 3.22)
project(js_runtime_2)

set(CMAKE_CXX_STANDARD 23)

add_executable(js_runtime_2 main.cpp src/expression.h src/statement.h src/JsType.h src/statement/Function.h src/statement/Assign.h src/statement/Branch.h src/Machine.h src/body.h src/statement/Branch.cpp src/statement/Assign.cpp src/body.cpp src/statement/Function.cpp src/expression.cpp src/Lexer.h src/statement.cpp)
