//
// Created by camanem on 23/6/21.
//

#ifndef ADS2_TECFILESYSTEM_CONTROLLERNODE_H
#define ADS2_TECFILESYSTEM_CONTROLLERNODE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <string>
#include <filesystem>
#include <bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>

namespace fs = std::filesystem;

class ControllerNode {

private:

    int blocks = 0;
public:
    void setBlocks(int _blocks);
    int getBlocks();

private:
    int usedMemory = 0;
    int availableMemory = 150;
    int parity_disk_turn = 2;
    std::string path_uwu;

public:

    /**
     * @brief es el constructor por defecto de la clase
     */
    ControllerNode();

    /**
     * Convierte la información a bytes y la guarda en el Raid
     * @param data  es la información que se desea guardar
     */
    void saveInRaid(std::string data);

    /**
     * @brief carga un archivo desde el Raid a su forma original
     * @param block
     * @return la informacion
     */
    std::string loadFromRaid(std::string block);

    /**
     * @brief Reconstruye la información cuando 1 o 2 discos se han eliminado
     */
    void recoverData();
};


#endif //ADS2_TECFILESYSTEM_CONTROLLERNODE_H
