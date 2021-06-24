#include <iostream>
#include "TECFS-Disk/ControllerNode.h"

int main() {
    ControllerNode controllerNode = ControllerNode();
    controllerNode.setBlocks(2);
//    controllerNode.saveInRaid("hi");
//    controllerNode.saveInRaid("hi2");

//    std::string path1 = "../TECFS-Disk/Disks/Disk 0";
//    std::string path2 = "../TECFS-Disk/Disks/Disk 1";
//
//    controllerNode.recoverData(path1, path2, "2");
    std::cout << controllerNode.loadFromRaid("0") << std::endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
