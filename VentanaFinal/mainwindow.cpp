#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include "../Sockets/Parser.h"

std::string MainWindow::json = "";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("APLICATION");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //boton abrir
    QFile file;
     QTextStream io;

     QString filePath = QFileDialog::getOpenFileName(this, "Open Directory");

     QDir d = QFileInfo(filePath).dir(); //hay que seleccionar uno de los archivos dentro de la carpeta
     QString absolute=d.path();

     qDebug()<< absolute; //absolute es el pto path a la carpeta del archivo seleccionado

     file.close();

    doc.setObject(Parser::Nothing());
    std::string json = Parser::ReturnChar(doc);
    MainWindow::setJson(json);
    client->Start();
}


void MainWindow::on_pushButton_2_clicked()
{
    QString test = ui->textBox->toPlainText(); //qstring para obtener lo que hay en la mrd
    qDebug()<<test;
    //boton buscar

    doc.setObject(Parser::Nothing());
    std::string json = Parser::ReturnChar(doc);
    MainWindow::setJson(json);
    client->Start();
}

std::string MainWindow::getJson() {
    return json;
}

void MainWindow::setJson(std::string toSet) {
    json = toSet;
}