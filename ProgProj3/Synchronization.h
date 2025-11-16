#pragma once

#include <semaphore>

namespace Sync {
    inline std::binary_semaphore upperNodeReady(0);
    inline std::binary_semaphore middleNodeReady(0);
    inline std::binary_semaphore lowerNodeReady(0);

    inline std::counting_semaphore<2> upperNodeCounter(0);
    inline std::counting_semaphore<2> middleNodeCounter(0);
    inline std::counting_semaphore<2> lowerNodeCounter(0);
}