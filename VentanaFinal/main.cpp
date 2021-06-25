#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <iostream>
#include "../Sockets/Client.h"
#include "../Sockets/Server.h"
#include "../Sockets/Parser.h"

int main(int argc, char *argv[]) {



    int aux;
    std::cout << "1 para server, 2 para cliente" << std::endl;
    std::cin >> aux;

    if (aux == 1) {


        Server *test = new Server;
        test->Start();


    } else if (aux == 2) {
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        return a.exec();
    }
}