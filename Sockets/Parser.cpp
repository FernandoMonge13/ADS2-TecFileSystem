//
// Created by marco on 23/6/21.
//

#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include "Parser.h"

//QJsonObject Parser::CreateJsonObj_NoAddress(std::string type, std::string name, std::string value){
//    QJsonObject obj;
//    obj["toDo"] = "assign";
//    obj["type"] = type.c_str();
//    obj["name"] = name.c_str();
//    obj["value"] = value.c_str();
//    return obj;
//}
//
//QJsonObject Parser::CreateJsonObj_Free(std::string name){
//    QJsonObject obj;
//    obj["toDo"] = "free";
//    obj["name"] = name.c_str();
//    return obj;
//}
//
//QJsonObject Parser::CreateJsonObj_Asking(std::string name){
//    QJsonObject obj;
//    obj["toDo"] = "asking";
//    obj["name"] = name.c_str();
//    return obj;
//}
//
QJsonObject Parser::Nothing(){
    QJsonObject obj;
    obj["toDo"] = "nothing";
    return obj;
}
//
//QJsonObject Parser::CreateJsonObj_ReturnsData(std::string name) {
//    QJsonObject obj;
//    obj["value"] = name.c_str();
//    return obj;
//}
//
//QJsonObject Parser::CreateJsonObj_Address(std::string type, std::string name, std::string value, std::string address){
//    QJsonObject obj;
//    obj["type"] = type.c_str();
//    obj["name"] = name.c_str();
//    obj["value"] = value.c_str();
//    obj["address"] = address.c_str();
//    return obj;
//}
//
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
//
QJsonDocument Parser::ReturnJsonFromStr(std::string text){
    QString Qstr = QString::fromUtf8(text.c_str()); //String to QString
    QJsonDocument document = QJsonDocument::fromJson(Qstr.toUtf8()); //QString to QJsonDocument
    return document;
}
//
//QJsonObject Parser::CreateJsonObj_NewStructObject(std::string name, std::string integers,
//                                                  std::string doubles, std::string longs, std::string floats,
//                                                  std::string chars) {
//    QJsonObject obj;
//    obj["name"] = name.c_str();
//    obj["toDo"] = "newStruct";
//    obj["integers"] = integers.c_str();
//    obj["doubles"] = doubles.c_str();
//    obj["longs"] = longs.c_str();
//    obj["floats"] = floats.c_str();
//    obj["chars"] = chars.c_str();
//    return obj;
//}
//
//QJsonObject Parser::CreateJsonObj_FillStruct(std::string type, std::string toModify, std::string name) {
//    QJsonObject obj;
//    obj["name"] = name.c_str();
//    obj["toDo"] = "fillStruct";
//    obj["type"] = type.c_str();
//    obj["toModify"] = toModify.c_str();
//    return obj;
//}
//
//QJsonObject Parser::CreateJsonObj_ModifyStruct(std::string type, std::string toModify, std::string value, std::string name) {
//    QJsonObject obj;
//    obj["name"] = (name + "_struct").c_str();
//    obj["toDo"] = "fillStruct";
//    obj["type"] = type.c_str();
//    obj["value"] = value.c_str();
//    obj["toModify"] = toModify.c_str();
//    return obj;
//}
//
//QJsonObject Parser::CreateJsonObj_whatType(std::string name) {
//    QJsonObject obj;
//    obj["toDo"] = "whatType";
//    obj["name"] = name.c_str();
//    return obj;;
//}
//
//QJsonObject Parser::CreateJsonObj_isAttribute(std::string name, std::string attribute) {
//    QJsonObject obj;
//    obj["toDo"] = "isAttribute";
//    obj["name"] = name.c_str();
//    obj["attribute"] = attribute.c_str();
//    return obj;;
//}
