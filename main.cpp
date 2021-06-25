#include <iostream>
#include "TECFS-Disk/ControllerNode.h"

int main() {
    ControllerNode controllerNode = ControllerNode();
    controllerNode.setBlocks(2);
//    controllerNode.saveInRaid("hi");
//    controllerNode.saveInRaid("hi2");


    controllerNode.recoverData();
//    std::cout << controllerNode.loadFromRaid("0") << std::endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
