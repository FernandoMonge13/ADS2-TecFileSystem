//
// Created by fernando on 22/6/21.
//

#include "Browser.h"
#include "../Huffman/Huffman.h"
#include <qdebug.h>

#include <utility>

Browser::Browser() {

}

bool Browser::analyze(std::string metadata) {

    if (info.find(metadata) != std::string::npos){
        std::cout << "FOUNDED";
        return true;
    }
    else{
        std::cout << "NO FOUNDED";
        return false;
    }

}

void Browser::setInfo(const std::string &info) {
    Browser::info = info;
}

