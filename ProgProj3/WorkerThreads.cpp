#include "WorkerThreads.h"
#include "Action.h"
#include "Config.h"
#include "Synchronization.h"

namespace Workers {

    void thread1Work() {
        for (int i = 1; i <= Config::SET_A; ++i) {
            executeAction("a", i);
        }

        Sync::upperNodeCounter.release();

        Sync::upperNodeCounter.acquire();
        Sync::upperNodeCounter.acquire();
        Sync::upperNodeReady.release();

        Sync::upperNodeReady.acquire();
        Sync::upperNodeReady.release();

        for (int i = 1; i <= Config::SET_G; ++i) {
            executeAction("g", i);
        }
    }

    void thread2Work() {
        for (int i = 1; i <= Config::SET_B; ++i) {
            executeAction("b", i);
        }

        Sync::middleNodeCounter.release();

        Sync::middleNodeCounter.acquire();
        Sync::middleNodeCounter.acquire();
        Sync::middleNodeReady.release();

        Sync::middleNodeReady.acquire();
        Sync::middleNodeReady.release();

        for (int i = 1; i <= Config::SET_H; ++i) {
            executeAction("h", i);
        }
    }

    void thread3Work() {
        for (int i = 1; i <= Config::SET_C; ++i) {
            executeAction("c", i);
        }

        Sync::upperNodeCounter.release();

        for (int i = 1; i <= Config::SET_D; ++i) {
            executeAction("d", i);
        }

        Sync::lowerNodeCounter.release();

        Sync::lowerNodeCounter.acquire();
        Sync::lowerNodeCounter.acquire();
        Sync::lowerNodeReady.release();

        Sync::lowerNodeReady.acquire();
        Sync::lowerNodeReady.release();

        for (int i = 1; i <= 4; ++i) {
            executeAction("j", i);
        }
    }

    void thread4Work() {
        for (int i = 1; i <= Config::SET_E; ++i) {
            executeAction("e", i);
        }

        Sync::middleNodeCounter.release();

        Sync::middleNodeReady.acquire();
        Sync::middleNodeReady.release();

        for (int i = 1; i <= Config::SET_I; ++i) {
            executeAction("i", i);
        }

        for (int i = 1; i <= Config::SET_F; ++i) {
            executeAction("f", i);
        }

        Sync::lowerNodeCounter.release();

        Sync::lowerNodeReady.acquire();
        Sync::lowerNodeReady.release();

        for (int i = 5; i <= Config::SET_J; ++i) {
            executeAction("j", i);
        }
    }

}