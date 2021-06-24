//
// Created by marco on 23/6/21.
//

#ifndef VENTANAFINAL_CLIENT_H
#define VENTANAFINAL_CLIENT_H

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include "Parser.h"



class Client {
private:
    char buf[4096];
    static QJsonDocument recibido;
public:

    /*!
     * @brief Getter para la informacion que se obtiene del socket
     * @return QJsonDocument
     */
    static QJsonDocument getReceived();

public:

    /*!
     * @brief Se encarga de levantar el socket y realizar la recepcion/envio de mensajes
     */
    void Start();
};




#endif //VENTANAFINAL_CLIENT_H
