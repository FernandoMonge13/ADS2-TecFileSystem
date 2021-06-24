//
// Created by marco on 23/6/21.
//

#ifndef VENTANAFINAL_PARSER_H
#define VENTANAFINAL_PARSER_H


#include "QApplication"
#include <iostream>


class Parser {
public:

/*!
 * @brief Se encarga de convertir un QJsonDocument a un std::string
 * @param documentDocumento a parsear
 * @return std::string
 */
    static std::string ReturnChar(QJsonDocument document);

/*!
 * @brief Se encarga de obtener un valor especifico de un QJsonDocument
 * @param document Documento sobre el cual trabajar
 * @param value Valor que se desea obtener
 * @return std::string
 */
    static std::string ReturnStringValueFromJson(QJsonDocument document, std::string value);

/*!
 * @brief Se encarga de convertir un conjuto de chars en el QJsonDocumt
 * @param inbox Caracteres a parsear
 * @return QJsonDocument
 */
    static QJsonDocument ReturnJson(const char* inbox);

/*!
 * @brief Se encarga de convertir un std::string a un QJsonDocument
 * @param text Valor a parsear
 * @return QJsonDocument
 */
    static QJsonDocument ReturnJsonFromStr(std::string text);

///*!
// * @brief Generar QJsonDocument el cual sera utilizado para cuando se desee liberar memoria
// * @param name Nombre de la variable que se desea liberar
// * @returnQJsonObject
// */
//    static QJsonObject CreateJsonObj_Free(std::string name);
//
///*!
// * @brief Se encarga de generar un QJsonDocument el cual sera utilizado para cuando se desear agregar variables a memoria
// * @param type El tipo de la variable
// * @param name El nombre de la vairable
// * @param value El valor que la variable almacenara
// * @return QJsonObject
// */
//    static QJsonObject CreateJsonObj_NoAddress(std::string type, std::string name, std::string value);
//
///*!
// * @brief Se encarga de generar un QJsonDocument el cual sera utilizado para cuando se reenviara al cliente el como la variable que se deseaba guardar se guardo
// * @param type El tipo de la variable
// * @param name El nombre de la vairable
// * @param value El valor que la variable almacenara
// * @param address La direccion de memoria
// * @return QJsonObject
// */
//    static QJsonObject CreateJsonObj_Address(std::string type, std::string name, std::string value, std::string address);
//
///*!
// * @brief  Generar QJsonDocument el cual sera utilizado para cuando se solitice lo que contiene una variable
// * @param name Nombre de la variable que se desea buscar
// * @return QJsonObject
// */
//    static QJsonObject CreateJsonObj_Asking(std::string name);
//
///*!
// * @brief Se encarga de generar un QJsonDocument el cual le permitira al cliente solicitar de que tipo de dato es una variable almacenada
// * @param name Nombre de la variable a buscar
// * @return QJsonDocument
// */
//    static QJsonObject CreateJsonObj_whatType(std::string name);
//
///*!
// * @brief Se encarga de generar un QJsonDocument el cual sera utilizado para reenviar los datos de una variable al cliente
// * @param name Nombre de la variable a buscar
// * @return
// */
//    static QJsonObject CreateJsonObj_ReturnsData(std::string name);
//
///*!
// * @brief Se encarga de generar un QJsonDocument el cual el servidor utilizara para generar los espacios en memoria del struct
// * @param name Nombre del struct que se esta generando
// * @param integers Cantidad de ints
// * @param doubles Cantidad de doubles
// * @param longs Cantidad de longs
// * @param floats Cantidad de floats
// * @param chars Cantidad de chars
// * @return QJsonDocument
// */
//    static QJsonObject CreateJsonObj_NewStructObject(std::string name, std::string integers, std::string doubles, std::string longs, std::string floats, std::string chars);
//
///*!
// * @brief Se encarga de generar un QJsonDocument el cual se encargara de asignarle los valores especificos a los atribustos de cada struct
// * @param type Tipo de dato a manipular
// * @param toModify Nombre del struct al que pertenece el atributo
// * @param name Nombre del atributo a modificar
// * @return
// */
//    static QJsonObject CreateJsonObj_FillStruct(std::string type, std::string toModify, std::string name);
//
///*!
// * @brief Se encarga de generar un QJsonDocument el cual el servidor utilizara para sobreescribir la informacion en los espacios de memoria de los atributos de un struct especifico
// * @param type Tipo de dato a manipular
// * @param toModify Struct el cual se va a manipular
// * @param value Dato que se sobreescribira
// * @param name Nombre del atriburo a sobreescribir
// * @return QJsonDocument
// */
//    static QJsonObject CreateJsonObj_ModifyStruct(std::string type, std::string toModify, std::string value, std::string name);
//
///*!
// * @brief Genera un QJsonDocument que le preguntara al servidor si una variable es un atributo de un struct
// * @param name Nombre del struct a buscar
// * @param attribute Nombre de la variable a buscar
// * @return
// */
//    static QJsonObject CreateJsonObj_isAttribute(std::string name, std::string attribute);
//
/*!
 * @brief Se encarga de generar un QJsonDocument el cual sera utilizado como un simple mensaje vacio que sera enviado al servidor cuando este no debe de realizar nada
 * @return QJsonObject
 */
    static QJsonObject Nothing();
};


#endif //VENTANAFINAL_PARSER_H
