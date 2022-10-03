#include <chrono>
class nanosecond_timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> time;

public:
    void start() { time = std::chrono::high_resolution_clock::now(); }
    unsigned long long stop() {
        auto elapsed = std::chrono::high_resolution_clock::now() - time;
        return std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed)
            .count();
    }
};
