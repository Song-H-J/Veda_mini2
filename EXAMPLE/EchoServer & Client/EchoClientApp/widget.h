#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QTcpSocket>

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
    ~Widget();

// 두 개의 커스텀 슬롯 등록
private slots:
    void echoData( );
    void sendData(  );

private:
    QTextEdit *message;
    QLineEdit *inputLine;
    QTcpSocket *clientSocket;
};

#endif // WIDGET_H
