//
// Created by zygisau on 01/04/2019.
//

#ifndef DUOMENU_APDOROJIMAS_TIMER_H
#define DUOMENU_APDOROJIMAS_TIMER_H

#include "../../includes.h"

// Klasė, matuojanti laiką
class Timer { // paimta iš https://github.com/objprog/paskaitos2019/wiki/Laiko-matavimas
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
    Timer() : start{std::chrono::high_resolution_clock::now()} {}
    void reset() {
        start = std::chrono::high_resolution_clock::now();
    }
    double elapsed() const {
        return std::chrono::duration<double>
                (std::chrono::high_resolution_clock::now() - start).count();
    }
};


#endif //DUOMENU_APDOROJIMAS_TIMER_H
