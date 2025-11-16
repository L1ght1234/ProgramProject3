#include "Action.h"
#include <iostream>
#include <syncstream>

void executeAction(const std::string& set_name, int action_num) {
    std::osyncstream(std::cout)
        << "Action " << action_num
        << " from set " << set_name
        << " completed." << std::endl;
}