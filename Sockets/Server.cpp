//
// Created by marco on 23/6/21.
//

#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QDebug>
#include <sstream>
#include "Server.h"
#include <string>
#include <iostream>
#include <QFile>
#include "../Huffman/Huffman.h"
#include "../TECFS-Disk/ControllerNode.h"
#include <iostream>
#include <fstream>
#include <string>

void Server::Start() {
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

    bind(listening, (sockaddr*)&hint, sizeof(hint));

    listen(listening, SOMAXCONN);

    sockaddr_in client;
    socklen_t clientSize = sizeof(client);

    int clientSockect = accept(listening, (sockaddr*)&client, &clientSize);

    char host[NI_MAXHOST];
    char service[NI_MAXSERV];

    memset(host, 0, NI_MAXHOST);
    memset(service, 0, NI_MAXSERV);

    close(listening);
    while (true){
        memset(this->buf, 0, 4096);

        int bytesReceived = recv(clientSockect, this->buf, 4096, 0);
        if (bytesReceived == -1){
            std::cerr << "Error in recv(). Quitting" << std::endl;
            break;
        }

        if (bytesReceived == 0){
            std::cout << "Client disconnected " << std::endl;
            close(clientSockect);
            this->Start();
            break;
        }
        QJsonDocument doc = Parser::ReturnJson(std::string(this->buf, 0, bytesReceived).c_str()); //Devolver lo que llego por el socket a json

        QJsonDocument toReturn; //objeto al que setearle lo que se va a devolver
        //toReturn.setObject(Parser::CreateJsonObj_ReturnsData(value)); esto va dentro de cada uno de los ifs con el respectivo metodo de parser

        //if (Parser::ReturnStringValueFromJson(doc, "variable a comparar") == "valor de la variable")
        if (Parser::ReturnStringValueFromJson(doc, "toDo") == "nothing") {
            toReturn.setObject(Parser::Nothing());
        } else if (Parser::ReturnStringValueFromJson(doc, "toDo") == "decodeHuffman") {

            std::string binary = Parser::ReturnStringValueFromJson(doc, "huffman");
            std::string strToReturn = "";

            Controller.recoverData();
            for (int i = 0; i < Controller.getBlocks(); i++){
                std::string toCompare = Controller.loadFromRaid(std::to_string(i));
                browser.setInfo(toCompare);
                if (browser.analyze(binary)){
                    strToReturn.append("Encontrado en el bloque " + std::to_string(i) + ":" + "\n" + toCompare + "\n\n");
                }
            }

            toReturn.setObject(Parser::ToShow(strToReturn));
        } else if (Parser::ReturnStringValueFromJson(doc, "toDo") == "Search") {
            std::string path = Parser::ReturnStringValueFromJson(doc, "huffman");



            //std::string path = Huffman::getInstance()->decode(binary);
            Controller.recoverData();
            for (const auto & entry : fs::directory_iterator(path)) {
                if (entry.path().u8string().find(".txt") != std::string::npos){
                    std::ifstream file (entry.path());
                    std::string content( (std::istreambuf_iterator<char>(file) ),
                                          (std::istreambuf_iterator<char>()    ) );

                    Controller.saveInRaid(content);
                }
            }


            //qDebug()<<"esta mrd ya no esta sirviendo";
            toReturn.setObject(Parser::Nothing());
        }
        //aqui van las condiciones para entender lo que entra

        qDebug()<<"arriba";
        qDebug()<<Parser::ReturnChar(toReturn).c_str();
        qDebug()<<"abajo";
        send(clientSockect, Parser::ReturnChar(toReturn).c_str(), Parser::ReturnChar(toReturn).size() + 1, 0);
    }
    close(clientSockect);

}