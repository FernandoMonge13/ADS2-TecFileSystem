//
// Created by camanem on 23/6/21.
//

#include "ControllerNode.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <unistd.h>
#include <QDebug>

ControllerNode::ControllerNode() {
    std::string path_owo = fs::current_path().c_str();
    for (int i = 0; i < 31; i++){
        path_owo.pop_back();
    }
    path_uwu = path_owo;
    std::ifstream openPort1;
    openPort1.open(path_uwu + "/TECFS-Disk/metadata2.txt");
    openPort1 >> blocks;
    openPort1 >> usedMemory;
    openPort1 >> parity_disk_turn;
    openPort1.close();

}

void ControllerNode::saveInRaid(std::string data) {

    // escribe el string del usuario en un txt



    std::ofstream ofs(path_uwu + "/TECFS-Disk/metadata.txt");
    if (ofs) {
        ofs << data << std::endl; // easy way, use the stream insertion operator   https://stackoverflow.com/questions/778378/how-to-write-bitset-data-to-a-file
    }

    // lee el txt y lo transforma en un vector de char
    std::ifstream input(path_uwu + "/TECFS-Disk/metadata.txt", std::ios::binary);
    std::vector<char> charVector((std::istreambuf_iterator<char>(input)),(std::istreambuf_iterator<char>()));
    charVector.pop_back();
    input.close();

    if (usedMemory+charVector.size() <= availableMemory){

        // Escritores de los bytes en los bloques
        std::ofstream writer_d0(path_uwu + "/TECFS-Disk/Disks/Disk 0/block " + std::to_string(blocks) + ".txt");
        std::ofstream writer_d1(path_uwu + "/TECFS-Disk/Disks/Disk 1/block " + std::to_string(blocks) + ".txt");
        std::ofstream writer_d2(path_uwu + "/TECFS-Disk/Disks/Disk 2/block " + std::to_string(blocks) + ".txt");

        // recorre cada char, lo tranforma en byte, lo divide y guarda junto con su paridad
        for (int i = 0; i < charVector.size(); i++) {

            std::bitset<8> charBytes(charVector.at(i));
            std::cout << "charBytes " << charBytes << std::endl;

            // divide el byte en bits
            std::bitset<4> charBytes1(0);
            charBytes1.set(3, charBytes[7]);
            charBytes1.set(2, charBytes[6]);
            charBytes1.set(1, charBytes[5]);
            charBytes1.set(0, charBytes[4]);

            std::bitset<4> charBytes2(0);
            charBytes2.set(3, charBytes[3]);
            charBytes2.set(2, charBytes[2]);
            charBytes2.set(1, charBytes[1]);
            charBytes2.set(0, charBytes[0]);

            std::bitset<4> charBytesParity = (charBytes1 ^ charBytes2);

            // se escribe un par de bits en un bloque de cada disco
            if (parity_disk_turn == 2){

                writer_d0 << charBytes1 << std::endl;
                writer_d1 << charBytes2 << std::endl;
                writer_d2 << charBytesParity << std::endl;
            }
            else if (parity_disk_turn == 1){
                writer_d0 << charBytes1 << std::endl;
                writer_d1 << charBytesParity << std::endl;
                writer_d2 << charBytes2  << std::endl;
            }
            else if(parity_disk_turn == 0){
                writer_d0 << charBytesParity << std::endl;
                writer_d1 << charBytes1 << std::endl;
                writer_d2 << charBytes2 << std::endl;
            }
        }
        // asigna al siguiente disco en el que se guardar?? la paridad
        if (parity_disk_turn == 2){

            parity_disk_turn--;
        }
        else if (parity_disk_turn == 1){

            parity_disk_turn--;
        }
        else if(parity_disk_turn == 0){

            parity_disk_turn = 2;
        }

        blocks++;
        usedMemory += charVector.size();
        std::cout << "usedMemory (bytes): " << usedMemory << std::endl;

        std::ofstream ofsBlock(path_uwu + "/TECFS-Disk/metadata2.txt");
        if (ofsBlock) {
            ofsBlock << blocks << std::endl;
            ofsBlock << usedMemory << std::endl;
            ofsBlock << parity_disk_turn;
        }
        ofsBlock.close();
    }else{
        qDebug() << "Espacio insuficiente, no se pudo cargar un archivo";
    }
}

