#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonDocument>
#include "../Sockets/Client.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    /*!
     * @brief Permite a la ventana principal obtener un Json para enviar al servidor por medio del cliente
     * @return std::string
     */
    static std::string getJson();

    /*!
     * @brief Permite a la ventana principal establecer un Json para enviar al servidor por medio del cliente
     * @param toSet Valor que se va a poner al Json
     */
    static void setJson(std::string toSet);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    QJsonDocument doc;
    Ui::MainWindow *ui;
    static std::string json;
    Client *client = new Client;
};
#endif // MAINWINDOW_H
