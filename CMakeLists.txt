cmake_minimum_required(VERSION 3.13)
project(Duomenu_apdorojimas)

set(CMAKE_CXX_STANDARD 14)

add_executable(Duomenu_apdorojimas
        source_vektoriai.cpp classes/Student/Student.cpp classes/Student/Student.h classes/Timer/Timer.h menu.cpp menu.h functions.cpp functions.h classes/Human/Human.cpp classes/Human/Human.h)

add_executable(Duomenu_apdorojimas_masyvai
        source_masyvai.cpp classes/Student/Student.cpp classes/Student/Student.h classes/Timer/Timer.h menu.cpp menu.h functions.cpp functions.h classes/Human/Human.cpp classes/Human/Human.h)