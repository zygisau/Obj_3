project(code)

set(SRC_FILES
        ../source_vektoriai.cpp
        ./classes/Student/Student.cpp
        ./classes/Student/Student.h
        ./classes/Timer/Timer.h
        menu.cpp
        menu.h
        functions.cpp
        functions.h
        ./classes/Human/Human.cpp
        ./classes/Human/Human.h
        )

add_library(src STATIC ${SRC_FILES})