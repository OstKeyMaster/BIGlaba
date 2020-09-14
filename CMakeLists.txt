cmake_minimum_required(VERSION 3.15)
project(BIGlaba)

set(CMAKE_CXX_STANDARD 20)

add_executable(BIGlaba main.cpp Stroka.h ID_Stroka.h Dec_Stroka.h Stroka.cpp ID_Stroka.cpp Dec_Stroka.cpp)