std::string ControllerNode::loadFromRaid(std::string block) {


    // determinar el disco en que se est?? la paridad
    int iblock = std::stoi(block);
    int counter= 0;
    int paritydisk = 2;

    while (counter < iblock){
        if (paritydisk == 0){
            paritydisk = 2;
            counter++;
        }
        else{
            paritydisk--;
            counter++;
        }
    }

    // obtiene la informaci??n
    std::ifstream openPort1;
    std::ifstream openPort2;

    if (paritydisk == 2){

        openPort1.open(path_uwu + "/TECFS-Disk/Disks/Disk 0/block " + block + ".txt");
        openPort2.open(path_uwu + "/TECFS-Disk/Disks/Disk 1/block " + block + ".txt");
    }
    else if (paritydisk == 1){

        openPort1.open(path_uwu + "/TECFS-Disk/Disks/Disk 0/block " + block + ".txt");
        openPort2.open(path_uwu +"/TECFS-Disk/Disks/Disk 2/block " + block + ".txt");
    }
    else if (paritydisk == 0){

        openPort1.open(path_uwu + "/TECFS-Disk/Disks/Disk 1/block " + block + ".txt");
        openPort2.open(path_uwu + "/TECFS-Disk/Disks/Disk 2/block " + block + ".txt");
    }

    std::vector<std::bitset<8>> byteVector;
    int index = 0;
    // lee y une los bits
    while (!openPort1.eof()){
        std::bitset<8> charBytes(0);
        std::bitset<4> charBits(0);
        openPort1 >> charBits;
        charBytes.set(7, charBits[3]);
        charBytes.set(6, charBits[2]);
        charBytes.set(5, charBits[1]);
        charBytes.set(4, charBits[0]);
        byteVector.push_back(charBytes);
    }
    openPort1.close();
    byteVector.pop_back();
    std::ofstream ofs(path_uwu +  "/TECFS-Disk/metadata.txt");

    while (!openPort2.eof() && index < byteVector.size()){
        std::bitset<4> charBits(0);
        openPort2 >> charBits;
        byteVector.at(index).set(3, charBits[3]);
        byteVector.at(index).set(2, charBits[2]);
        byteVector.at(index).set(1, charBits[1]);
        byteVector.at(index).set(0, charBits[0]);

        // convierte y escribe bytes a char
        unsigned long i = byteVector.at(index).to_ulong();
        unsigned char c = static_cast<unsigned char>( i );
        if (ofs) {
            ofs << c;
        }

        index++;
    }
    openPort2.close();
    ofs.close();

    // lee la info  de metadata
    std::string data;
    openPort1.open(path_uwu + "/TECFS-Disk/metadata.txt");
    while (!openPort1.eof()){
        openPort1 >> data;
    }

    return data;
}

void ControllerNode::recoverData() {

    std::string pathDiskGood;
    std::string pathDiskGood2;
    std::string pathDiskToReconstruct;

    bool missingDisk = false;

    std::string uwu1 = path_uwu + "/TECFS-Disk/Disks/Disk 2";
    std::string uwu2 = path_uwu + "/TECFS-Disk/Disks/Disk 1";
    std::string uwu3 = path_uwu + "/TECFS-Disk/Disks/Disk 0";
    // Crea la carpeta de disco eliminado
    if (mkdir(uwu1.c_str(), 0777) != -1) {

        std::cout << "Directory created" << std::endl;
        pathDiskGood = path_uwu + "/TECFS-Disk/Disks/Disk 0/block ";
        pathDiskGood2 = path_uwu + "/TECFS-Disk/Disks/Disk 1/block ";
        pathDiskToReconstruct = path_uwu + "/TECFS-Disk/Disks/Disk 2/block ";
        missingDisk = true;
    }
    else if (mkdir(uwu2.c_str(), 0777) != -1){

        pathDiskGood = path_uwu + "/TECFS-Disk/Disks/Disk 0/block ";
        pathDiskGood2 = path_uwu + "/TECFS-Disk/Disks/Disk 2/block ";
        pathDiskToReconstruct = path_uwu + "/TECFS-Disk/Disks/Disk 1/block ";
        missingDisk = true;
    }
    else if (mkdir(uwu3.c_str(), 0777) != -1){

        pathDiskGood = path_uwu + "/TECFS-Disk/Disks/Disk 1/block ";
        pathDiskGood2 = path_uwu + "/TECFS-Disk/Disks/Disk 2/block ";
        pathDiskToReconstruct = path_uwu + "/TECFS-Disk/Disks/Disk 0/block ";
        missingDisk = true;
    }
    else {

        std::cerr << "Error :  " << strerror(errno) << std::endl;
        std::cout << "Ningun disco ha fallado, no es necesario recuperar informaci??n" << std::endl;
    }

    // reconstruye la info
    int actual_block = 0;
    while (actual_block < blocks && missingDisk) {

        std::vector<std::bitset<4>> bitsetVector;

        std::ifstream openPort1;
        openPort1.open( pathDiskGood + std::to_string(actual_block) + ".txt");

        // obtiene los bits de un bloque y los guarda en un vector
        while (!openPort1.eof()) {
            std::bitset<4> charBits(0);
            openPort1 >> charBits;
            bitsetVector.push_back(charBits);
        }
        bitsetVector.pop_back();
        openPort1.close();

        openPort1.open(pathDiskGood2 + std::to_string(actual_block) + ".txt");

        int index = 0;
        std::ofstream ofs(pathDiskToReconstruct + std::to_string(actual_block) + ".txt");
        while (!openPort1.eof() && index < bitsetVector.size()) {
            std::bitset<4> charBits(0);
            openPort1 >> charBits;

            std::bitset<4> xorBits(0);
            xorBits = (bitsetVector.at(index) ^ charBits);

            if (ofs) {
                ofs << xorBits << std::endl; // easy way, use the stream insertion operator   https://stackoverflow.com/questions/778378/how-to-write-bitset-data-to-a-file
            }
            index++;
        }
        ofs.close();
        openPort1.close();
        actual_block++;
    }
}

void ControllerNode::setBlocks(int _blocks) {
    ControllerNode::blocks = _blocks;
}

int ControllerNode::getBlocks() {
    return blocks;
}






//std::string path = "../TECFS-Disk/Disks/";
//    std::string path1 = "";
//    std::string path2 = "";
//
//    // obtiene las direcciones de los discos existentes
//    for (const auto & entry : fs::directory_iterator(path)){
//
//        if (path1 == ""){
//            path1 = entry.path();
//            std::cout << entry.path() << std::endl;
//        }
//        else{
//            path2 = entry.path();
//            std::cout << entry.path() << std::endl;
//        }
//    }