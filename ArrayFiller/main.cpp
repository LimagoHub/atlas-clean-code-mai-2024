#include <iostream>
#include <climits>
#include <random>
#include <chrono>
#include <thread>

int feld[INT_MAX/8];

int main() {

    const size_t availableProcessors = std::thread::hardware_concurrency();

    std::cout << availableProcessors << std::endl;

    std::chrono::high_resolution_clock::time_point start_;
    std::chrono::high_resolution_clock::time_point end_;


    std::cout << "Start" << std::endl;
    start_ = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < INT_MAX/8; ++i) {
        feld[i] = std::rand();
    }
    end_ = std::chrono::high_resolution_clock::now();
    std::cout << "Duration " << std::chrono::duration_cast<std::chrono::milliseconds>(end_-start_).count() << std::endl;
    return 0;
}
