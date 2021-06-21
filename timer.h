#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <cstring>

class Timer {
private:
    char *label;
    std::chrono::time_point<std::chrono::_V2::system_clock> start;
    std::chrono::time_point<std::chrono::_V2::system_clock> stop;
    std::chrono::duration<long long, std::ratio<1, 1000>> duration{};
public:
    explicit Timer(const char *function_name) {
        label = new char[strlen(function_name) + 1];
        strcpy(label, function_name);
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer() {
        stop = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast <std::chrono::milliseconds > (stop - start);
        if (duration.count() > 0) {
            std::cout << "\n" << label << " function lasted " << (double)duration.count()/1000 << " seconds\n";
        }
    }
};


#endif //TIMER_H
