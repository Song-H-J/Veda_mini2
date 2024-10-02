#include "widget.h"

#include <QtGui>
#include <QtWidgets>
#include <QtNetwork>
#include <QDebug>

#define BLOCK_SIZE      1024

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    // 서버 주소 입력받는 LindEdit 위젯
    QLineEdit* serverAddress = new QLineEdit(this);

    
    serverAddress->setText("127.0.0.1");
    // serverAddress->setInputMask("999.999.999.999;_");
    QRegularExpression re("^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                          "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                          "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                          "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$|");
    QRegularExpressionValidator validator(re);
    serverAddress->setValidator(&validator);
    serverAddress->setPlaceholderText("Server IP Address");
    // 정규식을 활용하여 IP Addr이 제대로 입력됐는지 체크

    // 포트 번호를 입력받는 LineEdit 위젯
    QLineEdit* serverPort = new QLineEdit(this);
    serverPort->setInputMask("00000;_");
    serverPort->setPlaceholderText("Server Port No");

    // 연결 버튼
    QPushButton* connectButton = new QPushButton("connect", this);

    // 가로 배열 - ADDR | PORT | CONNECT_BUTTON
    QHBoxLayout *serverLayout = new QHBoxLayout;
    serverLayout->addStretch(1);
    serverLayout->addWidget(serverAddress);
    serverLayout->addWidget(serverPort);
    serverLayout->addWidget(connectButton);

    // 내가 입력한 메시지(사실은 서버가 날린 에코)가 보이는 Read Only Text Edit 위젯 
    message = new QTextEdit(this);
    message->setReadOnly(true);

    // 채팅 메시지 입력하는 LineEdit 위젯
    inputLine = new QLineEdit(this);

    // 메시지 송신 버튼
    // SIGNAL : Clicked | SLOT : sendData
    QPushButton* sentButton = new QPushButton("Send", this);
    connect(sentButton, SIGNAL(clicked( )), SLOT(sendData( )));

    // 메시지 입력 라인과 센드 버튼을 가로열로 연결
    QHBoxLayout *inputLayout = new QHBoxLayout;
    inputLayout->addWidget(inputLine);
    inputLayout->addWidget(sentButton);

    // 종료 버튼 위젯.
    // SIGNAL : Clicked | SLOT : quit
    QPushButton* quitButton = new QPushButton("Quit", this);
    connect(quitButton, SIGNAL(clicked( )), qApp, SLOT(quit( )));

    // 종료 버튼 들어있는 한줄짜리 Hbox
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(quitButton);
    
    // Window 구조
    // --- 서버 주소, 포트, 커넥트---
    // 채팅 내용
    // --- 채팅 입력, 전송 ---
    // 종료 버튼
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(serverLayout);
    mainLayout->addWidget(message);
    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    clientSocket = new QTcpSocket(this);

    // 커넥트 버튼이 눌리면, 서버 주소와 포트 번호를 가지고 서버에 연결 시도
    connect(connectButton, &QPushButton::clicked,
            [=]{ clientSocket->connectToHost(serverAddress->text(), serverPort->text().toInt()); } );

    // 연결 시도 실패 시, 에러 처리
    connect(clientSocket, &QAbstractSocket::errorOccurred,
            [=]{ qDebug( ) << clientSocket->errorString(); });

    // 클라이언트 소켓이 읽을 준비가 되면(SIGNAL), echoData 슬롯
    connect(clientSocket, SIGNAL(readyRead( )), SLOT(echoData( )));
    setWindowTitle(tr("Echo Client"));
}

// 소멸자에서 소켓 닫기
Widget::~Widget()
{
    clientSocket->close();
}

// echoData Slot :
// 서버로부터 수신한 데이터를 BLOCK_SIZE만큼 읽는다.
// 그 후 QByteArray에 저장하고, 그것을 message 위젯에 출력한다.
void Widget::echoData( )
{
    QTcpSocket *clientSocket = dynamic_cast<QTcpSocket *>(sender( ));
    if (clientSocket->bytesAvailable( ) > BLOCK_SIZE) return;
    QByteArray bytearray = clientSocket->read(BLOCK_SIZE);
    message->append(QString(bytearray));
}

// sendData Slot :
// Qstring에 inputLine 위젯에 쓰인 텍스트를 저장한다.
// strd을 UTF-8으로 인코딩하고, bytearray에 저장 후 서버 소켓에 전달한다.
void Widget::sendData(  )
{
    QString str = inputLine->text();
    if(str.length()) {
        QByteArray bytearray;
        bytearray = str.toUtf8();
        clientSocket->write(bytearray);
    }
}
