//
// Created by marco on 23/6/21.
//

#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include "Parser.h"

QJsonObject Parser::Nothing(){
    QJsonObject obj;
    obj["toDo"] = "nothing";
    return obj;
}

QJsonObject Parser::Huffman(std::string binary) {
    QJsonObject obj;
    obj["toDo"] = "decodeHuffman";
    obj["huffman"] = binary.c_str();
    return obj;
}

QJsonObject Parser::Path(std::string binary) {
    QJsonObject obj;
    obj["toDo"] = "Search";
    obj["huffman"] = binary.c_str();
    return obj;
}

QJsonObject Parser::ToShow(std::string text) {
    QJsonObject obj;
    obj["toDo"] = "toShow";
    obj["text"] = text.c_str();
    return obj;
}

std::string Parser::ReturnChar(QJsonDocument document){
    QString strJson(document.toJson(QJsonDocument::Compact)); //QJsonDocument to QString
    std::string str =  strJson.toUtf8().constData(); //QString to string
    return str; //String to char (to be able to send it through sockets)
}
//
std::string Parser::ReturnStringValueFromJson(QJsonDocument document, std::string value) {
    return document.object().value(QString(value.c_str())).toString().toUtf8().constData();
}

QJsonDocument Parser::ReturnJson(const char* inbox){
    std::string str = static_cast<std::string>(inbox); //Char to string
    QString Qstr = QString::fromUtf8(str.c_str()); //String to QString
    QJsonDocument document = QJsonDocument::fromJson(Qstr.toUtf8()); //QString to QJsonDocument
    return document;
}

QJsonDocument Parser::ReturnJsonFromStr(std::string text){
    QString Qstr = QString::fromUtf8(text.c_str()); //String to QString
    QJsonDocument document = QJsonDocument::fromJson(Qstr.toUtf8()); //QString to QJsonDocument
    return document;
}
