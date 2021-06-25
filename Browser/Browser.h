//
// Created by fernando on 22/6/21.
//

#ifndef ADS2_TECFILESYSTEM_BROWSER_H
#define ADS2_TECFILESYSTEM_BROWSER_H

#include <iostream>
#include <string>
#include "../TECFS-Disk/ControllerNode.h"

class Browser {

public:

    Browser();
    bool analyze(std::string metadata);

    void setInfo(const std::string &info);



private:


    std::string info;

};


#endif //ADS2_TECFILESYSTEM_BROWSER_H
