//
// Created by fernando on 22/6/21.
//

#include "Browser.h"

Browser::Browser() {

}

void Browser::analyze(std::string metadata) {

    if (info.find(metadata) != std::string::npos){
        std::cout << "FOUNDED";
    }
    else{
        std::cout << "NO FOUNDED";
    }

}
