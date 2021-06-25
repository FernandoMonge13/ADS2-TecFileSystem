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

    /**
     * @brief analyze if a string is inside other
     * @param metadata is the info that is gonna be searched
     * @return if the info was founded
     */
    bool analyze(std::string metadata);

    /**
     * @brief set the info where the program is gonna search
     * @param info where we are gonna search
     */
    void setInfo(const std::string &info);



private:


    std::string info;

};


#endif //ADS2_TECFILESYSTEM_BROWSER_H
