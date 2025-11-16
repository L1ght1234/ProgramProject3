#include <iostream>
#include <thread>
#include <syncstream>
#include "Config.h"
#include "WorkerThreads.h"

int main() {
    std::osyncstream(std::cout) << "Computation started." << std::endl;

    std::thread t1(Workers::thread1Work);
    std::thread t2(Workers::thread2Work);
    std::thread t3(Workers::thread3Work);
    std::thread t4(Workers::thread4Work);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::osyncstream(std::cout) << "Computation finished." << std::endl;

    return 0;
}