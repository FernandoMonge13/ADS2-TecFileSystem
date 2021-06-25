//
// Created by marco on 23/6/21.
//

#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include "../VentanaFinal/mainwindow.h"
#include "Client.h"
#include <QDebug>
#include <unistd.h>

QJsonDocument Client::recibido = QJsonDocument();

void Client::Start() {
    int sock= socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    inet_pton(AF_INET, "127.0.0.1", &hint.sin_addr);

    int connectRes = connect(sock, (sockaddr*)&hint, sizeof(hint));

    while (true){
        QJsonDocument doc= Parser::ReturnJson(MainWindow::getJson().c_str()); //Genera el documento con los rasgos de dentro
        //qDebug()<<MainWindow::getJson().c_str();
        std::string prueba= Parser::ReturnChar(doc); //String to char (to be able to send it through sockets) //Lo pasa a string
        int sendRes = send(sock, prueba.c_str(), prueba.size() + 1, 0);

        memset(this->buf, 0, 4096);
        int bytesReceived = recv(sock, this->buf, 4096, 0);

        if (bytesReceived != -1){
            recibido = Parser::ReturnJsonFromStr(std::string(this->buf, bytesReceived));
            break;
        }
    }
    close(sock);
}

QJsonDocument Client::getReceived() {
    return recibido;
}
