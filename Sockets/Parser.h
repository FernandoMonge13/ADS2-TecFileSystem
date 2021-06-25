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


/*!
 * @brief Se encarga de generar un QJsonDocument el cual sera utilizado como un simple mensaje vacio que sera enviado al servidor cuando este no debe de realizar nada
 * @return QJsonObject
 */
    static QJsonObject Nothing();

/*!
 * @brief Se encarga de generar un QJsonDocument el cual contiene la informacion brindada por el Huffman
 * @param binary Binario
 * @return QJsonObject
 */
    static QJsonObject Huffman(std::string binary);

/*!
 * @brief Se encarga de generar un QJsonDocument el cual contiene la informacion del path al cual dirigirse
 * @param binary Path al que dirigirse
 * @return QJsonObject
 */
    static QJsonObject Path(std::string binary);

/*!
 * @brief Se encarga de generar un QJsonDocument el cual contiene la informacion que debera de mostrarse en pantalla
 * @param text Texto a mostrarse
 * @return QJsonObject
 */
    static QJsonObject ToShow(std::string text);

};


#endif //VENTANAFINAL_PARSER_H
