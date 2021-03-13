#include <chrono>

class Timer {
    std::chrono::time_point<std::chrono::system_clock> cur;
    std::chrono::duration<double> elap;
public:
    Timer() : cur(), elap(std::chrono::duration<double>::zero()) {}

    void start() {
        cur = std::chrono::system_clock::now();
    }
    void stop() {
        elap += std::chrono::system_clock::now() - cur;
    }
    void reset() {
        elap = std::chrono::duration<double>::zero();
    }
    double seconds() {
        return elap.count();
    }
};