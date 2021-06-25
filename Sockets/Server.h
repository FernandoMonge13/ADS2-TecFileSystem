//
// Created by marco on 23/6/21.
//

#ifndef VENTANAFINAL_SERVER_H
#define VENTANAFINAL_SERVER_H

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include "Parser.h"
#include "../TECFS-Disk/ControllerNode.h"
#include "../Browser/Browser.h"


class Server {
private:
    char buf[4096];
    ControllerNode Controller = ControllerNode();
    Browser browser = Browser();

public:

    /*!
     * @brief Se encarga de levantar el servidor el cual estara acargo del el manejo de la memoria
     */
    void Start();
};



#endif //VENTANAFINAL_SERVER_H
