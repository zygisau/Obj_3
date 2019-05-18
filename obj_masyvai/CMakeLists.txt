cmake_minimum_required(VERSION 3.13)
project(Duomenu_apdorojimas_masyvai)

set(CMAKE_CXX_STANDARD 14)

add_executable(Duomenu_apdorojimas_masyvai
        source_masyvai.cpp ../src/classes/Student/Student.cpp ../src/classes/Student/Student.h ../src/classes/Timer/Timer.h ../src/menu.cpp ../src/menu.h ../src/functions.cpp ../src/functions.h ../src/classes/Human/Human.cpp ../src/classes/Human/Human.h)